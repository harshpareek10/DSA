class Solution {
public:

    bool dfs(int u, int v,vector<bool>& vis, vector<vector<int>>& adj){
        if(u == v){
            return true;
        }
        vis[u] = true;

        for(int ngbr : adj[u]){
            if(!vis[ngbr]){
               if(dfs(ngbr,v,vis,adj))
                return true;
               
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

        vector<bool> vis(n+1,false);
            if(dfs(u,v,vis,adj)){
                return x;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};