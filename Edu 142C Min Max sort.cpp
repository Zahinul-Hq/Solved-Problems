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

        vector<int>a(n+1);
        for(int i=0 ; i<n;i++){

        	int x ;
        	cin>>x ;

        	a[x]=i ;
        }

        int l = (n+1)/2 , r=(n+2)/2 ;

        while(l>0 && (l==r || (a[l]<a[l+1] && a[r-1]<a[r]))){

        	l-- ;
        	r++ ;
        }

        cout<<(n-r+l+1)/2<<endl;
    }
    return 0 ;
}
