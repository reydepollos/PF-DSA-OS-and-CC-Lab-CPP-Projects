#include <iostream>
#include <vector>
#include <OpenXLSX.hpp>  // Include OpenXLSX library header

using namespace OpenXLSX;
using namespace std;

int main() {
    // Load the Excel workbook
    XLDocument doc;
    doc.open("example.xlsx");  // Path to your Excel file
    auto sheet = doc.workbook().worksheet("Sheet1");  // Name of the sheet you want to read

    // Determine the range of cells with data
    int rows = sheet.rowCount();
    int cols = sheet.columnCount();

    // Create a 2D array (vector of vectors) to store cell data
    vector<vector<string>> data(rows, vector<string>(cols));

    // Read cell data into the 2D array
    for (int row = 1; row <= rows; ++row) {
        for (int col = 1; col <= cols; ++col) {
            auto cell = sheet.cell(XLCellReference(row, col));
            if (cell.value().type() == XLValueType::String) {
                data[row - 1][col - 1] = cell.value().get<string>();
            } else if (cell.value().type() == XLValueType::Integer) {
                data[row - 1][col - 1] = to_string(cell.value().get<int64_t>());
            } else if (cell.value().type() == XLValueType::Float) {
                data[row - 1][col - 1] = to_string(cell.value().get<double>());
            } else {
                data[row - 1][col - 1] = "";  // Empty cell or unknown type
            }
        }
    }

    // Print the 2D array (for verification)
    for (const auto& row : data) {
        for (const auto& cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }

    doc.close();  // Close the document
    return 0;
}
