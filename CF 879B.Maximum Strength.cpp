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
        string l , r ,nwl="";

        cin>>l>>r ;

        if(l.size()<r.size()){

        	for(int i=1; i<=r.size()-l.size();i++){
        		nwl+='0';
        	}

        }

        nwl+=l ;

        ll sum= 0;

        for(int i=0 ; i<r.size() ; i++){

        	int x = abs(nwl[i]-r[i]);
        	sum+=x ;
        	if(x>0){

        		sum+=((r.size()-i-1)*9);
        		break;
        	}
        }

        cout<<sum<<endl;

    }
    return 0 ;
}
