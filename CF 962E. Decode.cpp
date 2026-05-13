#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
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
const int mod = 1e9 + 7;

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
        int n = s.size();
        ll sum = 0;
        map<ll,ll>mp;
        mp[0] = 1;
        ll x = 0;
        ll ans = 0;


        for(int i = 0; i < n; i++){
            if(s[i] == '0') x--;
            else x++;

            if(mp.find(x) != mp.end()){
               ll l = mp[x];
               ll r = n - i;
                ans += (l * r);
                ans %= mod;
            }
            mp[x] += i + 2;
            mp[x] %= mod;
        }
        

        
        cout << ans << endl;
    }
    return 0 ;
}
