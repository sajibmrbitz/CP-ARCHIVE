#include <bits/stdc++.h>
using namespace std;

int digitsum(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void solve(){
    string s;
    cin>>s;

    int n=stoi(s);
    int first=n/1000;
    int last=n%1000;

    first=digitsum(first);
    last=digitsum(last);
    
    if(first==last)     cout<<"YES"<<endl;
    else                cout<<"NO"<<endl;

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
A ticket is a string consisting of six digits. A ticket is considered lucky if the sum of the 
first three digits is equal to the sum of the last three digits. Given a ticket, output if 
it is lucky or not. Note that a ticket can have leading zeroes.

Input
The first line of the input contains an integer t (1≤t≤103) — the number of testcases.

The description of each test consists of one line containing one string consisting of six digits.

Output
Output t lines, each of which contains the answer to the corresponding test case. 
Output "YES" if the given ticket is lucky, and "NO" otherwise.

*/