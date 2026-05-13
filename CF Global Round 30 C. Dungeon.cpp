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
    
    for(int t = 1; t <= test_cases; t++)
    {
    	int n, m;
    	cin >> n >> m;
    	vector<int>arr(n), zero, swrd;

    	vector<pair<int,int>>vp(m),non_zero;
        multiset<int>mst;
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
            mst.insert(arr[i]);
    	}

    	for(int i = 0; i < m; i++){
    		cin >> vp[i].first;
    	}
    	for(int i = 0; i < m; i++){
    		cin >> vp[i].second;
    	}

    	for(int i = 0; i < m; i++){
    		if(vp[i].second){
    			non_zero.push_back(vp[i]);
    		}else{
    			zero.push_back(vp[i].first);
    		}
    	}
    	sort(zero.begin(), zero.end());
        sort(non_zero.begin(), non_zero.end());
    	//debug(zero, pq);
    	
    	int ans = 0;

        for(int i = 0; i < (int)non_zero.size(); i++){

            bool e = 0;
            int s = *mst.begin();
            mst.erase(mst.begin());

            while(s < non_zero[i].first){
                swrd.push_back(s);
                if(mst.size() == 0){
                    e = 1;
                    break;
                }
                s = *mst.begin();
                mst.erase(mst.begin());


                
            }
            if(e)
                break;

            mst.insert(max(s, non_zero[i].second));
            ans++;
    	}

        for(auto i : swrd)mst.insert(i);

            debug(mst);


    	for(int i = 0; i < (int)zero.size(); i++){

            bool e = 0;
            if(mst.size() == 0){
                e = 1;
                break;
            }
            int s = *mst.begin();
            mst.erase(mst.begin());

            debug(mst);

            while(s < zero[i]){
                if(mst.size() == 0){
                    e = 1;
                    break;
                }
                debug(s);

                s = *mst.begin();
                mst.erase(mst.begin());
                
            }
            if(e)
                break;
            ans++;
    	}

    	cout << ans << endl;
    }
    return 0 ;

    runtime();

}
