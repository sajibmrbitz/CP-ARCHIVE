#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define nl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

pair<int,int> bfs(int start, const vector<vector<int>>& adj, vector<int>& color){
    queue<int> q;
    q.push(start);
    color[start]=0;
    int color0=1, color1=0;
    bool isBipartite=true;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(color[v]==-1){
                color[v]=1-color[u];
                if(color[v]==0){
                    color0++;
                }
                else color1++;
                q.push(v);
            } else if(color[v]==color[u]){
                isBipartite=false;
            }
        }
    }
    if(!isBipartite) return {-1,-1};
    return {color0,color1};
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> color(n+1,-1);
    int ans=0;

    for(int i=1;i<=n;i++){
        if(color[i]==-1){

            pair<int,int> konColorKoyta=bfs(i,adj,color);

            if(konColorKoyta.first!=-1){
                ans+=max(konColorKoyta.first,konColorKoyta.second);
            }
        }
    }
    cout<<ans<<nl;
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