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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	string x;

    	cin >> x;

    	string s = x;

    	reverse(x.begin(), x.end());
    	x.pop_back();

    	sort(x.begin(), x.end());
    	int sum = s[0] - '0', cnt = 0;
    	
    	int f= 1;
    	for(int i = 0; i < (int)x.size(); i++){

    		if(sum + (x[i] - '0') <= 9){
    			sum += (x[i] - '0');
    			cnt++;
    			if(x[i] == s[0]){
    				f = 0;
    			}
    		}else{
    			break;
    		}
    	}
    	debug(f,cnt);

    	cout << (int)x.size() - (cnt + f) << endl;
    }
    return 0 ;

    runtime();

}
