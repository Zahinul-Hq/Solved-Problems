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
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int N = INT_MAX;
map<ll,ll>mp;

ll binary_expo(ll base, ll pwr){
	ll result = 1; 
	while(pwr){
		if(pwr & 1){
			result = (result * 1LL * base) ;
		}
		base = (base * 1LL * base) ;
		pwr >>= 1;
	}
	return result;
}
void pre(){

	for(ll b = 2; b * b <= N; b++){
		ll pw = 2;

		ll val = binary_expo(b, pw);

		while(val <= N){
			mp[val] = max(pw, mp[val]);
			val = binary_expo(b, ++pw);
		}	
	}

	ll sq = sqrt(N) + 1;


	for(ll b = -2; b >= (-sq); b--){
		ll pw = 2;

		ll val = binary_expo(b, pw);

		while(val <= N){
			mp[val] = max(pw, mp[val]);
			val = binary_expo(b, ++pw);
		}	
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	pre();
    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;


    	cout << "Case " << cs++ << ": " ;

    	if(mp.count(n)){
    		cout << mp[n] << endl;
    	}else{
    		cout << 1 << endl;
    	}
    }
    return 0 ;

    runtime();

}
