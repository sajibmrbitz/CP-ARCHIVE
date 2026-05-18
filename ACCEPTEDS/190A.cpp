#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define nl '\n'

void solve(){
    ll n,a,b;
    cin>>n>>a>>b;

    ll remain=n%3;
    ll money=((n/3)*b)<(n-remain)*a?((n/3)*b):((n-remain)*a);

    ll addOn=(remain*a)<b?remain*a:b;
    money+=addOn;

    cout<<money<<nl;
    
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