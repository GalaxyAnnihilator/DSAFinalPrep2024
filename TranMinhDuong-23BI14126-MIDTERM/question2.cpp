#include <iostream>
using namespace std;

void recursivePythagorean(int* arr, int n, int i, int j, int k) {
    int a = arr[i], b = arr[j], c = arr[k];
    if (a*a + b*b == c*c || b*b+c*c==a*a ||a*a+c*c==b*b) {
        cout<< "(" << a << ", " << b << ", " << c <<") is Pythagorean triple" <<endl;
    }
    if (i >= n-2) {
        return; // Base-case
    }
    if (j >= n-1) {
        recursivePythagorean(arr,n,i + 1,i + 2,i + 3); //If j exceeds, we reset i,j,k := i+1,i+2,i+3
        return;
    }
    if (k >= n) {
        recursivePythagorean(arr,n,i,j + 1,j + 2); //If k exceeds, we reset i,j,k := i,j+1,j+2
        return;
    }

    recursivePythagorean(arr,n,i,j,k + 1); //next value of k
}

int main(){
    int arr[] = {2,3,6,4,9,5,8,6,10,13,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    recursivePythagorean(arr,n,0,1,2); //Begin search at i,j,k = 0,1,2

    return 0;
}

/*
Time complexity analysis:
+ This algorithm starts the first recursive call at i,j,k = 0,1,2
+ For k, it runs from 2 to n then resets i,j,k = i,j+1,j+2 ( n recursive calls for each j )
+ For j, it runs from 1 to n-1 then resets i,j,k = i+1,i+2,i+3 ( n recursive calls for each i)
+ For i, it runs from 0 to n-2 then terminate and end the recursion (n recursive calls)
=> There are total of n*n*n = n^3 recursive calls.
+ At each recursive call, we check if the triplet arr[i],arr[j],arr[k] satisfies the pythagorean condition ( O(1) )

==> The time complexity of this algorithm is O(n^3 * 1) = O(n^3) for all worst, best and average case scenario
*/