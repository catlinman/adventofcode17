#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Create a new input filestream to read from.
    std::ifstream filestream("input.txt");

    // Input data from the website. Using a string since we will be accessing single digits.
    std::vector<int> jumps(std::istream_iterator<int>(filestream), {});

    bool wrap = false; // Stores whether the iteration has wrapped or not.
    int index = 0;     // Current index of the iteration.
    int sum   = 0;     // Sum of our calculations.

    // Loop until a result is found.
    while (true) {
        int current = input.at(index); // Get the number at the index in the string.

        // Get the value halfway around the number and loop if needed.
        int selection = (index + (input.length() / 2)) % input.length();


        if (input.at(selection) == current) // If the input matches we add the value to the sum.
            sum += current - '0';           // Convert from a char to an integer first.

        else if (wrap) break;  // If we find no match but have wrapped we stop the loop.

        // Increment the index.
        index++;

        // Once the index surpasses the end make sure to wrap it back and flag.
        if (index == input.length()) {
            index = 0;
            wrap  = true;
        }
    }

    // Print out our resulting sum value.
    std::cout << sum << std::endl;

    return 0;
} // main
