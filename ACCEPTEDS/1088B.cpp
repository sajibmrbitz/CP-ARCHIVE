#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

ll divisorKoyta(ll n){
    if(n==0) return 1;
    ll count=0;

    for(ll i=1;i*i<=n;i++){

        if(n%i==0){
            count++;

            if(i*i!=n){
                count++;
            }
        }
    }

    return count;
}

void solve(){

    ll x,y;
    cin>>x>>y;

    cout<<divisorKoyta(abs(x-y))<<endl;

    for(int i=0;i<y;i++){
        cout<<"-1 ";
    }
    for(int i=0;i<x;i++){
        cout<<"1 ";
    }

    cout<<endl;
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