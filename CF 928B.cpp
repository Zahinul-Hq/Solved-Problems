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

        char arr[n+1][n+1];


        for(int i=0 ; i<n ;i++){
        	for(int j=0 ; j<n ; j++){
        		cin>>arr[i][j];

        	}

        }

        int val=0 ;

        vector<int>ln(n+1,0);

        for(int i=0 ; i<n ;i++){
        	for(int j=0 ; j<n ; j++){

        		//cout<<arr[i][j]<<" ";

        		if(arr[i][j]=='1'){
        			ln[i]++;
        		}
        		
        	}

        	//cout<<endl;
        	if(ln[i]!=0)
        		val=ln[i] ;
        }




        int f =0 ;


        for(int i=0 ; i<n ; i++){

        	//cout<<ln[i]<<" ";

        	if(ln[i]==0)
        		continue ;

        	if(val!=ln[i]){
        		f=1;
        		break ;
        	}

        }

        if(f)
        	cout<<"TRIANGLE"<<endl;
        else{
        	cout<<"SQUARE"<<endl;
        }
    }
    return 0 ;
}
