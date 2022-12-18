/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 17-12-2022
 *
 * Sieve of Eratosthenes is an algorithm that can be used for finding all the prime numbers in the range [1, n]
 * in just O(n * log(log(n))) time.
 *
 * Can be used when n <= 10^6 and is usually used to query prime numbers in a range.
 *
 * Code taken from cp-algorithms.
 *
 * Time Complexity = O(n * log(log(n)))
 * Space Complexity = O(n)
 *
 */

// using ll = long long;

vector<bool> sieveOfEratosthenes(int n) {

    vector<bool> isPrime(n+1, true);

    isPrime[0] = isPrime[1] = false;

    for(int i=2; (ll)i*i<=n; i++) {
        if(isPrime[i]) {
            for(int j=i*i; j<=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}
