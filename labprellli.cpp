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
        int n,x ,ans=1;

        cin>>n ;

        x=n ;


        if(n<=6){
        	cout<<"bob"<<endl;

        	continue ;
        }

        while((n/6)>0){

        	int i=0;

        	ans++ ;

        	while(!((6*i)<n))
        		i++ ;

        	if(i)
        		n=n-(n/i) ;
        	else
        		break ;
        }

        if(ans%2==0)
        	cout<<"Bob"<<endl;
        else
        	cout<<"Alice"<<endl;
    }
    return 0 ;
}
