// Reference
// Francois: https://github.com/beaufortfrancois
// GitHub: https://github.com/beaufortfrancois/webgpu-cross-platform-app
// Reference: https://github.com/beaufortfrancois/webgpu-cross-platform-app/blob/main/main.cpp

#include <iostream>

/**
 * GLFW: cross-platform window and input library.
 * Used here mainly to create a window and get a native handle for WebGPU.
 */
#include <GLFW/glfw3.h>

/**
 * Emscripten/WebAssembly support.
 * Only needed when building for browser/WebAssembly targets.
 */
#if defined(__EMSCRIPTEN__)
#include <emscripten/emscripten.h>
#endif

/**
 * Optional Dawn utility header.
 * Provides functions to print human-readable info for WebGPU objects.
 * Useful for debugging or logging GPU info.
 */
#include <dawn/webgpu_cpp_print.h>

/**
 * WebGPU C++ RAII wrapper.
 * Simplifies using the low-level C API in a safe, idiomatic C++ style.
 */
#include <webgpu/webgpu_cpp.h>

/**
 * Helper to integrate WebGPU with GLFW windows.
 * Abstracts platform-specific surface creation.
 */
#include <webgpu/webgpu_glfw.h>

/**
 * Core WebGPU objects.
 */

/**
 * Entry point to the WebGPU API.
 * - Manages adapters, surfaces, and asynchronous GPU events.
 * - All GPU operations (device creation, surface setup, etc.) start from the Instance.
 */
wgpu::Instance instance;

/**
 * Represents a physical GPU in the system.
 * - Could be a discrete GPU (high-performance) or integrated GPU (low-power).
 * - Provides information about supported features, limits, and formats.
 * - Used as a basis to create a logical GPU device.
 */
wgpu::Adapter adapter;

/**
 * Logical GPU object used to issue rendering commands.
 * - Created from the Adapter.
 * - Responsible for creating GPU resources like buffers, textures, and pipelines.
 * - Handles command submission, validation, and error reporting.
 * - Central object for recording and executing GPU work.
 */
wgpu::Device device;

/**
 * Describes the GPU rendering pipeline.
 * - Combines vertex and fragment shaders, input layouts, rasterization, and blending state.
 * - Defines how vertex data is processed and how fragments are shaded.
 * - Can be reused for multiple draw calls.
 */
wgpu::RenderPipeline pipeline;

/**
 * Surface for rendering, typically linked to a window or canvas.
 * - Represents the target for presenting rendered frames.
 * - Format specifies the color texture layout (e.g., RGBA8Unorm).
 * - Used to acquire textures for the swap chain.
 */
wgpu::Surface surface;
wgpu::TextureFormat format;

// Window dimensions.
const uint32_t kWidth = 512;
const uint32_t kHeight = 512;

/**
 * Configure the rendering surface (swap chain) based on GPU capabilities.
 * Uses double/triple buffering to avoid flicker and tearing.
 */
void ConfigureSurface() {
  wgpu::SurfaceCapabilities capabilities;
  surface.GetCapabilities(adapter, &capabilities);
  format = capabilities.formats[0];
  wgpu::SurfaceConfiguration config{
      .device = device,
      .format = format,
      .width = kWidth,
      .height = kHeight,
      .presentMode = wgpu::PresentMode::Fifo,  // V-sync
  };
  surface.Configure(&config);
}

/**
 * Initialize core WebGPU objects: Instance, Adapter, and Device.
 *
 * - Instance: the entry point to the WebGPU API. Manages adapters, surfaces, and async events.
 * - Adapter: represents a physical GPU (discrete or integrated) and its capabilities.
 * - Device: logical GPU used to create resources, pipelines, and issue rendering commands.
 */
void Init() {
  /**
   * Create a WebGPU Instance.
   *
   * - `timedWaitAnyEnable = true` allows synchronous waiting on multiple asynchronous operations.
   * - Instance is required before requesting an Adapter or creating a Surface.
   */
  wgpu::InstanceDescriptor instanceDesc{
        .capabilities = {
            .timedWaitAnyEnable = true,
        },
    };
  instance = wgpu::CreateInstance(&instanceDesc);

  /**
   * Request a GPU adapter asynchronously but wait synchronously.
   *
   * - Adapter represents the actual physical GPU the device will use.
   * - We check for success and exit if no adapter is found.
   */
  wgpu::Future f1 = instance.RequestAdapter(
      nullptr,
      wgpu::CallbackMode::WaitAnyOnly,
      [](wgpu::RequestAdapterStatus status, wgpu::Adapter a, wgpu::StringView message) {
        if (status != wgpu::RequestAdapterStatus::Success) {
          std::cout << "RequestAdapter: " << message << "\n";
          exit(0);
        }
        adapter = std::move(a);
      });
  instance.WaitAny(f1, UINT64_MAX);

  /**
   * Request a logical GPU device from the adapter.
   *
   * - Device is required to create GPU resources and pipelines.
   * - Set an uncaptured error callback to log any runtime GPU errors.
   * - Wait synchronously for device creation to complete.
   */
  wgpu::DeviceDescriptor desc{};
  desc.SetUncapturedErrorCallback(
      [](const wgpu::Device&, wgpu::ErrorType errorType, wgpu::StringView message) {
        std::cout << "Error: " << errorType << " - message: " << message << "\n";
      });
  wgpu::Future f2 = adapter.RequestDevice(
      &desc,
      wgpu::CallbackMode::WaitAnyOnly,
      [](wgpu::RequestDeviceStatus status, wgpu::Device d, wgpu::StringView message) {
        if (status != wgpu::RequestDeviceStatus::Success) {
          std::cout << "RequestDevice: " << message << "\n";
          exit(0);
        }
        device = std::move(d);
      });
  instance.WaitAny(f2, UINT64_MAX);
}

