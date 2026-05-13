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
const int N = 1e3 + 7;
vector<bool>is_prime(N, true);
vector<int> primes;
void seive(){
	is_prime[0] = false; is_prime[1] = true;
	for (int i = 2; i * i < N; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j < N; j += i)
	            is_prime[j] = false;
	    }
	}
	for(int i = 1; i < N; i++){
		if(is_prime[i])
			primes.push_back(i);
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
    	int n, k;
    	cin >> n >> k;

    	vector<int>arr(n + 1);
    	map<int,int>mp;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		mp[arr[i]] = 1;
    	}

    	vector<int>ans;

    	for(auto i : primes){
    		bool put = 0;
    		for(int j = i; j <= k; j += i){
    			if(mp.find(j) == mp.end()){
    				put = 0;
    				break;
    			}
    			if(mp[j] == 1)
    				put = 1;
    		}

    		if(put){
    			ans.push_back(i);
    			for(int j = i; j <= k; j += i){
	    			if(mp[j] == 1)
	    				mp[j] = 2;
    			}
    		}
    	}

    	for(auto i : mp){
    		bool put = 0;
    		if(i.second == 1){
    			for(int j = i.first; j <= k; j += i.first){
    				if(mp.find(j) == mp.end()){
    					put = 0;
    					break;

    				}
    				if(mp[j] == 1)
    					put = 1;

    			}
    			if(put){
    				ans.push_back(i.first);
	    			for(int j = i.first; j <= k; j += i.first){
	    				if(mp[j] == 1)
	    					mp[j] = 2;

	    			}
    			}
    		}
    	}

    	bool ok = 1;

    	debug(mp);

    	for(auto i : mp){
    		ok &= (i.second > 1);
    	}

    	if(!ok){
    		cout << -1 << endl;
    	}else{
    		cout << ans.size() << endl;

    		for(auto i : ans){
    			cout << i << " ";
    		}
    		cout << endl;

    	}
    }
    return 0 ;

    runtime();

}
