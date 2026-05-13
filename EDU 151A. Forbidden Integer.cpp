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
        int n , k , x ;

        cin>>n>>k>>x ;

        int div = n/k , val=0 , mval=0 ;
        bool flag=0 ;


        if( (x==1 && k<3 )){

        	if(n&1 || k==1){
        		cout<<"No"<<endl;
        		continue ;
        	}
        	
        }


        if(x!=1){

        	cout<<"Yes"<<endl<<n<<endl;

        	for(int i=0 ; i<n ;i++){
        		cout<<1<<" " ;
        	}
        }else if(n%2==0){

        	cout<<"Yes"<<endl<<n/2<<endl;

        	for(int i=1 ; i<=n/2 ;i++)
        		cout<<2<<" " ;
        }else{

        	cout<<"Yes"<<endl<<n/2 <<endl;

        	for(int i=1 ; i<n/2 ;i++)
        		cout<<2<<" " ;

        	cout<<3 ;

        }

        cout<<endl; 
	    
    }
    return 0 ;
}
