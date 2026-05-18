#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> rooms(n);
    for(int i=0;i<n;i++){
        cin>>rooms[i].first>>rooms[i].second;
    }

    int canHold=0;

    for(int i=0;i<n;i++){
        if(rooms[i].second-rooms[i].first>=2){
            canHold++;
        }
    }

    cout<<canHold<<"\n";
}