class Solution {
public:

    bool dfs(int curr, vector<vector<int>>& adj,
             vector<bool>& vis, vector<bool>& path) {

        vis[curr] = true;
        path[curr] = true;

        for(int ngbr : adj[curr]) {

            if(!vis[ngbr]) {
                if(dfs(ngbr, adj, vis, path)) {
                    return true;
                }
            }
            else if(path[ngbr]) {
                return true;
            }
        }

        path[curr] = false;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto x : prerequisites) {
            int course = x[0];
            int prerequisite = x[1];

            adj[prerequisite].push_back(course);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {
                if(dfs(i, adj, vis, path)) {
                    return false;
                }
            }
        }

        return true;
    }
};