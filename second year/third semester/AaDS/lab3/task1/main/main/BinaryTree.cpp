#include <iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include "BinaryTree.h"

using namespace std;

BST::BST() {
	root = nullptr;
}
BST::node* BST::GreatLeaf(int key, node* parent) {
	node* n = new node;
	n->key = key;
	n->left = nullptr;
	n->right = nullptr;
	n->parent = parent;

	return n;
}

int BST::AddLeaf(int key) {
	return AddLeaftPrivate(key, root);
}

int BST::AddLeaftPrivate(int key, node* Ptr ){
	int isCorrentItem = 0;
	if (root == nullptr) {
		root = GreatLeaf(key, nullptr);
		isCorrentItem = 1;
	}
	else if (key < Ptr->key) {
		if (Ptr->left != nullptr) {
			isCorrentItem = AddLeaftPrivate(key, Ptr->left);
		}
		else {
			Ptr->left = GreatLeaf(key, Ptr);
			isCorrentItem = 1;
		}
	}
	else if (key > Ptr->key) {
		if (Ptr->right != nullptr) {
			isCorrentItem = AddLeaftPrivate(key, Ptr->left);
		}
		else {
			Ptr->right = GreatLeaf(key, Ptr);
			isCorrentItem = 1;
		}
	}
	else {
		wcout << "\nthe elsement with this key " << key << "already exists in the tree\n";
	}

	return isCorrentItem;
}

void BST::PrintInOrder() {
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr) {
	if (root != nullptr) {
		if (Ptr->left != nullptr) {
			PrintInOrderPrivate(Ptr->left);
		}
		wcout << Ptr->key << " ";
		if (Ptr->right != nullptr) {
			PrintInOrderPrivate(Ptr->right);
		}
	}
	else {
		wcout << "tree is empty\n";
	}
}

BST::node* BST::ReturnNode(int key) {
	return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr) {
	if (Ptr != nullptr) {
		if (Ptr->key == key) {
			return Ptr;
		}
		else {
			if (key < Ptr->key) {
				return ReturnNodePrivate(key, Ptr->left);
			}
			else {
				return ReturnNodePrivate(key, Ptr->right);
			}
		}
	}
	else return NULL;
}

int BST::ReturnRootKey() {
	if (root != nullptr) {
		return root->key;
	}
	else return -1000;
}

void BST::PrintChildren(int key) {
	node* Ptr = ReturnNode(key);
	if (Ptr != nullptr) {
		wcout << "Parent Node = " << Ptr->key << "\n";
		if (Ptr->left == nullptr)wcout << "left child = nullptr.\n";
		else wcout << "left child = " << Ptr->left->key << "\n";
		if (Ptr->right == nullptr)wcout << "right child = nullptr.\n";
		else wcout << "right child = " << Ptr->right->key << "\n";
	}
	else wcout << "this key " << key << "was not found in the tree.\n";
}

int BST::findSmallestOrHighest(int removeType) {
	if (removeType == 1) {
		return findSmallestPrivate(root);
	}
	else 
		return findHighestPrivate(root);

}

int BST::findSmallestPrivate(node* Ptr) {
	if (root == nullptr) {
		wcout << "the tree is empty.\n";
		return -1000;
	}
	if (Ptr->left != nullptr) {
		return findSmallestPrivate(Ptr->left);
	}
	else {
		return Ptr->key;
	}
}

int BST::findHighestPrivate(node* Ptr) {
	if (root == nullptr) {
		wcout << "the tree is empty.\n";
		return -1000;
	}
	if (Ptr->right != nullptr) {
		return findHighestPrivate(Ptr->right);
	}
	else {
		return Ptr->key;
	}
}
int BST:: RemoveNode(int key, int removeType) {
	return RemoveNodePrivate(key, root, removeType);
}

