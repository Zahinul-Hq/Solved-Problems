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
        vector<int>a(3,0) ;

        cin>>a[0]>>a[1]>>a[2] ;

        sort(a.begin() ,a.end());


        if(a[1]%a[0]!=0 || a[2]%a[0]!=0 ){
        	cout<<"No"<<endl;
        	continue ;
        }

        int x = a[1]/a[0] ;

        x-- ;

        int y = a[2]/a[0] ;

        y-- ;

        if(x+y<=3)
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;

    }
    return 0 ;
}
