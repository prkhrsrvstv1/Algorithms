#include <bits/stdc++.h>
using namespace std;

int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
int size = 8;

void print_array(int *, int);
int partition(int *, int, int);
int rand_partition(int *, int, int);
void quicksort(int *, int, int);

int main() {
    cout << "Before sorting:\n";
    print_array(::A, ::size);
    quicksort(::A, 0, ::size-1);
    cout << "After sorting with Quicksort:\n";
    print_array(::A, ::size);
    return(0);
}

void print_array(int *A, int size) {
    for(int i = 0; i < size; ++i)
        cout<<A[i]<<' ';
    cout<<'\n';
}

int partition(int *A, int p, int r) {
    int x = A[r], i = p-1;
    for(int j = p; j < r; ++j)
        if(A[j] <= x) {
            ++i;
            swap(A[i], A[j]);
        }
    swap(A[i+1], A[r]);
    return(i+1);
}

int rand_partition(int *A, int p, int r) {
    swap(A[r], A[p + (int)((double)(rand()) / RAND_MAX * (r-p+1))]);
    return(partition(A, p, r));
}

void quicksort(int *A, int p, int r) {
    if(p < r) {
        int q = rand_partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}
