#include <iostream>
using namespace std;

const unsigned SIZE = 31;
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int Data) {
		data = Data;
	}
};
struct BinomialQueue {
	Node* mas[SIZE];
	int size;

	Node* join(Node* f, Node* s) {
		if (f->data > s->data) {
			s->right = f->left;
			f->left = s;
			return f;
		}
		else {
			f->right = s->left;
			s->left = f;
			return s;
		} 
	}

	void add(int value) {
		Node* newNode = new Node(value);
		Node* curNode = newNode;

		for (unsigned i = 0; i < SIZE; ++i) {
			if (mas[i] == NULL) {
				mas[i] = curNode;
				break;
			}
			else {
				curNode = join(curNode, mas[i]);
				mas[i] = NULL;
			}
		}
		size++;
	}

	void joinBQ(Node* a[], Node* b[SIZE]) {
		Node* c = 0;
		for (unsigned i = 0; i < SIZE; ++i) {
			switch ((c != 0, b[i] != 0, a[i] != 0)) {
			case 2: a[i] = b[i]; break;
			case 3: c = join(a[i], b[i]); a[i] = 0; break;
			case 4: a[i] = c; c = 0; break;
			case 5: c = join(a[i], c); a[i] = 0; break;
			case 6:
			case 7: c = join(b[i], c); break;
			}
		}
	}

	void joinBQ(BinomialQueue& bq) {
		joinBQ(mas, bq.mas);
		size += bq.size;
	}
	int getMax() {
		int res = 0;
		int resPos = -1;
		for (int i = 0; i < SIZE; i++) {
			if (mas[i] && mas[i]->data > res) {
				res = mas[i]->data;
				resPos = i;
			}
		}
		Node** tmp = new Node * [SIZE];
		memset(tmp, 0, sizeof(tmp) * SIZE);
		Node* cur = mas[resPos]->left;
		for (int i = resPos - 1; i >= 0; i--) {
			tmp[i] = new Node(*cur);
			cur = cur->right;
			tmp[i]->right = 0;
		}
		delete mas[resPos];
		mas[resPos] = 0;

		joinBQ(mas, tmp);
		delete tmp;
		size--;
		return res;
	}
};

void main() {
	setlocale(LC_ALL, "ru");

}