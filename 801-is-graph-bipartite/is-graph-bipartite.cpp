class Solution {
public:
    bool checkBFS(int src , vector<vector<int>> &graph , vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }

        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n,-1);
    // vector<vector<int>> adj(n);
    // if bi-directional graph was given then the following should be implemented
    // for(int i =0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(graph[i][j]){
    //             adj[i].push_back(j);
    //             adj[j].push_back(i);
    //         }
    //     }
    // }
    for(int i =0;i<n;i++){
        if(color[i]==-1){
            if(checkBFS(i,graph,color)==false) {
                return false;
            }
        }
    }
    return true;
    }   
};