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
        ll n , x, y , d=0;

        cin>>n>>x>>y ;

        string p ,q ,r(n,0) ;

        cin>>p>>q ;

        bool adj=false ;

        for(int i=0 ; i<n ; i++){
        	if(p[i]!=q[i])
        		r[i]='1';
        	else
        		r[i]='0' ;
        	
        }

        for(int i=0 ; i<n ; i++){
        	if(r[i]=='1' && r[i+1]=='1' && i<n-1)
        		adj=true;
        	if(r[i]=='1')
        		d++ ;
        }

        if(d%2){
        	cout<<-1<<endl;
        	continue;
        }

        if(d==2&& adj)
        	cout<<min(x,(2LL*y))<<endl;
        else{

        	cout<<((d/2)*y)<<endl;
        }




    }
    return 0 ;
}
