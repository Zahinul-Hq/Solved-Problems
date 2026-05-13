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

const ll N = 10000;

bool func(ll n){

	while(n > 1){

		if( n % 2 )
			return false;

		n = n / 2;
	}

	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;


	ll val ;

	cin >> val;

   
    	if(func(val)){
    		cout << "TAK" << endl;
    	}else
    		cout << "NIE" << endl;
    
    return 0 ;
}
