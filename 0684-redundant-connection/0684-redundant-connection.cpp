class Solution {
public:

    bool bfs(int u, int v, vector<vector<int>>& adj){
        queue<int> Q;
        vector<bool> vis(adj.size(),false);

        Q.push(u);
        vis[u] = true;

        while(!Q.empty()){
            int curr = Q.front();
            Q.pop();

            if(curr == v){
                return true;
            }
            for(int ngbr : adj[curr]){
                if(!vis[ngbr]){
                    vis[ngbr] = true;
                    Q.push(ngbr);
                }
            }
        }
        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);

        for(auto x : edges){
            int u = x[0];
            int v = x[1];

            if(bfs(u,v,adj)){
                return x;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};