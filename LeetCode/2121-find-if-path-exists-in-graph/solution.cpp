#define WHITE 0
#define GRAY  1
#define BLACK 2

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        vector<vector<int>> graph(n);
        for(auto &edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int color[n];
        int parent[n];
        int d[n];


        for(int u=0;u<n;u++){
            if(u!=source){
                color[u]=WHITE;
                parent[u]=-1;
                d[u]=INT_MAX;
            }
        }

        color[source]=GRAY;
        parent[source]=-1;
        d[source]=0;
        //BFS
        queue<int> q;
        q.push(source);

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:graph[u]){
                if(color[v]==WHITE){
                    color[v]=GRAY;
                    parent[v]=u;
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
            color[u]=BLACK;
        }
        return (color[destination]==BLACK);
    }
};
