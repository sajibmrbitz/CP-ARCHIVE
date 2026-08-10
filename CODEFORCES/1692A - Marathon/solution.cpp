#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ahead=0;
    if(b>a)     ahead++;
    if(c>a)     ahead++;
    if(d>a)     ahead++;

    cout<<ahead<<endl;
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
You are given four distinct integers a, b, c, d.

Timur and three other people are running a marathon. The value a is the distance that 
Timur has run and b, c, dcorrespond to the distances the other three participants ran.

Output the number of participants in front of Timur.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The description of each test case consists of four distinct integers a, b, c, d (0≤a,b,c,d≤104).

Output
For each test case, output a single integer — the number of participants in front of Timur.
*/