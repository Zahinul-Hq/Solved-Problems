#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

int arr[205];
ll dp[205][12];

vector<ll>s;

ll total_sum(int indx,int taken,int sum){

	if(taken == 0 || indx == 0){
		return 0;
	}

	if(dp[indx][taken] != -1)
		return dp[indx][taken];


	ll ans = total_sum(indx - 1, taken, sum);

	s.pb(sum + arr[indx]);

	ans += total_sum(indx - 1, taken - 1, sum + arr[indx]);

	return dp[indx][taken] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
   	{
       	int n;

       	cin >> n;

       	for(int i = 1; i <= n; i++){
       		cin >> arr[i];
       	}

       	total_sum(n, 10, 0);
       	vector<int>div(20,0);


       	=





        
    }
    return 0 ;
}
