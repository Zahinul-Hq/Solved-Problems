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


    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	string s;
    	cin >> s;

    	set<pair<int,int>> range;



        for (int i = 0; i < s.size(); ) {
            int j = i + 1;
            while (j < s.size() && s[j] == s[i]) j++;
            range.insert({i, j - 1});
            i = j;
        }

    	int q; cin >> q;


        cout << "Case " << cs++ << ": " << endl; 

    	while(q--){
    		int t, i;

    		cin >> t >> i;

            auto it = range.upper_bound({i, INT_MAX});
            it--;

    		if(t == 1){
    			cout << it->second - it->first + 1  << endl;
    			continue;
    		}

    		

    		if(it->first == i){

                
                range.insert({i + 1, it ->second});

    		}else if(it->second == i){

                range.insert({it->first, i - 1});
            }else{
                range.insert({it->first, i -1});
                range.insert({i + 1, it->second});

            }
            range.erase(it);

    	}
    }
    return 0 ;

    runtime();

}
