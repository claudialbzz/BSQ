# BSQ Project

## Overview
The BSQ (Biggest Square) project is a C application designed to find the largest square of '1's in a given map represented as a grid of '0's and '1's. The application reads a map from a file, processes it, and outputs the largest square found.

## Project Structure
```
bsq
├── src
│   ├── main.c        # Entry point of the application
│   ├── map.c         # Functions for map handling
│   ├── solve.c       # Logic for solving the problem
│   ├── print.c       # Functions for printing results
│   └── error.c       # Error handling functions
├── include
│   ├── map.h         # Header for map functions
│   ├── solve.h       # Header for solving functions
│   ├── print.h       # Header for printing functions
│   └── error.h       # Header for error handling functions
├── Makefile           # Build instructions
└── README.md          # Project documentation
```

## Compilation
To compile the project, navigate to the project directory and run the following command:

```
make
```

This will generate the executable file.

## Running the Application
After compiling, you can run the application with the following command:

```
./bsq <map_file>
```

Replace `<map_file>` with the path to the file containing the map.

## Error Handling
The application includes error handling to manage issues such as file not found, invalid map format, and memory allocation failures. Error messages will be displayed to guide the user.

## Contribution
Feel free to contribute to the project by submitting issues or pull requests.