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
        int n ,x  ,zero=0 , one=0 ; 

        bool flag = false;

        cin>>n ;

       
        for(int i=0 ; i<n ;i++){

        	cin>>x ;

        	if(x==0)
        		zero++ ;
        	if(x>1)
        		flag=1;
        }

        if(zero<=ceil(1.0*n/2.0)){
        	cout<<0<<endl;
        }else if(flag || zero==n)
        	cout<<1<<endl;
        else
        	cout<<2<<endl;



    }
    return 0 ;
}
