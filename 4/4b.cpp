#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

int main() {
    std::vector<std::string> phrases;

    // Create a new input filestream for the input data.
    std::ifstream input("input.txt");
    for (std::string line; getline(input, line);) {
        std::string buffer;             // Buffer for the string stream.
        std::stringstream stream(line); // Create a stream from the line.

        // Contains the separated words in tokenized form for verification.
        std::vector<std::string> tokens;

        // Stores whether or not a phrase is valid.
        bool valid = true;

        // Read word for word into a buffer.
        while (stream >> buffer) {
            // Iterate over already existing tokens.
            for (std::string token : tokens)
                // Precheck if token and buffer are the same size.
                if (token.size() == buffer.size()) {
                    // Sort both tokens. If they are anagrams they will be the same.
                    std::sort(token.begin(), token.end());
                    std::sort(buffer.begin(), buffer.end());

                    if (token == buffer) {
                        // Flag phrases if they contain a duplicate.
                        valid = false;
                        break;
                    }
                }

            // Add the token to the collection for this phrase.
            tokens.push_back(buffer);
        }

        // Only added phrases that are verified.
        if (valid) phrases.push_back(line);
    }

    // Output the final count of valid phrases.
    std::cout << phrases.size() << std::endl;

    return 0;
} // main
