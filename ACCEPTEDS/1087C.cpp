#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

int singleQuery(int i,int j){
    cout<<"? "<<i<<" "<<j<<endl; 
    int uttor;
    cin>>uttor;
    if(uttor==-1){
        exit(0);
    }
    return uttor;
}

void solve(){
    int n;
    cin>>n;
    
    if(singleQuery(1,2)==1){
        cout<<"! 1"<<endl; 
        return;
    }
    if(singleQuery(2,3)==1){ 
        cout<<"! 2"<<endl; 
        return;
    }
    if(singleQuery(1,3)==1){ 
        cout<<"! 3"<<endl;
        return;
    }
    
    for(int i=1;i<=n-2;i++){
        int u=2+2*i;
        int v=3+2*i;
        if(singleQuery(u,v)==1){
            cout<<"! "<<u<<endl;
            return;
        }
    }
    
    cout<<"! "<<2*n<<endl;
}

int main(){
    FAST_IO
    
    int t;
    cin>>t;

    while (t--){
        solve();
    }
    
    return 0;
}