#include<bits/stdc++.h>
using namespace std;

int A[] = {13, 3, 25, 20, 3, 16, 23, 18, 20, 7, 12, 5, 22, 15, 4, 7};
const int size = 16;
int B[::size];

void print_array(int *, int);
void countingsort(int *, int, int);

int main() {
    cout << "Before sorting:\n";
    print_array(::A, ::size);
    countingsort(::A, ::size, *max_element(::A, (::A)+::size));
    cout << "After sorting:\n";
    print_array(B, ::size);
    return(0);
}

void print_array(int *arr, int size) {
    for(int i = 0; i < size; ++i)
        cout<< arr[i] << " ";
    cout<<'\n';
}

void countingsort(int *A, int n, int k) {
    int C[k] = {0};
    for(int i = 0; i < n; ++i)
        C[A[i]] = C[A[i]] + 1;
    for(int i = 1; i < k; ++i)
        C[i] += C[i-1];
    for(int i = n-1; i >= 0; --i) {
        ::B[C[A[i]]] = A[i];
        --C[A[i]];
    }
}