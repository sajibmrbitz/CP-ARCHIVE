#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define nl '\n'


void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int wp = a[p-1];

    // Phase 1: initial cost to bring win-condition into first k slots
    int init_cost = wp;
    if(p > k){
        vector<int> before(a.begin(), a.begin() + p - 1);
        sort(before.begin(), before.end());
        for(int i = 0; i < p - k; i++) init_cost += before[i];
    }

    if(init_cost > m){
        cout << 0 << nl;
        return;
    }

    int remaining = m - init_cost;
    int plays = 1;

    // Phase 2: cycle cost = wp + sum of (n-k) cheapest non-win-condition cards
    int cycle_cost = wp;
    if(n > k){
        vector<int> others;
        for(int i = 0; i < n; i++)
            if(i != p-1) others.push_back(a[i]);
        sort(others.begin(), others.end());
        for(int i = 0; i < n - k; i++) cycle_cost += others[i];
    }

    plays += remaining / cycle_cost;
    cout << plays << nl;
}

int main() {
    FAST_IO

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}