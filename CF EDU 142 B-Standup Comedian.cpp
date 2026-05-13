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
        int a , b, c ,d;

        cin>>a>>b>>c>>d ;

        int ans = a ;
        if(a+b+c+d == 0){
        	cout<<0<<endl;
            continue ;
        }
        else if(a==0){
        	cout<<1<<endl;
            continue ;
        }
        else{

        	int mn = min(b ,c );

        	mn = mn*2 ;


        	ans=ans+mn ;

            ans= ans+ min(a+1 , (abs(b-c)+d)) ;

        	
        }

        cout<<ans<<endl;
    }
    return 0 ;
}
