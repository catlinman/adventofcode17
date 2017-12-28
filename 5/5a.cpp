#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

int main() {
    std::vector<int> jumps;

    // Create a new input filestream for the input data.
    std::ifstream input("input.txt");

    // Read lines from the input file.
    for (std::string line; getline(input, line);) {
        std::stringstream stream(line); // Create a new string stream for conversion.

        int converted = 0;   // The converted value.
        stream >> converted; // Stream and convert.

        jumps.push_back(converted); // Push the new value to the vector.
    }

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
