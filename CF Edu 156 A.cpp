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

        bool flag=0 ;

        if(n<7 || (n==9))
        	cout<<"NO"<<endl;
        else if(n%3==0)
        	cout<<"YES"<<endl<<1<<" "<<4<<" "<<n-5<<endl;
        else if(n%3!=0)
        	cout<<"YES"<<endl<<1<<" "<<2<<" "<<n-3<<endl;
        else
        	cout<<"NO"<<endl;
    }
    return 0 ;
}
