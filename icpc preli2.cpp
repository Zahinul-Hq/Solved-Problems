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
        ll n;

        cin>>n ;

        vector<int>a(n,0) ;


        ll sum = (n*(n+1))/2 ;


        map<int , int>mp ;

        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;
        }

        vector<int>v ;

        for(auto i : mp ){

        	//if(i.S>1)
        		sum-= i.S;
        }


        cout<<sum<<endl;

    }
    return 0 ;
}
