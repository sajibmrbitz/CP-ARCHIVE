#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// বাকি থাকা ফ্লেমগুলোর স্কোর হিসাব করার জন্য স্ট্রাকচার
struct Score {
    int v1, v2, v3;
    bool operator<(const Score& o) const {
        if (v1 != o.v1) return v1 < o.v1;
        if (v2 != o.v2) return v2 < o.v2;
        return v3 < o.v3;
    }
};

// ফ্লেমগুলোর সংখ্যা বড় থেকে ছোট সাজিয়ে স্কোর বের করা
Score get_score(int a, int b, int c) {
    int mx = max({a, b, c});
    int mn = min({a, b, c});
    int md = a + b + c - mx - mn;
    return {mx, md, mn};
}

void solve() {
    int R, G, B;
    cin >> R >> G >> B;

    // সর্বোচ্চ কতগুলো ব্যবহার করা যাবে তা বের করা
    int mx_c = max({R, G, B});
    int others = R + G + B - mx_c;
    if (mx_c > others + 1) {
        if (R == mx_c) R = others + 1;
        else if (G == mx_c) G = others + 1;
        else B = others + 1;
    }
    
    int L = R + G + B;
    if (L == 0) {
        cout << "\n";
        return;
    }

    vector<int> counts = {R, G, B};
    string res = "";
    vector<int> s(L);

    for (int i = 0; i < L; ++i) {
        // বাধ্যতামূলক অবস্থা
        if (i >= 3 && s[i-1] != s[i-3]) {
            int forced_c = s[i-2];
            s[i] = forced_c;
            counts[forced_c]--;
        } 
        // পছন্দের অবস্থা
        else {
            int best_c = -1;
            Score best_score = {10000000, 10000000, 10000000};

            for (int c = 0; c < 3; ++c) {
                if (i >= 1 && c == s[i-1]) continue;
                if (counts[c] == 0) continue;

                vector<int> temp = counts;
                temp[c]--;
                bool valid = true;

                // 1-step Lookahead: এই পছন্দটি কি পরের ধাপকে বাধ্য করছে?
                if (i + 1 < L) {
                    if (i >= 2 && c != s[i-2]) {
                        if (temp[s[i-1]] == 0) {
                            valid = false; // বাধ্য করার মতো ফ্লেম অবশিষ্ট নেই
                        } else {
                            temp[s[i-1]]--;
                        }
                    }
                }

                if (!valid) continue;

                // লেক্সিকোগ্রাফিকালি সবচেয়ে ছোট (ব্যালেন্সড) স্কোর বের করা
                Score sc = get_score(temp[0], temp[1], temp[2]);
                if (sc < best_score) {
                    best_score = sc;
                    best_c = c;
                }
            }
            s[i] = best_c;
            counts[best_c]--;
        }
    }

    string chars = "RGB";
    for (int i = 0; i < L; ++i) {
        res += chars[s[i]];
    }
    cout << res << "\n";
}

int main() {
    FAST_IO
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

/*
B
RGB
G
GBRBRG
GRGRGBGBGBG
*/