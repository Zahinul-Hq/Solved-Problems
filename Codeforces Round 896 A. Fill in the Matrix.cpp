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
        int n , k ;


        cin>>n>>k ;


        if(k==1)
        	cout<<0<<endl;
        else
        	cout<<min(n+1,k)<<endl;

        int cnt =1 , x=k-1 ;

        for(int i=1; ; i++){
        	
        	if(x>0)
        		i=i%x;
        	
        	for(int j=i ; j<k+i ; j++){
        		cout<<j%(k)<<" ";
        	}

        	cout<<endl;

        	if(cnt++==n)
        		break;
        }
    }
    return 0 ;
}
