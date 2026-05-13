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
        ll n , sum = 0 ; 


        cin>>n ;

        vector<ll>v(n,0) ;
        map<ll,ll>mp ;

        for(int  i=0 ; i<n ; i++){
        	cin>>v[i ];
        	mp[v[i]]++ ;
        } 

        for(int  i=0 ; i<n ; i++){
        	sum=0 ;

        	for(int j=i ; j<n ; j++){


        		if(sum>n)
        			break ;

        		sum+=v[j] ;

        		if(j>i){
        			mp[sum]++ ;
        		}
        		
        	}
        }

        for(int i=1 ; i<=n ; i++){
        	cout<<mp[i]<<" ";

        }

        cout<<endl;

    }
    return 0 ;
}
