#include <stdio.h>

int main() {
int t;
scanf("%d",&t);

while (t--){
    long long n;
    scanf("%lld",&n);
    long long cost=0;
    int x=0;
    long long p3_x_minus_1 = 0; // 3^(x-1)
    long long p3_x = 1;         // 3^x
    while (n>0)
    {
        int digit=n%3;
        if (digit>0) {
            long long deal_cost;
            if(x==0){
                deal_cost=3;
            }
            else{
                long long p3_x_plus_1=p3_x*3;
                deal_cost=p3_x_plus_1+(long long)x*p3_x_minus_1;
            }
        cost+=(long long)digit*deal_cost;
        }
        n/=3;
        x++;
        p3_x_minus_1=p3_x;
        p3_x*=3;
    }
    printf("%lld\n",cost);
}
    //accepted
return 0;
}
/*
After the cunning seller sold three watermelons instead of one, 
he decided to increase his profit — namely, he bought even more watermelons. 
Now he can sell 3x watermelons for 3x+1+x⋅3x−1 coins, where x
is a non-negative integer. Such a sale is called a deal.

A calculating buyer came to him, but he has critically little time.
Because of this, he wants to buy exactly nwatermelons,
making the least possible number of deals.

The buyer is in a hurry and has therefore turned to you to determine
the minimum number of coins he must pay the seller for n watermelons, 
considering that he will make the least possible number of deals.

Input
The first line contains an integer t (1≤t≤104)
— the number of test cases. The description of each test case follows.

In a single line of each test case, there is one integer n
(1≤n≤109)
— how many watermelons need to be bought.

Output
For each test case, output a single integer — the minimum cost of the watermelons.

Example Input
7
1
3
8
2
10
20
260010000

Example Output
3
10
26
6
36
72
2250964728


Note that there is no point in buying more watermelons than needed, 
so we won't consider deals where there are more watermelons than necessary.
Let's consider the costs of the first two deal options:

Deal A: 1 watermelon — 3 coins.

Deal B: 3 watermelons — 10 coins.

In the first sample, the only way to buy 1 watermelon is to use Deal A, so the answer is 3.

In the second sample, you can buy 3 watermelons with a single Deal B for 10 coins.

In the third sample, you can make 2 Deals A and 2 Deals B, which will cost a total of 26
coins. If we make 3 deals, we can get 3, 5, 7, or 9 watermelons. 
If we make fewer than 3 deals, we will get no more than 6 watermelons, 
which means it is impossible to buy 8 watermelons for less than 4 deals.

*/