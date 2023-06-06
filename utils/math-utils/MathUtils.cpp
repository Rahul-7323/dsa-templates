namespace MathUtils {
    using ll = long long;
    ll MOD = 1e9 + 7;

    ll modpow(ll a, ll n, ll m = MOD) {
        ll result = 1;

        while(n) {
            if(n & 1) result = (result * a) % m;
            a = (a * a) % m;
            n >>= 1;
        }

        return result;
    }

    ll modInv(ll num, ll m = MOD) {
        return modpow(num, m-2, m);
    }

    vector<ll> fact, factInv;

    void calcFactorials(int n) {
        fact.resize(n+1);
        factInv.resize(n+1);

        fact[0] = 1;
        factInv[0] = 1;

        for(int i=1; i<=n; i++) {
            fact[i] = (i * fact[i-1]) % MOD;
            factInv[i] = modInv(fact[i]);
        }
    }

    ll perm(int n, int r) {
        return (fact[n] * factInv[n-r]) % MOD;
    }

    ll comb(int n, int r) {
        return (perm(n, r) * factInv[r]) % MOD;
    }

    vector<bool> sieve(int n) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i=2; (ll)i*i <= n; i++) {
            if(isPrime[i]) {
                for(int j=i*i; j<=n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        return isPrime;
    }

    vector<vector<int>> divisorSieve(int n) {
        vector<vector<int>> divisors(n+1);

        for(int i=1; i<=n; i++) {
            for(int j=2*i; j<=n; j+=i) {
                divisors[j].push_back(i);
            }
        }

        return divisors;
    }

    vector<int> bigSieve(int n) {
        vector<int> big(n+1, 1);

        for(int i=2; i<=n; i++) {
            if(big[i] == 1) {
                for(int j=i; j<=n; j+=i) {
                    big[j] = i;
                }
            }
        }

        return big;
    }

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
        return a * b / gcd(a, b);
    }

    ll modadd(ll a, ll b, ll m = MOD) {
        return (a + b) % m;
    }

    ll modsub(ll a, ll b, ll m = MOD) {
        return (a - b + m) % m;
    }

    ll modmul(ll a, ll b, ll m = MOD) {
        return (a * b) % m;
    }

    ll moddiv(ll a, ll b, ll m = MOD) {
        return (a * modInv(b, m)) % m;
    }
}
