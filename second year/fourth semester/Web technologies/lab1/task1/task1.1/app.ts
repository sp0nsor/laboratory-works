function countBlackRectangles(matrix: number[][]): number {
  let count: number = 0;

  // Перебираем все клетки поля
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[0].length; j++) {
      // Если текущая клетка черная
      if (matrix[i][j] === 1) {
        // Идем вправо, пока клетки черные
        let width: number = 0;
        while (j + width < matrix[0].length && matrix[i][j + width] === 1) {
          width++;
        }

        // Идем вниз, пока клетки черные
        let height: number = 0;
        while (i + height < matrix.length && matrix[i + height][j] === 1) {
          height++;
        }

        // Увеличиваем счетчик прямоугольников
        count += width * height;
        
        // Закрашиваем все клетки прямоугольника белым, чтобы не учитывать их в дальнейшем
        for (let k = i; k < i + height; k++) {
          for (let l = j; l < j + width; l++) {
            matrix[k][l] = 0;
          }
        }
      }
    }
  }

  return count;
}

const matrix: number[][] = [
  [1, 0, 1, 0],
  [0, 1, 1, 1],
  [0, 1, 0, 1]
];

const blackRectanglesCount: number = countBlackRectangles(matrix);
console.log(blackRectanglesCount); // Выводим количество черных прямоугольников в консоль