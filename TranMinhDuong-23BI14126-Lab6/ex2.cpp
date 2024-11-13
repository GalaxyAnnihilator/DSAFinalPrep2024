/*
A complex number is given in the form:
    z = a + bi
where a is the real part, b is the imaginary part
A size of a complex number is determined by its modulo:
    |z| = sqrt(a^2 + b^2)
Given an array of complex number
b) Sort this array using recursion

*/

#include <iostream>
#include <cmath>
using namespace std;

typedef struct{
    float real;
    float imaginary; 
} Complex;

void swap(Complex* x, Complex* y){
    Complex temp = *x;
    *x = *y;
    *y = temp;
}

void displayComplex(Complex c){
    float a = c.real, b = c.imaginary;
    cout<<a<<" + " <<b<<"i  ";
}

void displayComplexArray(Complex* arr, int n){
    for (int i = 0; i < n;i++){
        displayComplex(arr[i]);
    }
    cout <<endl;
}

float modulo(Complex c){
    float a,b,modulo;
    a = c.real;
    b = c.imaginary;
    modulo = sqrt(a*a+b*b);
    return modulo;
}

void insertValues(Complex* complexArray, int i, float a, float b){
    complexArray[i].real = a;
    complexArray[i].imaginary = b;
}

void bubbleSort(Complex* arr, int i, int n){
    if (i>=n){
        return;
    }
    for (int j = 0; j<n-1;j++){
        if (modulo(arr[j]) > modulo(arr[j+1])){
            swap(arr[j],arr[j+1]);
        }
    }

    bubbleSort(arr,i+1,n);
}

int main(){
    Complex* complexArray;
    int n = 8;
    complexArray = (Complex*)malloc(n*sizeof(Complex));
    
    insertValues(complexArray,0,1,2);
    insertValues(complexArray,1,3,4);
    insertValues(complexArray,2,6,8);
    insertValues(complexArray,3,5,2);
    insertValues(complexArray,4,11,20);
    insertValues(complexArray,5,9,1);
    insertValues(complexArray,6,10,0);
    insertValues(complexArray,7,2,2);

    displayComplexArray(complexArray,n);

    bubbleSort(complexArray,0,n);

    displayComplexArray(complexArray,n);
    
}
