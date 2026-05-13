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
        int n;
        string s;
        cin >> n >> s;

        bool g = 0;
        map<char, int> mp;

        for(int i = 0; i < n; i++){
        	mp[s[i]]++;
        	if(mp[s[i]] > (n / 2))
        		g = 1;
        }
        if( n % 2 == 1 || g){
        	cout << -1 << endl;
        	continue;
        }

        int cnt = 0;
        mp.clear();

        for(int i = 0; i < n / 2; i++){
        	if(s[i] == s[n - i - 1]){
        		cnt++;
        		mp[s[i]]++;
        	}
        }

        ll ans = 0;
        vector<int>arr;

        for(auto i : mp){
        	if(i.S * 2 > cnt){
        		cout << i.S << endl;
        		cnt = -1;
        		break;
        	}
        }
        
        if(cnt >= 0)
        	cout << (cnt + 1) / 2 << endl;
    }
    return 0 ;
}
