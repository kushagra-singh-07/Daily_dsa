class Solution {
public:
bool check(string a,string b) {
    int n=a.size();
    int m=b.size();
        if (m!=n+1)
            return false;

        int i=0,j=0;

        while (i<n && j<m) {
            if (a[i]==b[j]) {
                i++;
            }
            j++;
        }
        return i==n;
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),[](string a, string b){
            return a.size()<b.size();
        });
        int ans=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(dp[i],ans);
        }
        return ans;
    }
};