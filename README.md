# Magic Square Visualizer

A lightweight C++ console application that generates an odd-order magic square and renders it in the terminal using cursor positioning and color styling. The project combines a reusable display library with a simple interactive console program to create a visually appealing numeric pattern.

## Overview

This project demonstrates:

- generation of odd-sized magic squares
- terminal cursor control with ANSI escape sequences
- animated number placement in the console
- reusable C++ library design using a static library

The application is designed for learning, demos, and terminal-based visualization experiments. It is intentionally simple, portable, and easy to build.

## Features

- Generates a magic square for any odd integer size
- Positions values on the terminal using coordinate-based output
- Supports multiple terminal colors: red, green, yellow, blue, magenta, cyan, and white
- Uses a clean separation between logic and terminal rendering
- Includes a static library build workflow and executable output

## Project Structure

```text
Magic/
├── app                     # Compiled executable
├── include/
│   └── mylib.h            # Public library declarations
├── src/
│   ├── magic.cpp          # Main program that builds the magic square
│   └── mylib.cpp          # Terminal color and display helpers
├── libmylib.a             # Static library artifact
├── README.md              # Project documentation
├── .git/                  # Git metadata
└── .gitignore             # Git ignore rules (if present)
```

## Requirements

- C++ compiler such as `g++`
- Linux or Unix-like environment
- Terminal that supports ANSI color and cursor control sequences

## Quick Start

### 1. Build the application

```bash
g++ -std=c++17 -Iinclude src/mylib.cpp src/magic.cpp -o app
```

### 2. Run it

```bash
./app
```

### 3. Enter a magic-square size

```text
Enter the size of the magic square: 5
```

The program will generate a 5x5 magic square and display each value in a terminal grid.

## Alternative Build Using a Static Library

This project also supports a static library workflow:

```bash
g++ -std=c++17 -Iinclude -c src/mylib.cpp -o mylib.o
ar rcs libmylib.a mylib.o
g++ -std=c++17 -Iinclude src/magic.cpp -L. -lmylib -o app
```

## How It Works

The program uses the standard Siamese method for odd-order magic squares. It places the first number at the center of the first row and then moves diagonally upward-left for successive numbers. When a move would go outside the bounds of the square, the implementation wraps around and continues the pattern.

The terminal output is controlled via the library functions in `include/mylib.h`, which place each value at a specific `(x, y)` coordinate on the screen.

## Library API

The reusable library exposes the following interface:

```cpp
#ifndef MYLIB2_HPP
#define MYLIB2_HPP

#include <string>

void setColor(std::string color);
void display(int x, int y, std::string message);

#endif
```

### Function Summary

- `setColor(color)`: changes the active terminal color
- `display(x, y, message)`: writes text at a specific screen position

## Example Output

The program prints a magic square in the terminal. For an input size of `5`, the display is arranged as a visual square grid rather than a plain numerical list.

```text
Enter the size of the magic square: 5
```

The output is rendered in the terminal with each number placed at a calculated position to form the magic square layout.

## Notes

- The implementation is intended for odd values such as 3, 5, 7, and so on.
- The display is best viewed in a terminal emulator that supports ANSI escape sequences.
- Small delays are introduced between updates to make the construction of the square visible in real time.

## License

This project is provided for educational and demonstration purposes.

## Author

Developed as a simple C++ terminal visualization project for learning and experimentation.
