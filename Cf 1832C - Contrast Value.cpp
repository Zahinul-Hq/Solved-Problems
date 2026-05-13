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

        vector<int>a(n) ;

        for(int &x : a)
        	cin>>x ;

         n= unique(a.begin() , a.end()) - a.begin() ;

        int ans = n ;

       

        for(int i=0 ; i+2 < n; i++){

        	ans -= (a[i]<a[i+1] && a[i+1]<a[i+2]) ;
        	ans -= (a[i]>a[i+1] && a[i+1]>a[i+2]) ;

        	
        }

        cout<<ans<<endl;






    }
    return 0 ;
}
