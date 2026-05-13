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

        if(n%2==1){

	        for(int i=n ;i>1 ;i-=2){
	        	cout<<i<<" " ;
	        }

	        cout<<1<<" ";

	        for(int i=n-1 ;i>1 ;i-=2){
	        	cout<<i<<" " ;
	        }
	    }else{


	    	for(int i=2 ;i<=n ;i+=2){
	        	cout<<i<<" " ;
	        }

	        cout<<1<<" ";

	        for(int i=3 ;i<=n ;i+=2){
	        	cout<<i<<" " ;
	        }
	    }

        cout<<endl;


    }
    return 0 ;
}
