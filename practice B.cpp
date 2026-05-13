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

/*void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	//inout() ;

    int arr[4][4] ;

    double sum = 0 , ii , jj;
    double last_i = 0 , last_j=0 ;


    for(int i=1; i<=3 ; i++){
    	for(int j=1 ; j<=3 ; j++){
    		cin>>arr[i][j];

    		if(arr[i][j]==1){
    			last_i = i;
    			last_j = j;
    		}
    	}
    }


    


    for(int l = 2 ; l<=9 ; l++){

    	bool f=0;

    	for(int i=1; i<=3 ; i++){
		   	for(int j=1 ; j<=3 ; j++){

		   		if(arr[i][j]==l){

		   			if(i==last_i){
		   				sum+=(abs(last_j-j));
		   			}
		   			else if(j==last_j){
		   				sum+=(abs(last_i-i));
		   			}else{

		   				double x = pow((last_i-i) , 2);
		   				double y = pow((last_j-j) , 2);
		   				sum+=(sqrt(x+y));

		   			}

		   			last_i= i;
		   			last_j= j;

		   			f=1 ;

		   			break;

		   		}
		   	}
		   	if(f)break;

		}

    }

    cout<<fixed<<setprecision(6)<<sum<<endl;
    return 0 ;
}
