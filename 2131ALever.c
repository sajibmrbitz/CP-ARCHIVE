#include <stdio.h>
#include <stdlib.h>

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){

    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int iteration=1;    //1 iteration is must and the last iteration doeas not do i++
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            iteration+=a[i]-b[i];
        }
    }
    printf("%d\n",iteration);
    }

return 0;
//accepted
}
/*
In Divergent Universe, The Lever iterates itself given two arrays a and b of length n. 
In each iteration, The Lever will do the following:

Choose a random index i such that ai>bi. Then, decrease ai by 1. 
If there does not exist such i, ignore this step.
Choose a random index i such that ai<bi. Then, increase ai by 1. 
If there does not exist such i, ignore this step.
After each iteration, the Lever will check if step 1 is ignored, 
and if so, it will end its iteration.

You're given the two arrays. Find the number of iterations that the Lever does. 
It can be shown this number is fixed over all possibilities of random indices that 
the Lever can choose for each step.

Input
Each test contains multiple test cases. The first line contains 
the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains one integer n (1≤n≤10).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤10).

The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤10).

Output
For each test case, output one integer — the number of iterations that the Lever does.

Example Input
4
2
7 3
5 6
3
3 1 4
3 1 4
1
10
1
6
1 1 4 5 1 4
1 9 1 9 8 1

Example Output
3
1
10
7
*/