int BST::RemoveNodePrivate(int key, node* parent, int removeType) {
	if (root != nullptr) {
		if (root->key == key) {
			RemoveRootMatch(removeType);
			return 1;
		}
		else {
			if (key < parent->key && parent->left != nullptr) {
				if (parent->left->key == key) {
					RemoveMatch(parent, parent->left, true, removeType);
				}
				else {
					RemoveNodePrivate(key, parent->left, removeType);
				}
				return 1;
			}
			else if (key > parent->key && parent->right != nullptr) {
				if (parent->right->key == key) {
					RemoveMatch(parent, parent->left, false, removeType);
				}
				else {
					RemoveNodePrivate(key, parent->left, removeType);
				}
				return 1;
			}
			else {
				wcout << "the key " << key << " was not found int the tree.\n";
				return 0;
			}
		}
	}
	else
		wcout << "the tree is empty.\n";
}

void BST::RemoveMatch(node* parent, node* match, bool left, int removeType) {
	if (root != nullptr) {
		node* delPtr;
		int matchKey = match->key;
		int smallestInRightSubTree, highestInLeftSubTree;

		if (match->left == nullptr && match->right == nullptr) {
			delPtr = match;
			if (left == true) parent->left = nullptr;
			else parent->right = nullptr;
			delete delPtr;
			wcout << "The node containing key " << matchKey << " was remove.\n";
		}

		else if (match->left == nullptr && match->right != nullptr) {
			if (left == true) parent->left = match->right;
			else parent->right = match->right;
			match->right = nullptr;
			delPtr = match;
			delete delPtr;
			wcout << "The node containing key " << matchKey << " was remove.\n";
		}

		else if (match->right == nullptr && match->left != nullptr) {
			if (left == true) parent->left = match->left;
			else parent->right = match->left;
			match->left = nullptr;
			delPtr = match;
			delete delPtr;
			wcout << "The node containing key " << matchKey << " was remove.\n";
		}

		else {
			if (removeType == 1) {
				highestInLeftSubTree = findHighestPrivate(match->left);
				RemoveNodePrivate(highestInLeftSubTree, match, 1);
				match->key = highestInLeftSubTree;
			}
			else {
				smallestInRightSubTree = findSmallestPrivate(match->right);
				RemoveNodePrivate(smallestInRightSubTree, match, 2);
				match->key = smallestInRightSubTree;
			}

		}
	}
	else wcout << "Can't remove match. The Tree is empty.\n";
}

void BST:: RemoveRootMatch(int removeType) {
	if (root != nullptr) {
		node* delPtr = root;
		int rootKey = root->key;
		int smallestInRightSubTree, highestInLeftSubTree;

		if (root->left == nullptr && root->right == nullptr) {
			root = nullptr;
			delete delPtr;
		}
		else if (root->left == nullptr && root->right != nullptr) {
			root = root->right;
			delPtr->right = nullptr;
			delete delPtr;
			wcout << "the  root node with key " << rootKey << " was deleted. " <<
				"the new root contains key " << root->key << ".\n";
		}
		else if (root->right == nullptr && root->left != nullptr) {
			root = root->right;
			delPtr->left = nullptr;
			delete delPtr;
			wcout << "the  root node with key " << rootKey << " was deleted. " <<
				"the new root contains key " << root->key << ".\n";
		}
		else {
			if (removeType == 1) {
				highestInLeftSubTree = findHighestPrivate(root->left);
				RemoveNodePrivate(highestInLeftSubTree, root, 1);
				root->key = highestInLeftSubTree;
				wcout << "the root containing key " << rootKey <<
					" was overwritten with key " << root->key << ".\n";
			}
			else {
				smallestInRightSubTree = findSmallestPrivate(root->right);
				RemoveNodePrivate(smallestInRightSubTree, root, 2);
				root->key = smallestInRightSubTree;
				wcout << "the root containing key " << rootKey <<
					" was overwritten with key " << root->key << ".\n";
			}
		}
	}
	else wcout << "can`t romove root. the tree is empty.\n";
}

