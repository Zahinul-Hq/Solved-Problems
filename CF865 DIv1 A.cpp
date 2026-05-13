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

        ll sum=0,x;

        vector<int>v ;

        for(int i=1 ; i<=n ; i++){

            cin>>x ;
            v.pb(x);  
        }

        for(int i=0 ; i<n-1 ; i+=2){
            sum+=v[i+1]-v[i] ;
        }

        if(sum>=0  || (n&1))
        	cout<<"yes"<<endl;
        else
        	cout<<"no"<<endl ;

    }
    return 0 ;
}
