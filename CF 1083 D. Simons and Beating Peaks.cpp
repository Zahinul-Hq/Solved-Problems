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

vector<int> LDSDP(vector<int>arr, int n){
        vector<int>temp;
        for(int i = 1; i <= n; i++){
            arr[i] *= -1;
        }
        vector<int> dp(n + 1 , 1), lis;
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();

            if(pos == (int)temp.size()){
                temp.push_back(arr[i]);
                dp[i] = (int)temp.size();
            }else{
                temp[pos] = arr[i];
                dp[i] = pos + 1;
            }
        }

    return dp;
}
vector<int>LISDP(vector<int>arr, int n){
        vector<int>temp;
        for(int i = 1; i <= n; i++){
            arr[i] *= -1;
        }
        vector<int> dp(n + 2 , 1);
        dp[0] = dp[n + 1] = 0;
        for(int i = n; i >= 1; i--){
            int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();

            if(pos == (int)temp.size()){
                temp.push_back(arr[i]);
                dp[i] = (int)temp.size();
            }else{
                temp[pos] = arr[i];
                dp[i] = pos + 1;
            }
        }

    return dp;
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
    	vector<int>arr(n + 2), pos(n + 2);

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}

    	vector<int>LIS(n + 2, 0), l, r;
        vector<int>LDS(n + 2, 0);
        l.push_back(INT_MAX);
        r.push_back(INT_MAX);

        for(int i = 1; i <= n; i++){
            while(l.back() < arr[i]){
                l.pop_back();
            }
            l.push_back(arr[i]);
            LDS[i] = l.size() - 1;
        }
        for(int i = n; i >= 1; i--){
            while(r.back() < arr[i]){
                r.pop_back();
            }
            r.push_back(arr[i]);
            LIS[i] = r.size() - 1;
        }



    	int ans = 0;

    	arr[0] = INT_MAX;
    	arr[n + 1] = INT_MAX; 

    	debug(LIS, LDS);

    	for(int i = 1; i <= n; i++){
    		
    			ans = max(ans, LIS[i + 1] + LDS[i]  );
                debug(i, LIS[i], LDS[i]);
    		
    	}

    	cout << n - ans << endl;

    }
    return 0 ;

    runtime();

}
