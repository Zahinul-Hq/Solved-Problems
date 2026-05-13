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
	//inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        int n , m ;
        cin>>n>>m ;

        vector<ll>v[m] ;


        for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<m ; j++){
        		int x ;
        		cin>>x ;
        		v[j].push_back(x) ;
        	}
        }


        for(int i= 0  ; i<m ; i++)
        	sort(v[i].begin() , v[i].end()) ;

        ll ans = 0 ; 

        for(int i=0  ; i<m ; i++){

        	vector<ll>res(n, 0 ) ;
        	res[n-1]= v[i][n-1] ;

        	cout<<res[n-1]<<endl;

        	for(int j=n-2 ; j>=0 ; j--){
        		res[j] = res[j+1]+v[i][j];

        		cout<<res[j]<<endl;
        	}

        	//break ;

        	for(int j=0 ; j<n-1 ; j++){
        		ll cnt = res[j+1] - ((n-1-j)*v[i][j]) ;

        		cout<<cnt<<" " <<res[j+1]<<endl;
        		ans=ans+cnt ;
        	}
        	break;
        }

        cout<<ans<<endl ;

    }
    return 0 ;
}
