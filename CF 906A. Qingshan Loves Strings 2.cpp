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
        int n , zero=0 , one=0;

        string s ;

        cin>>n>>s;

         vector<int>ans ;
        deque<char>q ;


        for(int i=0 ; i<s.size() ; i++){

        	if(s[i]=='0')
        		zero++ ;
        	else
        		zero-- ;

        	q.pb(s[i]);

        } 

        if(n%2==1 || (zero!=0)){
        	cout<<-1<<endl;
        	continue;
        }

        int c = 0 ;


        while(!q.empty()){

        	if(q.front()==q.back()){

        		if(q.front()=='0'){
        			q.push_back('0');
        			q.push_back('1');
        			ans.push_back(n-c) ;
        		}else{

        			q.push_front('1');
        			q.push_front('0');
        			ans.push_back(0+c) ;
        		}

        		n+=2 ;
        	}

        	while(!q.empty() && (q.front()!=q.back())){
        		q.pop_back() ;
        		q.pop_front() ;
        		c++ ;
        	}

        }
        


        cout<<ans.size()<<endl;

        for(int i =0 ; i<ans.size() ; i++){

        	cout<<ans[i]<<" " ;

        }

        cout<<endl;


    }
    return 0 ;
}
