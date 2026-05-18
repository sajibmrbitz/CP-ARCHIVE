#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> nums;
    for(char c:s){
        if(c!='+')      nums.push_back(c);
    }

    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i)   cout<<'+';
        cout<<nums[i]-'0';
    }
    cout<<endl;
    //acepted
return 0;
}


//input : 3+2+1  output: 1+2+3

/*
    vector<char> nums;
    for (char c : s) {
        if (c != '+') nums.push_back(c);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i) cout << '+';
        cout << nums[i];
    }
    cout << "\n";
    return 0;
*/