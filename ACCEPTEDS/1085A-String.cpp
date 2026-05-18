#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int N;
    cin>>N;
    string s;
    cin>>s;
    
    vector<bool> unpossible(N,false);
    
    for(int i=0;i<N;i++){
        if(s[i]=='0'){
            if(i==0 || i==N-1 || s[i-1]=='0' || s[i+1]=='0'){
                unpossible[i]=true;
            }
        }
    }
    
    int min=0;
    int max=0;
    int currentLength=0;
    
    for(int i=0;i<N;i++){
        if(!unpossible[i]){
            currentLength++;
        }
        else{
            if(currentLength>0){
                min+=(currentLength/2)+1;
                max+=currentLength;
                currentLength=0;
            }
        }
    }
    
    if(currentLength>0){
        min+=(currentLength/2)+1;
        max=currentLength;
    }
    
    cout<<min<<" "<<max<<"\n";
    
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T--){
        solve();
    }
    
    return 0;
}
