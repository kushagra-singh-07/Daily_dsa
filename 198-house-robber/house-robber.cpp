class Solution {
    vector<int> dp;
public:
    int solve(int i,int n,vector<int>& nums){
         n=nums.size();
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];
        int finalmaximum=INT_MIN;
        int robcurrent = nums[i] + solve(i+2,n,nums);
        int skipcurrent = solve(i+1,n,nums);

       finalmaximum = max(robcurrent, skipcurrent);

        return dp[i]=finalmaximum;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        return solve(0,n,nums);
    }
};