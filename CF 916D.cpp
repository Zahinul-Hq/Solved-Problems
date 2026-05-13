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
        int n,x ;

        cin>>n ;

        vector<pair<ll,int>>a[3],b,c;

        for(int i=0 ; i<n;i++){
        	cin>>x;
        	a[0].pb({x,i});
        }

        for(int i=0 ; i<n;i++){
        	cin>>x;
        	a[1].pb({x,i});
        }

        for(int i=0 ; i<n;i++){
        	cin>>x;
        	a[2].pb({x,i});
        }

        sort(a[0].rbegin() ,a[0].rend());
        sort(a[1].rbegin() ,a[1].rend());
        sort(a[2].rbegin() ,a[2].rend());

        vector<pair<ll,ll>>ans ;

        vector<int>pos(n+1,0), book(4,0);
        ll val1=0 , val2=0 , val3=0 ;

        /*if((a[0].F>=b[0].F)&&(a[0].F>=c[0].F)){
        	pos[a[0].S]=1;
        	book[1]=0;
        	val1=a[0].F ;
        }else if((a[0].F<b[0].F)&&(c[0].F<b[0].F)){
        	pos[b[0].S]=1;
        	book[2]=1;
        	val1=b[0].F ;

        }else{
        	pos[b[0].S]=1;
        	book[3]=1;
        	val1=c[0].F ;
        }*/

        for(int i=0 ; i<3 ; i++){
        	for(int j=0 ; j<3 ; j++){
        		if(val1<a[j][i].F && book[j]==0){
        			val1=a[j][i].F;
        		}
        	}
        }



    }
    return 0 ;
}
