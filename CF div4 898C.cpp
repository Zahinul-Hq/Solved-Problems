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
        char ch[11][11];

        int sum = 0 ;

        for(int i=1 ; i<=10 ; i++){
        	for(int j=1 ; j<=10 ; j++){
        		cin>>ch[i][j] ;
        	}
        }


        for(int i=1 ; i<=10 ; i++){

        	if(ch[1][i]=='X'){
        		sum+=1 ;
        	}
        	if( ch[10][i]=='X'){
        		sum+=1 ;
        	}

        	if((ch[i][1]=='X')&& (i>1 && i<10)){ 
        		sum+=1 ;

        	}
        	if((ch[i][10]=='X')&& (i>1 && i<10)){ 
        		sum+=1 ;

        	}
        }


        for(int i=2 ; i<=9 ; i++){

        	if(ch[2][i]=='X')
        		sum+=2 ;
        	if(ch[9][i]=='X')
        		sum+=2 ;

        	if((ch[i][2]=='X' ) && (i>2&& i<9))
        		sum+=2 ;
        	if( (ch[i][9]=='X') && (i>2&& i<9))
        		sum+=2 ;
        }

        for(int i=3 ; i<=8 ; i++){

        	if(ch[3][i]=='X' )
        		sum+=3 ;
        	if( ch[8][i]=='X')
        		sum+=3 ;
        	if((ch[i][3]=='X')&& (i>3 && i<8))
        		sum+=3 ;
        	if((ch[i][8]=='X')&& (i>3 && i<8))
        		sum+=3 ;
        }

        for(int i=4 ; i<=7 ; i++){

        	if(ch[4][i]=='X')
        		sum+=4 ;
        	if(ch[7][i]=='X')
        		sum+=4 ;
        	if((ch[i][4]=='X') && (i>4 && i<7))
        		sum+=4 ;
        	if((ch[i][7]=='X') && (i>4 && i<7))
        		sum+=4 ;
        }



        for(int i=5 ; i<=6 ; i++){

        	if(ch[5][i]=='X')
        		sum+=5 ;
        	if(ch[6][i]=='X')
        		sum+=5 ;
        	if((ch[i][5]=='X' )&& (i>5 && i<6))
        		sum+=5 ;
        	if((ch[i][6]=='X')&& (i>5 && i<6))
        		sum+=5 ;
        }

        cout<<sum<<endl;
    }
    return 0 ;
}
