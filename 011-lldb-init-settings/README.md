# LLDB Init Settings

## TL;DR

- It is tedious to set up LLDB commands every time you compile C++ code (or re-open LLDB)
- For example, you may need to run these 2 commands on restart (every time)
  - `b main` (break point at main)
  - `target stop-hook add -o "disassemble"` (show assembly)
- You can avoid this repetitive process by adding creating the `~/.lldbinit` file

## Video Overview

- Go over sample C++ code
- Show how to run LLDB by using `-g` compiler flag
- Show the need for using `b main` and `target stop-hook add -o "disassemble"`
- Change code, recompile, re-run LLDB, and notice that the settings are lost
- Show how setting up the `~/.lldbinit` file solves this problem

## LLDB Init Settings

- Add the settings with `vim ~/.lldbinit`

```bash
# vim ~/.lldbinit

# lldb (gdb)
# custom settings

# break point at main
breakpoint set --name main

# show assembly by default
target stop-hook add -o "disassemble"

# use this instead if you want to see 10 lines of assembly at program counter
# target stop-hook add -o "disassemble --pc --count 10"
```

## Titles

- How to Improve LLDB Debugger Developer Experience?
- How to Improve LLDB (gdb) Developer Experience for Debugging?
- How to Improve LLDB (GDB) Developer Experience with Custom Settings

## References

- ChatGPT
