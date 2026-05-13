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
static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    //cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
    return diff.count();
}
ll rnd(ll lw, ll high) {
    
    uniform_int_distribution<ll> dist(lw, high);

    return dist(rng);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	int n;
	cin >> n;
    vector<ll>arr(n , 0);

    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    int cnt =  8 ;

    ll ans = 1;
    while(cnt--){


    	shuffle(arr.begin(), arr.end(), rng);

    	ll val = arr[0];

    	map<ll,int> gcd;

    	for(int i = 0; i < n; i++){
    		gcd[__gcd(val, arr[i])]++;
    	}
    	vector<ll>div;	

    	for(ll i = 1; i * i <= val; i++){
    		if(val % i == 0){
    			div.push_back(val/ i);
    			if((val / i )!= i){
    				div.push_back(i);
    			}
    		}
    	}
    	sort(div.begin(), div.end());

    	ll temp_ans = 1;

    	for(int i = 0; i < div.size(); i++){
    		for(int j = i + 1; j < div.size(); j++){
    			if(div[j] % div[i] == 0){
    				gcd[div[i]] += gcd[div[j]];
    			}
    		}

    		if(gcd[div[i]] >= (n + 1) / 2){
    			temp_ans = max(temp_ans , div[i]);
    		}
    	}

    	ans = max(ans, temp_ans);
    }

    cout << ans << endl;

    return 0 ;
}
