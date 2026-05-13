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

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const int mod = 1e9 + 7;
ll binary_expo(ll base, ll pwr){
	ll result = 1; 
	base %= mod, pwr %= mod;
	while(pwr){
		if(pwr & 1){
			result = (result * 1LL * base) % mod;
		}
		base = (base * 1LL * base) % mod;
		pwr >>= 1;
	}
	return result;
}
pair<int,int> pwr(ll val){
	int c = 0;

	while(val % 2 == 0){
		val /= 2;
		c++;
	}
	return {val, c};
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;

    	vector<ll>arr(n + 1), ans(n + 1);
    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}

    	stack<pair<ll,int>>stk;

    	for(int i = 1; i <= n; i++){
    		pair<int,int> p = pwr(arr[i]);
    		arr[i] = p.first;
    		int c = p.second;
    		ans[i] = ans[i - 1];
    		while(!stk.empty()){
    			if(c > 32 || stk.top().first  < arr[i] * (1 << c)){
    				ll val = stk.top().first, pw = stk.top().second;
    				ans[i] = (ans[i] - (val * binary_expo(2, pw) % mod) + mod) % mod;
    				ans[i] = ans[i] + val;
    				c += pw;
    				stk.pop();
    			}else 
    				break;
    		}
    		stk.push({arr[i], c});
    		ans[i] = (ans[i] + arr[i] * binary_expo(2, c) % mod) % mod;

    	}

    	for(int i = 1; i <= n; i++){
    		cout << ans[i] << " ";
    	}
    	cout << endl;
    }
    return 0 ;
}
