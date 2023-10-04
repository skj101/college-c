#include <stdio.h>  // Include the standard input/output library which provides functions like printf and scanf.

struct Distance {  // Define a structure named "Distance" to hold feet and inches.
    int feet;  // Declare an integer variable "feet" to store the feet component.
    int inches;  // Declare an integer variable "inches" to store the inches component.
};

int main() {  // Start of the main function.
    struct Distance distance1, distance2, result;  // Declare three instances of the Distance structure: distance1, distance2, and result.

    // Prompt user to enter details for the first distance
    printf("Enter details for the first distance (feet inches): ");  // Print a message asking the user to enter details for the first distance.
    scanf("%d %d", &distance1.feet, &distance1.inches);  // Read the user's input and store it in the feet and inches components of distance1.

    // Prompt user to enter details for the second distance
    printf("Enter details for the second distance (feet inches): ");  // Print a message asking the user to enter details for the second distance.
    scanf("%d %d", &distance2.feet, &distance2.inches);  // Read the user's input and store it in the feet and inches components of distance2.

    // Calculate the sum of inches and feet
    result.inches = distance1.inches + distance2.inches;  // Add the inches components of both distances and store the result in result.inches.
    result.feet = distance1.feet + distance2.feet + (result.inches / 12);  // Add the feet components of both distances, along with any extra feet from the sum of inches.
    result.inches %= 12;  // Take the remainder of dividing the sum of inches by 12 to get the final inches component.

    // Display the resultant distance
    printf("Resultant distance: %d feet %d inches\n", result.feet, result.inches);  // Print the resultant distance in feet and inches.

    return 0;  // Return 0 to indicate successful program termination.
}
