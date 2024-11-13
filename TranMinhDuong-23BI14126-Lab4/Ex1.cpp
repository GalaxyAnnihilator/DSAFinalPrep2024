#include <iostream>
using namespace std;

/*
Pseudocode:
get N
result = 0
while N != 0 do:
    result = result + n%10
    n = n / 10

print result
*/

int digitSum1(int n){
    int result = 0;
    while (n!=0){
        result += n%10;
        n /= 10;
    }
    return result;
}

int digitSum2(int n){
    if (n==0){
        return 0;
    }
    else{
        return n%10 + digitSum2(n/10);
    }
}

int main(){
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "Sum of N with Iteration: " << digitSum1(N) << endl;

    cout << "Sum of N with Recursion: " << digitSum2(N) << endl;

    return 0;
}

/*
Time complexity:
The number of iterations or recursive calls is exactly the number of digits of N, that is log10(N)
Therefore the time complexity for both approaches is O(logN)

*/