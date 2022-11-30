#include <iostream>
#include <list>

using namespace std;

struct node {
	int value, degree;
	node* child, * sibling, * parent;
};

node* newNode(int number)
{
	auto* temp = new node;

	temp->value = number;
	temp->degree = 0;
	temp->child = temp->parent = temp->sibling = nullptr;
	return temp;
}

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

node* Merge(node* tree1, node* tree2)
{
	if (tree1->value > tree2->value)
		swap(tree1->value, tree2->value);
	tree2->parent = tree1;
	tree2->sibling = tree1->child;
	tree1->child = tree2;
	tree1->degree++;
	return tree1;
}

list<node*> Union(list<node*> heap1, list<node*> heap2) {
	list<node*> newHeap;
	auto i = heap1.begin();
	auto j = heap2.begin();
	while (i != heap1.end() && j != heap2.end()) {
		if ((*i)->degree <= (*j)->degree) {
			newHeap.push_back(*i);
			i++;
		}
		else {
			newHeap.push_back(*j);
			j++;
		}
	}
	while (i != heap1.end()) {
		newHeap.push_back(*i);
		i++;
	}
	while (j != heap2.end()) {
		newHeap.push_back(*j);
		j++;
	}
	return newHeap;
}

list<node*> Order(list<node*> MyHeap) {
	if (MyHeap.size() <= 1)
		return MyHeap;
	list<node*> newHeap;
	list<node*>::iterator i, j, k;
	i = j = k = MyHeap.begin();
	if (MyHeap.size() == 2) {
		j = i;
		j++;
		k = MyHeap.end();
	}
	else {
		j++;
		k = j;
		k++;
	}
	while (i != MyHeap.end()) {
		if (j == MyHeap.end())
			i++;
		else if ((*i)->degree < (*j)->degree) {
			i++;
			j++;
			if (k != MyHeap.end())
				k++;
		}
		else if (k != MyHeap.end() && (*i)->degree == (*j)->degree && (*i)->degree == (*k)->degree) {
			i++;
			j++;
			k++;
		}
		else if ((*i)->degree == (*j)->degree) {
			node* temp;
			*i = Merge(*i, *j);
			j = MyHeap.erase(j);
			if (k != MyHeap.end())
				k++;
		}
	}
	return MyHeap;
}

list<node*> InsertTree(list<node*> _heap, node* tree) {
	list<node*> temp;
	temp.push_back(tree);
	temp = Union(_heap, temp);
	return Order(temp);
}

list<node*> DeleteMin(node* tree) {
	list<node*> heap;
	auto* temp = tree->child;
	node* minimum;
	while (temp) {
		minimum = temp;
		temp = temp->sibling;
		minimum->sibling = nullptr;
		heap.push_front(minimum);
	}
	return heap;
}

list<node*> Insertion(list<node*> _head, int key) {
	auto* temp = newNode(key);
	return InsertTree(_head, temp);
}

node* getMin(list<node*> _heap) {
	auto i = _heap.begin();
	auto* temp = *i;
	while (i != _heap.end()) {
		if ((*i)->value < temp->value)
			temp = *i;
		i++;
	}
	return temp;
}

list<node*> extractMin(list<node*> _heap) {
	list<node*> newHeap, lo;
	node* temp;
	temp = getMin(_heap);
	list<node*>::iterator it;
	it = _heap.begin();
	while (it != _heap.end()) {
		if (*it != temp) {
			newHeap.push_back(*it);
		}
		it++;
	}
	lo = DeleteMin(temp);
	newHeap = Union(newHeap, lo);
	newHeap = Order(newHeap);
	return newHeap;
}

void ShowTree(node* root) {
	while (root) {
		cout << root->value << " ";
		ShowTree(root->child);
		root = root->sibling;
	}
}


void ShowHeap(list<node*> heap) {
	list<node*> ::iterator i;
	i = heap.begin();
	while (i != heap.end()) {
		ShowTree(*i);
		i++;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int number;
	list<node*> MyHeap;

	MyHeap = Insertion(MyHeap, 10);
	MyHeap = Insertion(MyHeap, 5);
	MyHeap = Insertion(MyHeap, 15);
	MyHeap = Insertion(MyHeap, 7);

	cout << "Куча после вставки: ";
	ShowHeap(MyHeap);
	cout << endl;
	cout << "Минимальный элемент: " << getMin(MyHeap)->value << endl;

	MyHeap = extractMin(MyHeap);
	cout << "Куча после удаления минимального елемента: ";
	ShowHeap(MyHeap);
	cout << endl;

	return 0;
}