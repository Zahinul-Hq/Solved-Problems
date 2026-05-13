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

    int tt ;
    cin>>tt;
    
    while (tt--)
    {
        int t, w, x, d ;

        cin>>t>>x>>d>>w ;

        vector<int>vec(t,0), diff;

        for(int i=0 ; i<t ; i++){
        	cin>>vec[i] ;
        }

        ll kk=x ,cnt=0 ,valid=0 ;

        for(int i=0 ; i<t ; i++){

        	if(i==0 or valid<vec[i] or kk<1){
        		cnt++ ;
        		kk=x ;
        		valid = vec[i]+w+d ;
        	}

        	kk-- ;
        }

        cout<<cnt<<endl;
    }
    return 0 ;
}
