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
       int n , m , k , h ;

       cin>>n>>m>>k>>h ;

       vector<int>high;

       for(int i=0 ; i<n ; i++){
       		int x ;
       		cin>>x ;
       		high.pb(abs(h-x));
       }

       int cnt=0 ;


       for(int i=0 ; i<n ; i++){

       		if((high[i]%k==0) && (high[i]/k)<m  && high[i]){
       			cnt++ ;
       		}

       } 

       cout<<cnt<<endl;
    }
    return 0 ;
}
