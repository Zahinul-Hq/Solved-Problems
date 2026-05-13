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

string a, b;
string dp[105][105];
string lcs(int i , int j){


	if(a.size() <= i || b.size() <= j)
		return "";

	if(dp[i][j] != "#")
		return dp[i][j];


	string ans = "";

	if(a[i] == b[j]){
		ans = string(1, a[i]) + lcs(i + 1, j + 1);;
	}else{

		string x = lcs(i + 1, j);
		string y = lcs(i, j + 1);

		if(x.size() < y.size()){

			ans = y;
		}else if( x.size() > y.size()){

			ans = x;
		}else{
			ans = min(x, y);
		}

	}

	return dp[i][j] = ans;

}

/*void print(int i, int j){
	if(a.size() <= i || b.size() <= j)
		return ;
	

	string x = lcs(i + 1, j);
	string y = lcs(i, j + 1);
	if(a[i] == b[j]){
		cout << a[i] ;
		print(i + 1, j + 1);
		return ;
	}

	if(x >= y){
		print(i + 1, j);
	}else{
		print(i, j + 1);
	}



}*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t, c = 1;
    cin >> t ;
    
    while (t--)
    {
    	cin.ignore();

    	for(int i = 0; i < 105; i++){
    		for(int j = 0; j < 105; j++){
    			dp[i][j] = "#";
    		}
    	}

    	cin >> a >> b;

    	string ans = lcs(0, 0);


    	cout << "Case " << c++ << ": "; 

    	if(ans.size() == 0){

    		cout << ":(";
    	}else{

    		cout << ans;
    	}

    	cout << endl;


        
    }
    return 0 ;
}
