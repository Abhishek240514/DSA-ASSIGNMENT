#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> heap;

    void heapifyUp(int i){
        while(i > 0){
            int p = (i - 1) / 2;
            if(heap[p] < heap[i]){
                swap(heap[p], heap[i]);
                i = p;
            } else break;
        }
    }

    void heapifyDown(int i){
        int n = heap.size();
        while(true){
            int l = 2*i + 1;
            int r = 2*i + 2;
            int largest = i;

            if(l < n && heap[l] > heap[largest]) largest = l;
            if(r < n && heap[r] > heap[largest]) largest = r;

            if(largest != i){
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
    void push(int x){
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int top(){
        if(heap.empty()) return -1;
        return heap[0];
    }

    void pop(){
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int size(){
        return heap.size();
    }

    bool empty(){
        return heap.empty();
    }
};

int main(){
    MaxHeap pq;
    pq.push(10);
    pq.push(40);
    pq.push(30);
    pq.push(5);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    cout << pq.size() << endl;
}
