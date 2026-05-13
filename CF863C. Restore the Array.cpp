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
        int n ; 

        cin>>n ;

        vector<int>a(n) ,b ;

        int mn = INT_MAX, pos=-1 ;

        for(int i=1  ; i<n ; i++){
        	cin>>a[i] ;
        }

        a[0]=a[1] ;

        

        for(int i=1 ; i<n ; i++){

        	b.pb(min(a[i] , a[i-1]));

        }

        b.pb(a[n-1]) ;

        for(int i=0 ; i<n ; i++){
        	cout<<b[i]<<" ";
        }

        cout<<endl;

        




    }
    return 0 ;
}
