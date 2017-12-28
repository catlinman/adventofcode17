#include <iostream>
#include <vector>
#include <fstream>

int main() {
    // Create a new input filestream to read from.
    std::ifstream filestream("input.txt");

    // Input data from the website read and converted directly into an integer vector.
    std::vector<int> jumps((std::istream_iterator<int>(filestream)), {});

    int steps = 0; // Number of steps taken so far.
    int index = 0; // Navigation index within the jumps vector.

    while (index >= 0 && index < jumps.size()) {
        index += jumps[index]++; // Apply the jump and increment.
        ++steps;                 // Increment the step.
    }

    // Output the final count of valid phrases.
    std::cout << steps << std::endl;

    return 0;
} // main
