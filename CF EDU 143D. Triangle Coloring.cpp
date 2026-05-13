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
const int  mod = 998244353;
ll binary_expo(ll base, ll pwr, ll m){
	ll result = 1; 
	base %= m, pwr %= m;
	while(pwr){
		if(pwr & 1){
			result = (result * 1LL * base) % m;
		}
		base = (base * 1LL * base) % m;
		pwr >>= 1;
	}
	return result;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

   		ll n;
        cin >> n;
        ll arr[n][3];
        ll fact[n], ans;
        fact[0] = 1;


        for(int i = 0; i < (n / 3) ; i++){
        	cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        	sort(arr[i], arr[i] + 3);
        }
        for(ll i = 1; i <= n; i++){
        	fact[i] = (i * fact[i - 1]) % mod;
        }
        ans = (fact[n / 3]  * (binary_expo(fact[n / 6], mod - 2, mod))) % mod;
        ans = (ans * binary_expo(fact[n / 6], mod - 2, mod)) % mod;

        for(int i = 0; i < (n / 3); i++){
        	ll val = 1;
        	if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
        		val = 3;
        	}
        	if(arr[i][0] == arr[i][1] && arr[i][1] < arr[i][2]){
        		val = 2;
        	}
        	ans = (ans * val) % mod;
        }
        cout << ans << endl;
        

    
    return 0 ;
}
