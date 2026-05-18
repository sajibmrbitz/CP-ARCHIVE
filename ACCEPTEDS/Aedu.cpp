#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define nl '\n'

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<bool> paise(n,false);

    int cur=0;
    paise[cur]=true;

    for(int i=0;i<n;i++){
        if(s[cur]=='L'){
            cur--;
        }
        else{
            cur++;
        }
        paise[cur]=true;
    }

    int count=0;
    for(int i=0;i<n;i++){
        if(paise[i]){
            count++;
        }
    }

    cout<<count<<nl;
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