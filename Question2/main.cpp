#include <iostream>
using namespace std;

int main() {
    int rows, columns;

    do {
        cout << "Enter the number of rows (1 to 8): ";
        cin >> rows;
        if (rows < 1 || rows > 8) {
            cout << "Invalid input! Rows must be between 1 and 8." << endl;
        }
    } while (rows < 1 || rows > 8);

    do {
        cout << "Enter the number of columns (1 to 8): ";
        cin >> columns;
        if (columns < 1 || columns > 8) {
            cout << "Invalid input! Columns must be between 1 and 8." << endl;
        }
    } while (columns < 1 || columns > 8);

    int matrix[8][8];
    cout << "Enter the elements of the " << rows << " x " << columns << " matrix row by row:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "Enter " << columns << " elements for row " << i + 1 << ": ";
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }

    int rotatedMatrix[8][8];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            rotatedMatrix[j][rows - i - 1] = matrix[i][j];
        }
    }

    cout << "Rotated matrix (90 degrees clockwise):" << endl;
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    int borderSum = 0;
    for (int i = 0; i < columns; ++i) {
        borderSum += rotatedMatrix[i][0] + rotatedMatrix[i][rows - 1];
    }
    for (int j = 1; j < rows - 1; ++j) {
        borderSum += rotatedMatrix[0][j] + rotatedMatrix[columns - 1][j];
    }

    cout << "Sum of border elements: " << borderSum << endl;

    return 0;
}
