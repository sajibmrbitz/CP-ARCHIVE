#include <bits/stdc++.h>
using namespace std;

#define YES cout<<"YES\n"
#define NO  cout <<"NO\n"


void solve() {
    int s,n;
    cin>>s>>n;

    vector<vector<int>> dragons(n,vector<int>(2));

    for(int i=0;i<n;i++){
        cin>>dragons[i][0]>>dragons[i][1]; 
    }

    // Sort dragons by strength (ascending)
    sort(dragons.begin(),dragons.end());

    for(int i=0;i<n;i++){
        int dragon_strength=dragons[i][0];
        int bonus=dragons[i][1];

        if (s>dragon_strength){
            s+=bonus;
        }
        else{
            NO;
            return;
        }
    }
    YES;
}

int main(){
    solve();
    return 0;
}

/*
Kirito is stuck on a level of the MMORPG he is playing now. To move on in the game, 
he's got to defeat all n dragons that live on this level. Kirito and the dragons have strength, 
which is represented by an integer. In the duel between two opponents the duel's outcome is determined 
by their strength. Initially, Kirito's strength equals s.

If Kirito starts duelling with the i-th (1 ≤ i ≤ n) dragon and Kirito's strength is not greater than 
the dragon's strength xi, then Kirito loses the duel and dies. But if Kirito's strength is greater than 
the dragon's strength, then he defeats the dragon and gets a bonus strength increase by yi.

Kirito can fight the dragons in any order. Determine whether he can move on to the next level of the game, 
that is, defeat all dragons without a single loss.

Input
The first line contains two space-separated integers s and n (1 ≤ s ≤ 104, 1 ≤ n ≤ 103). 
Then n lines follow: the i-th line contains space-separated integers xi and yi (1 ≤ xi ≤ 104, 0 ≤ yi ≤ 104) 
— the i-th dragon's strength and the bonus for defeating it.

Output
On a single line print "YES", if he can move on to next level and print "NO" if he can't.
*/