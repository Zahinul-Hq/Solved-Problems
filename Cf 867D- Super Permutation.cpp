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

       	if(n==1){
       		cout<<1<<endl;
       	}
      	else if(!(n&1)){

       		cout<<n<<" "; 

       		for(int i=n-1 ; i>=1 ; i--){

       			if((i&1))
       				cout<<i;
       			else{
       				n=n-4 ;
       				cout<< i-n;
       			}
       			if(i!=1)
       				cout<<" ";
       			else
       				cout<<endl;
       		}
       }
       else{

       	cout<<-1<<endl;
       }

    }
    return 0 ;
}
