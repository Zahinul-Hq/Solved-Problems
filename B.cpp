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

    string s ;

    int n= s.size(); 

    cin>>s ;

    

    string word  ;

    vector<string>stor ;
    vector<int>check(130 , 0 ) ;

    for(int i=0 ; i<n ; i++){

    	if(check[s[i]]==0){
    		word=word+s[i] ;
    		check[s[i]]++ ;
    	}else{

    		stor.push_back(word) ;
    		word="" ;
    		check.assign(check.begin() ,check.end()) ;
    	}

    }
    string ss ;
    if(stor.size()>0){
    	 ss = *min_element(stor.begin() , stor.end()) ;
    	 cout<<ss.size()<<endl;
   	}else{
   		cout<<-1<<endl ;
   	}


    



    return 0 ;
}
