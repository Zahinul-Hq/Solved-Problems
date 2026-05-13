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
void solve(){
	int n;
    	cin >> n;

    	vector<int>arr(n);

    	map<int,int>mp;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		mp[arr[i]]++;
    	}
    	
    	vector<int>tmp;

    	ll ans = 0, cnt = 0;

    	for(auto i : mp){

    		if(i.second >= 2){
    			int x = i.second / 2;

    			ans += (2LL * x * i.first);

    			cnt += x;
    		}
    		if(i.second % 2 == 1){
    			tmp.push_back(i.first);
    		}
    	}
    	if(ans == 0){
    		cout << 0 << endl;
    		return;
    	}

    	sort(tmp.rbegin(), tmp.rend());

    	for(int i = 1; i < (int) tmp.size(); i++){

    		if(tmp[i - 1] < ans + tmp[i]){
    			cout << ans + tmp[i] + tmp[i - 1] << endl;
    			return;
    		}
    	}
    	for(int i = 0; i < (int) tmp.size(); i++){

    		if(tmp[i] < ans){
    			cout << ans + tmp[i]<< endl;
    			return;
    		}
    	}

    	if(cnt > 1){
    		cout << ans << endl;
    		return ;
    	}

    	cout << 0 << endl;

    	return;
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
    	solve();
    }
    return 0 ;

    runtime();

}
