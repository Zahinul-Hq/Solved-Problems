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
};

bool cmp(pair<int,int> a, pair<int,int>b){

    if(a.first != b.first)
        return a.first > b.first;

    return a.second < b.second;
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
    	ll n, m, k;

    	cin >> n >> m >> k;

    	vector<int>a(m);
        multiset<int>mset;
    	vector< pair<int,int>>arr;

    	for(int i = 0; i < m; i++){
    		cin >> a[i];
            mset.insert(a[i]);
    	}
        ll ex = k;

    	for(int i = 0; i < n; i++){
    		int x, y, z;
    		cin >> x >> y >> z;
    		arr.push_back({ z - y , x });
            ex -= y;
    	}

    	sort(arr.begin(), arr.end(), cmp);

        vector<int>mark(n , 0);

    	for(int i = 0; i < n; i++){

            auto it = mset.lower_bound(arr[i].second);

            if(it != mset.end()){
                mset.erase(it);
                mark[i] = 1;
            }
    	}

        for(int i = n - 1; i >= 0; i--){
            if(!mark[i]){
                ex -= arr[i].first;

                mark[i] = (ex >= 0);
            }
        }

    	cout << accumulate(mark.begin(), mark.end(), 0) << endl;










    }
    return 0 ;

    runtime();

}
