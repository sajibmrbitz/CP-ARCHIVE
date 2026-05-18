#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int &x:v)   cin>>x;
    bool possible =false;
    for(int x:v){
        if(x==k){
            possible=true;
            break;
        }
    }
    if(possible)    cout<<"YES"<<endl;
    else            cout<<"NO"<<endl;
}

int main() {

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


/*
We define an integer to be the most common on a subsegment, if its number of occurrences on 
that subsegment is larger than the number of occurrences of any other integer in that subsegment. 
A subsegment of an array is a consecutive segment of elements in the array a.

Given an array a of size n, and an integer k, determine if there exists a non-empty subsegment of a
where k is the most common element.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤1000) 
— the number of test cases. The description of test cases follows.

The first line of each test case contains two integers n and k (1≤n≤100, 1≤k≤100) 
— the number of elements in array and the element which must be the most common.

The second line of each test case contains n integers a1, a2, a3, …, an (1≤ai≤100) — elements of the array.

Output
For each test case output "YES" if there exists a subsegment in which k is the most common element, 
and "NO" otherwise.
*/