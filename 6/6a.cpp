#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

int maxValueIndex(std::vector<int>& vec) {
    int max = 0, index = 0; // Max value and index of max value.

    for (auto i = vec.begin(); i != vec.end(); ++i)
        if (*i > max) {
            max   = *i;
            index = i - vec.begin();
        }

    return index;
}

int main() {
    // Create a new input filestream to read from.
    std::ifstream filestream("input.txt");

    // Input data from the website read and converted directly into an integer vector.
    std::vector<int> banks(std::istream_iterator<int>(filestream), {});

    // Vector containing previous setups.
    std::vector<std::vector<int> > records;

    int amount = banks.size(); // Total amounts of banks from the input setup.
    bool found = false;        // Is true if a match/duplicate was detected.

    while (!found) {
        records.push_back(banks); // Store the current state.

        int start = maxValueIndex(banks); // Index of the highest bank.
        int value = banks[start];         // Value of the highest bank.

        banks[start] = 0; // Set the starting value to zero as we use it's value.

        // Iterate and add until the value is empty.
        for (int i = 0; i < value; ++i)
            ++banks[(i + start + 1) % amount];

        // Begin iterating over states in the record.
        for (int i = 0; i < records.size(); ++i) {
            bool match = true; // If all matches pass this value remains true.

            // Iterate over values in both the record and current setup.
            for (int j = 0; j < amount; ++j)
                if (banks[j] != records[i][j]) {
                    match = false; // If a comparison is false the match is invalid.

                    break;
                }

            if (match) {
                found = true; // If we had a match we can stop searching.

                break;
            }
        }
    }

    // Output the index of the duplicate plus one which equals the steps.
    std::cout << "Found duplicate: " << records.size() << std::endl;

    return 0;
} // main
