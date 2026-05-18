#include <bits/stdc++.h>
using namespace std;

#define YES cout<<"YES\n"
#define NO  cout <<"NO\n"

string upper(string &s){
    for(int i=0;i<s.length();i++){
        s[i]=toupper(s[i]);
    }
    return s;
}
void solve(){
    string s;
    cin>>s;
    upper(s);
    if(s=="YES"){
        YES;
    }
    else NO;
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
There is a string s of length 3, consisting of uppercase and lowercase English letters. 
Check if it is equal to "YES" (without quotes), where each letter can be in any case. 
For example, "yES", "Yes", "yes" are all allowable.

Input
The first line of the input contains an integer t (1≤t≤103) — the number of testcases.

The description of each test consists of one line containing one string s
consisting of 3 characters. Each character of s is either uppercase or lowercase English letter.

Output
For each test case, output "YES" (without quotes) if s satisfies the condition, 
and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings 
"yES", "yes" and "Yes" will be recognized as a positive response).

Example Input
10
YES
yES
yes
Yes
YeS
Noo
orZ
yEz
Yas
XES

Output
YES
YES
YES
YES
YES
NO
NO
NO
NO
NO

*/