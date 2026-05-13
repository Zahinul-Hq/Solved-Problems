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
	inout();


    int t ;
    cin>>t ;

    while (t--)
    {

    	char s[3][3] ;

    	for(int i=0 ; i<3 ;i++){
    		for(int j=0; j<3 ; j++){
    			cin>>s[i][j];
    		}
    	}


    	int flag=0 ;

    	char win='N' ;

    	for(int i=0 ; i<3 ;i++ ){
			int a=s[i][0];
			int b=s[i][1];
			int c=s[i][2];
    		if(a==b&&b==c){
    			flag++ ;
    			win=s[i][0] ;
    		}
    	}



    	if(flag==1 && win!='.'){
    		cout<<win<<endl;
    		continue ;
    	}

    	int flag2=0;
    	char win2='N' ;

    	for(int i=0 ; i<3 ;i++ ){
			int a=s[0][i];
			int b=s[1][i];
			int c=s[2][i];

    		if(a==b &&b==c){
    			flag2=flag2+1 ;
    			win2=s[0][i] ;
    		}
    	}





    	if(flag2==1 && win2!='.'){
    		cout<<win2<<endl;
    		continue ;
    	}

    	char win3='N';

    	if(((s[0][0]==s[1][1])&& (s[1][1]==s[2][2])) ||((s[0][2]==s[1][1])&&(s[1][1]==s[2][0]))){

			win3=s[1][1];


			if(win3!='.'){
    			cout<<win3<<endl;
    			continue ;
    		}
    	}


    	cout<<"DRAW"<<endl;

    }
    return 0 ;
}
