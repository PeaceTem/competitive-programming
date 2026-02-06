//---------------------------
// Count Unique Paths in a Grid
// Given an n x m grid, count the number of unique paths from the top-left corner to the bottom-right corner,
// moving only down or right at any point in time.
//---------------------------

long long countPaths(int n, int m) {
    vector<vector<long long>> dp(n, vector<long long>(m, 0));

    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) continue;

            long long fromUp   = (i > 0 ? dp[i-1][j] : 0);
            long long fromLeft = (j > 0 ? dp[i][j-1] : 0);
            
            long long fromUP = (i > 0 ? dp[i-1][j] : 0);
            long long fromLeft
            dp[i][j] = fromUp + fromLeft;
        }
    }

    return dp[n-1][m-1];
}
