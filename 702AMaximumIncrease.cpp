#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,maxsublen=1,len=1;
    cin>>n;
    vector<int> v(n);
    for(int &x:v)     cin>>x;
   
    for(int i=1;i<n;i++){
        if(v[i]>v[i-1]){
            len++;
        }
        else len=1;
        maxsublen=max(maxsublen,len);
    }
    cout<<maxsublen<<"\n";
return 0;
//accepted
}



// idea: Traverse array and count length of longest strictly increasing subarray using sliding window//dp
// complexity: Time O(n), Space O(1)
// tags: arrays, sliding window, implementation
// source: Codeforces 702A - Maximum Increase
// edge cases: all elements equal, increasing at the end, single element



/*
You are given array consisting of n integers. Your task is to find the maximum length of an 
increasing subarray of the given array.

A subarray is the sequence of consecutive elements of the array. Subarray is called increasing 
if each element of this subarray strictly greater than previous.

Input
The first line contains single positive integer n (1 ≤ n ≤ 105) — the number of integers.
The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
Print the maximum length of an increasing subarray of the given array.

example input
5
1 7 2 11 15

output
3

input
6
100 100 100 100 100 100

output 
1
*/