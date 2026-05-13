#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

const int N = 105;
int arr[N], dp[N][N][2];

bool solve(int even, int odd, int parity){

	if(even + odd == 0)
		return parity == 0;

	if(dp[even][odd][parity] != -1)
		return dp[even][odd][parity];

	bool ans = 0;

	if(even > 0)
		ans |= 1 - solve(even - 1, odd, (parity + odd + 1) % 2);
	if(odd > 0)
		ans |= 1 - solve(even, odd - 1, (parity + odd + 1) % 2);


	return dp[even][odd][parity] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int n, odd = 0, sum = 0, even = 0,x;

        memset(dp, -1, sizeof dp);

        cin >> n;

        for(int i = 0; i < n; i++){

        	cin >> x;
        	if(x < 0) x *= -1;

        	if(x % 2 == 0)
        		even++;
        	else
        		odd++;
        }

        if(solve(even, odd, 0))
        	cout << "Alice" << endl;
        else
        	cout << "Bob" << endl;
    }
    return 0 ;
}
