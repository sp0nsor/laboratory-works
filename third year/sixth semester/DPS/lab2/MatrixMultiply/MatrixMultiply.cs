using System.Diagnostics;

namespace DPS.Lab2.MatrixMultiply;

class MatrixMultiply
{
    private static object _lockObject = new object();
    private static int[][] _matrixA;
    private static int[][] _matrixB;
    private static int[][] _result;
    private static Stopwatch s_stopWatch = new Stopwatch();
    
    private static void Main()
    {
        Console.WriteLine($"Введите размерность матрицы: ");
        if (!int.TryParse(Console.ReadLine(), out int size) | size <= 1) 
            Console.Error.WriteLine("ОШИБКА: некорректные данные.");

        Console.WriteLine($"Введите количество потоков: ");
        if (!int.TryParse(Console.ReadLine(), out int threadCount) | threadCount <= 0 | threadCount > 12)
            Console.Error.WriteLine("ОШИБКА: некорректные данные.");

        InitializeMatrices(size);
        
        Thread[] threads = new Thread[threadCount];
        for (int i = 0; i < threadCount; i++)
        {
            var i1 = i;
            threads[i] = new Thread(() => MultiplyMatrixPart(size, i1, threadCount));
            threads[i].Start();
        }
        s_stopWatch.Start();
        foreach (var thread in threads)
        {
            thread.Join();
        }
        s_stopWatch.Stop();
        
        PrintMatrixToFile(_result, "D:\\laboratory-works\\third year\\sixth semester\\DPS\\lab2\\MatrixMultiply\\result.txt");
        Console.WriteLine($"Время выполнения операции: {s_stopWatch.Elapsed}");
        Console.ReadLine();
    }

    private static void InitializeMatrices(int size)
    {
        Random random = new Random();

        _matrixA = new int[size][];
        _matrixB = new int[size][];
        _result = new int[size][];

        for (int i = 0; i < size; i++)
        {
            _matrixA[i] = new int [size];
            _matrixB[i] = new int [size];
            _result[i] = new int [size];

            for (int j = 0; j < size; j++)
            {
                _matrixA[i][j] = random.Next(100, 10000);
                _matrixB[i][j] = random.Next(100, 10000);
            }
        }
    }

    private static void MultiplyMatrixPart(int size, int threadIndex, int threadCount)
    {
        for (int i = threadIndex; i < size; i += threadCount)
        {
            for (int j = 0; j < size; j++)
            {
                int particleResult = MultiplyRowColumn(_matrixA, _matrixB, i, j, size);
                lock (_lockObject)
                {
                    _result[i][j] = particleResult;
                }
            }
        }
    }

    private static int MultiplyRowColumn(int[][] matrixA, int[][] matrixB, int row, int column, int length)
    {
        int result = 0;
        for (int k = 0; k < length; k++)
        {
            result += matrixA[row][k] * matrixB[k][column];
        }

        return result;
    }

    private static void PrintMatrixToFile(int[][] matrix, string filePath)
    {
        try
        {
            using (StreamWriter sw = new(filePath))
            {
                for (int i = 0; i < matrix.Length; i++)
                {
                    for (int j = 0; j < matrix[i].Length; j++)
                    {
                        sw.Write(matrix[i][j] + " ");
                    }
                    sw.WriteLine();
                }
                sw.Flush();
            }

            Console.WriteLine($"Результаты записаны в файл: {filePath}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка при записи в файл: {ex.Message}");
        }
    }
}

