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
	inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        string s  , ans;

        cin>>s ;

        for(int i=0 ;i<50 ; i++)
        {
        	ans+="Yes" ;
        }

        if(ans.find(s) )
        	cout<<"Yes"<<endl ;
        else
        	cout<<"No"<<endl ;




    }
    return 0 ;
}
