
/**
 * @param {number[][]} firstGrid    
 * @param {number[][]} secondGrid   
 * @return {number[][]}
 */
var multiply = function (firstGrid, secondGrid) {
    const firstGrid_nonZeroValues = [];
    const secondGrid_nonZeroValues = [];

    initializeList_nonZeroValues(firstGrid, firstGrid_nonZeroValues);
    initializeList_nonZeroValues(secondGrid, secondGrid_nonZeroValues);

    const resultMultiplication = Array.from(new Array(firstGrid.length), () => new Array(secondGrid[0].length).fill(0));
    const rows = resultMultiplication.length;

    for (let row = 0; row < rows; row++) {

        const firstNonZero = firstGrid_nonZeroValues[row];
        for (let first of firstNonZero) {

            const secondNonZero = secondGrid_nonZeroValues[first.column];
            for (let second of secondNonZero) {
                resultMultiplication[row][second.column] += first.value * second.value;
            }
        }
    }
    return resultMultiplication;
};

/**
 * @param {number} value    
 * @param {number} column   
 */
function Element(value, column) {
    this.value = value;
    this.column = column;
}

/**
 * @param {number[][]} grid    
 * @param {number[][]} nonZeroValues   
 * @return {void}
 */
function initializeList_nonZeroValues(grid, nonZeroValues) {
    const rows = grid.length;
    const columns = grid[0].length;

    for (let row = 0; row < rows; row++) {
        const currentRow = [];
        for (let column = 0; column < columns; column++) {
            if (grid[row][column] !== 0) {
                currentRow.push(new Element(grid[row][column], column));
            }
        }
        nonZeroValues.push(currentRow);
    }
}
