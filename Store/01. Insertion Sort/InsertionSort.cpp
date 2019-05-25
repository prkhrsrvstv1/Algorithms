#include<iostream>

using namespace std;

int A[] = {2,89,96,4,49,77,145,257,114,24,84,6,711,517,3,66,64,89};
int size = 18;

void print_array(int *);
void insertion_sort(int *);

int main() {
    cout<<"before sorting\n";
    print_array(A);
    insertion_sort(A);
    cout<<"\nafter sorting\n";
    print_array(A);
    return(0);
}

void print_array(int *A) {
    for(int i = 0; i < size; i++)
        cout<<A[i]<<' ';
    cout<<'\n';
}

void insertion_sort(int * A) {
    if (size == 1) {
        return;
    }
    int key;
    for(int j = 1; j < size; j++) {
        key = A[j];
        int i = j-1;
        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
    return;
}