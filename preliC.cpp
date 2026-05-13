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
const int N = 1e6 + 7;
vector<int>dis_val(N, 0);
void pre_calculate(){
	for(int i = 2; i <N; i++){
		if(!dis_val[i])
			for(int j = i; j < N; j += i)
				dis_val[j]++;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

	pre_calculate();
	int pref_sum[11][N];
	memset(pref_sum, 0, sizeof pref_sum);

	for(int i = 1; i <= 10; i++){
		for(int j = 1; j < N; j++){
			pref_sum[i][j] = pref_sum[i][j - 1] + (dis_val[j] == i);
		}
	}

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int l, r, n;
        cin >> l >> r >> n;

        int ans = pref_sum[n][r] - pref_sum[n][l - 1];

        cout << ans << endl;
    }
    return 0 ;
}
