#include <bits/stdc++.h>

using namespace std;

inline int parent(int i);
inline int left(int i);
inline int right(int i);
void print_array(int *, int);
void max_heapify(int *, int, int);
void build_max_heap(int *, int);
void max_heapsort(int *, int);
void min_heapify(int *, int, int);
void build_min_heap(int *, int);
void min_heapsort(int *, int);


int B[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
int size = 16;

int main() {
    cout << "Before sorting:\n";
    print_array(::B, ::size);
    max_heapsort(::B, ::size);
    cout << "After max_heapsort:\n";
    print_array(::B, ::size);
    min_heapsort(::B, ::size);
    cout << "After min_heapsort:\n";
    print_array(::B, ::size);
    return(0);
}

inline int parent(int i) {
    return(i / 2);
}

inline int left(int i) {
    return(2 * i);
}

inline int right(int i) {
    return(2 * i + 1);
}

void print_array(int *A, int size) {
    for(int i = 0; i < size; i++)
        cout<<A[i]<<' ';
    cout<<'\n';
}

void max_heapify(int *A, int size, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l < size && A[l] > A[i]) largest = l;
    if(r < size && A[r] > A[largest]) largest = r;
    if(largest != i) {
        swap(A[i], A[largest]);
        max_heapify(A, size, largest);
    }
}

void build_max_heap(int *A, int size) {
    for(int i = size / 2; i >= 0; --i)
        max_heapify(A, size, i);
}

void max_heapsort(int *A, int size) {
    build_max_heap(A, size);
    for(int i = size-1; i >= 0; --i) {
        swap(A[0], A[i]);
        max_heapify(A, i, 0);
    }
}

void min_heapify(int *A, int size, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < size && A[l] < A[i]) smallest = l;
    if(r < size && A[r] < A[smallest]) smallest = r;
    if(smallest != i) {
        swap(A[i], A[smallest]);
        min_heapify(A, size, smallest);
    }
}

void build_min_heap(int *A, int size) {
    for(int i = size / 2; i >= 0; --i)
        min_heapify(A, size, i);
}

void min_heapsort(int *A, int size) {
    build_min_heap(A, size);
    for(int i = size-1; i >= 0; --i) {
        swap(A[0], A[i]);
        min_heapify(A, i, 0);
    }
}
