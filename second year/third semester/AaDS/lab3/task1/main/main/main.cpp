#include <iostream>
#include <cstdlib>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include "BinaryTree.h"
using namespace std;

void menu() {
	wcout << "\n\tSelect an action:\n"
		<< "\t1)Add items\n"
		<< "\t2)Add random items\n"
		<< "\t3)Output tree\n"
		<< "\t4)Delete item\n"
		<< "\t5)Delete tree\n"
		<< "\t6)Find item\n"
		<< "\t7)Personal Task\n"
		<< "\t0)Exit the program\n";
}

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	BST NewTree;
	bool work = true;
	int action(0),
		numberOfLeaf(0),
		deleteLeaf(0),
		temp(0),
		totalNumberOfLeaf(0),
		removeType;
	while (work) {
		menu();
		cin >> action;

		switch (action) {
		case 1:
			wcout << "How many items to add?\n";
			cin >> numberOfLeaf;

			wcout << "Enter items:\n";
			for (int i = 0; i < numberOfLeaf; i++) {
				cin >> temp;
				totalNumberOfLeaf += NewTree.AddLeaf(temp);
			}

			wcout << "Items added successfully. Total:" << totalNumberOfLeaf << "\n";
			break;
		case 2:
			wcout << "How many items to add?\n";
			cin >> numberOfLeaf;

			for (int i = 0; i < numberOfLeaf; i++)
				totalNumberOfLeaf += NewTree.AddLeaf(rand() % 200 - 50);

			wcout << "Items added successfully. Total:" << totalNumberOfLeaf << "\n";
			break;
		case 3:
			if (NewTree.ReturnRootKey() == -1000)
				wcout << "The Tree is empty.\n";
			else {
				wcout << "Symmetrical order output:  ";
				NewTree.PrintInOrder();
				wcout << endl;
				wcout << "Pre order output:  ";
				NewTree.PrintPreOrder();
				wcout << endl;
				wcout << "Post order output:  ";
				//NewTree.PrintPostOrder();
				wcout << endl;
				wcout << "Tree output:\n";
				NewTree.SpecialPrint();
				wcout << endl;
			}
			break;
		case 4:
			wcout << "Which item do you want tu remove?\n";
			cin >> deleteLeaf;

			wcout << "Select type of deleting:\n"
				<< "1)Left\n"
				<< "2)Right\n";
			cin >> removeType;

			totalNumberOfLeaf -= NewTree.RemoveNode(deleteLeaf, removeType);
			break;
		case 5:
			wcout << "Select type of deleting:\n"
				<< "1)Left\n"
				<< "2)Right\n";
			cin >> removeType;

			totalNumberOfLeaf = 0;
			while (deleteLeaf != -1000) {
				NewTree.RemoveNode(deleteLeaf, removeType);
				deleteLeaf = NewTree.ReturnRootKey();
			}
			break;
		case 6:
			int h;
			wcout << "Which item do you want to find?\n";
			cin >> temp;

			NewTree.FindItem(temp);
			break;
		case 7:
			if (totalNumberOfLeaf % 2 == 0)
				wcout << "Middle node does not exist.";
			else if (totalNumberOfLeaf == 1) {
				wcout << "Middle node is root: " << NewTree.ReturnRootKey() << " was remove.";
				NewTree.RemoveNode(NewTree.ReturnRootKey(), 1);
			}
			else if (totalNumberOfLeaf % 2 == 1) {
				wcout << "Middle node: ";
				NewTree.FindMiddleNode(totalNumberOfLeaf);
			}
			break;
		case 0:
			wcout << "The program completed\n";
			work = false;
			break;
		}
	}
	return 0;
}