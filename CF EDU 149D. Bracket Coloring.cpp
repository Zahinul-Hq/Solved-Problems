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

    	int n ,cnt=1 , sz=1 ; 
    	string s ;
    	map<char , int>mp ;

    	cin>>n>>s ;
    	char l=')', r='(' , ch=s[0];

    	for(int i=0 ; i<n ; i++){
    		mp[s[i]]++ ;
    	}



    	if(mp[l]!=mp[r]){
    		cout<<-1<<endl;
    		continue ;
    	}

    	vector<int>mark(n,0) ;
    	stack<pair<char,int>>st ;

    	if(s[0]!=l){
    		r= l;
    		l=s[0] ;
    	}

    	for(int i=0 ;i<n ;i++){

    		if(s[i]==l)
    			st.push({s[i], i}) ;
    		else if(!st.empty()){

    			auto x = (st.top()) ;
    			mark[i]=cnt ;
    			mark[x.S]=cnt ;
    			st.pop() ;
    		}

    	}

    	while(!st.empty()){
    		st.pop() ;
    	}

    	cnt++ ;

    	for(int i=0 ;i<n ;i++){


    		if(mark[i]>0)
    			continue ;

    		if(s[i]==r)
    			st.push({s[i], i}) ;
    		else if(!st.empty()){

    			auto x = (st.top()) ;
    			mark[i]=cnt ;
    			mark[x.S]=cnt ;
    			st.pop() ;
    		}

    		sz=max(mark[i],sz);

    	}

    	cout<<sz<<endl;

    	for(int i=0 ; i<n ; i++){
    		cout<<mark[i]<<" ";
    	}

    	cout<<endl;

    }
    return 0 ;
}
