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


int dp[1005][1005];

string s;

int Longest_Palindrome(int start , int end){


	if(start > end)
		return 0;
	if(start == end)
		return 1;

	if(dp[start][end] != -1)
		return dp[start][end];

	int ans = 0;

	if(s[start] == s[end])
		ans = 2 + Longest_Palindrome(start + 1, end - 1);
	else
		ans = max(Longest_Palindrome(start + 1, end),Longest_Palindrome(start, end - 1));


	return dp[start][end] = ans; 


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;

    cin.ignore();
    
    while (t--)
    {

    	memset(dp, -1, sizeof dp);
    	
        getline(cin, s);

        cout << Longest_Palindrome(0, s.size() - 1) << endl;
    }
    return 0 ;
}
