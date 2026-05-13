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
bool check(int a , int b  , ll x){

	if(x%a!=0 || x%b!=0)
		return false ;
	if((x/a) > a || (x/b)>b)
		return false ;


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
        ll a, b ;

        cin>>a>>b ;

        ll lcm = (a*b)/__gcd(a,b);

        if(b%a!=0){
        	cout<<lcm<<endl;
        }else{
        	cout<<b*(b/a)<<endl;
        }



    }
    return 0 ;
}
