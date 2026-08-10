#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int moves=(n+1)/2;
    int result=-1;

    for(int i=moves;i<=n;++i){
        if(i%m==0){
            result=i;
            break;
        }
    }

    cout<<result<<endl;
    return 0;
}

/*
Dreamoon wants to climb up a stair of n steps. He can climb 1 or 2 steps at each move. 
Dreamoon wants the number of moves to be a multiple of an integer m.
What is the minimal number of moves making him climb to the top of the stairs that satisfies his condition?

Input
The single line contains two space separated integers n, m (0 < n ≤ 10000, 1 < m ≤ 10).

Output
Print a single integer — the minimal number of moves being a multiple of m. 
If there is no way he can climb satisfying condition print  - 1 instead.

input : 10 2
output: 6

input : 18 10
output:10

input : 3 5
output: -1
*/
