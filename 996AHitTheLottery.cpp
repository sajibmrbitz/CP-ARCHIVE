#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int notes=0;
    int dollars[5]={1,5,10,20,100};
    int idx=4;
    while(n){
        if(dollars[idx]<=n){
            notes++;
            n-=dollars[idx];
        }
        else  idx--;
    }

    cout<<notes<<"\n";
    
    return 0;
}

/*
Allen has a LOT of money. He has n dollars in the bank. For security reasons, he wants to withdraw 
it in cash (we will not disclose the reasons here). 
The denominations for dollar bills are 1, 5, 10, 20, 100. 
What is the minimum number of bills Allen could receive after withdrawing his entire balance?

Input
The first and only line of input contains a single integer n (1≤n≤109).

Output
Output the minimum number of bills that Allen could receive.
*/