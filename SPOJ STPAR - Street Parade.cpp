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

    
    while (1)
    {
       	int n;
       	cin >> n;

       	if(!n)
       		break;

       	vector<int>ans, input(n,0);

       	for(int i = 0; i < n; i++){
       		cin >> input[i];

       	}

       	int val = 1;

       	stack<int>st;

       	for(int i = 0; i < n; i++){

       		if(input[i] == val){
       			ans.push_back(val);
       			val++;
       		}
       		else{

       			while( !st.empty() && st.top() == val){
       				ans.push_back(val);
       				st.pop();
       				val++;
       			}

       			st.push(input[i]);
       		}
       	}

       	while( !st.empty() && st.top() == val){
       		ans.push_back(val);
       		st.pop();
       		val++;
       	}




       	if(st.empty() && is_sorted(ans.begin(), ans.end()) && ans.size() == n){

       		cout << "yes" << endl;

       	}else
       		cout << "no" << endl;


    }

    return 0 ;
}
