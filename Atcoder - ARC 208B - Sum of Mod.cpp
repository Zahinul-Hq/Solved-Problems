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


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	ll n, k;
    	cin >> n >> k;

    	if(n == 2){
    		cout << k + 1 << " " << k + k + 1 << endl;
    		continue;
    	}

    	vector<ll>pwr, ans;

    	for(int i = 0; ; i++){
    		ll p = 1LL << i;
    		if(p >= k){
    			pwr.push_back(k);
    			break;
    		}else{
    			pwr.push_back(p);
    		}
    		k -= p; 
    	}
    	sort(pwr.begin(), pwr.end());
    	int len = 0;

    	if(n - 1 < (int)pwr.size()){
    		len = (int)pwr.size() - (n - 1); 
    	}

    	
    	debug(len, pwr);
    	for(int i = 0; i < len; i++){
    		pwr[i + 1] += pwr[i];
    	}
    	debug(len, pwr);
    	ans.push_back(pwr[len] + 1);

    	for(int i = len ; i < (int)pwr.size(); i++){
    		ans.push_back(ans.back() + pwr[i]);

    	}
    	while((int)ans.size() < n)
    		ans.push_back(ans.back());

    	for(auto i : ans)cout << i << " ";

    	cout << endl;
    }
    return 0 ;

    runtime();

}
