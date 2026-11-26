class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
        queue<int> q;

        vector<bool> vis(n,0);
        q.push(0);
        vis[0]=1;

        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it:rooms[temp]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};