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
    	int n, k, blue_cnt = 0;
    	cin >> n >> k;

    	string s;
    	cin >> s;

    	s = "#" + s;

    	vector<ll>arr(n + 1, 0), pref(n + 1, 0);

    	ll pen = 0;

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		pref[i] = pref[i - 1] + arr[i];
    		blue_cnt += (s[i] == 'B');
    	}

    	

    	if(blue_cnt <= k ){
    		cout << pen << endl;
    		continue;
    	}

    	int ex = blue_cnt - k;
    	int prev = 1;

    	while(s[prev] != 'B'){
    		prev++;
    	}
    	vector<ll>vals;


    	if(pref[prev - 1]){
    		vals.push_back(pref[prev - 1]);
    	}

    	

    	for(int i = prev + 1; i <= n; i++){
    		if(s[i] == 'B'){
    			if(pref[i - 1] - pref[prev] > 0){
    				vals.push_back(pref[i - 1] - pref[prev]);
    			}

    			if(pref[i - 1] - pref[prev] == 0)
    				ex--;
    			prev = i;
    		}
    	}

    	if(pref[n] - pref[prev]){
    		vals.push_back(pref[n] - pref[prev]);
    	}

    	if(ex <= 0){
    		cout << pen << endl;
    		continue;
    	}
    	

    	debug(vals, ex);


    	sort(vals.begin(), vals.end());

    	

    	for(int i = 0; i < vals.size(); i++){
    		pen += vals[i];
    		ex--;
    		if(ex == 0)
    			break;


    	}

    	cout << pen << endl;


    }
    return 0 ;

    runtime();

}
