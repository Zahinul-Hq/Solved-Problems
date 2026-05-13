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
vector<int>price(N,0);
vector<string>vitamins(N);

ll dp[N][2][2][2];

ll solve(int i, bool A, bool B, bool C){

	if(A & B & C)
		return 0;
	if(i < 0)
		return inf;

	if(dp[i][A][B][C] != -1)
		return dp[i][A][B][C];

	ll ans  = solve(i - 1, A, B, C);

	bool a = 0, b = 0, c = 0;
	for(int j = 0; j < vitamins[i].size(); j++){
		if(vitamins[i][j] == 'A')
			a = 1;
		if(vitamins[i][j] == 'B')
			b = 1;
		if(vitamins[i][j] == 'C')
			c = 1;
	}
	ans = min(ans, price[i] + solve(i - 1, A | a, B | b, C | c ));
	return dp[i][A][B][C] = ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int n;

    cin >> n;

    //memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++){
    	cin >> price[i] >> vitamins[i];
    }

   	//ll ans = solve(n - 1, 0, 0, 0);

   	for(int i = 0; i <= n; i++)
   		for(int a = 0; a <= 1; a++)
   			for(int b = 0; b <= 1; b++)
   				for(int c = 0; c <= 1; c++)
   					dp[i][a][b][c] = inf;

   	dp[0][0][0][0] = 0;

   	for(int i = 1; i <= n; i++){
   		bool a = 0, b = 0, c = 0;
		for(int j = 0; j < vitamins[i - 1].size(); j++){
			if(vitamins[i - 1][j] == 'A')
				a = 1;
			if(vitamins[i - 1][j] == 'B')
				b = 1;
			if(vitamins[i - 1][j] == 'C')
				c = 1;
		}

   		for(int A = 0; A <= 1; A++){
   			for(int B = 0; B <= 1; B++){
   				for(int C = 0; C <= 1; C++){

   					dp[i][A][B][C] =  min(dp[i][A][B][C], dp[i - 1][A][B][C]);

   					dp[i][A | a][B | b][C | c] = min(dp[i][A | a][B | b][C | c], dp[i - 1][A][B][C] + price[i -1] );

   					
   				}
   			}
   		}
   	}


   	

   	if(dp[n][1][1][1] == inf){
   		cout << -1 << endl;
   	}else{
   		cout << dp[n][1][1][1] << endl;
   	}
    return 0 ;
}
