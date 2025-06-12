#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <vector>   // Required for using std::vector (dynamic arrays)
#include <algorithm> // Not strictly needed for XOR, but useful for general utilities

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded).
    std::ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    std::cin.tie(NULL);                   // Prevents std::cout from flushing before std::cin reads

    int n; // Declare an integer variable 'n' to store the grid size
    std::cin >> n; // Read the value of 'n' from standard input

    // Declare a 2D vector (vector of vectors) to represent the n x n grid.
    // 'int' is sufficient for storing the values, as the maximum possible value
    // (r XOR c) for r, c < 1000 will be less than 2000 (e.g., 511 ^ 512 = 1023).
    std::vector<std::vector<int>> grid(n, std::vector<int>(n));

    // Fill the grid using the bitwise XOR property: grid[r][c] = r ^ c
    for (int r = 0; r < n; ++r) { // Loop through each row, from 0 to n-1
        for (int c = 0; c < n; ++c) { // Loop through each column, from 0 to n-1
            grid[r][c] = r ^ c; // Calculate the bitwise XOR of the row and column indices
        }
    }

    // Print the constructed grid to standard output
    for (int r = 0; r < n; ++r) { // Loop through each row for printing
        for (int c = 0; c < n; ++c) { // Loop through each column for printing
            std::cout << grid[r][c]; // Print the value in the current cell
            if (c < n - 1) { // If it's not the last element in the row
                std::cout << " "; // Print a space to separate numbers
            }
        }
        std::cout << "\n"; // After printing all elements in a row, print a newline character
    }

    return 0; // Indicate successful program execution
}
