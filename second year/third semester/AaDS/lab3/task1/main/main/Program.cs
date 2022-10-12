using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace Trees
{
    class Program
    {
        public static void Main(string[] args)
        {
            Random rList = new Random(47);
            Random rTree = new Random(47);
            int maxVal = 10;
            int n = 10;

            List<int> list = new List<int>();
            list.Add(rList.Next(maxVal));
            BinaryTree<int> tree = new BinaryTree<int>(maxVal, null);
            int[] nabor = new int[12];


            for (int i = 0; i < n; i++)
            {
                int val = rList.Next(maxVal);
                if (!list.Contains(val))
                {
                    list.Add(val);
                    tree.add(val);
                }
            }


            tree.print();
            tree.remove(10);
            tree.print();
            Console.WriteLine("Data loaded.");
            Console.ReadKey();
        }
    }
}

