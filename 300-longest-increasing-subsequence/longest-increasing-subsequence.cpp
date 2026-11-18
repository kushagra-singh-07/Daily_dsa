class Solution {
    vector<vector<int>> dp;
public:
    int solve(int i,int prev,vector<int>& nums){
        int n=nums.size();
        
        if(i>=n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take=0;
        if(prev==-1||nums[i]>nums[prev]){
            take=1+solve(i+1,i,nums);
        }
        int skip=solve(i+1,prev,nums);
        return dp[i][prev+1]=max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n+1,-1));
        return solve(0,-1,nums);
    }
};
// class Solution {
// public:
//     int solve(int i,int prev,vector<int>& nums){
//         int n=nums.size();
//         int ans=0;
//         if(i>=n) return 0;

//         int take=0;
//         if(prev==-1||nums[i]>nums[prev]){
//             take=1+solve(i+1,i,nums);
//         }
//         int skip=solve(i+1,prev,nums);
//         ans=max(skip,take);
//         return ans;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         return solve(0,-1,nums);
//     }
// };