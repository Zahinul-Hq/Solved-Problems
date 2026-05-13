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

bool possible (int val , int mx){

	if(val==mx){
		return true ;
	}
	vector<int>a ;
	int x= val ;

	while((val-x)<=20){

		int r = val%10 ;
		if(r==0)break;
		val+=r ;

		if(val==mx)
			return true;
		a.pb(val);
	}

	for(auto i : a){

		if(mx>i &&((mx-i)%20==0))
			return true;
	}

	return false ;
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
        int n , mx=-1; cin>>n ;
        vector<int>a(n,0) ;

        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;

        	if(a[i]%2)
        		a[i]+=(a[i]%10) ;
        	mx=max(mx,a[i]);
        }

        bool ok = true ;

        for(int i=0 ; i<n ; i++){

        	if(!possible(a[i],mx))
        		ok=false ;
        }

        if(ok)
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;

        
    }
    return 0 ;
}
