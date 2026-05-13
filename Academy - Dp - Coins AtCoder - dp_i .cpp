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

const int N = 3003;
double dp[N][N], p[N];
double probability(int i, int head, int tail){

	if(i == 0){
		if(head > tail)
			return 1;

		return 0;
	}

	if( dp[i][head] > -1.00)
		return dp[i][head];

	double ans = p[i] * probability(i - 1 , head + 1, tail);
	ans += (1 - p[i]) * probability(i - 1, head, tail + 1);


	return dp[i][head] = ans ;


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n; 

    cin >> n;

    memset(dp, -1.00, sizeof dp);

    for(int i = 1; i <= n; i++){
    	cin >> p[i];
    }

    double ans = probability(n, 0, 0);

    cout << fixed << setprecision(10) << ans << endl;


    return 0 ;
}
