// __attribute__((noinline)) is a compiler directive
// (GCC/Clang) that tells it not to inline this
// function, even if it thinks it would be faster

// assembly is easy!

__attribute__((noinline)) int add(int a, int b) {
  return a + b;
}

__attribute__((noinline)) int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int main() {
  int a = add(1, 2);   // 3
  int b = max(a, 10);  // 10
  return 0;
}
