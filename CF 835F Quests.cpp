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
        int n , d ;
        ll c ;

        cin>>n>>c>>d ;

        vector<ll>a(n) ;

        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;
        }

        int l=0 , r=d+2 ;


        sort(a.rbegin() ,a.rend());
        

        while(l<r){

        	ll mid = l+(r-l+1)/2 ;
        	ll total = 0 ;

        	for(int i=0 ; i<d ; i++){
        		if(i%mid<n)
        			total=total+a[i%mid];
        	}

        	if(total>=c)
        		l=mid ;
        	else
        		r=mid-1 ;

        }

        if(l==d+2)
        	cout<<"Infinity"<<endl;
        else if(l==0)
        	cout<<"Impossible"<<endl;
        else
        	cout<<l-1<<endl;
    }
    return 0 ;
}
