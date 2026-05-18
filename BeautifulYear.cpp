#include <bits/stdc++.h>
using namespace std;


bool year(int t){
    int a,b,c,d;
    d=t%10;
    t/=10;
    b=t%10;
    t/=10;
    c=t%10;
    t/=10;
    a=t%10;
    t/=10;
    if(a==b || a==c || a==d || b==c || b==d || c==d){
        return false;
    }
    return true;

}

int main(){

    int n;
    cin>>n;
    while(n++){
        if(year(n)){
            cout<<n<<endl;
            break;
        }
    }
    return 0;
}

/*
It seems like the year of 2013 came only yesterday. Do you know a curious fact? 
The year of 2013 is the first year after the old 1987 with only distinct digits.

Now you are suggested to solve the following problem: given a year number, 
find the minimum year number which is strictly larger than the given one and has only distinct digits.

Input
The single line contains integer y (1000 ≤ y ≤ 9000) — the year number.

Output
Print a single integer — the minimum year number that is strictly larger than y 
and all it's digits are distinct. It is guaranteed that the answer exists.
*/