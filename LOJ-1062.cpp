#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define long double double 
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
double x, y, c;
bool func(double d){

	double sq1 = sqrt((x * x) - (d * d));
	double sq2 = sqrt((y * y) - (d * d));

	return  (c * (sq1 + sq2)) <= (sq1 * sq2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {

    	cin >> x >> y >> c;

    	double lo = 0.0, hi = min(x, y);

    	double eps = 1e-7, ans = 0;

    	while(hi - lo > eps){
    		double mid = (hi + lo) / 2.0;

    		if(func(mid)){
    			lo = mid ;
    			ans = mid;
    		}else{
    			hi = mid ;
    		}
    	}

    	cout << "Case " << cs++ << ": " << fixed << setprecision(6) << ans << endl;



    }
    return 0 ;

    runtime();

}
