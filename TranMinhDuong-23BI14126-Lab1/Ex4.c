#include <stdio.h>
/*
Pseudo-code:
Input: n
Output: print out n is sphenic or not

function primeCheck(x):
    if x<=1:
        return 0
    if x<=3:
        return 1
    for i from 2 to x/2:
        if x mod i == 0:
            return 0

    return 1        

//Main program
Get n
primeFound = 0
for i from 2 to n-1:
    if (n mod i == 0 and primeCheck(i)==1) then:
        primeFound++

if primeFound == 3:
    print "n is sphenic"
else:
    print "n is NOT sphenic"    

*/

int primeCheck(int x){
    if (x<=1){
        return 0;
    }
    if (x<=3){
        return 1;
    }
    for (int i = 2;i<=x/2;i++){
        if (x%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int primeFound = 0;

    for (int i = 2;i<n;i++){
        if (n%i==0 && primeCheck(i)==1){
            primeFound++;
        }
    }

    if (primeFound == 3){
        printf("%d is sphenic\n",n);
    }
    else{
        printf("%d is NOT sphenic\n",n);
    }
}

/*
Time complexity analyse:
- The primeCheck(x) function contains a for loop that iterate i from 2 to x/2 ==> O(n)
- In the main program, we have another for loop of i from 2 to n-1. For each iteration,
we check if n is divisible by i ( O(1) ) and call primeCheck(i) ( O(n) ).
- Therefore, the time complexity of this program is O(n^2)
*/
