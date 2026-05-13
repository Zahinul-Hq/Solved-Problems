#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

const int N = 1005;

int dp[N][N][3];

int solve(int health, int armor,int x){

	if(health <= 0 || armor <= 0)
		return 0;

	if(dp[health][armor][x] != -1)
		return dp[health][armor][x];

	int ans = 0;
	if(x % 2 == 0){
		ans = solve(health + 3 , armor + 2, 1) + 1;
	}else{

		if(health - 5 >= 0 || armor - 10 >= 0){
			ans = max(ans, solve(health - 5, armor - 10, 0) + 1);
		}
		if(health - 20 >= 0 || armor + 5 >= 0){
			ans = max(ans, solve(health - 20, armor + 5, 0) + 1);
		}
	}

	return dp[health][armor][x] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int a, b;

        memset(dp, -1, sizeof dp);

        cin >> a >> b;

        cout << solve(a, b, 0) - 1 << endl;

    }
    return 0 ;
}
