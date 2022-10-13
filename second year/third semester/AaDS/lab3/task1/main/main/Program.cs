using DinaryTreeExample;
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

        }

        public static int getHeight(TreeNode root)
        {
            if (root == null)
            {
                return 0;
            }

            return Math.Max(getHeight(root.LeftNode), getHeight(root.RightNode)) + 1;
        }

        public static bool isBalanced(TreeNode root)
        {
            if (root == null)
            {
                return true;
            }

            int heightDiff = getHeight(root.LeftNode) - getHeight(root.RightNode);
            if (Math.Abs(heightDiff) > 1)
            {
                return false;
            }
            else
            {
                return (isBalanced(root.LeftNode) && isBalanced(root.RightNode));
            }
        }

    }
}