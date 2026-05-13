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
void solution(){

	cout<<"|---------------------------|"<<endl;
	cout<<"|Sun|Mon|Tue|Wed|Thu|Fri|Sat|"<<endl;
	cout<<"|---------------------------|"<<endl;
}
unsigned day_of_week( unsigned year, unsigned month, unsigned day )
  {
  unsigned a, y, m;
  a = (14 - month) / 12;
  y = year - a;
  m = month + (12 * a) - 2;
  // Gregorian:
  return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
  }
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    string s,  bar ;

    char x,y,z ;

    int  day  , mnth  ,year ;

    cin>>day>>x>>mnth>>y>>year>>bar ;


    int cnt = 0 ;


    if(mnth==1||mnth==3||mnth==5||mnth==7||mnth==8||mnth==10||mnth==12){
    	cnt=31 ;

    }else if(mnth==2){
    	if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)){
    		cnt=29 ;

    	}else{
    		cnt=28 ;
    	}
    }else{
    	cnt=30 ;
    }

    cout<<cnt<<endl;

    int arr[5][7];

    for(int i=0 ; i<5 ; i++){
    	for(int j=0 ; j<7 ; j++){
    		arr[i][j]=0 ;
    	}
    }

    int f = day_of_week(year,mnth , 1) ;

    int p = 1;

    for(int i=0 ; i<5 ; i++){
    	int j=0 ;
    	if(i==0)j=f;

    	for( ; j<7 ; j++){

    		if(p<=cnt)
    			arr[i][j]=(p++);
    		
    		
    	}
    }
    cout<<"|---------------------------|"<<endl;
	cout<<"|Sun|Mon|Tue|Wed|Thu|Fri|Sat|"<<endl;
	cout<<"|---------------------------|"<<endl;

    for(int i=0 ; i<5 ; i++){
    	cout<<"| ";
    	for( int j =0 ; j<7 ; j++){

    		if(arr[i][j]==0){
    			cout<<"- |";
    		}else{
    			cout<<arr[i][j]<<"|";
    		}
    		
    	}
    	cout<<endl;
    }

    return 0 ;
    
}
