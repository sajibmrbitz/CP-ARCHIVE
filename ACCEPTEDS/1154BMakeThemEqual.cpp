#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int &x:v) cin>>x;

    int res=-1;
    for(int D=0;D<=100;D++){
        set<int> candidates;
        for(int i=0;i<n;i++){
            candidates.insert(v[i]);
            candidates.insert(v[i]+D);
            candidates.insert(v[i]-D);
        }

        for(int target:candidates){
            bool valid=true;
            for(int i=0;i<n;i++){
                int diff=abs(v[i]-target);
                if(diff!=0 && diff!=D){
                    valid=false;
                    break;
                }
            }
            if (valid){
                res=D;
                goto done;
            }
        }
    }
done:
    cout<<res<<"\n";
    return 0;
    //accepted
}



// idea: Try all possible D and check if all elements can be transformed to a common value using ±D or 0
// complexity: Time O(n * maxD), Space O(n)
// tags: brute force, greedy transformation
// source: Equalize with ±D – Codeforces 1204/A
// edge cases: all equal, multiple valid D, no valid D




/*
You are given a sequence a1,a2,…,an consisting of n integers.

You can choose any non-negative integer D (i.e. D≥0 , and for each ai you can:
add D (only once), i. e. perform ai:=ai+D, or
subtract D (only once), i. e. perform ai:=ai−D, or
leave the value of ai unchanged.
It is possible that after an operation the value ai becomes negative.

Your goal is to choose such minimum non-negative integer D and perform changes in such a way, 
that all ai are equal (i.e. a1=a2=⋯=an).

Print the required D or, if it is impossible to choose such value D, print -1.

For example, for array [2,8] the value D=3 is minimum possible because you can obtain the array [5,5]
if you will add D to 2 and subtract D from 8. And for array [1,4,7,7] the value D=3
is also minimum possible. You can add it to 1 and subtract it from 7 and obtain the array [4,4,4,4].

Input
The first line of the input contains one integer n (1≤n≤100) — the number of elements in a.

The second line of the input contains n integers a1,a2,…,an (1≤ai≤100) — the sequence a.

Output
Print one integer — the minimum non-negative integer value D such that if you add this value 
to some ai, subtract this value from some ai and leave some ai without changes, all obtained values become equal.

If it is impossible to choose such value D, print -1.
*/