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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


	int n, q;

	cin >> n >> q;

	vector<ll>a(n + 1), b(n + 1), pref(n + 1, 0), suff(n + 2, 0) ;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	bool f = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] + b[i] <0)
			f = 1;
	}
	for(int i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + a[i];
	}
	for(int i = n; i >= 1; i--){
		suff[i] = suff[i + 1] + b[i];
	}
	f |= (suff[1] < 0);
	f |= (pref[n] < 0);
	while(q--){

		int l, r;
		cin >> l >> r;
		ll ans;
		if(f){
			cout << "flawed" << endl;
			continue;
		}

		if(l <= r){

			//debug(pref[r - 1] - pref[l - 1], suff[1] - suff[l] + suff[r]);
			ans = min(pref[r - 1] - pref[l - 1], suff[1] - suff[l] + suff[r]);
		}else{
			//debug(pref[n] - pref[l] + pref[r - 1], suff[r] - suff[l]);
			ans = min(pref[n] - pref[l - 1] + pref[r - 1], suff[r] - suff[l]);
		}

		cout << ans << endl;


	}    

    return 0 ;

    runtime();

}
