
#include <bits/stdc++.h>
using namespace std;

int count = 0;

struct Bill {
    string name;
    int amount;
    int timestamp;

    Bill(string n, int a, int t) {
        name = n;
        amount = a;
        timestamp = t;
    }
};

class PQ {
public:
    int heap_size = 0;
    Bill bill[100];

    void heapinsert(Bill val) {
        heap_size++;
        bill[heap_size] = val;  // Insert the new bill at the last position
        heapifyUp(heap_size);  // Call heapifyUp to maintain the heap property
    }

    void heapifyUp(int index) {
        // If index is the root, stop.
        if (index == 1) {
            return;
        }

        // If the current bill's amount is greater than its parent's amount, swap them
        if (bill[index].amount > bill[index / 2].amount) {
            swap(bill[index], bill[index / 2]);
            heapifyUp(index / 2);  // Recurse for the parent
        }
    }
};

int main() {
    PQ pq;
    while (true) {
        string s;
        int amount;

        cin >> s;
        if (s == "exit") break; // Exit condition, break if user types "exit"

        cin >> amount;
        count++;
        Bill bill = Bill(s, amount, count);
        pq.heapinsert(bill);  // Insert the bill into the priority queue
    }

    // Print the bills in the priority queue
    for (int i = 1; i <= pq.heap_size; i++) {
        cout << pq.bill[i].amount << " ";  // Output the amounts of all bills in the heap
    }

    return 0;
}
