#include <stdio.h>
#include <string.h>

/*
Pseudocode:
Input: a positive integer
Output: that integer but with the first and last digit swapped

function power(x,a):
    result = 1
    for i from 0 to a-1:
        result = result * x

    return x    

function getDigits(n):
    result = 0
    while (n!=0) then
        result = result + 1
        n = n /10
    
    return result

Get n
length = getDigits(n)
first = n / power(10,length-1)
last = n % 10

n = n - first * power(10,length-1) + last * power(10,length-1) ==> This will replace the first digit
n = n - last + first ==> This will replace the last digit

Print n

*/

int power(int x,int a){
    int result = 1;
    for (int i = 0;i<a;i++){
        result *= x;
    }
    return result;

}

int getDigits(int n){
    int result = 0;
    while (n!=0){
        result = result+1;
        n/=10;
    }
    return result;
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    int length = getDigits(n);
    int first,last;

    first = n / power(10,length-1);
    last = n % 10;

    n = n - first * power(10,length-1) + last * power(10,length-1); //Replace first digit
    n = n - last + first; // replace last digit;
    
    printf("After swapping: %d\n",n);

    return 0;
}