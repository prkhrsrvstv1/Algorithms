#include<iostream>

using namespace std;

int A[] = {2,89,96,4,49,77,145,257,114,24,84,6,711,517,3,66,64,89};
int size = 18;

void print_array(int *);
void selection_sort(int *);

int main() {
    cout<<"before sorting\n";
    print_array(A);
    selection_sort(A);
    cout<<"\nafter sorting\n";
    print_array(A);
    return(0);
}

void print_array(int *A) {
    for(int i = 0; i < size; i++)
        cout<<A[i]<<' ';
    cout<<'\n';
}

void selection_sort(int * A) {
    if (size == 1) {
        return;
    }
    int min;
    for(int i = 0; i < size-1; i++) {
        min = i;
        int j;
        for(j = i; j < size; j++) {
            if(A[j] < A[min]) {
                min = j;
            }
        }
        if(i != min) {
            A[i] += A[min];
            A[min] = A[i] - A[min];
            A[i] = A[i] - A[min];
        }
    }
    return;
}