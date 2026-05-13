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
int binary_expo(int base, ll pwr, int mod){
	int result = 1; 
	base %= mod;
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
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	ll n, k;

    	cin >> n >> k;

    	double N = (double)k * log10(n);

    	N -= floor(N);

    	N = pow(10, N);

    	N *= 100;


    	int last_dig = binary_expo(n, k, 1000);
    	cout << "Case " << cs++ << ": " << (ll)N << " ";

    	if(last_dig < 10){
    		cout << "00" << last_dig << endl;
    	}else if(last_dig <= 100){
    		cout << "0" << last_dig << endl;
    	}else{
    		cout << last_dig << endl;
    	}

    }
    return 0 ;

    runtime();

}
