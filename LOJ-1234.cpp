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

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int N = 1e8 + 2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;



	vector<pair<int,int>>cases;


    int test_cases, cs = 1;
    cin >> test_cases ;
    
    while (test_cases--)
    {

    	int n;

    	cin >> n;

    	cases.push_back({n, cs++});
    }

    sort(cases.begin(), cases.end());

    vector<double>ans(10005, -1.0);

    double H = 0.0;
    int c = 0;

   	for(int i = 1; i < N; i++){
		double d = 1.00 / i;
		H = H + d;
		while(cases[c].first == i && c <= cs){
			ans[cases[c++].second] = H;
		}
	}

	for(int i = 1; i <= cs; i++){

		if(ans[i] > -1.0){
			cout << "Case " << i << ": " << fixed << setprecision(10) << ans[i] << endl;
		}
	}

    
    runtime();
    return 0 ;

    

}
