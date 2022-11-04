
int nCr(int n, int r) {
    vector<vector<int>> C(n+1, vector<int>(r+1));

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=min(r, i); j++) {
            if(j==0 or j==n) C[i][j] = 1;
            else C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][r];
}
