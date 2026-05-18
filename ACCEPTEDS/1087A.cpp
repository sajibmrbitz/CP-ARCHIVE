#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define nl '\n'
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n,c,k;
    cin>>n>>c>>k;

    vector<ll> power(n);
    for(auto i=0;i<n;i++){
        cin>>power[i];
    }

    sort(all(power));

    for(auto i=0;i<n;i++){
        if(c>=power[i]){
            ll useK=min(k,c-power[i]); 
            c+=(power[i]+useK);
            k-=useK;
        }
    }

    cout<<c<<nl;

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