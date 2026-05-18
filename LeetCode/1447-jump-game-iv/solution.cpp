class Vertex{
public:
    int id;
    int val;
    bool visited;
    int dist;

    Vertex(int id,int val){
        this->id=id;
        this->val=val;
        this->visited=false;
        this->dist=0;
    }
};

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n<=1) return 0;

        vector<Vertex> nodes;
        unordered_map<int, vector<int>> adj;

        for(int i=0;i<n;i++){
            nodes.push_back(Vertex(i,arr[i]));
            adj[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        nodes[0].visited=true;
        nodes[0].dist=0;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            if(u==n-1){
                return nodes[u].dist;
            }

            for(int v:adj[nodes[u].val]){
                if(!nodes[v].visited){
                    nodes[v].visited=true;
                    nodes[v].dist=nodes[u].dist+1;
                    q.push(v);
                }
            }
            
            adj[nodes[u].val].clear();

            int nextNode=u+1;
            if(nextNode<n && !nodes[nextNode].visited){
                nodes[nextNode].visited=true;
                nodes[nextNode].dist=nodes[u].dist+1;
                q.push(nextNode);
            }

            int prevNode=u-1;
            if(prevNode>=0 && !nodes[prevNode].visited){
                nodes[prevNode].visited=true;
                nodes[prevNode].dist=nodes[u].dist+1;
                q.push(prevNode);
            }
        }

        return -1;
    }
};
