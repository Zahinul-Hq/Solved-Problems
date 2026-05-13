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
    	int n;
    	cin >> n;
    	vector<int>arr(n + 1), cnt(n+1, 0);

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		cnt[arr[i]]++;
    	}

    	int mex = 0;
    	while(cnt[mex]){
    		mex++;
    	}
    	if(mex == 0){
    		cout << 2 << endl;
    		cout <<  "1 1 " << endl << "2 " << n << endl;
    		continue;
    	}

    	vector<pair<int,int>>ans;
    	set<int>st;
    	int l = 1;

    	for(int i = 1; i <= n; i++){
    		if(arr[i] < mex)
    			st.insert(arr[i]);

    		if(st.size() == mex && l == 1 ){
    			st.clear();
    			ans.push_back({l, i});
    			l = i + 1;

    		}
    	}

    	if(st.size() != mex){
    		cout << -1 << endl;
    	}else{

    		cout << 2 << endl;

    		for(auto i : ans){
    			cout << i.F << " " << i.S << endl;
    		}

    		cout << l << " " << n << endl;
    	}
    }
    return 0 ;

    runtime();

}
