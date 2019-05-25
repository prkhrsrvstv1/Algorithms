#include<iostream.h>
#include<limits.h>

int A[] = {2,89,96,4,49,77,145,257,114,24,84,6,711,517,3,66,64,89};
int size = 18;

void print_array(int *);
void merge_sort(int *, int, int);
void merge(int *, int, int, int);

int main() {
    cout<<"before sorting\n";
    print_array(A);
    merge_sort(A);
    cout<<"\nafter sorting\n";
    print_array(A);
    return(0);
}

void print_array(int *A) {
    for(int i = 0; i < size; i++)
        cout<<A[i]<<' ';
    cout<<'\n';
}

void merge_sort(int * A, int start, int end) {
    if (start == end) {
        return();
    }
    int mid = (start+end)/2;
    merge_sort(A, start, mid);
    merge_sort(A, mid+1, end);
    merge(A, start, end, mid);
    return();
}

void merge(int *A, int start, int end, int mid) {
    int L[mid-start+1], R[end-mid];
    for(int i = start; i < mid; i++) {
        L[i-start] = A[i];
    }
    L[i] = INT_MAX;
    for(i = mid+1; i < end; i++) {
        R[i-mid-1] = A[i];
    }
    R[i] = INT_MAX;
    int leftHead, rightHead = 0;
    for(i = start; i < end; i++) {
        if(L[leftHead] < R[rightHead]) {
            A[i] = L[leftHead];
            leftHead++;
        }
        else {
            A[i] = R[rightHead];
            rightHead++;
        }
    }
    return();
}