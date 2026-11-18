
class Solution {
    vector<vector<int>> dp;
public:
    int solve(int i,int prev,vector<int>& nums){
        int n=nums.size();

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=-1;j--){
                int take=0;
                if(j==-1||nums[i]>nums[j]){
                    take=1+dp[i+1][i+1];
                }
                int skip=dp[i+1][j+1];
                dp[i][j+1]=max(take,skip);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,0));
        return solve(0,-1,nums);
    }
};



// class Solution {
//     vector<vector<int>> dp;
// public:
//     int solve(int i,int prev,vector<int>& nums){
//         int n=nums.size();
//         if(i>=n) return 0;
//         if(dp[i][prev+1]!=-1) return dp[i][prev+1];

//         int take=0;
//         if(prev==-1||nums[i]>nums[prev]){
//             take=1+solve(i+1,i,nums);
//         }
//         int skip=solve(i+1,prev,nums);
//         return dp[i][prev+1]=max(skip,take);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         dp.resize(n,vector<int>(n+1,-1));
//         return solve(0,-1,nums);
//     }
// };



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