/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 17-12-2022
 *
 * Binary Exponentiation can be used for calculating a^n in just O(log(n)) time instead of using O(n) time like 
 * naive multiplication. This code is taken from cp-algorithms
 * 
 * Time Complexity = O(log(n))
 */

// using ll = long long;

ll binpow(ll a, ll b) {
    ll res = 1;

    while(b) {
        if(b & 1) res *= a;
        a = a * a;
        b >>= 1;
    }

    return res;
}
