
#include <vector>
using namespace std;

class Solution {

    struct Element {
        int value{};
        int column{};
        Element(int value, int column) : value{value}, column{ column} {}
    };

public:

    vector<vector<int>> multiply(vector<vector<int>>& firstGrid, vector<vector<int>>& secondGrid) {
        vector<vector < Element>> firstGrid_nonZeroValues;
        vector<vector < Element>> secondGrid_nonZeroValues;

        initializeList_nonZeroValues(firstGrid, firstGrid_nonZeroValues);
        initializeList_nonZeroValues(secondGrid, secondGrid_nonZeroValues);

        vector<vector<int>> resultMultiplication(firstGrid.size(), vector<int>(secondGrid[0].size(), 0));
        const size_t rows = resultMultiplication.size();

        for (int row = 0; row < rows; row++) {

            vector<Element> firstNonZero = firstGrid_nonZeroValues[row];
            for (Element first : firstNonZero) {

                vector<Element> secondNonZero = secondGrid_nonZeroValues[first.column];
                for (Element second : secondNonZero) {
                    resultMultiplication[row][second.column] += first.value * second.value;
                }
            }
        }

        return resultMultiplication;
    }

private:

    void initializeList_nonZeroValues(const vector<vector<int>>& grid, vector<vector<Element>>& nonZeroValues) {
        const size_t rows = grid.size();
        const size_t columns = grid[0].size();

        for (int row = 0; row < rows; row++) {
            vector<Element> currentRow;
            for (int column = 0; column < columns; column++) {
                if (grid[row][column] != 0) {
                    currentRow.push_back(Element(grid[row][column], column));
                }
            }
            nonZeroValues.push_back(currentRow);
        }
    }
};
