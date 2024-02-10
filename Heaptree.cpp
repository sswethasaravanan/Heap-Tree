#include <iostream>
#include <vector>
using namespace std;

class BHeap {
private:
    vector<int> heap;
    int left(int parent) { return 2 * parent + 1 < heap.size() ? 2 * parent + 1 : -1; }
    int right(int parent) { return 2 * parent + 2 < heap.size() ? 2 * parent + 2 : -1; }
    int parent(int child) { return (child - 1) / 2; }
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    BHeap() {}
    void insert(int element);
    void deleteMin();
    int extractMin();
    void showHeap();
    int size() { return heap.size(); }
};

void BHeap::insert(int ele) {
    heap.push_back(ele);
    heapifyUp(heap.size() - 1);
}

void BHeap::deleteMin() {
    if (heap.empty()) {
        cout << "Heap is Empty" << endl;
        return;
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    cout << "Element Deleted" << endl;
}

int BHeap::extractMin() {
    return heap.empty() ? -1 : heap[0];
}

void BHeap::showHeap() {
    cout << "Heap --> ";{
        cout << BHeap << " ";
    }
    cout << endl;
}

void BHeap::heapifyUp(int in) {
    while (in > 0 && heap[parent(in)] > heap[in]) {
        swap(heap[in], heap[parent(in)]);
        in = parent(in);
    }
}

void BHeap::heapifyDown(int in) {
    int child = left(in);
    int child1 = right(in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]) {
        child = child1;
    }
    if (child >= 0 && heap[in] > heap[child]) {
        swap(heap[in], heap[child]);
        heapifyDown(child);
    }
}

int main() {
    BHeap h;
    cout << "1. Insert Element\n2. Delete Minimum Element\n3. Extract Minimum Element\n4. Show Heap\n5. Exit" << endl;
    while (true) {
        int choice, element;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> element;
                h.insert(element);
                break;
            case 2:
                h.deleteMin();
                break;
            case 3:
                if (h.extractMin() == -1) {
                    cout << "Heap is Empty" << endl;
                } else {
                    cout << "Minimum Element: " << h.extractMin() << endl;
                }
                break;
            case 4:
                cout << "Displaying elements of Heap: ";
                h.showHeap();
                break;
            case 5:
                exit(0);
            default:
                cout << "Enter Correct Choice" << endl;
        }
    }
    return 0;
}

