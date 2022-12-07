#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class DaryHeap
{
private:
    int d;
    int currentSize;
    int size;
    int* array;
public:

    DaryHeap(int capacity, int numKids)
    {
        currentSize = 0;
        d = numKids;
        size = capacity + 1;
        array = new int[capacity + 1];
        for (int i = 0; i < capacity + 1; i++)
            array[i] = -1;
    }

    DaryHeap(int* array, int numKids)
    {
        int i = 0;
        while (array[i] != -1)
            i++;
        currentSize = i;
        this->array = array;
        this->d = numKids;
        buildHeap();
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    bool isFull()
    {
        return currentSize == size;
    }

    void makeEmpty()
    {
        currentSize = 0;
    }

    int parent(int i)
    {
        return (i - 1) / d;
    }

    int kthChild(int i, int k)
    {
        return d * i + k;
    }

    void insert(int x)
    {
        if (isFull())
        {
            cout << "Array Out of Bounds" << endl;
            return;
        }
        int hole = currentSize;
        currentSize++;
        array[hole] = x;
        percolateUp(hole);
    }

    int findMin()
    {
        if (isEmpty())
        {
            cout << "Array Underflow" << endl;
            return 0;
        }
        return array[0];
    }

    int Delete(int hole)
    {
        if (isEmpty())
        {
            cout << "Array Underflow" << endl;
            return 0;
        }
        int keyItem = array[hole];
        array[hole] = array[currentSize - 1];
        currentSize--;
        percolateDown(hole);
        return keyItem;
    }

    void buildHeap()
    {
        for (int i = currentSize - 1; i >= 0; i--)
            percolateDown(i);
    }

    void percolateDown(int hole)
    {
        int child;
        int tmp = array[hole];
        for (; kthChild(hole, 1) < currentSize; hole = child)
        {
            child = smallestChild(hole);
            if (array[child] < tmp)
                array[hole] = array[child];
            else
                break;
        }
        array[hole] = tmp;
    }

    int smallestChild(int hole)
    {
        int bestChildYet = kthChild(hole, 1);
        int k = 2;
        int candidateChild = kthChild(hole, k);
        while ((k <= d) && (candidateChild < currentSize))
        {
            if (array[candidateChild] < array[bestChildYet])
                bestChildYet = candidateChild;
            k++;
            candidateChild = kthChild(hole, k);
        }
        return bestChildYet;
    }

    void percolateUp(int hole)
    {
        int tmp = array[hole];
        for (; hole > 0 && tmp < array[parent(hole)]; hole = parent(hole))
            array[hole] = array[parent(hole)];
        array[hole] = tmp;
    }

    void printHeap()
    {
        int d = 3;
        int h = 1;
        int index = 0;
        cout << "\nHeap = ";
        for (int i = 0; i < currentSize; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
        if (index == 0) cout << "\t\t\t   " << array[index] << endl;;
        index++;
        do {
            for (int i = 0; i < pow(d, h); i++)
            {

                if (h != 2) {
                    if (i % 3 != 0) {
                        cout << " ";
                    }
                    else cout << "\t";
                    cout << "     " << array[index] << "      ";
                    index++;
                    if (index + 1 > currentSize) break;
                }
                else {
                    if (i % 3 != 0) {
                        cout << " ";
                    }
                    else cout << "\t";
                    cout << array[index] << " ";
                    index++;
                    if (index + 1 > currentSize) break;
                }
            }
            h++;
            cout << endl;
        } while (index < currentSize);
    }
};

int main()
{
    cout << "Dary Heap Test\n\n";
    cout << "Enter size and D of D-ary Heap: ";
    int size, num, choice, val, amount;
    cin >> size >> num;
    DaryHeap th(size, num);
    char ch;
    bool flag = true;
    do
    {
        cout << "\nDary Heap Operations\n";
        cout << "1. Insert random" << endl;
        cout << "2. Insert " << endl;
        cout << "3. Delete" << endl;
        cout << "4. Print heap" << endl;
        cout << "5. Check full" << endl;
        cout << "6. Check empty" << endl;
        cout << "7. Clear" << endl;
        cout << "8. Terminate" << endl;

        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter amount of elements to be inserted: ";
            cin >> amount;
            for (int i = 0; i < amount; i++) {
                th.insert(rand() % 100 + 1);
            }
            break;
        case 2:
            cout << "Enter integer element to insert: ";
            cin >> val;
            th.insert(val);
            break;
        case 3:
            cout << "Enter delete position: ";
            cin >> val;
            th.Delete(val - 1);
            break;
        case 4:
            th.printHeap();
        case 5:
            if (th.isFull())
                cout << "The Heap is Full" << endl;
            else
                cout << "The Heap is not Full" << endl;
            break;
        case 6:
            if (th.isEmpty())
                cout << "The Heap is Empty" << endl;
            else
                cout << "The Heap is not Empty" << endl;
            break;
        case 7:
            th.makeEmpty();
            cout << "Heap Cleared\n";
            break;
        case 8:
            cout << "Terminate programm" << endl;
            flag = false;
            break;
        default:
            cout << "Wrong Entry \n ";
            break;
        }
    } while (flag);
    return 0;
}