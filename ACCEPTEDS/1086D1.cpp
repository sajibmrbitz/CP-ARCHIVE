#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define NO cout<<"NO\n";

vector<bool> bfs(int start,int n,const vector<vector<int>>& g){
    vector<bool> vis(n,false);
    queue<int> q;
    q.push(start);
    vis[start]=true;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
    return vis;
}

void solve(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    vector<bitset<505>> R(n),C(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='1'){
                R[i].set(j);
                C[j].set(i);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(!R[i][i]){
            NO
            return;
        }
        for(int j=i+1;j<n;j++){
            if(R[i][j]&&R[j][i]){
                NO
                return;
            }
        }
    }

    vector<pair<int,int>> edges;
    vector<vector<int>> adj(n),dir(n);

    for(int u=0;u<n;u++){
        for(int v=0;v<n;v++){
            if(u!=v&&R[u][v]){
                if((R[u]&C[v]).count()==2){
                    edges.push_back({u,v});
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    dir[u].push_back(v);
                }
            }
        }
    }

    if(edges.size()!=n-1){
        NO
        return;
    }

    vector<bool> vis=bfs(0,n,adj);
    int comp=0;
    for(int i=0;i<n;i++){
        if(vis[i]) comp++;
    }

    if(comp!=n){
        NO
        return;
    }

    for(int i=0;i<n;i++){
        vector<bool> reach=bfs(i,n,dir);
        for(int j=0;j<n;j++){
            if((s[i][j]=='1')!=reach[j]){
                NO
                return;
            }
        }
    }

    cout<<"Yes\n";
    for(auto& e:edges){
        cout<<e.first+1<<" "<<e.second+1<<"\n";
    }
}

int main(){
    FAST_IO
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}