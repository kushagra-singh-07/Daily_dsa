class Solution {
    vector<int> dp;

public:
    int solve(int i, int end, vector<int>& nums) {

        if (i > end)
            return 0;
        if (dp[i]!=-1)
            return dp[i];
        int robcurrent = nums[i]+solve(i+2,end,nums);
        int skipcurrent = solve(i+1,end,nums);

        return dp[i] = max(robcurrent, skipcurrent);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n==1)
            return nums[0];

        dp.assign(n, -1);
        int case1 = solve(1,n-1,nums);
        dp.assign(n,-1);
        int case2 = solve(0,n-2,nums);
        return max(case1,case2);
    }
};