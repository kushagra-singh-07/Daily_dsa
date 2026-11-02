
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n=code.size();

        for(int i=0;i<n;i++){
            int sum=0;

            if(k>0){
                for(int j=1;j<=k;j++){
                    sum += code[(i+j)%n];
                }
            }
            else if(k<0){
                for(int j=1;j<=abs(k);j++){
                    sum += code[(i-j+n)%n];
                }
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
