#include<iostream.h>

int A[] = {2,89,96,4,49,77,145,257,114,24,84,6,711,517,3,66,64,89};
int size = 18;

void print_array(int *);
void bubble_sort(int *);

int main() {
    cout<<"before sorting\n";
    print_array(A);
    bubble_sort(A);
    cout<<"\nafter sorting\n";
    print_array(A);
    return(0);
}

void print_array(int *A) {
    for(int i = 0; i < size; i++)
        cout<<A[i]<<' ';
    cout<<'\n';
}

void bubble_sort(int * A) {
    if (size == 1) {
        return();
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j <= i; j++) {
            if (A[j] > A[j+1]) {
                A[j] = A[j]+A[j+1]
                A[j+1] = A[j]-A[j+1]
                A[j] = A[j]-A[j+1];
            }
        }
    }
    return();
}