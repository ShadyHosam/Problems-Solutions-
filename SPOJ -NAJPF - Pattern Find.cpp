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

    void solve() {
        string s;
        cin >> s;
        string pt;
        cin >> pt;
        int m = pt.size();
        pt += '$';
        pt += s;
        vector<int> ans;
        vector<int> arr = bulidPrefix(pt);
        for (int i = m + 1; i < m + s.size() + 1; i++) {
            if (arr[i] == m)
                ans.push_back(i - 2 * m + 1);
            /// how to get the index of the real string ???
            /// first we must subtract m+1
            /// m = the pattern we search that we have added to the string
            /// +1 = $ sign
            /// then we need to find where we are in the string ?
            /// subtract i - m + 1 - ( m + 1 ) = i - 2 * m
            /// current index in the real string = i - 2 * m
        }
        if (ans.size()) {
            cout << ans.size() << "\n";
            for (auto i: ans)
                cout << i << " ";
            cout <<"\n";
        } else cout << "Not Found\n";

    }

    int main() {
        fast;
        //  freopen("input.txt", "r", stdin);
        //  freopen("output.txt","w",stdout);
           int t;
          cin >> t;
        while (t--)
        {

            solve();
            cout << "\n";
        }
    }


