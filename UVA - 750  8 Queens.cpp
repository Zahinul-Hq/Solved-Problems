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
int a, b, line = 1;
int col[8];

bool canBePlaced(int r, int c){
	for(int i = 0; i < c; i++){
		if(col[i] == r || abs(i - c) == abs(col[i] - r)){
			return false;
		}
	}
	return true;
}
void rec(int pos){
	if(pos == 8 && col[b] == a){
		if(line < 10)
			cout << " " << line++ << "      ";
		else
			cout << line++ << "      ";
		for(int i = 0; i < 8; i++){
			cout << col[i] + 1;
			if(i != 7) cout << " " ;
		}
		cout << endl;
		return ;
	}

	for(int i = 0; i < 8; i++){
		if(pos == b && i != a){
			continue;
		}
		if(canBePlaced(i, pos)){
			col[pos] = i;
			rec(pos + 1);
		}
	}

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
    	cin.ignore();
    	cin >> a >> b;
    	a-- , b--;
    	line = 1;

    	cout << "SOLN       COLUMN" << endl;
    	cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
    	rec(0);

    	if(test_cases)
    		cout << endl;


    }
    return 0 ;

    runtime();

}
