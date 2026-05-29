#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    int zeroes=0;
    for(char c:s){
        if(c=='0') zeroes++;
    }

    int misplaced=0;
    for(int i=zeroes;i<n;i++){
        if(s[i]=='0') misplaced++;
}

    cout<<misplaced<<'\n';
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}