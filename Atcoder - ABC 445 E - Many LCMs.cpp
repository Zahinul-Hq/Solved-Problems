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
const int mod = 998244353;
int binary_expo(int base, ll pwr){
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
const int N = 1e7 + 7;
vector<bool>is_prime(N, true);
vector<int>spf(N);
void seive(){
	is_prime[0] = is_prime[1] = false;
	for(int i = 1; i < N; i++){
		spf[i] = i;
	}
	for (int i = 2; i * i < N; i++) {
	    if (is_prime[i]) {
	        for (int j = i + i ; j < N; j += i){
	            is_prime[j] = false;
	            spf[j] = min(spf[j], i);
	        }
	    }
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;

    seive();
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;
    	vector<int>arr(n);

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}
    	map<int,pair<int,int>>mp;
    	for(int l = 0; l < n; l++){
    		int val = arr[l];
    		map<int,int>cnt;
    		while(val > 1){
    			cnt[spf[val]]++;
    			val /= spf[val];
    		}

    		for(auto i : cnt){
    			if(mp.find(i.first) == mp.end()){
    				mp[i.first] = {i.second, -1};
    			}else{
    				pair<int,int> p = mp[i.first];
    				if(p.first == i.second)
    					mp[i.first] =  {p.first, p.first};
    				else if(p.first < i.second){
    					mp[i.first] =  {i.second, p.first};
    				}else if(p.second < i.second){
    					mp[i.first] = {p.first, i.second};
    				}
    			}
    		}

    	}
    	ll lcm = 1;

    	debug(mp);

    	for(auto i : mp){
    		ll val = binary_expo(i.first, i.second.first);
    		lcm = (lcm % mod * val % mod) % mod;
    	}
    	for(int l = 0; l < n; l++){
    		int val = arr[l];
    		map<int,int>cnt;
    		while(val > 1){
    			cnt[spf[val]]++;
    			val /= spf[val];
    		}

    		ll tlcm = lcm;
    		for(auto i : cnt){

    			pair<int,int> p = mp[i.first];
    			if(p.first == i.second && p.second == -1){
    				int var = binary_expo(i.first, p.first);
    				tlcm = (tlcm % mod * binary_expo(var, mod - 2) % mod) % mod;
    			}else if(p.first == i.second ){

    				int var = binary_expo(i.first, p.first);

    				tlcm = (tlcm % mod * binary_expo(var, mod - 2) % mod) % mod;
    				tlcm = (tlcm % mod * binary_expo(i.first, p.second) % mod) % mod;

    				debug(arr[l], p, i.first, p.second, tlcm);
    			}

    		}

    		cout << tlcm << " ";
    	}
    	cout << endl;


    }
    return 0 ;

    runtime();

}
