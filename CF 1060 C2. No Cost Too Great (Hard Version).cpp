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
int spf[N];
void sieve() {
	for (int i = 2; i < N; i++) {
    	spf[i] = i;
  	}
  	for (int i = 2; i * i < N; i++) {
    	if (spf[i] == i) {
      		for (int j = i * i; j < N; j += i) {
        		spf[j] = min(spf[j], i);
      		}
    	}
  	}
}

bool cmp(pair<int,int>a, pair<int,int>b){
	return a.second < b.second; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;

    sieve();

    while (test_cases--)
    {
    	int n;
    	cin >> n;
    	vector<pair<int,int>>arr(n);
    	for(int i = 0; i < n; i++){
    		cin >> arr[i].first;
    	}
    	for(int i = 0; i < n; i++){
    		cin >> arr[i].second;
    	}

    	debug(arr);

    	map<int,int>factors;
    	bool z = 0;
    	sort(arr.begin(), arr.end(),cmp);

    	for(int i = 0; i < n; i++){
    		int temp = arr[i].first;
    		while(temp > 1){
    			if(factors.find(spf[temp]) != factors.end() && factors[spf[temp]] != i){
    				z = 1;
    			}
    			factors[spf[temp]] = i;
    			temp /= spf[temp];
    		}
    	}
    	if(z){
    		cout << 0 << endl;
    		continue;
    	}

    	

    	ll ans = (ll)arr[0].second + arr[1].second;

    	for(int i = 0; i < n; i++){
    		int temp = arr[i].first + 1;

    		while(temp > 1){
    			if(factors.find(spf[temp]) != factors.end()){
    				if(factors[spf[temp]] != i)
    					z = 1;
    			}
    			debug(factors, i, temp);
    			temp /= spf[temp];
    		}
    		if(z){
    			ans = min(ans, (ll)arr[i].second);
    			break;
    		}
    	}
    	
    	auto first_val = arr[0];

    	for(auto val : factors){
    		if(0 == val.second ){
    			continue;
    		}
    		ll rem = first_val.first % val.first;
    		if(rem != 0)
    			rem = (val.first - rem);

    		ans = min(ans , rem * arr[0].second );

    		
    		debug(val.first, first_val, rem, ans);
    	}

    	cout << ans << endl;
    }
    return 0 ;

    runtime();

}
