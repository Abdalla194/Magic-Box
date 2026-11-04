# Magic Square Console App

A compact C++ project that generates and displays a magic square in the terminal using custom terminal positioning and color utilities. The project combines a reusable library with a simple console application to produce a visually structured numeric pattern.

## Overview

This project demonstrates:

- generation of odd-order magic squares
- terminal cursor positioning via ANSI escape sequences
- colored console output
- a small static library and executable workflow in C++

The application is intentionally lightweight and focused on terminal-based visualization, making it useful as a learning project or a small utility for demos.

## Features

- Generates a magic square for any odd integer size
- Positions values in a terminal grid using coordinates
- Supports multiple text colors such as red, green, blue, yellow, magenta, cyan, and white
- Uses a reusable C++ library for display logic
- Produces a visual, interactive console output with delayed updates

## Project Structure

```text
Magic/
├── app                     # Built executable
├── include/
│   └── mylib.h            # Public library interface
├── src/
│   ├── magic.cpp          # Magic square generator application
│   └── mylib.cpp          # Terminal color and display implementation
├── libmylib.a             # Static library build artifact
├── README.md              # Project documentation
└── .git/                  # Git metadata
```

## Requirements

- C++ compiler (g++ recommended)
- Linux or Unix-like environment with terminal ANSI support
- Standard C++17-compatible toolchain

## Building

### Option 1: Compile directly

```bash
g++ -std=c++17 -Iinclude src/mylib.cpp src/magic.cpp -o app
```

### Option 2: Build the static library and link it

```bash
g++ -std=c++17 -Iinclude -c src/mylib.cpp -o mylib.o
ar rcs libmylib.a mylib.o
g++ -std=c++17 -Iinclude src/magic.cpp -L. -lmylib -o app
```

## Running

```bash
./app
```

When prompted, enter the size of the magic square. For example:

```text
Enter the size of the magic square: 5
```

The program will generate a 5x5 magic square in the terminal.

## Example Behavior

The library uses terminal cursor control to place each number at a specific coordinate. The application delays each step slightly to create a visible animation in the console.

A sample input/output flow looks like this:

```text
Enter the size of the magic square: 5
```

The terminal then displays a 5x5 magic square layout with numbered cells arranged according to the standard magic-square algorithm.

## Library API

The public interface is defined in `include/mylib.h`:

```cpp
void setColor(std::string color);
void display(int x, int y, std::string message);
```

### Function behavior

- `setColor(color)`: sets the active terminal color for subsequent output
- `display(x, y, message)`: writes text to the cursor position `(x, y)`

## Notes

- The project currently targets terminal rendering, so output is best viewed in a terminal emulator that supports ANSI escape sequences.
- The `display()` function uses console cursor movement to position text, which makes the output especially suitable for visual demonstrations.
- The application focuses on odd-sized magic squares, which is the standard case handled by the Siamese method used in the code.

## License

This project is provided as a learning/demo utility and is intended for educational use.

## Author

Developed as a small C++ terminal visualization project.
