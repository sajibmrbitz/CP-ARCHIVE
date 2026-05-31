#include <bits/stdc++.h>
using namespace std;

#define YES cout<<"YES\n"
#define NO  cout <<"NO\n"

void solve(){
    long long n;
    cin>>n;
    if(n%4!=0){
        NO;
        return;
    }
    
    YES;
    vector<long long> v(n);
    long long evensum=0,oddsum=0;
    for(auto i=0;i<n/2;i++){
        v[i]=2*(i+1);
        evensum+=v[i];
    }
    for(auto i=0;i<n/2-1;i++){
        v[(n/2)+i]=(2*i)+1;
        oddsum+=v[(n/2)+i];
    }
    v[n-1]=evensum-oddsum;

    for(auto x:v)    cout<<x<<" ";
    cout <<endl;

}

int main(){

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
You are given a positive integer n, it is guaranteed that n is even (i.e. divisible by 2).

You want to construct the array a of length n such that:
The first n2 elements of a are even (divisible by 2);
the second n2 elements of a are odd (not divisible by 2);
all elements of a are distinct and positive;
the sum of the first half equals to the sum of the second half.
If there are multiple answers, you can print any. It is not guaranteed that the answer exists.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases.

The only line of the test case contains one integer n (2≤n≤2⋅105) — the length of the array. 
It is guaranteed that that n is even (i.e. divisible by 2).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105 (∑n≤2⋅105).

Output
For each test case, print the answer — "NO" (without quotes), if there is no suitable answer 
for the given test case or "YES" in the first line and any suitable array a1,a2,…,an (1≤ai≤109) 
satisfying conditions from the problem statement on the second line.

Example input
6
2
4
6
8
10
12

Output
NO
YES
2 4 1 5 
NO
YES
2 4 6 8 1 3 5 11 
NO
YES
2 4 6 8 10 12 1 3 5 7 9 17 
*/