#include <iostream>
using namespace std;

int getDigits(int N){
    int result = 0;
    while (N){
        N = N/10;
        result++;
    }
    return result;
}

void bubbleSortRecursive(int arr[],int size,int i){
    if (i >= size){
        return;
    }
    for (int j = 0;j<size-1;j++){
        if (arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
    bubbleSortRecursive(arr,size,i+1);
}

int main(){
    int N = 2041;
    int M = N; //create a copy for N, first later on when we print
    
    //put all digits of N into an array
    int size = getDigits(M);
    int arr[size];
    for (int i = 0; i<size;i++){
        arr[i] = M%10;
        M = M / 10;
    }

    //sort
    bubbleSortRecursive(arr,size,0);

    //fix the case where 0 is at the beginning:
    if (arr[0] == 0){
        int i = 1;
        while (i < size){
            if (arr[i]!=0){
                break;
            }
            i++;
        }
        
        arr[0] = arr[i];
        arr[i] = 0;
    }

    //print the min permutation
    cout << "The minimum permutation of " << N << " is ";
    for (int i = 0;i<size;i++){
        cout << arr[i];
    }
    cout << endl;

    return 0;
}

/*
TIME COMPLEXITY ANALYSIS:
- First, we get the size or number of digits of N:
    + For each iteration, we divide N by 10 until N reaches 0
    + Hence, the time complexity for getDigits() is O(logn)
- Next, we put the digits of N into an array => This costs O(n)
- After, we sort the array using bubbleSortRecursive():
    + For each recursive call, the largest number is pushed towards the end using j running from 0 to n-1
    + We increase i by 1 after each call
    + Until i == n, we terminate the recursion and the array is sorted
    => Total cost of O(n^2)
- Finally, we check i fthe first number of the array is 0, then we find the first non-zero and swap them O(n)

==> The time complexity is O(logn + n + n^2 + n) = O(n^2) for all best, worst and average case scenarios
*/

/*
PROPSAL OF OPTIMIZATION:
- Since all digits are number < 10, we can use something called "COUNTING SORT"
- We initialized an array of size 10, storing the frequency of each digits from 0 to 9
- After having this array of frequency, we construct a number by printing a non-zero number first
- Then, we print the rest in their order

- For example: N = 99988877744221000 ==> arr[] = {9,9,9,8,8,8,7,7,7,4,4,2,2,1,0,0,0}
- The frequency array will be freq[] = {3,1,2,0,2,0,0,3,3,3}
==> After reconstructing, we get the minimum number: 10002244777888999

Here's the pseudo-code for COUNTING SORT function:

void countingSort(int arr[], int n) {
    int output[n];
    int count[10] = {0,0,0,0,0,0,0,0,0,0}; 

    //Get the frequency for each digit
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    //Filling the output
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]]] = arr[i];
        count[arr[i]]--;
    }

    //Replace the output with array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

The COUNTING SORT is more optimized because it only uses O(n*k) time, where k is the range of numbers
In this case, k = 10 since we only have 10 digits from 0 to 9
==> The time complexity is now O(10n) = O(n)
*/