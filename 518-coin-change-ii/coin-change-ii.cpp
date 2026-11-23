// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         vector<vector<long long>>dp(n+1,vector<long long>(amount+1,0));

//         for(int k=0;k<=n;k++){
//             dp[k][0]=1;
//         }
//         for(int i=n-1;i>=0;i--){
//             for(int j=1;j<=amount;j++){
//                 long long  take=0;
//                 if(coins[i]<=j){
//                     take=dp[i][j-coins[i]];
//                 }
//                 int skip=dp[i+1][j];
//                 dp[i][j]=(skip+take);
//             }
//         }
//         return dp[0][amount];
//     }
// };



class Solution {
    vector<vector<int>>dp;
public:
    int solve(int i,int amount,vector<int>& coins){
        int n=coins.size();
        if(amount==0) return 1;
        if(i>=n) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=0;
        if(coins[i]<=amount){
            take=solve(i,amount-coins[i],coins);
        }
        int skip=solve(i+1,amount,coins);
        return dp[i][amount]=skip+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};



// class Solution {
// public:
//     int solve(int i,int amount,vector<int>& coins){
//         int n=coins.size();
//         if(amount==0) return 1;
//         if(i>=n) return 0;
//         int take =0;
//         if(coins[i]<=amount){
//             take=solve(i,amount-coins[i],coins);
//         }
//         int skip=solve(i+1,amount,coins);
//         return skip+take;
//     }
//     int change(int amount, vector<int>& coins) {
//         return solve(0,amount,coins);
//     }
// };