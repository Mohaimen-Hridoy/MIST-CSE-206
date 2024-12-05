
#include<bits/stdc++.h>

using namespace std;

int counts=0;

struct Bill
{
    string name;
    int amount;
    int timestamp;
    Bill()
    {
        name="";
        amount=0;
        timestamp=0;
    }
    Bill(string n,int a,int t)
    {
        name=n;
        amount=a;
        timestamp=t;
    }
};

class PQ
{
    public:
    int heap_size;
    Bill bill[100];
    PQ()
    {
        heap_size = 0;
    }
    void heapInsert(Bill val)
    {
        heap_size++;
        bill[heap_size]=val;
        heapifyUp(heap_size);
    }
    void heapifyUp(int index)
    {
        if(index==1) return;
        if(bill[index].amount > bill[index/2].amount)
        {
            swap(bill[index],bill[index/2]);
            heapifyUp(index/2);
        }
    }
};

int main()
{
    PQ pq;
    while(1)
    {
        string s; cin >> s;
        if(s=="Q") break;
        int amount; cin >> amount;
        counts++;
        Bill bill=Bill(s,amount,counts);
        pq.heapInsert(bill);
    }

    for(int i=1;i<=pq.heap_size;i++)
    {
        cout << pq.bill[i].amount << " ";
    }

    return 0;
}
