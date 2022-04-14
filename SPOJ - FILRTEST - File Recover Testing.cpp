#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

ll Log(int x) { return 31 - __builtin_clz(x); }

ll lcm(ll a, ll b) { return (b / __gcd(a, b)) * a; }

#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int MOD = 1e9 + 7;
int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f;
const int N = 1e5 + 5;

// only god know what happens in there

vector<int> bulidPrefix(string s) {
    int n = s.size();
    vector<int> prefix(n);
    prefix[0] = 0;
    int border = 0;
    /// border is the maximum prefix = suffix   , *NOTE* // the border must be less than the whole length
    /// a b x a b y a b x a b x
    //  0 0 0 1 2 0 1 2 3 4 5 3

    for (int i = 1; i < n; i++) {
        /// i will see if i can expand from now or not !
        while (border > 0 and s[i] != s[border])
            border = prefix[border - 1];
        /// if the current char that i want to expand with not equal s[border]
        /// then i will see the prev border until i reach the 0  then break or find border = current
        /// EX : abxabxy
        // a    --> border = 0
        // a ,b --> border = 0
        // a,b,x--> border = 0
        // a b x a --> border = 1
        // a b x a b--> border = 2
        // a b x a b x-->  border = 3
        // abxabxy -- > border = 0 .
        if (s[i] == s[border])border++;
        prefix[i] = border;
    }
    return prefix;
}

vector<int> bulidZalgo(string s) {
    int n = s.size();

    vector<int> z(n);
    int l = 0, r = 0; /// left , right  pointer to determine my window im in..
    z[0] = 0;

    for (int i = 1; i < n; i++) {
        int k = i - l;
        /// k is the reflected element of the Current i .
        /// check if current i is in the range [L ,R] .
        if (i >= r || i + z[k] >= r) {
            l = i;             /// create new window
            r = max(r, i); /// start
            while (r < n and s[r - l] == s[r])r++;
            z[i] = r - l; /// size of the window ..

        } else /// just Copy
        {
            z[i] = z[k];
        }

    }
    return z;

}


void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    vector<int> prefix = bulidPrefix(s);
    ll x = prefix[n - 1];
    if (x == 0) {
        cout << k / n;
    } else {
        cout << k / x;
    }


}

int main() {
    fast;
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt","w",stdout);
    //  int t;
    //cin >> t;
    // while (t--)
    {
        int k;
        string s;
        while (cin >> k and k != -1) {
            string s;
            cin >> s;
            int n = s.size();
            vector<int> prefix = bulidPrefix(s);
            int x = prefix[n -1];
            if (k < n) {
                cout << 0 << "\n";
                continue;
            }
            n -= x; 
            k -= x;
            cout << k / n << "\n";
        }
        //  solve();
      //  cout << "\n";

    }
}


