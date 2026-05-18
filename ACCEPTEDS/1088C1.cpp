#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define YES cout<<"YES\n";
#define NO  cout<<"NO\n";

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1), b(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    vector<bool> unfixed(n+1,false);
    vector<bool> fixed(n+1,false);

    for(int i=n-k+1;i<=k;i++){
        unfixed[a[i]]=true;
    }

    bool possible=true;
    for(int i=1;i<=n;i++){
        if(i<=n-k || i>k){
            if(b[i]!=-1 && b[i]!=a[i]){
                possible=false;
                break;
            }
        } 
        else{
            if(b[i]!=-1){
                if(!unfixed[b[i]] || fixed[b[i]]){
                    possible=false;
                    break;
                }
                fixed[b[i]]=true;
            }
        }
    }

    if(possible){
        YES
    } 
    else{
        NO
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