#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

void solve(){
    ll a,b,c,m;
    cin>>a>>b>>c>>m;

    ll nA=m/a,nB=m/b,nC=m/c;        // koydin visit kore
    
    ll LCMab=(a/__gcd(a,b))*b;      // count common days
    ll LCMac=(a/__gcd(a,c))*c;
    ll LCMbc=(b/__gcd(b,c))*c;
    ll LCMabc=(LCMab/__gcd(LCMab,c))*c;

    ll nAB=m/LCMab,nAC=m/LCMac,nBC=m/LCMbc;
    ll nABC=m/LCMabc;

    cout<<6*nA-3*nAB-3*nAC+2*nABC<<" ";     // waters
    cout<<6*nB-3*nAB-3*nBC+2*nABC<<" ";
    cout<<6*nC-3*nAC-3*nBC+2*nABC<<"\n";
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