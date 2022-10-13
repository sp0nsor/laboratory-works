using System;
using System.Collections.Generic;

namespace BinaryTreeExample
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTree tree = new BinaryTree();

            tree.Inset(12);
            tree.Inset(21);
            tree.Inset(90);
            tree.Inset(7);
            tree.Inset(32);
            tree.Inset(48);
            tree.Inset(57);
            tree.Inset(87);
            tree.Inset(100);

            tree.IsBalanced();
        }
    }
}