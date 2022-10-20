class PolyRollingHash:
    def __init__(self, s, p=31, m=2**63-1):
        n = len(s)

        p_pow = [0] * n
        p_pow[0] = 1

        for i in range(1, n):
            p_pow[i] = (p_pow[i-1] * p) % m

        h = [0] * (n+1)

        for i in range(n):
            h[i+1] = (h[i] + (ord(s[i]) - ord('a') + 1) * p_pow[i]) % m

        self.s, self.n, self.p, self.m, self.p_pow, self.h = s, n, p, m, p_pow, h

    def substrHash(self, i, j):
        '''
        Returns the hash of the substring s[i:j] in O(1) time
        '''
        n, p_pow, h, m = self.n, self.p_pow, self.h, self.m

        hsh = (h[j] - h[i] + m) % m
        hsh = (hsh * p_pow[n-1-i]) % m

        return hsh
