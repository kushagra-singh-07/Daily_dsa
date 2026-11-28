class Solution {
    vector<vector<int>> dp;
public:
    int solve(int i,int j,string& word1, string& word2){
        int n=word1.size();
        int m=word2.size();
        int maxi=INT_MAX;
        if(i>=n ||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=1+solve(i+1,j+1,word1,word2);
        }
        int take1=solve(i+1,j,word1,word2);
        int take2=solve(i,j+1,word1,word2);
        maxi=max(take1,take2);
        return dp[i][j]=maxi;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int ans=0;
        dp.resize(n,vector<int>(m,-1));
        ans=(n-solve(0,0,word1,word2))+(m-solve(0,0,word1,word2));

        return ans;
    }
};


// class Solution {
// public:
//     int solve(int i,int j,string& word1, string& word2){
//         int n=word1.size();
//         int m=word2.size();
//         int maxi=INT_MAX;
//         if(i>=n ||j>=m) return 0;
//         if(word1[i]==word2[j]){
//             return 1+solve(i+1,j+1,word1,word2);
//         }
//         int take1=solve(i+1,j,word1,word2);
//         int take2=solve(i,j+1,word1,word2);
//         maxi=max(take1,take2);
//         return maxi;
//     }
//     int minDistance(string word1, string word2) {
//         int n=word1.size();
//         int m=word2.size();
//         int ans=0;
//         ans=(n-solve(0,0,word1,word2))+(m-solve(0,0,word1,word2));

//         return ans;
//     }
// };