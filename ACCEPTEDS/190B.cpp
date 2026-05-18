#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){

    string s;
    cin>>s;
    int n=s.size();

    vector<int> SamneTwoKoyta(n+1,0);
    vector<int> PoreOddKoyta(n+1,0);

    for(int i=0;i<n;i++){
        SamneTwoKoyta[i+1]=SamneTwoKoyta[i]+(s[i]=='2');
    }

    for(int i=n-1;i>=0;i--){
        PoreOddKoyta[i]=PoreOddKoyta[i+1]+(s[i]=='1' || s[i]=='3');
    }

    int best=0;

    for(int split=0;split<=n;split++){
        int keep=SamneTwoKoyta[split]+PoreOddKoyta[split];
        best=max(best,keep);
    }

    cout<<n-best<<'\n';
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