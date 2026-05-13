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
        string s ;

        cin>>s ;

        int flag=0 ;

        if(s[0]=='a' )
        	flag++ ;
        if(s[1]=='b' )
        	flag++ ;
        if(s[2]=='c' )
        	flag++ ;

        if(flag>=1)
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;

    }
    return 0 ;
}
