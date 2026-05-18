#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,R;
    cin>>N>>R;
    vector<int> doors(N);
    for(int &x:doors)   cin>>x;

    int left=-1,right=-1;
    for(int i=0;i<N;i++){
        if(doors[i]==0){
            left=i;
            break;
        }
    }
    for(int i=N-1;i>=0;i--){
        if(doors[i]==0){
            right=i;
            break;
        }
    }

    int ops=0;
    if (left!=-1 && right!=-1){
        for(int i=left;i<=right;i++){
            ops+=(doors[i]==0?1:2);
        }
    }

    cout<<ops<<"\n";
    return 0;
}
