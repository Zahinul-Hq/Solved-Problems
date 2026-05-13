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

        vector<int>vec(n,0) ;

        for(int i=0 ; i<n ; i++){
        	cin>>vec[i] ;
        }

        vector<int>less ;

        bool flag=0 ;

        for(int i=0 ; i<n-1 ; i++){
        	 
        	 int x= vec[i+1]-vec[i] ;

        	 if(x<0){
        	 	flag=1 ;
        	 	break;
        	}
        	 else
        	 	less.pb(x);
        }

        if(flag)
        	cout<<0<<endl;
        else{

        	int mn = 0 ;

        	if(less.size()>=1)
        		mn= *min_element(less.begin() , less.end());


        	cout<<(mn/2)+1<<endl;
        }




    }
    return 0 ;
}
