#include <stdio.h>

typedef struct{
    float real;
    float fake;
} Complex;

Complex add(Complex num1, Complex num2){
    Complex result;
    result.real = num1.real + num2.real;
    result.fake = num1.fake + num2.fake;
    return result;
}

Complex multiply(Complex num1, Complex num2){
    Complex result;
    float a,b,c,d;
    a = num1.real;
    b = num1.fake;
    c = num2.real;
    d = num2.fake;

    result.real = a*c-b*d;
    result.fake = a*d+b*c;
    return result;
}

void printComplex(Complex num){
    float a,b;
    a = num.real;
    b = num.fake;
    printf("%.2f + %.2fi",a,b);
}

int main(){
    Complex x,y;
    printf("Enter the real part for x: ");
    scanf("%f",&x.real);
    printf("Enter the imaginary part for x: ");
    scanf("%f",&x.fake);

    printf("Enter the real part for y: ");
    scanf("%f",&y.real);
    printf("Enter the imaginary part for y: ");
    scanf("%f",&y.fake);

    //Display x,y
    printf("x = ");
    printComplex(x);
    printf("\n");
    printf("y = ");
    printComplex(y);
    printf("\n");

    //Addition
    Complex addition;
    addition = add(x,y);
    printf("x + y = ");
    printComplex(addition);
    printf("\n");

    //Multiplication
    Complex multiplication;
    multiplication = multiply(x,y);
    printf("x * y = ");
    printComplex(multiplication);
    printf("\n");


    return 0;
}