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

        vector<int>vec(n+1,0 );

        for(int i=1 ; i<=n ; i++){
        	cin>>vec[i] ;
        }

        if(n==1){
        	cout<<0<<endl;
        	continue ;
        }

        if(vec[1]+vec[n]%2!=0)
        	vec[n]=vec[1] ;
        else
        	vec[1]=vec[n] ;

        cout<<n-1<<endl;

        cout<<1<<" "<<n<<endl;


        for(int i=2; i<n ; i++){

        	if((vec[1]+vec[i]) %2!=0)
        		cout<<1<<" "<<i<<endl;
        	else
        		cout<<i<<" "<<n<<endl;

        }


    }
    return 0 ;
}
