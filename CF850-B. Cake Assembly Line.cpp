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
        int n , w, h ;

        cin>>n>>w>>h ;

        vector<ll>a(n,0) ;
        vector<ll>b(n,0) ;

        for(int i=0 ;i<n ; i++)
        	cin>>a[i];
        for(int i=0 ;i<n ; i++)
        	cin>>b[i];

        bool flag=0 ;

        ll rtshift=-inf ;
        ll lfshift=inf ;

        for(int i=0 ;i<n ; i++){

        	rtshift=max(rtshift,(b[i]+h)-(a[i]+w));
        	lfshift=min(lfshift , (b[i]-h)-(a[i]-w));

       	}

       	if(rtshift<=lfshift)
       		cout<<"Yes"<<endl;
       	else
       		cout<<"No"<<endl;

        	
    }
    return 0 ;
        
}
