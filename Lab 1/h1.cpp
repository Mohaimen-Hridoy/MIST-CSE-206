#include <iostream>
#include <cstring>
using namespace std;

#define MAX_SIZE 100

// Bill class representing a customer's bill
class Bill {
public:
    char name[50];   // Customer's name
    int amount;    // Bill amount
    int timestamp; // Timestamp to handle tie-breaking

    // Default constructor
    Bill() {
        strcpy(this->name, "");
        this->amount = 0;
        this->timestamp = 0;
    }

    // Parameterized constructor
    Bill(char name[50], int amount = 0, int timestamp = 0) {
        strcpy(this->name, name);
        this->amount = amount;
        this->timestamp = timestamp;
    }
};

// Priority Queue class
class PriorityQueue {
private:
    Bill heap[MAX_SIZE]; // Array for the max-heap
    int size_;           // Current number of elements in the heap

    // Utility function to swap two bills
    void swap_(Bill& a, Bill& b) {
        Bill temp = a;
        a = b;
        b = temp;
    }

    // Heapify up to maintain max-heap property
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            // Compare by amount first, then by timestamp if amounts are equal
            if (heap[index].amount > heap[parent].amount ||
                (heap[index].amount == heap[parent].amount && heap[index].timestamp < heap[parent].timestamp)) {
                swap_(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Heapify down to maintain max-heap property
    void heapifyDown(int index) {
        while (index < size_) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size_ && (heap[left].amount > heap[largest].amount ||
                                 (heap[left].amount == heap[largest].amount && heap[left].timestamp < heap[largest].timestamp))) {
                largest = left;
            }

            if (right < size_ && (heap[right].amount > heap[largest].amount ||
                                  (heap[right].amount == heap[largest].amount && heap[right].timestamp < heap[largest].timestamp))) {
                largest = right;
            }

            if (largest != index) {
                swap_(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Constructor
    PriorityQueue() {
        size_ = 0;
    }

    // Add a bill to the priority queue
    void addBill(char name[50], int amount, int timestamp) {
        if (size_ >= MAX_SIZE) {
            cout << "Priority queue is full!" << endl;
            return;
        }

        heap[size_] = Bill(name, amount, timestamp);
        heapifyUp(size_);
        size_++;
    }

    // Process the highest-priority bill
    void processBill() {
        if (size_ == 0) {
            cout << "No bills to process!" << endl;
            return;
        }

        cout << "Processing bill for: " << heap[0].name << ", Amount: " << heap[0].amount << endl;
        heap[0] = heap[size_ - 1];
        size_--;
        heapifyDown(0);
    }

    // Peek the highest-priority bill
    void peekBill() {
        if (size_ == 0) {
            cout << "No bills in the queue!" << endl;
            return;
        }

        cout << "Highest priority bill is for: " << heap[0].name << ", Amount: " << heap[0].amount << endl;
    }
};

int main() {
    PriorityQueue pq;

    // Simulate timestamps
    int timestamp = 0;

    // Add bills
    pq.addBill("Alice", 200, timestamp++);
    pq.addBill("Bob", 100, timestamp++);
    pq.addBill("Charlie", 300, timestamp++);
    pq.addBill("Dave", 200, timestamp++);

    // Peek the highest-priority bill
    pq.peekBill();

    // Process bills
    pq.processBill();
    pq.processBill();
    pq.processBill();
    pq.processBill();

    // Try to process an empty queue
    pq.processBill();

    return 0;
}
