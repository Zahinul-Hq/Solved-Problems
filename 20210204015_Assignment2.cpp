#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define inf   2e18
int main()
{

	int node , edges , weight ;

	cin>>node>>edges>>weight ;

	ll dis[node+1][node+1] ; 

	for(int i=0 ; i<=node ; i++){
		for(int j=0 ; j<=node ; j++){
			if(i==j)
				dis[i][j]=0;
			else
				dis[i][j]=inf ;
		}
	}

	int a , b , w ;

	while(edges--){

		cin>>a>>b>>w ;
		dis[a][b]=w ;
	}

	for (int k = 0; k <=node; ++k) {
	    for (int i = 0; i <=node; ++i) {
	        for (int j = 0; j <=node; ++j) {
	            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
	        }
	    }
	}

	for(int i=1 ; i<=node ; i++){
		for(int j=1 ; j<=node ; j++){
			
			if(dis[i][j]==inf)
				cout<<"No path " ;
			else
				cout<<dis[i][j]<<" ";
		}
	}

	cout<<endl;



    
    return 0 ;
}
