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
        int n , k , a1,ak;

        cin>>n>>k>>a1>>ak ;

        int div = n/k ;
        int md = n%k  ;

        int u = min(a1 , md);

        int ans=0 ;

        a1-=u , md-=u ;

        ans+=md ;

        ak+=(a1/k) ;

        div-=min(div , ak) ;

        ans+=div ;

        cout<<ans<<endl ;

        


    }
    return 0 ;
}
