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
        ll n ,x, sev=0 ,neg=0,sod=0, mx=low;

        cin>>n ;

        for(int i=1; i<=n ; i++){

        	cin>>x ;

        	

        	if(i%2==0 && x>0)
        		sev+=x;
        	
        	if(i%2==1&&x>0)
        		sod+=x;

        	if(x<0)
        		neg++ ;
        	
        	mx=max(mx ,x) ;

        }

       	if(neg==n)
       		cout<<mx<<endl;
       	else
       		cout<<max(mx,max(sev,sod))<<endl;
    }
    return 0 ;
}
