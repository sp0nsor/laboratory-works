class DoubleIntegral
{
    private static void Main()
    {
        double a = 0, b = 1, c = 0, d = 1;
        int n = 1000, m = 1000;

        Task<double> task1 = Task.Run(() => CalculateDoubleIntegral(a, b, c, d, n, m, (x, y) => Math.Exp(x) * Math.Sin(y)));
        Task<double> task2 = Task.Run(() => CalculateDoubleIntegral(a, b, c, d, n, m, (x, y) => Math.Sin(x + 2 * y)));
        Task<double> task3 = Task.Run(() => CalculateDoubleIntegral(a, b, c, d, n, m, (x,y)=> Math.Cos(x*Math.Exp(y))));
        Task<double> task4 = Task.Run(() => CalculateDoubleIntegral(a, b, c, d, n, m, (x, y) => Math.Exp(Math.Cos(x * x + y))));
        Task<int> task5 = Task.Run(() => MultiplyMatrix(n));

        Task.WaitAll(task1, task2, task3, task4, task5);

        double result1 = task1.Result;
        double result2 = task2.Result;
        double result3 = task3.Result;
        double result4 = task4.Result;
        int result5 = task5.Result;
        

        Console.WriteLine($"Result 1: {result1}");
        Console.WriteLine($"Result 2: {result2}");
        Console.WriteLine($"Result 3: {result3}");
        Console.WriteLine($"Result 4: {result4}");
        Console.WriteLine($"Result 5: {result5}");
        
        Console.ReadLine();
    }

    private static double CalculateDoubleIntegral(double a, double b, double c, double d, int n, int m, Func<double, double, double> func)
    {
        double result = 0;

        double deltaX = (b - a) / n;
        double deltaY = (d - c) / m;

        Parallel.For(0, n, i =>
        {
            double x = a + i * deltaX;
            Parallel.For(0, m, j =>
            {
                double y = c + j * deltaY;
                result += func(x, y) * deltaX * deltaY;
            });
        });

        return result;
    }

    private static int MultiplyMatrix(int size)
    {
        int[][] matrixA = new int[size][];
        int[][] matrixB = new int[size][];
        int[][] result = new int[size][];
        int count = 0;

        Random random = new Random();
        matrixA = Enumerable.Range(0, size)
            .Select(i => Enumerable.Range(0, size)
                .Select(j => random.Next(1, size))
                .ToArray())
            .ToArray();
        
        matrixB = Enumerable.Range(0, size)
            .Select(i => Enumerable.Range(0, size)
                .Select(j => random.Next(1, size))
                .ToArray())
            .ToArray();
        
        Parallel.For(0, size, i =>
        {
            result[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                result[i][j] = matrixA[i][j] * matrixB[j][i];
                ++count;
            }
        });

        return count;
    }
} 