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
const int N = 1e7 +3;
vector<int>spf(N, 0);
void seive(){

	for(int i = 2; i <= N; i++){
		spf[i] = i;
	}
	for(int i = 2; i <= N; i++)
			for(int j = i + i; j <= N; j += i)
				spf[j] = min(spf[j] ,i);

}
set<int>factorials(int val){
	set<int>facts;

	while(val > 1){
		facts.insert( spf[val]);
		val = val / spf[val];

	}
	return facts;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;
	seive();

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int x, y;
        cin >> x >> y;

        if(__gcd(x, y) != 1){
        	cout << 0 << endl;
        	continue;
        }
        if(x < y){
        	swap(x, y);
        }
        int diff = (x - y);
        if(diff == 1){
        	cout << -1 << endl;
        	continue;
        }
        if(diff % 2 == 0){
        	cout << 1 << endl;
        	continue;
        }
        set<int>factors = factorials(diff);
        int ans = INT_MAX;



        for(auto p : factors){
        	ans = min(ans, ((x + p - 1) / p) * p);
        	//cout << ans << endl;
        }

        cout << ans - x << endl;
    }
    return 0 ;
}
