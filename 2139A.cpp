#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    int multi=0;
    if(a==b){
        multi=0;
    }
    else if((a%b==0) || (b%a==0)){
        multi=1;
    }
    else multi=2;

    cout<<multi<<endl;
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
Maple has two positive integers a and b. She may perform the following operation 
any number of times (possibly zero) to make a equal to b:

Choose any positive integer x, and multiply either a or b by x.
Your task is to determine the minimum number of operations required to make a equal to b. 
It can be proven that this is always possible.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). 
The description of the test cases follows.

The first and only line of each test case contains two positive integers a and b (1≤a,b≤1000) 
— the numbers Maple currently has.

Output
For each test case, output a single integer representing the minimum number of 
operations Maple needs to make a equal to b.

Example Input
3
1 2
10 3
1000 1000

Output
1
2
0

*/