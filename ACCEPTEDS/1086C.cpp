#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define nl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define YES cout << "YES\n"
#define NO  cout << "NO\n"

void solve() {
    int n;
    cin>>n;
    vector<int> c(n),p(n);
    for(int i=0;i<n;i++){
        cin>>c[i]>>p[i];
    }

    double maximum=0.0;

    for(int i=n-1;i>=0;i--){
        double complete=c[i]+(1.0-p[i]/100.0)*maximum;
        maximum=max(maximum,complete);
    }
    printf("%.10f\n",maximum);

}

int main() {
    FAST_IO

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}