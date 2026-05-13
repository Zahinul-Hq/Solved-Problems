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
    	int n;
    	cin >> n;

    	string s;
    	cin >> s;
    	vector<int>suff_indx(n + 1, n + 1), suff(n + 5, 0);


    	for(int i = n - 1; i >= 0; i--){

    		if(s[i] == '('){
    			suff_indx[i] = i;
    		}else{
    			suff_indx[i] = suff_indx[i + 1]; 
    		}

            
            suff[i] += s[i] == '(';
            suff[i] += suff[i + 1];
            
    	}


    	int mx = -1;

    	for(int i = 0; i < n; i++){
            if(s[i] == ')' && suff_indx[i] <= n ){
                int d = suff_indx[i] - i;
                if(suff[suff_indx[i] + 1] >= d){
                    mx = max(mx, n - (2 * d));
                }
            }
        }

    	cout << mx << endl;

    	
    }
    return 0 ;

    runtime();

}
