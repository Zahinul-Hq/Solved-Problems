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
        int n ,q;

        cin>>n ;

        int a[n+1] ,pref[n+1];

        a[0]=0;

        for(int i=1 ; i<=n ; i++){
        	cin>>a[i] ;
        }

        cin>>q ;

        for(int i=1 ; i<=n ; i++){

        	if(i==1){
        		pref[i]=0;
        		continue ;
        	}

        	if(a[i-1]!=a[i]){
        		pref[i]= pref[i-1]+1;
        	}else{
        		pref[i]=pref[i-1] ;
        	}
        }

       /* for(int i=1 ; i<=n ; i++){
        	cout<<pref[i]<<" ";
        }

        cout<<endl;*/


        while(q--){

        	int l ,r ;

        	cin>>l>>r ;

        	if(pref[l]==pref[r]){
        		cout<<-1<<" "<<-1<<endl;
        		continue ;
        	}   


        	int indx = upper_bound(pref , pref+r , pref[l])-pref; 


        	cout<<l<<" "<<indx<<endl;

        }

        cout<<endl;


    }
    return 0 ;
}
