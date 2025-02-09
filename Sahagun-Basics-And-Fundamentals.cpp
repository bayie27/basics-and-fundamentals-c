#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

// Function to validate integer input (returns true if valid)
bool isValidInteger(const string& input, int& output) {
    try {
        size_t pos;
        output = stoi(input, &pos);  // Try converting string to integer
        if (pos == input.length()) {  // Ensure no extra characters are present
            return true;
        }
    } catch (const exception&) {
        return false;  // Catch invalid integer conversion
    }
    return false;
}

// Function to check if the input contains only one valid integer (no extra characters or numbers)
bool isSingleInteger(const string& input) {
    stringstream ss(input);
    int number;
    char extra;
    ss >> number;  // Try reading an integer from the string
    if (ss >> extra) {
        return false;  // If any extra characters exist, return false
    }
    return true;  // Otherwise, it's a valid single integer
}

// Function to validate input to be strictly a number (e.g., '1', '10')
bool isValidElementNumber(const string& input, int& output, int min, int max) {
    // Check if input is a valid single integer with no spaces
    if (input.find(' ') != string::npos) {
        return false;  // If there is a space, return false
    }
    if (isSingleInteger(input) && isValidInteger(input, output)) {
        if (output >= min && output <= max) {
            return true;
        }
    }
    return false;
}

// Function to check if the input is a valid real number (positive, negative, or decimal)
bool isValidRealNumber(const string& input) {
    regex realNumberRegex("^-?\\d*\\.?\\d+$");  // Pattern to match integers or decimals
    return regex_match(input, realNumberRegex);
}

// Function to manually sort the array in descending order using Bubble Sort
void bubbleSortDescending(vector<float>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] < arr[j + 1]) {
                // Swap if the current element is smaller than the next
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to merge two arrays into a third array
void mergeAndSortArrays() {
    vector<float> array1(10), array2(10), mergedArray;
    int n1, n2;

    // Get elements for the first array (only accept whole numbers between 1 and 10)
    string input;
    do {
        cout << endl << "Enter the number of elements for the first array (1-10): ";
        getline(cin, input);

        if (!isValidElementNumber(input, n1, 1, 10)) {
            cout << "Invalid input! Please enter a valid whole number between 1 and 10, without spaces." << endl;
        }
    } while (n1 <= 0 || n1 > 10);

    for (int i = 0; i < n1; ++i) {
        while (true) {
            cout << "Enter element " << (i + 1) << " of " << n1 << ": ";
            getline(cin, input);

            // Validate that the input is a valid real number
            if (isValidRealNumber(input)) {
                stringstream(input) >> array1[i];  // Convert the string to float
                break;
            } else {
                cout << "Invalid input! Please enter a valid numeric value." << endl;
            }
        }
    }

    // Get elements for the second array (only accept whole numbers between 1 and 10)
    do {
        cout << endl << "Enter the number of elements for the second array (1-10): ";
        getline(cin, input);

        if (!isValidElementNumber(input, n2, 1, 10)) {
            cout << "Invalid input! Please enter a valid whole number between 1 and 10, without spaces." << endl;
        }
    } while (n2 <= 0 || n2 > 10);	

    for (int i = 0; i < n2; ++i) {
        while (true) {
            cout << "Enter element " << (i + 1) << " of " << n2 << ": ";
            getline(cin, input);

            // Validate that the input is a valid real number
            if (isValidRealNumber(input)) {
                stringstream(input) >> array2[i];  // Convert the string to float
                break;
            } else {
                cout << "Invalid input! Please enter a valid numeric value." << endl;
            }
        }
    }

    // Merge arrays into mergedArray
    mergedArray.insert(mergedArray.end(), array1.begin(), array1.begin() + n1);
    mergedArray.insert(mergedArray.end(), array2.begin(), array2.begin() + n2);

    // Sort mergedArray in descending order using bubble sort
    bubbleSortDescending(mergedArray);

    // Display the merged and sorted array
    cout << endl << "Merged and sorted array in descending order: ";
    for (float num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to check if the input choice is valid (y/n)
bool isValidChoice(const string& input) {
    return (input == "y" || input == "Y" || input == "n" || input == "N");
}

int main() {
    char choice;
    do {
        // Introduction and instructions
        cout << "Welcome to the Array Merge Program!" << endl;
        cout << "This program will merge two arrays and display them in descending order." << endl;
        cout << "Each array can hold up to 10 elements." << endl;

        // Call the mergeAndSortArrays function
        mergeAndSortArrays();

        // Ask the user if they want to use the program again
        string input;
        while (true) {
            cout << endl << "Do you want to use the program again? (y/n): ";
            getline(cin, input);  // Read the entire input line

            // Check if input contains only one valid character and no extra spaces
            if (input.length() == 1 && isValidChoice(input)) {
                choice = input[0];  // Set the choice based on user input
                break;
            } else {
                cout << "Invalid input! Please enter 'y' or 'n'." << endl;
            }
        }

    } while (choice == 'y' || choice == 'Y');  // Repeat if the user says 'y' or 'Y'

    cout << endl << "Thank you for using the Array Merge Program. Goodbye!" << endl;
    return 0;
}