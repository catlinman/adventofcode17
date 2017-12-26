#include <iostream>
#include <cmath>
#include <vector>
#include <string>

// Get the digits of a number.
long digits(long i) {
    return i > 0 ? (int) log10((double) i) + 1 : 1;
}

// Pretty print a grid of numbers.
void printGrid(std::vector<std::vector<long> > grid) {
    long topValue = 0; // Store the highest entry.

    // Begin iterating over rows in the grid and select their top value.
    for (int i = 0; i < grid.size(); i++) {
        long curValue = *max_element(grid[i].begin(), grid[i].end());

        // Check if this value is bigger than our current top. If so, replace it.
        if (curValue > topValue) topValue = curValue;
    }

    // Get the digits of the biggest value.
    int topDigits = digits(topValue);

    // Create a new string which will act as a separator.
    std::string separator = "";

    // Iterate over the size of the grid multiplied by the max digits and add to the separator.
    for (int i = 0; i < grid.size() * (topDigits + 1) + 1; i++)
        separator += "─";

    // Print it out as bounds for the top most row.
    std::cout << separator << std::endl;

    // Begin iterating over rows and columns.
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid.size(); x++) {
            int curDigits = digits(grid[y][x]); // Get this entry's digits.

            std::string padding = ""; // Create a new padding string-

            // Only create further padding if required. Otherwise increment and add.
            if (curDigits < topDigits)
                for (int i = 0; i < topDigits - curDigits; i++)
                    padding += " ";

            // Apply a bounding character and padding around this value.
            std::cout << "|" << padding << grid[y][x];

            // If this is the last column apply another bounding character.
            if (x == grid.size() - 1) std::cout << "|";
        }

        // Print out the entire row.
        std::cout << std::endl << separator << std::endl;
    }
} // printGrid

int main() {
    // Size of the grid to create.
    int size;

    // Ask the user to enter the input value.
    std::cout << "Enter the input size layers of the grid: ";
    std::cin >> size;

    // Make sure the grid is not pow2.
    size = size * 2 - 1;

    // Create a new grid.
    std::vector<std::vector<long> > grid(size, std::vector<long>(size));

    // Get the start position by placing it in the center of the grid.
    int start = std::ceil(size / 2);

    // Insert the starting value.
    grid[start][start] = 1;

    // Set the starting position.
    int px = start;
    int py = start;

    // Set the starting directions.
    int dx = 1;
    int dy = 0;

    // Begin iterating over cells.
    for (int i = 0; i < size * size; i++) {
        // Apply movement.
        px += dx;
        py += dy;

        // Proximity check for bounding cells.
        for (int y = 0; y <= 2; y++)
            for (int x = 0; x <= 2; x++) {
                if (x == 1 && y == 1) continue;  // Skip the center cell.

                // Get the absolute position of the bounding cell.
                int cx = px - 1 + x;
                int cy = py - 1 + y;

                // Make sure the bounding cell is inside the vector's bounds.
                if (cx >= 0 && cx <= size - 1 && cy >= 0 && cy <= size - 1)
                    grid[py][px] += grid[cy][cx];
            }

        // Position checks to assess if there are values around in certain spots.
        bool up    = py - 1 >= 0 && py - 1 <= size - 1 ? grid[py - 1][px] != 0 : true;
        bool down  = py + 1 >= 0 && py + 1 <= size - 1 ? grid[py + 1][px] != 0 : true;
        bool left  = px - 1 >= 0 && px - 1 <= size - 1 ? grid[py][px - 1] != 0 : true;
        bool right = py + 1 >= 0 && px + 1 <= size - 1 ? grid[py][px + 1] != 0 : true;

        // Begin handling movement direction based on current movement and surrounding cells.
        if (dx == 1 && !up) {
            // Going right, turn up.
            dx = 0;
            dy = -1;


        } else if (dy == -1 && !left) {
            // Going up, turn left.
            dx = -1;
            dy = 0;


        } else if (dx == -1 && !down) {
            // Going left, turn down.
            dx = 0;
            dy = 1;


        } else if (dy == 1 && !right) {
            // Going down, turn right.
            dx = 1;
            dy = 0;
        }
    }

    // Print out the resulting grid.
    printGrid(grid);

    return 0;
} // main
