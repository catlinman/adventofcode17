#include <iostream>

int main() {
    // The input here refers to the position at the same time if this were an array.
    int input;

    // Ask the user to enter the input value.
    std::cout << "Enter the input value: ";
    std::cin >> input;

    int steps = 0; // Amount of steps to the origin.

    int layer  = 0; // Layer of the spiral the value is on.
    int amount = 0; // Number of values in this layer.
    int low    = 1; // Lowest value in the layer.
    int high   = 1; // Highest value in the layer.

    // Get information on the input number and its layer.
    for (int i = 1; high < input; i++) {
        layer  = i;
        amount = 8 * layer;
        low    = high + 1;
        high  += amount;
    }

    // Create an array containing distances for the layer.
    int distances[(layer * 2) - 1];

    // Populate the distances array with the distances from the highest value
    // which also at the same time logically has the highest distance. Only
    // populate to the halfway point of a row since this has the lowest distance.
    for (int i = 0; i < layer + 1; i++) {
        distances[i] = (layer * 2) - i;

        // Mirror results as well for ping pong iteration.
        if (i < layer) distances[i + layer] = layer + i;
    }

    // Counter used to track the position in the ping pong distance array.
    int counter = 0;

    // Iterate from the highest number to the lowest as this makes things easier.
    for (int i = high; i >= low; i--) {
        // Check if our number matches the iteration number. If so, lookup the distance.
        if (i == input) {
            steps = distances[counter % (layer * 2)];
            break;
        }

        // Increment the counter and move on the next number.
        counter++;
    }

    // Print out all information.
    std::cout << "INPUT: (" << input
              << ") LAYER: " << layer
              << " AMOUNT: " << amount
              << " LOW: " << low
              << " HIGH: " << high
              << " STEPS: " << steps
              << std::endl;

    return 0;
} // main
