class Solution {
    vector<int> dp;

public:
    int solve(int i, int n) {
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i] != -1)
            return dp[i];

        int take = solve(i+1, n);
        int skip = solve(i+2, n);

        return dp[i] = take+skip;
    }

    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return solve(0, n);
    }
};