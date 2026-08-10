#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,s; 
    cin>>n>>s;                
    int coinsUsed=0;
    while(n){
        if(n>s){
            n--; 
            continue;   
        }
        s-=n;
        coinsUsed++;
    }
    cout<<coinsUsed;

    //accepted
    return 0;
}



/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,s; 
    cin>>n>>s;                
    int coinsUsed=(s+n-1)/n;        //ceil value of s and n
    cout<<coinsUsed;

    return 0;
}
*/

/*
You have unlimited number of coins with values 1,2,…,n. You want to select 
some set of coins having the total value of S.

It is allowed to have multiple coins with the same value in the set. 
What is the minimum number of coins required to get sum S?

Input
The only line of the input contains two integers n and S (1≤n≤100000, 1≤S≤109)

Output
Print exactly one integer — the minimum number of coins required to obtain sum S.
*/