
#include <stdio.h>

void dream(int a,int b,int c,int d);
int main(){
    int t,a,b,c,d;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        dream(a,b,c,d);
    }
return 0;
}

void dream(int a,int b,int c,int d){
    if(a<=2*(b+1) && b<=2*(a+1) && (c-a)<=2*(d-b+1) && (d-b)<=2*(c-a+1)){
        printf("YES\n");
    }
    else printf("NO\n");
    //accepted
}


//idea: Aquawave's dream validation — no team scores 3 consecutive goals per half
//complexity: O(1) per test case, total O(t)
//tags: implementation, constraints checking, football simulation
//source: Codeforces Round 1046-A (Div. 2)
//edge cases:
//  a = b = c = d = 0 → YES (no goals at all)
//  a = c, b = d → second half unchanged → check first half only
//  max goals (100) with minimal opponent goals → likely NO due to 3+ streaks



/*
Two football teams, the RiOI team and the KDOI team, are about to have a football match. 
A football match consists of two halves — the first half and the second half. At the beginning of the match, 
both teams have a score of 0.

As a fan of both teams, Aquawave knows that the two teams have similar levels, 
so neither team will score three consecutive goals in the same half.

Aquawave had a dream the night before the match, in which:
The score at the end of the 1st half was a:b, where a is the score of the RiOI team, and b is the score of the KDOI team;
and score at the end of the 2nd half was c:d where c is the score of the RiOI team and d is the score of the KDOI team.
You have to determine whether Aquawave's dream can come true according to the above information.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). 
The description of the test cases follows.

The only line of each test case contains four integers a, b, c, and d (0≤a≤c≤100, 0≤b≤d≤100) — 
the score at the end of the first half and the score at the end of the second half.

Output
For each test case, print "YES" if Aquawave's dream can come true. Otherwise, print "NO".

You can output the ans in any case (upper or lower)the strings "yEs", "yes", "Yes", and "YES" will be recognized same

Example Input
11
1 4 1 4
4 1 4 1
1 4 2 5
0 100 0 100
1 4 2 9
3 1 13 5
8 11 17 36
19 41 30 50
20 38 30 60
0 0 0 0
100 100 100 100

Example Output
YES
YES
YES
NO
NO
YES
NO
NO
YES
YES
YES
*/