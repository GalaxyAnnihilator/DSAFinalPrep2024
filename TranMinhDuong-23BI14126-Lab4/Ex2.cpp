#include <iostream>
using namespace std;

int primeCheck(int n, int div){
    if (n > 1 && n < 4) { // 2,3 are prime
        return 1;
    } else if (n <= 1) { // 0, 1 and negatives are not prime
        return 0;
    }

    if (div * div > n) { // equivalent to div > sqrt(n)
        return 1; // base-case: no divisor found ==> n is a prime
    }

    if (n % div == 0) {
        return 0;
    } else {
        return primeCheck(n, div + 1);
    }
}

int sphenicCheck(int n, int primeCount, int lastPrime){
    if (n == 1) {
        if (primeCount == 3) { // n is completely factorized and found 3 distinct prime divisors
            return 1;
        } else {
            return 0;
        }
    }

    int i;
    for (i = 2; i <= n; i++) {
        if (n % i == 0 && primeCheck(i, 2)) { // found a distinct prime divisor
            break;
        }
    }
    
    if (i == lastPrime) { // to ensure we count distinct primes
        return 0;
    }

    return sphenicCheck(n / i, primeCount + 1, i);
}

void initiateSearch(int n, int i){
    if (n == i) {
        return;
    }

    if (sphenicCheck(i, 0, -1)) { // start with 0 primes and no lastPrime (-1 means no prime found yet)
        cout << i << " is sphenic" << endl;
    }
    initiateSearch(n, i + 1);
}

int main(){
    int n = 100;
    initiateSearch(n, 1);
    return 0;
}

/* Time complexity analysis:
- The primeCheck() function checks for div from 2 to sqrt(n) 
=> The time complexity for primeCheck() is O(sqrt(n))

- The sphenicCheck() function iterates i until a prime factor is found. 
However, this function ends when n is completely factorized, =1
This depends on how many factors there are, either n is prime with one factor or a composite with many
=> Assume n has exactly 3 prime factors, the time complexity for sphenicCheck() is O(n)

- Lastly, initiateSearch() will check every i from 1 to n so see if i is sphenic. This takes n recursive calls.
=> The time complexity for initiateSearch() is O(n)

==> The total time complexity of the program is O(n*n*sqrt(n)) = O(n^2 sqrt(n))

*/