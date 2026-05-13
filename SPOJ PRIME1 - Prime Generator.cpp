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

bool is_prime(ll val){

	if(val < 2)
		return false;
	if( val == 2)
		return true;

	if(val % 2 == 0)
		return false;

	for(int i = 3; i*i <= val; i+=2)
		if(val % i == 0)
			return false;


	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        ll n, m;

        cin >> n >> m;

        for(ll i = n; i <= m ; i++){

        	if(is_prime(i))
        		cout << i << endl;
        }


    }
    return 0 ;
}
