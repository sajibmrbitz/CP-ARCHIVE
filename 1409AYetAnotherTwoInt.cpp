#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long a,b;
    cin>>a>>b;
    cout<<(abs(a-b)+10-1)/10<<"\n";    //ceil of difference and 10
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}



/*
You are given two integers a and b.

In one move, you can choose some integer k from 1 to 10 and add it to a or subtract it from a. 
In other words, you choose an integer k∈[1;10] and perform a:=a+k or a:=a−k. 
You may use different values of k in different moves.

Your task is to find the minimum number of moves required to obtain b from a.
You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤2⋅104) 
— the number of test cases. Then t test cases follow.

The only line of the test case contains two integers a and b (1≤a,b≤109).

Output
For each test case, print the answer: the minimum number of moves required to obtain b from a.
*/