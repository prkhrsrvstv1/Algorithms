#include<bits/stdc++.h>
#define MAX_HEAP_SIZE 100
using namespace std;

int B[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
int size = 16;

class Heap {

    private:
        int *A;
        int heap_size;
    
    public:
        Heap(int *arr, int size) {
            A = arr;
            heap_size = size;
        }

        void print_heap() {
            for(int i = 0; i < heap_size; i++)
                cout << A[i] << " ";
            cout << "\n";
        }

};

int main() {
    Heap* heap = new Heap(::B, ::size);
    heap->print_heap();
}