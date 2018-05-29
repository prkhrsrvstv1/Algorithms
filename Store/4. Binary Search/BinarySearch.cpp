#include<iostream.h>

int A[] = {2,89,96,4,49,77,145,257,114,24,84,6,711,517,3,66,64,89};
int size = 18;
int target = 4;

void print_array(int *);
void binary_search(int, int *, int, int);

void main() {
    cout<<"finding "<<target<<" in\n";
    print_array(A);
    int position = binary_search(target,A,0,size-1);
    if (position == -1)
        cout<<"\nElement not found.";
    else
        cout<<"\nElement found at index "<<position;
    return(0);
}

void print_array(int *A) {
    for(int i = 0; i < size; i++)
        cout<<A[i]<<' ';
    cout<<'\n';
}

void binary_search(int target, int *A, int start, int end) {
    int mid = (start+mid)/2;
    if (A[mid] == target)
        return(mid);
    else if(start == end)
        return(-1);
    else if (A[mid] > target)
        return(binary_search(target,A,start,mid));
    else
        return(binary_search(target,A,mid+1,end));
}