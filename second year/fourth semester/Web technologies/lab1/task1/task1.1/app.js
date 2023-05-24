function countBlackRectangles(matrix) {
    var count = 0;
    // Перебираем все клетки поля
    for (var i = 0; i < matrix.length; i++) {
        for (var j = 0; j < matrix[0].length; j++) {
            // Если текущая клетка черная
            if (matrix[i][j] === 1) {
                // Идем вправо, пока клетки черные
                var width = 0;
                while (j + width < matrix.length && matrix[i][j + width] === 1) {
                    width++;
                }
                // Идем вниз, пока клетки черные
                var height = 0;
                while (i + height < matrix.length && matrix[i + height][j] === 1) {
                    height++;
                }
                // Увеличиваем счетчик прямоугольников
                count += width * height;
                // Закрашиваем все клетки прямоугольника белым, чтобы не учитывать их в дальнейшем
                for (var k = i; k < i + height; k++) {
                    for (var l = j; l < j + width; l++) {
                        matrix[k][l] = 0;
                    }
                }
            }
        }
    }
    return count;
}
var matrix = [
    [1, 0, 1, 0, 1],
    [0, 0, 1, 0, 0],
    [1, 1, 0, 1, 1],
];
var blackRectanglesCount = countBlackRectangles(matrix);
console.log(blackRectanglesCount); // Выводим количество черных прямоугольников в консоль
