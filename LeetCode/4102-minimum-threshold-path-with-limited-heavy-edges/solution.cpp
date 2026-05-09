class Solution{
public:
    int minimumThreshold(int n,vector<vector<int>>& edges,int s,int t,int k){
        if(s==t) return 0;
        vector<vector<pair<int,int>>> adj(n);
        int lo=0,hi=0,ans=-1;
        for(const auto& e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
            hi=max(hi,e[2]);
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;
            vector<int> dist(n,1e9);
            pq.push({0,s});
            dist[s]=0;
            while(!pq.empty()){
                auto [cost,u]=pq.top();
                pq.pop();
                if(cost>dist[u] || cost>k) continue;
                for(const auto& edge:adj[u]){
                    int v=edge.first;
                    int nextCost=cost+(edge.second>mid?1:0);
                    if(nextCost<dist[v]){
                        dist[v]=nextCost;
                        pq.push({nextCost,v});
                    }
                }
            }
            if(dist[t]<=k){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};
