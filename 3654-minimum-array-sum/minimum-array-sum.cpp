// class Solution {
// public:
//     int minArraySum(vector<int>& nums, int k, int op1, int op2) {
//         int n=nums.size();
//         vector<vector<vector<int>>>dp(n,vector<vector<int>>(op1+1,vector<int>(op2+1,0)));
//         for(int i=n-1;i>=0;i--){
//             for(int a=0;a<=op1;a++){
//                 for(int b=0;b<=op2;b++){
//                     int skip=nums[i]+dp[i+1][a][b];
//                     int take1=INT_MAX;
//                     int take2=INT_MAX;
//                     int take3=INT_MAX;
//                     int take4=INT_MAX;
//                     if(op1>0){
//                         int temp1=(nums[i]+1)/2;
//                         take1 =temp1+dp[i+1][a-1][b];
//                     }
//                     if(op2>0 && nums[i]>=k){
//                         int temp2 =nums[i]-k;
//                         take2 =temp2+dp[i+1][a][b-1];
//                     }
//                      if(op1>0 && op2>0){
//                         int temp3 =(nums[i]+1)/2;
//                         if(temp3>=k){
//                         temp3-=k;
//                         take3 = temp3 +dp[i+1][a-1][b-1];
//                     }
//                     if(nums[i]>=k){
//                     int temp4 = (nums[i]-k+1);
//                     temp4=temp4/2;
//                     take4 =temp4+dp[i+1][a-1][b-1];
//                     }
//             }
//                 }
//             }
//         }
//     }
// };
 
class Solution {
    vector<vector<vector<int>>>dp;
public:
    int solve(int i, vector<int>& nums, int k, int op1, int op2){
        int n = nums.size();

        if (i>=n) return 0;
        if(dp[i][op1][op2]!=-1) return dp[i][op1][op2];
        int skip =nums[i]+solve(i+1,nums,k,op1,op2);
        int take1=INT_MAX;
        int take2=INT_MAX;
        int take3=INT_MAX;
        int take4=INT_MAX;
        if(op1>0){
            int temp1=(nums[i]+1)/2;
            take1 =temp1+solve(i+1,nums,k,op1-1,op2);
        }
        if(op2>0 && nums[i]>=k){
            int temp2 =nums[i]-k;
            take2 =temp2+solve(i+1,nums,k,op1,op2-1);
        }
        if(op1>0 && op2>0){
            int temp3 =(nums[i]+1)/2;
            if(temp3>=k){
                temp3-=k;
                take3 = temp3 +solve(i+1,nums,k,op1-1,op2-1);
            }
            if(nums[i]>=k){
                int temp4 = (nums[i]-k+1);
                temp4=temp4/2;
                take4 =temp4+solve(i+1,nums,k,op1-1,op2-1);
            }
        }
        return dp[i][op1][op2]=min({skip,take1,take2,take3,take4});
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n=nums.size();
        dp.resize(n,vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));
        return solve(0,nums,k,op1,op2);
    }
};