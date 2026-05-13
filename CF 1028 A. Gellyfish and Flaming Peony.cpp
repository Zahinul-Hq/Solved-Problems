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
const int Max_Value = 5005;

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

    	vector<int>arr(n);

    	int one = 0;
    	bool alleq = 0;

        vector<int>dp(5001, Max_Value);

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];

            dp[arr[i]] = 0;
    	}

        vector<vector<int>>gcd(5001, vector<int>(5001, 0));


        for(int i = 0; i < Max_Value; i++){
            gcd[i][0] = gcd[0][i] = gcd[i][i] = i;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                gcd[i][j] = gcd[j][i] = gcd[i][j % i];
            }
        }

    	for(int i = 5000; i >= 1; i--){
    		for(int j = 0; j < n; j++){
                dp[gcd[arr[j]][i]] = min(dp[gcd[arr[j][i]]], d[i] + 1  );
    		}
    	}
    	cout << dp[] << endl; 
    }
    return 0 ;

    runtime();

}