/**
 * Embedded WGSL shader code as a raw string.
 *
 * - Vertex shader (`vertexMain`): outputs positions of a single triangle.
 * - Fragment shader (`fragmentMain`): outputs a solid magenta color.
 *
 * Notes:
 * - WGSL is the shading language used in WebGPU.
 * - Raw string literal (R"( ... )") avoids escaping quotes or newlines.
 */
const char shaderCode[] = R"(
    @vertex fn vertexMain(@builtin(vertex_index) i : u32) -> @builtin(position) vec4f {
        const pos = array(vec2f(0,1), vec2f(-1,-1), vec2f(1,-1));
        return vec4f(pos[i],0,1);
    }
    @fragment fn fragmentMain() -> @location(0) vec4f {
        return vec4f(1,0,0,1);
    }
)";

/**
 * Create a render pipeline: encapsulates all GPU state needed to draw.
 *
 * A render pipeline in WebGPU defines:
 *  - Vertex processing: how vertices are transformed and passed to the fragment stage.
 *  - Fragment processing: how pixel colors are computed and written to the framebuffer.
 *  - Output formats, blending, rasterization, and other GPU state.
 *
 * This function sets up a simple pipeline using the embedded WGSL shader.
 */
void CreateRenderPipeline() {
  wgpu::ShaderSourceWGSL wgsl{{
      .code = shaderCode,
  }};
  wgpu::ShaderModuleDescriptor shaderModuleDescriptor{
      .nextInChain = &wgsl,
  };
  wgpu::ShaderModule shaderModule = device.CreateShaderModule(&shaderModuleDescriptor);
  wgpu::ColorTargetState colorTargetState{
      .format = format,
  };
  wgpu::FragmentState fragmentState{
      .module = shaderModule,
      .targetCount = 1,
      .targets = &colorTargetState,
  };
  wgpu::RenderPipelineDescriptor descriptor{
      .vertex = {
          .module = shaderModule,
      },
      .fragment = &fragmentState,
  };
  pipeline = device.CreateRenderPipeline(&descriptor);
}

/**
 * Render a single frame.
 *
 * Steps:
 * 1. Acquire the next available texture from the surface to render into.
 * 2. Set up a render pass describing how the GPU should render to that texture.
 * 3. Record drawing commands (vertex/fragment pipeline operations) into a command encoder.
 * 4. Submit the recorded commands to the GPU queue for execution.
 *
 * This function is typically called every frame in the main loop.
 */
void Render() {
  wgpu::SurfaceTexture surfaceTexture;
  surface.GetCurrentTexture(&surfaceTexture);

  wgpu::RenderPassColorAttachment attachment{
      .view = surfaceTexture.texture.CreateView(),
      .loadOp = wgpu::LoadOp::Clear,
      .storeOp = wgpu::StoreOp::Store,
  };
  wgpu::RenderPassDescriptor renderpass{
      .colorAttachmentCount = 1,
      .colorAttachments = &attachment,
  };

  wgpu::CommandEncoder encoder = device.CreateCommandEncoder();
  wgpu::RenderPassEncoder pass = encoder.BeginRenderPass(&renderpass);
  pass.SetPipeline(pipeline);
  pass.Draw(3);  // Single triangle
  pass.End();

  wgpu::CommandBuffer commands = encoder.Finish();
  device.GetQueue().Submit(1, &commands);
}

/** Setup graphics objects: configure surface and create pipeline */
void InitGraphics() {
  ConfigureSurface();
  CreateRenderPipeline();
}

/**
 * Start application: initialize GLFW, create window and surface, enter render loop.
 */
void Start() {
  if (!glfwInit())
    return;

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);  // WebGPU only
  GLFWwindow* window = glfwCreateWindow(kWidth, kHeight, "WebGPU window", nullptr, nullptr);

  surface = wgpu::glfw::CreateSurfaceForWindow(instance, window);
  InitGraphics();

#if defined(__EMSCRIPTEN__)
  emscripten_set_main_loop(Render, 0, false);
#else
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    Render();
    surface.Present();
    instance.ProcessEvents();
  }
#endif
}

/** Program entry point */
int main() {
  Init();
  Start();
}
