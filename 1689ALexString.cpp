#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second
#define fori(i,a,b) for(int i = (a); i < (b); ++i)
#define forj(j,a,b) for(int j = (a); j < (b); ++j)

// ---------- Debug (toggle with #define DEBUG) ----------
#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
#define dbg(x)
#endif

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    string a,b,c;
    cin>>a>>b;

    sort(all(a));
    sort(all(b));
    int i=0,j=0,counta=0,countb=0;
    while(i<n && j<m){
        if(a[i]<b[j] && counta<k || countb==k){
            c+=a[i];
            i++;
            counta++;
            countb=0;
        }
        else{
            c+=b[j];
            j++;
            countb++;
            counta=0;
        }
    }
    cout<<c<<"\n";
}

int main() {
    FAST_IO

    #ifndef ONLINE_JUDGE
    // Local testing: read from input.txt, write to output.txt
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


// idea: two pointer,sorting string
// while respecting the k-limit on consecutive picks from the same string.
// complexity: Time O(n + m), Space O(n + m)
// tags: greedy, strings, sorting, two pointers
// source: Codeforces 1689A (798-Div. 2) - Lex String
// edge cases: equal chars at current positions, one string exhausted early, forced switch due to k-limit


/*
Kuznecov likes art, poetry, and music. And strings consisting of lowercase English letters.

Recently, Kuznecov has found two strings, a and b, of lengths n and m respectively. 
They consist of lowercase English letters and no character is contained in both strings.

Let another string c be initially empty. Kuznecov can do the following two types of operations:

Choose any character from the string a, remove it from a, and add it to the end of c.
Choose any character from the string b, remove it from b, and add it to the end of c.
But, he can not do more than k operations of the same type in a row.
He must perform operations until either a or b becomes empty. 
What is the lexicographically smallest possible value of c after he finishes?

A string x is lexicographically smaller than a string y if and only if one of the following holds:
x is a prefix of y, but x≠y;
in the first position where x and y differ, the string x has a letter that appears earlier 
in the alphabet than the corresponding letter in y.
Input
There are several test cases in the input data. The first line contains a single integer t (1≤t≤100) 
— the number of test cases. This is followed by the test cases description.

The first line of each test case contains three integers n, m, and k (1≤n,m,k≤100) 
— parameters from the statement.
The second line of each test case contains the string a of length n.
The third line of each test case contains the string b of length m.
The strings contain only lowercase letters, guaranteed that no symbol appears in a and b simultaneously.

Output
In each test case, output a single string c — the answer to the problem.

Example Input
3
6 4 2
aaaaaa
bbbb
5 9 3
caaca
bedededeb
7 7 1
noskill
wxhtzdy

Example Output
aabaabaa
aaabbcc
dihktlwlxnyoz

*/
