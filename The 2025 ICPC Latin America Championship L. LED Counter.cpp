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


    string dig[10] = 
    {	"GGGgGGG",
		"gggggGG",
		"gGGGGGg",
		"ggGGGGG",
		"GggGgGG",
		"GgGGGgG",
		"GGGGGgG",
		"ggGggGG",
		"GGGGGGG",
		"GgGGGGG",
	};
	int n;
	cin >> n;
	string s;

	debug(dig);  

	for(int i = 0; i < n; i++){
		cin >> s;
		int digit = -1, mx = -1;
		vector<int>freq(10, 0);
		for(int d = 0; d <= 9; d++){
			int cnt = 0;
			for(int l = 0; l < 7; l++){
				if(s[l] == '+' || s[l] == '-'){
					continue;
				}
				cnt += (s[l] == dig[d][l]);
			}
			freq[cnt]++;
			if(cnt > mx ){
				digit = d;
				mx = cnt;
			}
			//debug(d, cnt, mx, digit);
		}

		debug(freq, mx);

		if(digit == -1 || freq[mx] > 1){
			cout << "*";
		}else{
			cout << digit;
		}
	}

	cout << endl;


    return 0 ;

    runtime();

}
