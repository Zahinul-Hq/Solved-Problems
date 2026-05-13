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
const int N =  1e5 + 7;

vector<int>vec;

int dp[N][36];

bool solve(int i, int sum, int n){

	if(i == n){
		if(sum == 0){
			return 1;
		}
		return 0;
	}
	if(dp[i][sum] != -1)
		return dp[i][sum];
	int ans = 0;

	debug(sum);

	ans |= solve(i + 1, sum % 9 , n);


	ans |= solve(i + 1, (sum + vec[i]) % 9, n);

	debug(sum, ans);

	return dp[i][sum] = ans;
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
    	string s;
    	cin >> s;

    	ll tot = 0;
    	int c2 = 0, c3 = 0;

    	for(int i = 0; i <s.size(); i++){

    		tot += (s[i] - '0');

    		c2 += (s[i] == '2');
    		c3 += (s[i] == '3');
    	}
    	vec.clear();
    	for(int i = 0; i < c2; i++){
    		vec.push_back(2);

    	}
    	for(int i = 0; i < c3; i++){
    		vec.push_back(6);

    	}

    	for(int i = 0; i <= vec.size(); i++){
    		for(int j = 0; j < 20; j++){
    			dp[i][j] = -1;
    		}
    	}
    	int md = (tot % 9);
    	debug(tot, md, c2, c3);

    	bool x = solve(0, md , vec.size());

    	debug(dp);


    	if(x == 1){
    		cout << "Yes" << endl;
    	}else{
    		cout << "No" << endl;
    	}

    }
    return 0 ;

    runtime();

}
