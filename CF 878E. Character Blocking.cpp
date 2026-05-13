#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
       vector<string> s(2);
        cin >> s[0] >> s[1];
        int n = s[0].size();
        int bad = 0;
        for (int i = 0; i < n; ++i) {
            if (s[0][i] != s[1][i]) {
                ++bad;
            }
        }
        int t, q;
        cin >> t >> q;
        queue<pair<int, int>> unblock;
        for (int i = 0; i < q; ++i) {
            while (!unblock.empty() && unblock.front().first == i) {
                if (s[0][unblock.front().second] != s[1][unblock.front().second]) {
                    ++bad;
                }
                unblock.pop();
            }
            int type;
            cin >> type;
            if (type == 1) {
                int pos;
                cin >> pos;
                if (s[0][pos - 1] != s[1][pos - 1]) {
                    --bad;
                }
                unblock.emplace(i + t, pos - 1);
            } else if (type == 2) {
                int num1, pos1, num2, pos2;
                cin >> num1 >> pos1 >> num2 >> pos2;
                --num1; --pos1; --num2; --pos2;
                if (s[num1][pos1] != s[1 ^ num1][pos1]) {
                    --bad;
                }
                if (s[num2][pos2] != s[1 ^ num2][pos2]) {
                    --bad;
                }
                swap(s[num1][pos1], s[num2][pos2]);
                if (s[num1][pos1] != s[1 ^ num1][pos1]) {
                    ++bad;
                }
                if (s[num2][pos2] != s[1 ^ num2][pos2]) {
                    ++bad;
                }
            } else {
                cout << (!bad ? "YES" : "NO") << "\n";
            }
        
        }
    }
    return 0 ;
}
