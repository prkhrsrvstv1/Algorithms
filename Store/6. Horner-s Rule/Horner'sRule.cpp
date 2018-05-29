#include<iostream.h>

float A[] = {2,89,96,4,49,77,145,257,114,24,84,6,711,517,3,66,64,89};
int deg = 17;
float x = 2.9932;
float polynomial(float *, float);

int main() {
    cout<<"f("<<x<<") = "<<polynomial(A, x)<<"\n";
    return(0);
}

float polynomial(float *A, float x) {
    float value = A[deg];
    for(int i = deg-1; i >= 0; i--) {
        value += A[i] + x*value;
    }
    return(value);
}