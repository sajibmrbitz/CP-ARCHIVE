#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n<=1399)         cout<<"Division 4"<<endl;
    else if(n<=1599)    cout<<"Division 3"<<endl;
    else if(n<=1899)    cout<<"Division 2"<<endl;
    else                cout<<"Division 1"<<endl;
}

int main() {

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//determine codeforces division from rating