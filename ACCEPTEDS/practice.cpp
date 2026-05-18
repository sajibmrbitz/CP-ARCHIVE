#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,t;
    cin>>n>>t;

    vector<ll> tasks(n);
    for(ll i=0;i<n;i++){
        cin>>tasks[i];
    }

    ll lo=1;
    ll hi=min_element(tasks.begin(),tasks.end())[0]*t;

    while(lo<hi){

        ll mid=lo+(hi-lo)/2;
        ll produced=0;

        for(ll i=0;i<n;i++){

            produced+=mid/tasks[i];
            
            if(produced>=t){
                break;
            }
        }
        if(produced>=t){
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }

    cout<<lo<<"\n";

    return 0;
}   
