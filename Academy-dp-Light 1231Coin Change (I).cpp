#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define endl  "\n"


void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 55;
int mod = 100000007;
ll dp[N][1005], k;

int coin_value[N], number_of_coins[N];

ll coin_change(int indx, int curr_value){


	if(curr_value == k)
		return 1;

	if(indx == 0 || curr_value > k)
		return 0;

	

	if(dp[indx][curr_value] != -1){
		return dp[indx][curr_value];
	}
	
	ll ans = 0;

	for(int i = 0; i <= number_of_coins[indx] ; i++){

		if(curr_value + (coin_value[indx]*i) <= k )
			ans += coin_change(indx - 1, curr_value + (coin_value[indx]*i)) % mod ;
	}

	return dp[indx][curr_value] = (ans) % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t , c = 1 ;
    cin >> t ;
    
    while (t--)
    {
        memset(dp, -1, sizeof dp);

        int n; 

        cin >> n >> k;


        coin_value[0] = 0;
        number_of_coins[0] = 0;

        for(int i = 1; i <= n; i++){
        	cin >> coin_value[i];
        }
        for(int i = 1; i <= n; i++){
        	cin >> number_of_coins[i];
        }

        cout << "Case " << c++ << ": " << coin_change(n, 0) % mod << endl;
    }

    return 0 ;
}
