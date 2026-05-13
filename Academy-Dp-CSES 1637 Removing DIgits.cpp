#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define PI    acos(-1.0)
#define endl  "\n"
#define inf 2e18


void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 1e6+9  , infi =1e9;


ll dp[N] ;

vector<int> check_dig(int nm){

	vector<int>digits ;

	while(nm>0){

		int dig = nm%10 ;
		digits.push_back(dig) ;
		nm=nm/10 ;
	}

	return digits ;
}

ll steps(ll n){

	if( n == 0)
		return 1;

	if(dp[n] != -1)
		return dp[n];

	

	ll step = infi;

	vector<int>digits = check_dig(n);

	for(int i = 0; i < digits.size(); i++){

		if(digits[i] != 0)
			step = min( step, steps(n - digits[i])+1 );

	}
	return dp[n] = step;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int x ;

    memset(dp , -1 , sizeof dp ) ;

    cin >> x ; 

  	cout << steps(x) - 1 << endl;

    return 0 ;
}
