#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define inf   1e18
#define endl  "\n"


void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

int wt[105], value[105] ;

const int N = 105;

ll dp[105][(N*1000)], highest_possible_value, possible_value,n  ; 

ll weight_taken(int i , int curr_value){


	if(i == 0){

		if(curr_value == possible_value){
			return 1;
		}

		return inf;

	}	
	
	if(dp[i][curr_value] != -1)
		return dp[i][curr_value];

	ll weight = inf;

	weight = weight_taken(i - 1, curr_value);

	weight = min(weight, weight_taken(i - 1, curr_value + value[i]) + wt[i]);

	return dp[i][curr_value] = weight;

}
int main()
{

	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	inout() ;

    int  capacity ;
    cin >> n >> capacity ;

    for(int i = 1 ; i <= n ; i++){
    	cin >> wt[i] >> value[i] ;

    	highest_possible_value += value[i];
    }

    ll ans = 0;

    memset(dp, -1, sizeof (dp));
    

    for( possible_value = 1; possible_value <= highest_possible_value ; possible_value++){

    	ll total_weight = weight_taken(n, 0);

    	cout<< total_weight <<endl;

    	if( total_weight <= capacity){
    		ans = max(ans, possible_value);

    	}

    }

    cout << ans << endl;

 
    return 0 ;
}
