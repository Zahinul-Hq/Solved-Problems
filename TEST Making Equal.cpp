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


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n, x;
    	cin >> n;

    	unordered_map<int,int>row1, row2;

    	for(int i = 0; i < n; i++){
    		cin >> x;
    		row1[x]++;
    	}
    	for(int i = 0; i < n; i++){
    		cin >> x;

    		row2[x]++;
    	}
        int cnt = 0;

    	bool ok = 1, same = 1;
        vector<pair<int,int>>arr;

        for(auto [i, j] : row1){
            ll diff = abs(j - row2[i]);

            if(diff % 2 == 1){
                ok = 0;
                break;
            }
            if(diff != 0)
                same = 0;

            diff /= 2;

            if(diff > 0)
                arr.push_back({i, diff});
            cnt += diff;
            
        }
        for(auto [i, j] : row2){
            if(row1[i] != 0 )continue;
            ll diff = abs(j - row1[i]);

            if(diff % 2 == 1){
                ok = 0;
                break;
            }
            if(diff != 0)
                same = 0;

            diff /= 2;

            if(diff > 0)
                arr.push_back({i, diff});
            cnt += diff;
        }

        int mn = min(row1.begin()->first, row2.begin()->first);

        if(!ok){
            cout << -1 << endl;
            continue;
        }
        if(same){
            cout << 0 << endl;
            continue;
        }

        sort(arr.begin(), arr.end());

        cnt /= 2;

    	ll ans = 0;

    	for(int i = 0; i < (arr.size()) && cnt > 0; i++){

            int x = min(arr[i].second,cnt);
            
    		ans += min(2LL * mn * x ,1LL*arr[i].first * x);
            cnt -= min(cnt, arr[i].second);
    	}


        cout << ans << endl;
    	
    }
    runtime();
    return 0 ;

    

}
