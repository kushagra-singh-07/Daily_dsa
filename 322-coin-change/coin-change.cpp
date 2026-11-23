class Solution {
    vector<vector<int>>dp;
public: 
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int k=0;k<=amount;k++){
            dp[n][k]=INT_MAX;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                int take=INT_MAX;
                if(coins[i]<=j){
                    int x=dp[i][j-coins[i]];
                    if(x!=INT_MAX) take=1+x;
                }
                int skip=dp[i+1][j];
                dp[i][j]=min(skip,take);
            }
        }
        int ans=dp[0][amount];
        return ans==INT_MAX ? -1:ans;
    }
};

// class Solution {
//     vector<vector<int>>dp;
// public:
//     int solve(int i,int amount,vector<int> &coins){
//         if(amount==0) return 0;

//         if(i>=coins.size()) return INT_MAX;
//         if(dp[i][amount]!=-1) return dp[i][amount];
        
//         int take=INT_MAX;
//         if(coins[i]<=amount){
//             int x=solve(i,amount-coins[i],coins);    
//             if(x!=INT_MAX){
//                 take=1+x;
//             }
//         }
//         int skip=solve(i+1,amount,coins);
//         int mini=min(take,skip);
    

//         return dp[i][amount]=mini;
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         dp.resize(n,vector<int>(amount+1,-1));
//         int ans=solve(0,amount,coins);
//         return ans==INT_MAX ? -1:ans;
//     }
// };