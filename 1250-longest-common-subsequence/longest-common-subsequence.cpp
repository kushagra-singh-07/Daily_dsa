// class Solution {
//     vector<vector<int>> dp;
// public:
//     int solve(int i,int j,string text1, string text2){
//         if(i>=text1.size() || j>=text2.size()) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(text1[i]==text2[j]){
//             return dp[i][j]=1+solve(i+1,j+1,text1,text2);
//         }
//         int take1=solve(i+1,j,text1,text2);
//         int take2=solve(i,j+1,text1,text2);


//         return dp[i][j]=max(take1,take2);
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         dp.resize(text1.size(),vector<int>(text2.size(),-1));
//         return solve(0,0,text1,text2);
//     }
// };

class Solution {
    vector<vector<int>> dp;
public:
    int solve(int i, int j, const string& text1, const string& text2) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j])
            return dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2);

        int take1 = solve(i + 1, j, text1, text2);
        int take2 = solve(i, j + 1, text1, text2);
        return dp[i][j] = max(take1, take2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size(), vector<int>(text2.size(), -1));
        return solve(0, 0, text1, text2);
    }
};