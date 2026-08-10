#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,y,n;
    cin>>x>>y>>n;
    int result=((n-y)/x)*x+y;
    cout<<result<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}