#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> percentages(n);
    double sum=0;
    for(int i=0;i<n;i++){
        cin>>percentages[i];
        sum+=percentages[i];
    }

    double finalpercentage=sum/n;


    cout<<finalpercentage<<"\n";
}   