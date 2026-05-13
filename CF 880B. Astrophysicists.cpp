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

    int t ;
    cin>>t ;
    
    while (t--)
    {
        ll n , k , g ;

        cin>>n>>k>>g ;


        ll mn = min(((g-1)/2)*n , k*g ) ;

        ll rem = (k*g - mn) %g ;

        if (rem > 0) {
		    mn -= (g - 1) / 2;
		    ll last = ((g - 1) / 2 + rem) % g;
 
		    if (last * 2 < g) {
		        mn += last;
		    } else {
		        mn -= g - last;
		    }
		}

		cout<<mn<<endl;
    }
    return 0 ;
}
