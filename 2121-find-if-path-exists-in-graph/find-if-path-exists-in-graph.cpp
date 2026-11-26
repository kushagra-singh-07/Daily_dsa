class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,int destination) {
        queue<int> q;
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        q.push(source);
        vis[source] = true;
        if(source==destination) return true;

        for (auto x : edges) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            for (auto it : adj[temp]) {
                if (!vis[it]) {
                    if (it == destination)
                        return true;
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};