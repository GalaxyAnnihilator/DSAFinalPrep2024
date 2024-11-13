/*
Pseudo-code:

arr := {2,3,6,4,9,5,8,6,10,13,12}
n = sizeof(arr)/sizeof(arr[0])
for i := 0->n-2 do
    for j := i+1 to n-1 do
        for k := j+1 to n do
            a,b,c = arr[i],arr[j],arr[k]
            if (a**2 + b**2 == c**2 or b**2+c**2==a**2 or a**2+b**2==c**2) then
                print (a,b,c)

*/

#include <iostream>
using namespace std;

int main(){
    int arr[] = {2,3,6,4,9,5,8,6,10,13,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0;i<n-2;i++){
        for (int j = i+1;j<n-1;j++){
            for (int k = j+1;k<n;k++){
                int a = arr[i],b = arr[j],c=arr[k];
                if (a*a + b*b == c*c || b*b+c*c==a*a ||a*a+c*c==b*b){
                    cout<< "(" << a << ", " << b << ", " << c <<") is Pythagorean triple" <<endl;
                }
            }
        }
    }
    return 0;
}

/*
Time complexity analysis:
+ Since this algorithm involes 3 nested for loops, each variable i, j, k in their any case scenario iterates from 0 to n ( O(n) for each variable )
+ Each time, there check if the triplet ( arr[i], arr[j], arr[k] ) satistifies the pythagorean condition ( O(1) )
==> The time complexity for this algorithm is O(n * n * n * 1) = O(n^3) for all best, average and worst cases.
*/