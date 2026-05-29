#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> prefix(n+1,0);
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+a[i];
    }
    for(int l=1;l<n-1;l++){
        for(int r=l+1;r<n;r++){
            int sum1=prefix[l];
            int sum2=prefix[r]-prefix[l];
            int sum3=prefix[n]-prefix[r];

            int s1=sum1%3;
            int s2=sum2%3;
            int s3=sum3%3;

            bool allsame=(s1==s2 && s2==s3);
            bool different=(s1!=s2 && s1!=s3 && s2!=s3);
            if(allsame || different){
                cout<<l<<" "<<r<<endl;
                return; 
            }
        }
    }

    cout<<"0 0"<<endl;
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
A. Cut the Array
time limit per test : 2 seconds
memory limit per test : 512 megabytes
You are given an array of n non-negative integers [a1,a2,…,an].

Your task is to cut it into three non-empty parts: a prefix, a middle part, and a suffix. 
Formally, you need to choose two integers l and r such that 1≤l<r<n, and obtain three parts:
the prefix upto the element at index l inclusive (i.e., [a1,a2,…,al]);
the central part from the element at index l+1 to the element at index r inclusive (i.e., [al+1,al+2,…,ar]);
the suffix from the element at index r+1 to n inclusive (i.e., [ar+1,ar+2,…,an]).
Let s1,s2,s3 be the remainders of the sums of these parts modulo 3. In other words:

s1=(∑i=1 to l ai)mod3; s2=(∑i=l+1 to r ai)mod3; s3=(∑i=r+1 to n ai)mod3;
Your task is to find such boundaries l and r that either all s1,s2,s3 are different or the same.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.
Each test case consists of two lines:

the first line contains a single integer n (3≤n≤40);
the second line contains n integers a1,a2,…,an (0≤ai≤40).
Output
For each test case, if a suitable pair of integers l and r (1≤l<r<n) exists, output these two integers 
(if there are multiple suitable pairs, you can output any of them). Otherwise, output two 0s.

Example Input
4
6
1 2 3 4 5 6
4
1 3 3 7
3
2 1 0
5
7 2 6 2 4

Output
3 5
0 0
1 2
2 4

*/