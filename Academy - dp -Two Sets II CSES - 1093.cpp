#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define endl  "\n"

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

const int N = (505 * 506) / 2, mod = 1e9 + 7;
int dp[505][N], total_sum ;


int power(int a, int k){

	int ans = 1;

	while(k){

		if(k & 1){
			ans = 1LL * ans * a % mod;
		}

		a = 1LL * a * a % mod;

		k >>= 1;
	}

	return ans;
}

int inverse(int x){
	return power(x, mod - 2);
}

ll sets(int i, int sum){

	if( i == 0){
		if(sum == (total_sum - sum))
			return 1;

		return 0;
	}

	if(dp[i][sum] != -1){
		return dp[i][sum];
	}

	int ans = sets(i - 1, sum);

	ans += sets(i - 1, sum + i);

	ans %= mod;

	return dp[i][sum] = ans ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n;

    cin >> n;

    memset(dp, -1, sizeof dp);

    total_sum = (n * (n + 1)) / 2;

    if(total_sum % 2 != 0){
    	cout << 0 << endl;

    	return 0 ;
    }

    cout << (sets(n, 0) * inverse(2)) % mod << endl;


    return 0 ;
}
