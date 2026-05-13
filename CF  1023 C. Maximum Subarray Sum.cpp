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

    	string s;

    	cin >> n >> k >> s;

    	s = '#' + s;

    	vector<ll>arr(n + 1);

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}

    	ll mx = -inf, sub = 0, sub_mx = -inf;
    	bool t = 0;

    	for(int i = 1; i <= n; i++){

    		if(s[i] != '0'){
    			sub = max(arr[i], sub + arr[i]);
    			sub_mx = max(sub, sub_mx);
    			
    			
    		}else{
    			mx = max(sub_mx, mx);
    			t = 1;
    			sub = 0;
    		}

    	}

    	sub_mx = max(sub_mx, sub);
    	mx = max(sub_mx, mx);
    	debug(mx);

    	if(!t){
    		if(mx == k){
    			cout << "Yes" << endl;
    			for(int i = 1; i <= n; i++){
    				cout << arr[i] << " ";
    			}
    			cout << endl;
    		}else{
    			cout << "No" << endl;
    		}
    		continue;
    	}

    	if(mx > k){
    		cout << "No" << endl;
    		continue;
    	}
    	cout << "Yes" << endl;

    	bool f = 0;
    	

    	for(int i = 1; i <= n; i++){
    		ll mx_pref = 0, mx_suff = 0, pref = 0, suff = 0;
    		if(s[i] == '0' && !f){
    			for(int j = i + 1; s[j] != '0' && j <= n; j++){
    				pref += arr[j];
    				mx_pref = max(pref, mx_pref);

    			}
    			for(int j = i - 1; s[j] != '0' && j > 0; j--){
    				suff += arr[j];
    				mx_suff = max(suff, mx_suff);
    			}

    			arr[i] = (k - (mx_pref + mx_suff));
    			f = 1;
    		}else if(s[i] == '0'){
    			arr[i] = -1e18;
    		}
    	}

    	for(int i = 1; i <= n; i++){
    		cout << arr[i] << " ";
    	}
    	cout << endl;



    	


    }
    return 0 ;

    runtime();

}
