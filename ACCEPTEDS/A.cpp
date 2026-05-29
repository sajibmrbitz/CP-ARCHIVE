#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k,x;
    cin>>k>>x;

    while(k--){
        if((x-1)%3==0){
            int prev=(x-1)/3;
            if(prev%2){
                x=prev;
                continue;
            }
        }
        x*=2;
    }

    cout<<x<<"\n"; 
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
You are doing a research paper on the famous Collatz Conjecture. In your experiment, 
you start off with an integer x, and you do the following procedure k times:

If x is even, divide x by 2.
Otherwise, set x to 3⋅x+1.
For example, starting off with 21 and doing the procedure 5 times, you get 21→64→32→16→8→4.

After all k iterations, you are left with the final value of x.Unfortunately, 
you forgot the initial value. Please output any possible initial value of x.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤400). 
The description of the test cases follows.

The first line of each test case contains two integers k and x (1≤k,x≤20).

Output
For each test case, print any possible initial value on a new line. 
It can be shown that the answer always exists.

Example Input
3
1 4
1 5
5 4
Output
1
10
21

*/