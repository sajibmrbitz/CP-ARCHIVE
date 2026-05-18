#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        string a,b,c;
        cin>>a>>b;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0,j=0,counta=0,countb=0;
        while(i<n && j<m){
            if(a[i]<b[j] && counta<k || countb==k){
                c+=a[i];
                i++;
                counta++;
                countb=0;
            }
            else{
                c+=b[j];
                j++;
                countb++;
                counta=0;
            }
        }
        cout<<c<<"\n";
    }

return 0;
}