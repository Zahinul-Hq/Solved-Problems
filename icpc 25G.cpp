#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n, m;

    	cin >> n >> m;

    	int mat[n + 1][m + 1];
    	vector<int>r(n + 1), col(m + 1);

    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			cin >> mat[i][j]; 
    		}
    	}

    	for(int i = 1; i <= n; i++){
    		int pref = 0;
    		for(int j = 1; j <= m; j++){
    			pref = pref ^ mat[i][j];
    		}
    		r[i] = pref;
    	}
    	for(int i = 1; i <= m; i++){
    		int pref = 0;
    		for(int j = 1; j <= n; j++){
    			pref = pref ^ mat[j][i];
    		}
    		col[i] = pref;
    	}
    	ll ans = 0;

    	for(int i = 1; i <= m; i++){
    		ans += col[i];
    	}
    	for(int i = 1; i <= n; i++){
    		ans += r[i];
    	}

    	ll max_ans = ans;

    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			int tmpc = col[j] ^ mat[i][j];
    			int tmpr = r[i] ^ mat[i][j];
    			ll tmp_ansr = ans - r[i] - col[j]  + (tmpc ^ tmpr);
    			ll tmp_ansc = ans - col[j] - r[i]  + (tmpc ^ tmpr);
    			max_ans = min(max_ans, tmp_ansc);
    			max_ans = min(max_ans, tmp_ansr);

    		}
    	}

    	cout << max_ans << endl;




    }
    return 0 ;

    runtime();

}
