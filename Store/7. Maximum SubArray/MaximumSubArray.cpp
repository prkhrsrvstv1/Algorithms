#include <bits/stdc++.h>

using namespace std;

typedef struct {int low, high, sum;} triple;

int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
int size = 16;
void print_array(int *, pair<int, int>);
triple maximum_subarray(int *, int, int);
triple maximum_crossing_subarray(int *, int, int, int);

int main() {
    
    cout << "The maximum subarraay in :\n";
    print_array(A, make_pair(0, ::size-1));
    triple temp = maximum_subarray(A, 0, ::size-1);
    cout << "is from " << temp.low << " and " << temp.high <<", the sum is " << temp.sum << "\n";
    cout << "And the maximum subarray is:\n";
    print_array(A, make_pair(temp.low, temp.high));

}

void print_array(int *A, pair<int, int> lr) {
    for(int i = lr.first; i <= lr.second; i++)
        cout<<A[i]<<' ';
    cout<<'\n';
}

triple maximum_subarray(int *A, int low, int high) {

    if(low == high) {
        triple temp;
        temp.low = low; temp.high = high; temp.sum = temp.low;
        return(temp);
    }
    int mid = (low + high) / 2;
    triple triple_left = maximum_subarray(A, low, mid);
    triple triple_right = maximum_subarray(A, mid+1, high);
    triple triple_cross = maximum_crossing_subarray(A, low, mid, high);

    if(triple_left.sum > triple_right.sum && triple_left.sum > triple_cross.sum)
        return(triple_left);
    else if(triple_right.sum > triple_left.sum && triple_right.sum > triple_cross.sum)
        return(triple_right);
    else
        return(triple_cross);
}

triple maximum_crossing_subarray(int *A, int low, int mid, int high) {
    int temp_sum = 0;
    int left_sum = std::numeric_limits<int>::min();
    int left_index;
    for(int i = mid; i >= low ; i--) {
        temp_sum += A[i];
        if(temp_sum > left_sum) {
            left_sum = temp_sum;
            left_index = i;
        }
    }
    temp_sum = 0;
    int right_sum = std::numeric_limits<int>::lowest();
    int right_index;
    for(int i = mid+1; i <= high; i++) {
        temp_sum += A[i];
        if(temp_sum > right_sum) {
            right_sum = temp_sum;
            right_index = i;
        }
    }
    triple temp;
    temp.low = left_index; temp.high = right_index; temp.sum = left_sum + right_sum;
    return(temp);
}
