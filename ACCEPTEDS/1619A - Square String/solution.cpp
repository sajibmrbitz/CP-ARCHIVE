#include <bits/stdc++.h>
using namespace std;

#define YES cout<<"YES\n"
#define NO  cout <<"NO\n"

void solve(){
    string s,temp;
    cin>>s;
    temp=s;
    int n=s.length();
    s.resize(n/2);
    for(int i=0;i<n/2;i++){
        s.push_back(s[i]);
    }

    if(s==temp)     YES;
    else            NO;

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
A string is called square if it is some string written twice in a row. For example, 
the strings "aa", "abcabc", "abab" and "baabaa" are square. But the strings 
"aaa", "abaaab" and "abcdabc" are not square.

For a given string s determine if it is square.

Input
The first line of input data contains an integer t (1≤t≤100) —the number of test cases.

This is followed by t lines, each containing a description of one test case. The given strings 
consist only of lowercase Latin letters and have lengths between 1 and 100 inclusive.

Output
For each test case, output on a separate line:

YES if the string in the corresponding test case is square,
NO otherwise.
*/