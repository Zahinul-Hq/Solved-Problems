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
const int N = 1e6 + 7;
vector<ll>spf(N, INT_MAX), gpf(N, 0), dis(N, 0);

void Precalculate(){

	for(ll i = 2; i < N; i++){
		if(spf[i] == INT_MAX){
			for(ll j = i; j < N; j += i){
				spf[j] = min(spf[j], i);
				gpf[j] = max(gpf[j], i);
				dis[j]++;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;



	Precalculate();
    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;

    	int x = n;

    	int cnt = 0;

    	ll nod = 1, sod = 1;

    	while(n > 1){

    		int prime = spf[n];
    		ll pwr = prime;
    		int e = 0;

    		while(n % prime == 0){

    			e++;
    			n /= prime;
    			pwr *= prime;
    			cnt++;
    		}

    		nod *= (e + 1);
    		sod *= ((pwr - 1) / (prime - 1));
    		
    	}

    	cout << spf[x] << " " << gpf[x]<< " " << dis[x] << " " << cnt << " " << nod << " " << sod << endl;
    }
    return 0 ;

    runtime();

}
