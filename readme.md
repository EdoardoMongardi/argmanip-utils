# argmanip-utils

A simple C library for transforming command-line arguments, with case conversion utilities and example programs.

## Description
This project provides a small, header-only C library to manipulate arrays of string arguments (`argv`), including case conversion functions (`toupper`, `tolower`). It includes example programs demonstrating usage and a test program showcasing process creation and execution flow.

## Contents

- **argmanip.h / argmanip.c**: Library API and implementation for copying and transforming `argv` entries.
- **nyuc.c**: Example program converting each argument to upper- and lower-case and printing the results.
- **test.c**: Demonstrates `fork`, `execl`, and argument flow by printing messages before and after process execution.
- **Makefile**: Build targets for the library and example programs.

## Building

To compile the library and example programs, run:

```sh
make all
```

This will produce:

- `libargmanip.a`: Static library
- `nyuc`: Upper- and lower-case argument transformer
- `test`: Fork and exec demonstration

## Usage

### nyuc

Convert arguments to upper- and lower-case:

```sh
./nyuc Hello World
```

Output:

```
[Hello] -> [HELLO] [hello]
[World] -> [WORLD] [world]
```

### test

Demonstrates process creation and execution:

```sh
./test
```

Output:

```
one
two
three
```

## Cleaning

Remove compiled artifacts:

```sh
make clean
```
