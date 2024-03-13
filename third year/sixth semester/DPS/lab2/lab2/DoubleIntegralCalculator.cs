using System;

namespace DPS.Lab2.DoubleIntegralCalculator;

class DoubleIntegralCalculator
{
    private static object _lockObject = new object();
    private static double _result = 0f;
    
    private static void Main()
    {
        Console.WriteLine($"Выберите функцию f(x, y): ");
        Console.WriteLine($"1. Math.Exp(x) * Math.Sin(y)");
        Console.WriteLine($"2. Math.Sin(x + 2 * y)");
        Console.WriteLine($"3. Math.Cos(x*Math.Exp(y))");
        Console.WriteLine($"4. Math.Exp(Math.Cos(x * x + y))");

        if (!int.TryParse(Console.ReadLine(), out int choice) | choice > 4) 
            Console.Error.WriteLine("ОШИБКА: некорректные данные.");

        Console.WriteLine($"Введите количество потоков K:");
        if (!int.TryParse(Console.ReadLine(), out int K) | K > 12) 
            Console.Error.WriteLine("ОШИБКА: некорректные данные.");

        Console.WriteLine($"Введите нижний предел а: ");
        if (!double.TryParse(Console.ReadLine(), out double a)) 
            Console.Error.WriteLine("ОШИБКА: некорректные данные.");

        Console.WriteLine($"Введите верхний предел b: ");
        if (!double.TryParse(Console.ReadLine(), out double b)) 
            Console.Error.WriteLine("ОШИБКА: некорректные данные.");

        Console.WriteLine($"Введите нижний предел с: ");
        if (!double.TryParse(Console.ReadLine(), out double c)) 
            Console.Error.WriteLine("ОШИБКА: некорректные данные.");

        Console.WriteLine($"Введите верхний предел d: ");
        if (!double.TryParse(Console.ReadLine(), out double d)) 
            Console.Error.WriteLine("ОШИБКА: некорректные данные.");
        
        Console.Write($"Введите количество частей для разбиения отрезка [a, b] (n): ");
        if (!int.TryParse(Console.ReadLine(), out int n)) 
            Console.Error.WriteLine("ОШИБКА: некорректные данные.");
        
        Console.Write($"Введите количество частей для разбиения отрезка [c, d] (m): ");
        if (!int.TryParse(Console.ReadLine(), out int m)) 
            Console.Error.WriteLine("ОШИБКА: некорректные данные.");

        Thread[] threads = new Thread[K];
        Func<double, double, double> func = null;

        switch (choice)
        {
            case 1:
                func = (x, y) => Math.Exp(x) * Math.Sin(y);
                break;
            case 2:
                func = (x, y) => Math.Sin(x + 2 * y);
                break;
            case 3:
                func = (x, y) => Math.Cos(x * Math.Exp(y));
                break;
            case 4:
                func = (x, y) => Math.Exp(Math.Cos(x * x + y));
                break;
            
        }

        for (int i = 0; i < K; i++)
        {
            threads[i] = new Thread(() => CalculateIntegralWithThreads(a, b, c, d, m, n, func, K, i));
            threads[i].Start();
        }

        foreach (var thread in threads)
            thread.Join();

        Console.WriteLine($"Результат {_result}");
        Console.ReadLine();
    }

    private static void CalculateIntegralWithThreads(double a, double b, double c, double d, int m, int n, Func<double, double, double> func, int K, int threadIndex)
    {
        double partialResult = 0f;

        for (int i = threadIndex; i < n; i += K)
        {
            double x = a + i * (b - a) / n;
            for (int j = 0; j < m; j++)
            {
                double y = c + j * (d - c) / m;
                partialResult += func(x, y) * (b - a) / n * (d - c) / m;
            }
        }
        lock (_lockObject)
        {
            _result += partialResult;
        }
    }
    
}

