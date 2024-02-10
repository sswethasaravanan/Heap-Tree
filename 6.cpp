#include <iostream>
#include <vector>
using namespace std;
class BHeap {
private:
    vector<int> heap;
    int left(int parent);
    int right(int parent);
    int parent(int child);
    void heapifyUp(int index);
    void heapifyDown(int index);
public:
    BHeap() {}
    void insert(int element);
    void deleteMin();
    int extractMin();
    void showHeap();
    int size();
};
int main() {
    BHeap h;
    cout << "1. Insert Element" << endl;
    cout << "2. Delete Minimum Element" << endl;
    cout << "3. Extract Minimum Element" << endl;
    cout << "4. Show Heap" << endl;
    cout << "5. Exit" << endl;
    while (1) {
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
int BHeap::size() {
    return heap.size();
}
void BHeap::insert(int ele) {
    heap.push_back(ele);
    heapifyUp(heap.size() - 1);
}
void BHeap::deleteMin() {
    if (heap.size() == 0) {
        cout << "Heap is Empty" << endl;
        return;
    }   
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    cout << "Element Deleted" << endl;
}
int BHeap::extractMin() {
    if (heap.size() == 0) {
        return -1;
    } else {
        return heap[0];
    }
}
void BHeap::showHeap() {
    vector<int>::iterator pos = heap.begin();
    cout << "Heap --> ";
    while (pos != heap.end()) {
        cout << *pos << " ";
        pos++;
    }
    cout << endl;
}
int BHeap::left(int parent) {
    int l = 2 * parent + 1;
    return (l < heap.size()) ? l : -1;
}
int BHeap::right(int parent) {
    int r = 2 * parent + 2;
    return (r < heap.size()) ? r : -1;
}
int BHeap::parent(int child) {
    return (child - 1) / 2;
}

void BHeap::heapifyUp(int in) {
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in]) {
        swap(heap[in], heap[parent(in)]);
        heapifyUp(parent(in));
    }
}
void BHeap::heapifyDown(int in) {
    int child = left(in);
    int child1 = right(in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]) {
        child = child1;
    }
    if (child > 0 && heap[in] > heap[child]) {
        swap(heap[in], heap[child]);
        heapifyDown(child);
    }
}
