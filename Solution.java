
import java.util.ArrayList;
import java.util.List;

public class Solution {

    private record Element(int value, int column) {}

    public int[][] multiply(int[][] firstGrid, int[][] secondGrid) {

        List<List<Element>> firstGrid_nonZeroValues = new ArrayList<>();
        List<List<Element>> secondGrid_nonZeroValues = new ArrayList<>();

        initializeList_nonZeroValues(firstGrid, firstGrid_nonZeroValues);
        initializeList_nonZeroValues(secondGrid, secondGrid_nonZeroValues);

        int[][] resultMultiplication = new int[firstGrid.length][secondGrid[0].length];
        final int rows = resultMultiplication.length;

        for (int row = 0; row < rows; row++) {

            List<Element> firstNonZero = firstGrid_nonZeroValues.get(row);
            for (Element first : firstNonZero) {

                List<Element> secondNonZero = secondGrid_nonZeroValues.get(first.column);
                for (Element second : secondNonZero) {
                    resultMultiplication[row][second.column] += first.value * second.value;
                }
            }
        }

        return resultMultiplication;
    }

    private void initializeList_nonZeroValues(int[][] grid, List<List<Element>> nonZeroValues) {
        final int rows = grid.length;
        final int columns = grid[0].length;

        for (int row = 0; row < rows; row++) {
            List<Element> currentRow = new ArrayList<>();
            for (int column = 0; column < columns; column++) {
                if (grid[row][column] != 0) {
                    currentRow.add(new Element(grid[row][column], column));
                }
            }
            nonZeroValues.add(currentRow);
        }
    }
}