int l(0); int r(0);
void BST::FindItem(int key) {
	int depth = FindItemPrivate(root, key, 0);
	if (depth >= 0) {
		wcout << "depth of search item: " << depth;
		int height = heightOfNode(key);
		wcout << "\nheight of rearch item: " << height;
		wcout << "\nleve of search item: " << height - depth;
	}
	else wcout << "The key " << key << " was not found in the tree.\n";
	
}
int BST::FindItemPrivate(node* Ptr, int key, int depth) {
	if (root != nullptr) {
		if (Ptr->key == key) {
			return key;
		}
		else {
			if (key < Ptr->key) {
				if (Ptr->left != nullptr) {
					FindItemPrivate(Ptr->left, key, depth + 1);
				}
				else {
					return -1000;
				}
			}
			else {
				if (Ptr->right != nullptr) {
					FindItemPrivate(Ptr->right, key, depth + 1);
				}
				else {
					return -1000;
				}
			}
		}
	}
	else {
		wcout << "the tree is empty.\n";
		return -1000;
	}
}

int BST::heightOfNode(int key) {
	l = 0, r = 0;
	return heightOfNodePrivate(key, 0);
}

int BST::heightOfNodePrivate(int key, int height) {
	node* Ptr = ReturnNode(key);

	if (Ptr != nullptr) {
		if (Ptr->left != nullptr) {
			l = height + 1;
			heightOfNodePrivate(Ptr->left->key, height + 1);
		}
		if (Ptr->right != nullptr) {
			r = height + 1;
			heightOfNodePrivate(Ptr->right->key, height + 1);
		}
		return max(l, r);
	}
	else {
		return -1000;
	}
}

BST::~BST() {
	RemoveSubTree(root);
}

void BST::RemoveSubTree(node* Ptr) {
	if (Ptr == nullptr) {
		return;
	}
	RemoveSubTree(Ptr->left);
	RemoveSubTree(Ptr->right);
	delete Ptr;
}

int totalNumber, counter = 0;
void BST::FindMiddleNode(int totalNumberOfLeaf) {
	totalNumber = totalNumberOfLeaf;
	FindMiddleNodePrivate(root);
}

void BST::FindMiddleNodePrivate(node* Ptr) {
	if (root != nullptr) {
		if (counter == totalNumber / 2 + 1) {
			wcout << Ptr->key << endl;
			RemoveNode(Ptr->key, 2);
		}
		else {
			if (Ptr->left != nullptr || Ptr->right != nullptr) {
				if (Ptr->left != nullptr) {
					FindMiddleNodePrivate(Ptr->left);
				}
				counter++;
				if (Ptr->right != nullptr) {
					FindMiddleNodePrivate(Ptr->right);
				}
			}
			else {
				counter++;
				if (counter == totalNumber / 2 + 1) {
					wcout << Ptr->key << endl;
					RemoveNode(Ptr->key, 1);
				}
			}
		}
	}
	else {
		wcout << "tree is empty.\n";
	}
}

void BST::FindCountOfChildren() {
	if (root != nullptr)
		FindCountOfChildrenPrivate(root);
	else
		wcout << "The Tree is empty.\n";
}
int BST::FindCountOfChildrenPrivate(node* Ptr) {
	int leftChildren = 0, rightChildren = 0;
	if (Ptr->left != nullptr)
		leftChildren = FindCountOfChildrenPrivate(Ptr->left) + 1;
	if (Ptr->right != nullptr)
		rightChildren = FindCountOfChildrenPrivate(Ptr->right) + 1;
	if (leftChildren > rightChildren) {
		wcout << "Node " << Ptr->key << "\nl=" << leftChildren << "\nr=" << rightChildren << "\n";
		RemoveNode(Ptr->key, 2);
	}

	return leftChildren + rightChildren;
}