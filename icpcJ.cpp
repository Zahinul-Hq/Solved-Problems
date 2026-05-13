
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
	#endif
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


    int t ;
    cin>>t ;

    int n , i=0;

    ll k , sum=0  ;

    while (t--)
    {


        cin>>n>>k ;

        vector<ll>arr ;


        sum=0 ;


        for(int i=0 ; i<n ;i++)
        {
        	ll p ;

        	cin>>p ;

        	arr.pb(p) ;

        	sum = sum+p ;
        }

        ll mx = *max_element(arr.begin() ,arr.end()) ;





        if(k==1)
        	cout<<"Case "<<++i<<": "<<sum<<endl ;

        else
        	cout<<"Case "<<++i<<": "<<sum+((k-1)*mx)<<endl ;




    }
    return 0 ;
}
