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
int binary_expo(int base, int pwr){
	int result = 1; 
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t, i = 0 ;
    cin >> t ;

    vector<int>n(t, 0), k(t, 0);

    for(int i = 0; i < t; i++){
    	cin >> n[i];
    }
    for(int i = 0; i < t; i++){
    	cin >> k[i];
    }

    for(int j = 0; j < t; j++ ){
    	if(n[j] == k[j]){
    		cout << 1 << endl;
    	}else{
    		int ans = binary_expo(2, k[j]);
    		cout << ans << endl;

    	}
    }
    return 0 ;
}
