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
const ll mod = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        string s;

        cin >> s;
        s = "#" + s;
        int n = s.size();
        ll pref[2][n + 5];
        pref[0][0] = pref[1][0] = 0;

        for(int i = 1; i <= n; i++){
        	pref[0][i] = pref[0][i - 1] + (s[i] == '0');
        	pref[1][i] = pref[1][i - 1] + (s[i] == '1');
        }
        ll ans = 0;
        for(int l = 1; l <= n; l++){
        	
        }

        cout << ans << endl;
    }
    return 0 ;
}
