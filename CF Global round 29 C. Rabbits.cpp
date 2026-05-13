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
const int N = 2e5 + 7;
int n;
string s;
int dp[N][4][2];

bool rec(int i, int cnt, bool right){
	if(i == n){
		if(right && cnt)
			return 0;
		return 1;
	}

	if(right && cnt == 2)
		return 0;

	if(dp[i][cnt][right] != -1)
		return dp[i][cnt][right];

	bool ans = 0;
	if(s[i] == '1'){
		ans |= rec(i + 1, min(cnt + 1, 2), right);
	}else{
		if(!cnt){
			ans |= rec(i + 1, 0, right);
		}
		ans |= rec(i + 1, 0, right ^ 1);
			
	}


	return dp[i][cnt][right] = ans;
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
    	cin >> n >> s;


    	for(int i = 0; i <= n; i++){
    		for(int j = 0; j < 4; j++){
    			dp[i][j][0] = dp[i][j][1] = -1;
    		}
    	}

    	if(rec(0, 0, 0)){
    		cout << "YES" << endl;
    	}else{
    		cout << "NO" << endl;
    	}
    }
    return 0 ;

    runtime();

}
