# Ptr vs Ref for Output Params

## TL;DR

- Why pass-by-ptr is better than pass-by-ref for output params in C++
- This is recommended by Google C++ style guide (used in industry)

## Video Overview

- [x] C++ double variables and add function example
- [x] Output params - pass variable by reference
- [x] Output params - pass variable as a pointer
- [x] Which approach is better (simpler, readable, maintainable, code story)
  - [x] Prefer using return values over output params (if possible)
  - [x] Google C++ style guide recommends the pointer approach
- [x] AI vibe coding, code reviewing rant

## Titles

- Google C++ Style Guide: Pointers vs References for Output
- C++ Pointers vs References: Which is Better for Outputs?
- Google C++ Coding Standards: Why use Pointers for Out Parameters?
- How to Guide AI to Write Clean C++ (Google Style Edition)
- Vibe Coding C++: Why You Need the Google Style Guide
- Prompting for Performance: Using Google C++ Rules in Cursor AI

```cpp

int sum(int& a, int* b);

```

## Timestamps

- 00:00 Intro

## References

- Google C++ Style Guide, Inputs and Outputs - https://google.github.io/styleguide/cppguide.html#Inputs_and_Outputs
- ChatGPT and Gemini
