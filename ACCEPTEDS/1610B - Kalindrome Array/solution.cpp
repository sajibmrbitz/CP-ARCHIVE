#include <bits/stdc++.h>
using namespace std;

#define YES cout<<"YES\n"
#define NO  cout <<"NO\n"

bool palindrome(vector<int> v){
    int l=0,r=v.size()-1;
    while(l<r){
        if(v[l]!=v[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

bool check(const vector<int>& v, int skip) {
    vector<int> temp;
    for(int x:v){
        if(x!=skip) temp.push_back(x);
    }
    return palindrome(temp);
}

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x:v)   cin>>x;
    if(palindrome(v)){
        YES;
        return;
    }

    int l=0,r=n-1;
    while(l<r && v[l]==v[r]){
        l++;
        r--;
    }
    if(l>=r){
        YES;
        return;
    }

    if(check(v,v[l]) || check (v,v[r]))       YES;
    else                                      NO;


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
An array [b1,b2,…,bm] is a palindrome, if bi=bm+1−i for each i from 1 to m. Empty array is also a palindrome.

An array is called kalindrome, if the following condition holds:
It's possible to select some integer x and delete some of the elements of the array equal to x, 
so that the remaining array (after gluing together the remaining parts) is a palindrome.

Note that you don't have to delete all elements equal to x, and you don't have to 
delete at least one element equal to x.

For example :

[1,2,1] is kalindrome because you can simply not delete a single element.[3,1,2,3,1] is 
kalindrome because you can choose x=3 and delete both elements equal to 3,[1,2,1] is a palindrome.
[1,2,3] is not kalindrome.
You are given an array [a1,a2,…,an]. Determine if a is kalindrome or not.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of the array.
The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — elements of the array.

It's guaranteed that the sum of n over all test cases won't exceed 2⋅105.

Output
For each test case, print YES if a is kalindrome and NO otherwise. You can print each letter in any case.
*/