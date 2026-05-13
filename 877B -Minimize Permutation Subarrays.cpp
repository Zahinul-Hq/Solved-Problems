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

        int arr[n] ;

       int on , tw , en ;

        for(int i =0 ; i<n ; i++){

        	cin>>arr[i] ;

        }

        for(int i =0 ; i<n ; i++){

        	if(arr[i]==1)
        		on=i+1 ;
        	if(arr[i]==2)
        		tw=i+1 ;
        	if(arr[i]==n)
        		en= i+1 ;

        }

       vector<int>v ;

       v.pb(on);
       v.pb(tw) ;
       v.pb(en) ;


       sort(v.begin() , v.end()) ;

       if(v[1]!=en)
       		cout<<v[1]<<" "<<en<<endl ;
       else
       	cout<<1<<" "<<1<<endl;
    }
    return 0 ;
}
