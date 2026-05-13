#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   1e9
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
const int N = 16 + 7;
ll dp[N],a[N], n;
vector<vector<ll>> arr(N, vector<ll>(2));
ll rec(int i, int prev){
    if(i == n){
        return 0;
    }


    if(dp[i] != -1)
        return dp[i];

    ll ans = 0;


    if(a[i] != -1){
        if(prev <= a[i]){
            ans =  rec(i + 1, a[i]) + a[i];
        }else{
            ans = max(ans, rec(i + 1, a[i]) + a[i]);
        }
    }else{
        ans =  max(ans, rec(i + 1, arr[i][0]) + arr[i][0]);
        ans = max(ans,  rec(i + 1, arr[i][1]) + arr[i][1]);
    }

    return dp[i] = ans;

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
    	cin >> n;

    	int b[n + 1];

    	for(int i = 0; i < n; i++){
    		cin >> a[i];
    	}

    	if(a[0] == -1)
    		b[0] = inf;
    	else
    		b[0] = a[0];
    	for(int i = 1; i < n; i++){
    		if(a[i] == -1)
    			b[i] = b[i - 1];
    		else
    			b[i] = a[i];
    	}
    	b[n] = inf;


    	if(a[n - 1] == -1)
    		arr[n - 1][0] = arr[n - 1][1] = inf;
    	else
    		arr[n - 1][1] = arr[n - 1][0] = a[n - 1];

    	arr[n][1] = arr[n][0] = inf;

    	for(int i = n - 2; i >= 0; i--){
    		if(a[i] == -1){
    			arr[i][1] = inf;
    			arr[i][0] = arr[i + 1][0];
    		}else{
    			arr[i][1]= arr[i][0] = a[i];
    		}
    	}

    	ll curr_sum0 = 0, curr_sum1 = 0, curr_sum3 = 0, ans = 0;

    	//debug(arr);

    	for(int i = 0; i < n; i++){
    		if(arr[i][0] <= arr[i + 1][0] && i != n -1){
    			curr_sum0 += arr[i][0];
    		}else{
    			ans = max(ans, curr_sum0 + arr[i][0]);
    			curr_sum0 = 0;
    		}

    		debug(i, curr_sum0);

    		if(arr[i][1] <= arr[i + 1][1] && i != n - 1){
    			curr_sum1 += arr[i][1];
    		}else{
    			ans = max(ans, curr_sum1 + arr[i][1]);
    			curr_sum1 = 0;
    		}

    		if(b[i] <= b[i + 1] && i != n-1){
    			curr_sum3 += b[i];
    		}else{
    			ans = max(ans, curr_sum3 + b[i]);
    			curr_sum3 = 0;
    		}
    	}

        for(int i = 0; i <= n; i++){
            
                dp[i] = -1;
        }

    	cout << rec(0, 0) << endl;

        debug(dp);

    	

    	
    }
    return 0 ;

    runtime();

}
