#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define nl '\n'

void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        int danpasherCount=0;
        int bampasherCount=0;
        
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                danpasherCount++;
            }
            else if(a[j]<a[i]){
                bampasherCount++;
            }
        }
        
        cout<<max(danpasherCount,bampasherCount)<<(i==n-1?"":" ");
    }

    cout<<nl;
}

int main() {
    FAST_IO

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}
