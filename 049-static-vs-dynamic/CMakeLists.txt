cmake_minimum_required(VERSION 3.20)

project(MyProject)

# Note: Build a library whose code gets copied into the final executable when linking.
# add_library(MathLib STATIC
#     src/math.cpp
# )

# # Note: Build a library that stays as a separate file, and the executable loads it at runtime.
# # lldb commands
# # image list
# # image lookup --name add
add_library(MathLib SHARED
    src/math.cpp
)

target_include_directories(MathLib PUBLIC
    include
)

add_executable(App
    src/main.cpp
)

target_link_libraries(App PRIVATE MathLib)
