#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> doors(N);
    for (int &x:doors) cin>>x;

    int first=-1,last=-1,unreachable=0;
    for(int i=0;i<N;i++){
        if (doors[i]==1){
            if (first==-1) first=i;
            last=i;
        }
    }

    if(first!=-1){
        unreachable=last-first;
    }

    cout<<unreachable<<"\n";
    return 0;
}
