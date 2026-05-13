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
        ll k ;

        cin>>k ;

        vector<ll>dig ;

        while(k>0){

        	dig.push_back(k%9) ;
        	k= k/9 ;
        }
        reverse(dig.begin() ,dig.end());

        for(int i=0 ; i<dig.size() ;i++){

        	if(dig[i]>=4)
        		cout<<dig[i]+1 ;
        	else
        		cout<<dig[i] ;
        }

        cout<<endl;
    }

    return 0 ;
}