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

    int t , c = 1 ;
    cin>>t ;
    
    while (t--)
    {
    	string s ,curr = "http://www.lightoj.com/" ;
    	stack <string> backward;
    	stack <string> forward;

    	cout<<"Case "<<c++<<": "<<endl;

        while(1){

        	cin >> s;

        	if(s == "QUIT")
        		break ;
        	else if(s == "VISIT"){

        		backward.push(curr) ;
        		cin >> curr ;
        		cout << curr <<endl;

        		while(!forward.empty())
        			forward.pop();


        	}else if(s == "BACK"){

        		if(!backward.empty()){

        			forward.push(curr);
        			curr = backward.top() ;
        			cout << curr << endl;
        			backward.pop();

        		}else{
        			cout << "Ignored" << endl;
        		}

        	}else if(s == "FORWARD"){

        		if(!forward.empty()){

        			backward.push(curr);
        			curr = forward.top();
        			cout << curr << endl;
        			forward.pop();

        		}else{
        			cout << "Ignored" << endl;
        		}
        	}
        }
    }
    return 0 ;
}
