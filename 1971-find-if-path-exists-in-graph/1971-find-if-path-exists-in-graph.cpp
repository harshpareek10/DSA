class Solution {
public:

    bool dfs(int source, int destination,vector<vector<int>>& adj,vector<bool>& vis){

        if(source == destination){
            return true;
        }

        vis[source] = true;
        for(int neighbour : adj[source]) {
            if(!vis[neighbour]) {
                if(dfs(neighbour, destination, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }



    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);

        for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
       adj[u].push_back(v);
       adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        return dfs(source, destination, adj, vis);
    }
};