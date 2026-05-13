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


    int test_cases, cs = 0 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n, d;

    	cin >> n >> d;
    	vector<int>arr(n);
    	multiset<int>mst1, mst2;
    	int mn = 0;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		mn = max(arr[i], mn);
    	}

    	if(d == 1){
    		cout << mn << endl;
    		continue;
    	}
    	mst1.insert(arr[0]);
    	mst2.insert(-arr[0]);

    	mn = 0;

    	for(int i = 1; i < n; i++){
    		mst1.insert(arr[i]);
    		mst2.insert(-arr[i]);
    		if(mst1.size() > d){
    			mst1.erase(mst1.find(arr[i - d]));
    			mst2.erase(mst2.find(-arr[i - d]));
    		}
    		int l = *mst1.begin(), r = *mst2.begin();

    		if(mst1.size() == d){
    			mn = max(mn, (-r) - l);
    		}
    	}
    	cout << "Case " << ++cs << ": " << mn << endl;
    }
    return 0 ;

    runtime();

}
