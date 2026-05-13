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

        string s;

        cin>>s;


        stack<char>st ;

        map<char,int>mp ;

        priority_queue<pair<char,int>>pq ;

        for(int i=0; i<n ;){

        	int j=i;

        	while(s[i]==s[j])
        		j++ ;

        	pq.push({s[i],(j-i)});

        	//cout<<j-i<<endl;

        	i=j ;
        }


        while(pq.size()!=1){

        	auto tp = pq.top() ;

        	pq.pop() ;

        	auto stp = pq.top();

        	pq.pop() ;

        	if(tp.F==stp.F){
        		pq.push({tp.F,(tp.S+stp.S)});
        	}else{
        		pq.push(abs(tp.S-stp.S)) ;
        	}

        }

        //cout<<pq.top()<<endl;
        

        
    }
    return 0 ;
}
