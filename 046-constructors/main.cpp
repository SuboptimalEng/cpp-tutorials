#include <cassert>
#include <iostream>

// Why we need constructors (ctor)?
// What is a constructor?
// Naming + syntax
// Default, parameterized ctors

// Types of ctors
// - Default, parameterized, copy, move, etc.

// ==============================
// Example 1
// Why do we need constructors?
// Ensure object starts in valid state.
// - Prevent garbage data
// - Enforce rules upon creation
// - Prevent boilerplate code
// ==============================

// struct Box {
//   int x;
//   int y;
//   int z;
//   // default ctor is running...
//   // Box() {}
//   void PrintData() {
//     std::cout << "============" << std::endl;
//     std::cout << "X: " << this->x << std::endl;
//     std::cout << "Y: " << this->y << std::endl;
//     std::cout << "Z: " << this->z << std::endl;
//   }
// };

// int main() {
//   Box b1;
//   b1.PrintData();
//   // Example 2
//   // b1.x = 1;
//   // b1.y = 1;
//   // b1.z = 1;
//   b1.PrintData();
//   return 0;
// }

// // ==============================
// // Example 3
// // What is a Constructor (ctor)?
// // ==============================

struct Box {
  int x;
  int y;
  int z;

  // Constructor (ctor): A special method that runs automatically when an object is created
  // to initialize its member variables and set up its initial state.
  // Rules:
  // - Same name as struct/class
  // - No return type

  // Default ctor
  Box() {
    this->x = 1;
    this->y = 1;
    this->z = 1;
  }

  // With params
  Box(int a) {
    assert(a > 0);
    this->x = a;
    this->y = a;
    this->z = a;
  }

  // Ctor with multiple params
  Box(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  void PrintData() {
    std::cout << "============" << std::endl;
    std::cout << "X: " << this->x << std::endl;
    std::cout << "Y: " << this->y << std::endl;
    std::cout << "Z: " << this->z << std::endl;
  }
};

int main() {
  Box b1;
  b1.PrintData();
  Box b2(3);
  b2.PrintData();
  Box b3(2, 3, 4);
  b3.PrintData();
  return 0;
}

// struct Box2D {
//   int width;
//   int height;
//   Box2D();
// };

// Box2D::Box2D() {
//   this->width = 1;
//   this->height = 1;
// }
