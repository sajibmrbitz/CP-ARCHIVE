#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int cnt[10001]={};
    for(int i=0;i<n*n;i++){
        int x; 
        cin>>x; 
        cnt[x]++;
    }
    bool ok=true;
    for(int i=1;i<=n*n;i++){
        if(cnt[i]>n*(n-1)){
            ok=false;
        }
    }
    cout<<(ok?"YES\n":"NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}