#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n,m;
    cin>>n>>m;
    vector<int> tasks(m);
    for(int &x:tasks)   cin>>x;
    
    long long times=tasks[0]-1;
    for( int i=0;i<m-1;i++){
        if(tasks[i+1]<tasks[i])     times+=n-tasks[i]+tasks[i+1];
        else                        times+=tasks[i+1]-tasks[i];
    }

    cout<<times<<endl;

    return 0;
}

/*
Xenia lives in a city that has n houses built along the main ringroad. The ringroad houses 
are numbered 1 through n in the clockwise order. The ringroad traffic is one way and clockwise.

Xenia has recently moved into the ringroad house number 1. As a result, she's got m things to do. 
In order to complete the i-th task, she needs to be in the house number ai and complete all tasks with 
numbers less than i. Initially, Xenia is in the house number 1, find the minimum time she needs to 
complete all her tasks if moving from a house to a neighboring one along the ringroad takes one unit of time.

Input
The first line contains two integers n and m (2 ≤ n ≤ 105, 1 ≤ m ≤ 105). 
The second line contains m integers a1, a2, ..., am (1 ≤ ai ≤ n). Note that Xenia can have 
multiple consecutive tasks in one house.

Output
Print a single integer — the time Xenia needs to complete all tasks.

Example Input
4 3
3 2 3

Output
6

Input
4 3
2 3 3

Output
2

*/