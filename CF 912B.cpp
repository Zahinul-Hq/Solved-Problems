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

        int arr[n][n] ;

        vector<int>a;

        


        for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<n ; j++){
        		cin>>arr[i][j];
        	}
        }

        if(n==1){
        	cout<<"Yes"<<endl;
        	cout<<1<<endl;
        	continue;
        }

        for(int i=0 ; i<n ; i++){

        	int x ;

        	if(i)
        		x= arr[0][i];
        	else
        		x= arr[1][i] ;
        	for(int j=0 ; j<n ; j++){

        		if(i==j)
        			continue ;
        		x=(x&arr[j][i]);
        	}

        	a.pb(x) ;
        }

        bool ok = 1;


        for(int i=0 ; i<a.size() ; i++){
        	for(int j=0 ; j<a.size() ; j++){

        		if(i==j)
        			continue ;

        		int x = a[i] ;

        		int y = a[j] ;

        		int z = (x|y) ;

        		if(z!=arr[i][j])
        			ok=0;



        	}

        }

        

        if(ok){
        	cout<<"Yes"<<endl;
        	for(int i=0 ; i<a.size() ;i++){
        		cout<<a[i]<<" " ;
       		 }
        }
        else
        	cout<<"No";


        

        cout<<endl;


    }
    return 0 ;
}
