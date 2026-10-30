
class Solution {
    vector<vector<vector<int>>> dp;

public:
    int solve(int r1, int c1, int r2, int n,
              vector<vector<int>>& grid) {

        int c2 = r1 + c1 - r2;

        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
           grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];

        if(dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = grid[r1][c1];

        if(r1 != r2 || c1 != c2)
            cherries += grid[r2][c2];

        int maxi = -1e9;
        maxi = max(maxi, solve(r1+1, c1, r2+1, n, grid));
        maxi = max(maxi, solve(r1+1, c1, r2, n, grid));
        maxi = max(maxi, solve(r1, c1+1, r2+1, n, grid));
        maxi = max(maxi, solve(r1, c1+1, r2, n, grid));

        return dp[r1][c1][r2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1)));

        return max(0, solve(0, 0, 0, n, grid));
    }
};
