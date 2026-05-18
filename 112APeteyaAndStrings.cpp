#include <bits/stdc++.h>
using namespace std;
 

string lower(string &s){
    for(int i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
    }
    return s;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;

    s1=lower(s1);
    s2=lower(s2);
    int c=s1.compare(s2);
    if(c>0)          cout<<"1";
    else if(c<0)     cout<<"-1";
    else             cout<<"0";

    return 0;
}