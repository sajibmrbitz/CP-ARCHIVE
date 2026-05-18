#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> polys(n);
    long long faces=0;
    for(int i=0;i<n;i++){
        cin>>polys[i];
        if(polys[i]=="Tetrahedron")         faces+=4;
        else if(polys[i]=="Cube")           faces+=6;
        else if(polys[i]=="Octahedron")     faces+=8;
        else if(polys[i]=="Dodecahedron")   faces+=12;
        else if(polys[i]=="Icosahedron")    faces+=20;
    }

    cout<<faces<<endl;
    return 0;
}