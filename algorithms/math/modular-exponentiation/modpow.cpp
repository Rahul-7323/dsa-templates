/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 07-01-2023
 *
 * Binary exponentiation under a modulo.
 *
 * Time Complexity: O(log(n))
 * Space Complexity: O(1)
 */

using ll = long long;

ll modpow(ll a, ll n, ll m) {
    ll result = 1;

    while(n) {
        if(n & 1) result = (result*a)%m;
        a = (a*a)%m;
        n >>= 1;
    }

    return result;
}
