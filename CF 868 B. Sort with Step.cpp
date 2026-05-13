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
        int n , k ,cnt=0; 

        cin>>n>>k ;

        vector<int>vec(n+1,0) ;

        for(int i=1;i<=n;i++){
        	cin>>vec[i];
        }

        for(int i=1 ; i<=n ; i++){

        	if(vec[i]%k != i%k)
        		cnt++ ;
        }

        if(cnt==0)
        	cout<<0<<endl;
        else if(cnt==2)
        	cout<<1<<endl;
        else
        	cout<<-1<<endl;
    }
    return 0 ;
}
