#include<bits/stdc++.h>
#define MAX_HEAP_SIZE 100
using namespace std;

int B[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
int size = 16;

class Heap {

    protected:
        int *A;
        int heap_size;
    
    public:
        inline int parent(int i) {
            return(i / 2);
        }
        
        inline int left(int i) {
            return(2 * i);
        }

        inline int right(int i) {
            return(2 * i + 1);
        }

        void print_heap() {
            for(int i = 0; i < heap_size; i++)
                cout << A[i] << " ";
            cout << "\n";
        }

        virtual void heapify() {}

        virtual void build_heap() {}

};

class MaxHeap: public Heap {
    public:
        MaxHeap(int *arr, int size) {
            this->build_heap(arr, size);
            this->heap_size = size;
        }

        void heapify(int i) {
            int l = left(i);
            int r = right(i);
            int largest = i;
            if (l < heap_size && A[l] > A[i])
                largest = l;
            if(r < heap_size && A[r] > A[largest])
                largest = r;
            if(largest != i) {
                swap(A[largest], A[i]);
                heapify(largest);
            }
        }

        void build_heap(int *arr, int size) {
            if(size > MAX_HEAP_SIZE) {
                cout << "ERROR. Array too large.\n";
                return;
            }
            A = arr;
            heap_size = size;
            for(int i = heap_size / 2; i >= 0; --i)
                heapify(i);
        }

};

class MinHeap: public Heap {
    public:
        MinHeap(int *arr, int size) {
            this->build_heap(arr, size);
            this->heap_size = size;
        }

        void heapify(int i) {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if (l < heap_size && A[l] < A[i])
                smallest = l;
            if(r < heap_size && A[r] < A[smallest])
                smallest = r;
            if(smallest != i) {
                swap(A[smallest], A[i]);
                heapify(smallest);
            }
        }

        void build_heap(int *arr, int size) {
            if(size > MAX_HEAP_SIZE) {
                cout << "ERROR. Array too large.\n";
                return;
            }
            A = arr;
            heap_size = size;
            for(int i = heap_size / 2; i >= 0; --i)
                heapify(i);
        }
};

int main() {
    MinHeap* minheap = new MinHeap(::B, ::size);
    minheap->print_heap();
}