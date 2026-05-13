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
        int n , x ;

        cin>>n ; 

        vector<pair<int,int>>pr ;

        vector<int>a(n,0),b ;


        for(int i=0 ; i<n ; i++){
        	cin>>a[i];
        }

        for(int i=0 ; i<n ; i++){
        	cin>>x;
        	pr.pb({a[i]-x , i+1}) ;
        }


        sort(pr.begin() , pr.end() ,greater<pair<int,int>>()) ;

        int cnt=1;

        b.pb(pr[0].S) ;

        for(int i=1; i<n ; i++){

        	if(pr[i].F-pr[i-1].F==0){
        		b.pb(pr[i].S) ;
        	}else
        		break;

        }

        cout<<b.size()<<endl;



        for(int i=b.size()-1 ; i>=0 ; i--)
        	cout<<b[i]<<" "; 


        cout<<endl;       



    }
    return 0 ;
}
