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
        ll n ;

        cin>>n ;

        if(n%2==1){
        	cout<<-1<<endl;
        	continue ;
        }


        ll a = n+(n/2) ;
        ll b = n/2 ;

        if((a^b)==n){
        	cout<<a<<" "<<b<<endl;

        }else{
        	cout<<-1<<endl;
        }
    }
    return 0 ;
}
