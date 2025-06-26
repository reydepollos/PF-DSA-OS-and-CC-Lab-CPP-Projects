#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

int main() {
    int integerNumbers;
    cout << "Enter the number of elements in the array (2 to 100): ";
    cin >> integerNumbers;

    if (integerNumbers < 2 || integerNumbers > 100) {
        cout << "Invalid input! The number must be between 2 and 100." << endl;
        return 1;
    }

    int arr[100];
    cout << "Enter " << integerNumbers << " integers:" << endl;
    for (int i = 0; i < integerNumbers; ++i) {
        cin >> arr[i];
    }

    int maxLength = 0, startIdx = -1, endIdx = -1;

    for (int i = 0; i < integerNumbers; ++i) {
        int sum = 0;
        for (int j = i; j < integerNumbers; ++j) {
            sum += arr[j];
            if (isPrime(sum)) {
                int length = j - i + 1;
                if (length > maxLength) {
                    maxLength = length;
                    startIdx = i;
                    endIdx = j;
                }
            }
        }
    }

    if (maxLength > 0) {
        cout << "Longest sub-Array with a prime sum starts at index "
             << startIdx << " and ends at index " << endIdx << "." << endl;
    } else {
        cout << "No subarray with a prime sum found." << endl;
    }

    return 0;
}
