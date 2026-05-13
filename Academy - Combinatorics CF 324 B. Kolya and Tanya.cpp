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
const int mod = 1e9 + 7;

ll bin_expo(ll base, int pwr){
	ll ans = 1;
	base = base % mod;
	pwr = pwr % mod;

	while(pwr){

		if(pwr & 1)
			ans = (ans * base) % mod;
		base = (base * base) % mod;

		pwr >>= 1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    ll n;
    cin >> n;

    cout << (bin_expo(3LL, 3*n) - bin_expo(7LL, n) + mod) % mod << endl;

    return 0 ;
}
