using System;
using System.Collections.Generic;
namespace Trees
{
    public class BinaryTree<T> where T : IComparable<T>
    {
        private BinaryTree<T> parent, left, right;
        private T val;
        private List<T> listForPrint = new List<T>();

        public BinaryTree(T val, BinaryTree<T> parent)
        {
            this.val = val;
            this.parent = parent;
        }

        public void add(T val)
        {
            if (val.CompareTo(this.val) < 0)
            {
                if (this.left == null)
                {
                    this.left = new BinaryTree<T>(val, this);
                }
                else if (this.left != null)
                    this.left.add(val);
            }
            else
            {
                if (this.right == null)
                {
                    this.right = new BinaryTree<T>(val, this);
                }
                else if (this.right != null)
                    this.right.add(val);
            }
        }

        private BinaryTree<T> _search(BinaryTree<T> tree, T val)
        {
            if (tree == null) return null;
            switch (val.CompareTo(tree.val))
            {
                case 1: return _search(tree.right, val);
                case -1: return _search(tree.left, val);
                case 0: return tree;
                default: return null;
            }
        }

        public BinaryTree<T> search(T val)
        {
            return _search(this, val);
        }

        public bool remove(T val)
        {
            //���������, ���������� �� ������ ����
            BinaryTree<T> tree = search(val);
            if (tree == null)
            {
                //���� ���� �� ����������, ������ false
                return false;
            }
            BinaryTree<T> curTree;

            //���� ������� ������
            if (tree == this)
            {
                if (tree.right != null)
                {
                    curTree = tree.right;
                }
                else curTree = tree.left;

                while (curTree.left != null)
                {
                    curTree = curTree.left;
                }
                T temp = curTree.val;
                this.remove(temp);
                tree.val = temp;

                return true;
            }

            //�������� �������
            if (tree.left == null && tree.right == null && tree.parent != null)
            {
                if (tree == tree.parent.left)
                    tree.parent.left = null;
                else
                {
                    tree.parent.right = null;
                }
                return true;
            }

            //�������� ����, �������� ����� ���������, �� �� ������� ������� ���������
            if (tree.left != null && tree.right == null)
            {
                //������ ��������
                tree.left.parent = tree.parent;
                if (tree == tree.parent.left)
                {
                    tree.parent.left = tree.left;
                }
                else if (tree == tree.parent.right)
                {
                    tree.parent.right = tree.left;
                }
                return true;
            }

            //�������� ����, �������� ������ ���������, �� �� ������� ������ ���������
            if (tree.left == null && tree.right != null)
            {
                //������ ��������
                tree.right.parent = tree.parent;
                if (tree == tree.parent.left)
                {
                    tree.parent.left = tree.right;
                }
                else if (tree == tree.parent.right)
                {
                    tree.parent.right = tree.right;
                }
                return true;
            }

            //������� ����, ������� ���������� � ����� ������
            if (tree.right != null && tree.left != null)
            {
                curTree = tree.right;

                while (curTree.left != null)
                {
                    curTree = curTree.left;
                }

                //���� ����� ����� ������� �������� ������ ��������
                if (curTree.parent == tree)
                {
                    curTree.left = tree.left;
                    tree.left.parent = curTree;
                    curTree.parent = tree.parent;
                    if (tree == tree.parent.left)
                    {
                        tree.parent.left = curTree;
                    }
                    else if (tree == tree.parent.right)
                    {
                        tree.parent.right = curTree;
                    }
                    return true;
                }
                //���� ����� ����� ������� �� �������� ������ ��������
                else
                {
                    if (curTree.right != null)
                    {
                        curTree.right.parent = curTree.parent;
                    }
                    curTree.parent.left = curTree.right;
                    curTree.right = tree.right;
                    curTree.left = tree.left;
                    tree.left.parent = curTree;
                    tree.right.parent = curTree;
                    curTree.parent = tree.parent;
                    if (tree == tree.parent.left)
                    {
                        tree.parent.left = curTree;
                    }
                    else if (tree == tree.parent.right)
                    {
                        tree.parent.right = curTree;
                    }

                    return true;
                }
            }
            return false;
        }

        private void _print(BinaryTree<T> node)
        {
            if (node == null) return;
            _print(node.left);
            listForPrint.Add(node.val);
            Console.Write(node + " ");
            if (node.right != null)
                _print(node.right);
        }
        public void print()
        {
            listForPrint.Clear();
            _print(this);
            Console.WriteLine();
        }

        public override string ToString()
        {
            return val.ToString();
        }
    }
}