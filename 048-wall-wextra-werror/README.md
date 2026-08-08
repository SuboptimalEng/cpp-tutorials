## Video Overview

- Why is it recommended to enable Wall, Wextra, Werror?
  -Wall: "Tell me about the obvious problems."
  -Wextra: "Tell me about less obvious problems too."
  -Werror: "Don't let me compile the program if there are any warnings."

- Why do we need Wextra, shouldn't Wall handle all errors?
  - Late 80s -Wall was created
  - As more warnings were added as GCC evolved and could detect more bugs
    - Added -W
    - The -W flag was confusing because -Wall already existed...
    - Early 2000s, -Wextra was introduced as preferred name for -W

- Wall errors examples

- Wextra errors examples

- Werror demo

```bash
clang++ -Wall -Wextra -Werror main.cpp -o main && ./main
```

## Titles

- Why Does C++ Need -Wextra If You Already Have -Wall?
- What Do These C++ Compiler Flags Do?
- Why Enable -Wall and -Wextra in C++?

- Why Do You Need -Wextra When You Already Have -Wall in C++?
- C++ Wall, Wextra, Werror Explained
- Why you should enable Wall, Wextra, Werror in C++
- Why is it recommended to enable Wall, Wextra, Werror in C++?

## References

- [cppreference.com](https://cppreference.com/cpp)
- [learncpp.com](https://www.learncpp.com/)
- ChatGPT and Gemini
