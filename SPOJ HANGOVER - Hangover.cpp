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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;
    
    while (1)
    {
       double n, sum = 0;

       cin >> n;

       if(!n)
       		break;

       	int i ;

       	for( i = 2; sum < n; i++){

       		sum += (1.00 / (1.00 * i) );

       	}



       	cout << i - 2 << " card(s)" << endl;
    }
    return 0 ;
}
