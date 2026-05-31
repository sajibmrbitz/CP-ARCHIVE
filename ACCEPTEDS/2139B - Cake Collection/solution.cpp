#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> times(n);
    for(auto &x:times)    cin>>x;

    sort(times.rbegin(),times.rend()); 
    long long k=min((long long)n,m);
    long long ans=0;
    for (long long i=0;i<k;i++){
        ans+=times[i]*(m-i);
    }

    cout<<ans<<"\n";

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
Maple wants to bake some cakes for Chocola and Vanilla.

One day, she discovers n magical cake ovens. The i-th oven bakes ai cakes every second. 
The cakes remain in their respective ovens until they are collected.

At the end of each second, she may teleport to any oven (including the one she is currently at) 
and collect all the cakes that have accumulated in that oven up to that point.

Your task is to determine the maximum number of cakes Maple can collect in m seconds.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). 
The description of the test cases follows.

The first line of each test case contains two integers n and m (1≤n≤105, 1≤m≤108) 
— the number of magical ovens and the number of seconds during which Maple will collect cakes.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤105) 
— the number of cakes the i-th oven bakes every second.
It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output a single integer representing the maximum number of cakes 
Maple can collect in m seconds.
*/