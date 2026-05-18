#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define nl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> eiPonjontoMax(n);
    eiPonjontoMax[0]=a[0];
    for(int i=1;i<n;i++){
        eiPonjontoMax[i]=max(eiPonjontoMax[i-1],a[i]);
    }

    int operations=0;
    int i=n-1;
    while(i>=0){
        int khujtesi=eiPonjontoMax[i];
        while(i>=0 && a[i]<khujtesi){
            i--;
        }
        if(i>=0){
            operations++;
            i--;
        }
    }
    cout<<operations<<nl;
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