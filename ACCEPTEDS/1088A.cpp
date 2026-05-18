#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){

    int n;
    cin>>n;

    // ajaira input

    vector<int> ajaira(n);
    for(int i=0;i<n;i++){
        cin>>ajaira[i];
    }

    if(n==1){
        cout<<1<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            cout<<2<<(i==n-1?"":" ");
        }
        cout<<endl;
    }
}

int main() {
    FAST_IO

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}