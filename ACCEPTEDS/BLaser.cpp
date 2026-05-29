#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fori(i,a,b) for(int i=(a);i<(b);i++)
#define forj(j,a,b) for(int j=(a);j<(b);j++)
#define YES cout<<"YES\n"
#define NO  cout <<"NO\n"

#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
#define dbg(x)
#endif

void solve(){
    int n,m;
    long long x,y;
    cin>>n>>m>>x>>y;

    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    cout<<n+m<<"\n";

}


int main(){
    FAST_IO

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
There is a 2D-coordinate plane that ranges from (0,0) to (x,y). You are located at (0,0) and want to head to (x,y).

However, there are n horizontal lasers, with the i-th laser continuously spanning (0,ai) to (x,ai). 
Additionally, there are also m vertical lasers,the i-th laser continuously spanning (bi,0) to (bi,y).

You may move in any direction to reach (x,y), but your movement must be a continuous curve that lies 
inside the plane. Every time you cross a vertical or a horizontal laser, it counts as one crossing. 
Particularly, if you pass through an intersection point between two lasers, it counts as two crossings.


What is the minimum number of crossings necessary to reach (x,y)


Input
The first line contains t (1≤t≤104)  — the number of test cases.
The first line of each test case contains four integers n, m, x, and y (1≤n,m≤2⋅105,2≤x,y≤109).

The following line contains n integers a1,a2,…,an (0<ai<y)  — the y-coordinates of the horizontal lasers. 
It is guaranteed that ai>ai−1 for all i>1.

The following line contains m integers b1,b2,…,bm (0<bi<x)  — the x-coordinates of the vertical lasers. 
It is guaranteed that bi>bi−1 for all i>1.

It is guaranteed that the sum of n and m over all test cases does not exceed 2⋅105.

Output
For each test case, output the minimum number of crossings necessary to reach (x,y).

Example Input
2
1 1 2 2
1
1
2 1 100000 100000
42 58
32

Output
2
3
*/