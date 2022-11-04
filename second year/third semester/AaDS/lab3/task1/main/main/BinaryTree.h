#pragma once
class BST {
private:
	struct node {
		int key;
		node* left;
		node* right;
		node* parent;
	};
	node* root;
	int AddLeaftPrivate(int key, node* Ptr);
	int FindCountOfChildrenPrivate(node* Ptr);
	int findSmallestPrivate(node* Ptr);
	int RemoveNodePrivate(int key, node* Parent, int removeType);
	int findHighestPrivate(node* Ptr);
	int FindItemPrivate(node* Ptr, int key, int depth);
	int heightOfNodePrivate(int key, int height);

	void SpecialPrintPrivate(node* Ptr, int level, int side);
	void RemoveMatch(node* parent, node* match, bool left, int removeType);
	void RemoveRootMatch(int removeType);
	void FindMiddleNodePrivate(node* Ptr);
	void RemoveSubTree(node* Ptr);
	void PrintPreOderPrivate(node* Ptr);
	void PrintInOrderPrivate(node* Ptr);
	void PrintPostOrderPrivate(node* Ptr);

	node* GreatLeaf(int key, node* Parent);
	node* ReturnNode(int key);
	node* ReturnNodePrivate(int key, node*Ptr);

public:
	BST();
	~BST();

	int heightOfNode(int key);
	int ReturnRootKey();
	int AddLeaf(int key);
	int RemoveNode(int key, int removeType);
	int findSmallestOrHighest(int removeType);

	void SpecialPrint();
	void FindMiddleNode(int totalNumberOfLeaf);
	void FindItem(int key);
	void FindCountOfChildren();
	void PrintInOrder();
	void PrintPreOrder();
	void PrintPostOrder();
	void PrintChildren(int key);


};