#include <bits/stdc++.h>
using namespace std;

int main(){
    long long X;
    int C;
    cin>>X>>C;

    long long low=0,high=X/1000,withdraw=0;
    while(low<=high){
        long long mid=(low+high)/2;
        long long totalcost=mid*(1000+C);
        if(totalcost<=X){
            withdraw=mid;
            low=mid+1;
        } 
        else{
            high=mid-1;
        }
    }

    cout<<withdraw*1000<<"\n";
    return 0;
}


/*
You have a bankbook from The Terrifying Bank. The deposit passbook of the bank has a terrifyingly scary 
property that the commission fee changes according to the withdrawal amount.

To withdraw money from the passbook, you need to specify the withdrawal amount in units of 
1000 yen, and pay a commission fee of C yen per 1000 yen of withdrawal amount separately from the balance. 
Withdrawals are not allowed if they would leave the balance below 0 yen.

When the balance of your passbook from the bank is X yen, 
what is the maximum amount of money you can withdraw from it?

Constraints
1≤X≤10^7
 
1≤C≤999
All input values are integers.
*/