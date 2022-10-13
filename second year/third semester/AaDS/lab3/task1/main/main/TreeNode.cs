using System;
using System.Data;

namespace DinaryTreeExample
{

    public class TreeNode
    {
        private int data;
        public int Data
        {
            get { return data; }
        }


        private TreeNode rightNode;
        public TreeNode RightNode
        {
            get { return rightNode; }
            set { rightNode = value; }

        }// правое подерево


        private TreeNode leftNode;
        public TreeNode LeftNode
        {   
            get { return leftNode; }
            set { leftNode = value; }
        }// левое поддерево


        private bool isDeleted;
        public bool IsDeleted
        {
            get { return isDeleted; }
        }


        public TreeNode(int value)
        {
            data = value;
        }


        public void Delete()
        {
            isDeleted = true;
        }


        public TreeNode Find(int value)
        {
            TreeNode currentNode = this;

            while (currentNode != null)
            {
                if (currentNode.data == value && isDeleted == false)
                {
                    return currentNode;
                }
                else if (value > currentNode.data)
                {
                    currentNode = currentNode.rightNode; ;
                }
                else
                {
                    currentNode = currentNode.leftNode;
                }
            }

            return null;
        }


        public void Insert(int value)
        {

            if (value >= data)
            {
                if (rightNode != null)
                {
                    rightNode = new TreeNode(value);
                }
                else
                {
                    rightNode.Insert(value);
                }
            }
            else
            {
                if (leftNode == null)
                {
                    leftNode = new TreeNode(value);
                }
                else
                {
                    leftNode.Insert(value);
                }
            }

        }


        public int Hight()
        {
            if (this.leftNode == null && this.rightNode == null)
            {
                return 1;
            }

            int left = 0;
            int right = 0;
            
            if (this.leftNode != null)
            {
                left = this.leftNode.Hight();
            }
            if (this.rightNode != null)
            {
                right = this.rightNode.Hight();
            }

            if (left > right)
            {
                return left + 1;
            }
            else
            {
                return right + 1;
            }
        }    


        public bool IsBalanced()
        {
            int LeftHeight = LeftNode != null ? LeftNode.Hight() : 0;
            int RightHeight = RightNode != null ? RightNode.Hight() : 0;

            int heightDifference = LeftHeight - RightHeight;

            if (Math.Abs(heightDifference) > 1)
            {
                Console.WriteLine("Tree is Balansed");
                return false;
            }
            else
            {
                Console.WriteLine("----Tree is Balansed");
                return ((LeftNode != null ? LeftNode.IsBalanced():true) && (RightNode != null ? RightNode.IsBalanced():true));
            }
        }


    }

}