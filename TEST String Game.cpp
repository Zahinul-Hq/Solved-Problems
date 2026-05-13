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

string s1, s, s2;

void half(int n){
	s1.clear(), s2.clear();
	for(int i = 0; i < n / 2; i++){
    	s1.push_back(s[i]);
    	s2.push_back(s[(n / 2) + i]);
    }

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    ll n, k;
    cin >> n >> k;

    cin >> s;



    bool f = 1;

    vector<string>pre;

    for(int i = 1; i <= min(4LL, k); i++){
    	
    	half(n);
    	int s1_last = s1.size() - 1;
    	int s2_last = s2.size() - 1;
    	if(f){
    		swap(s1[0], s2[s2_last]);
    		swap(s1, s2);
    		s = s1 + s2;
    	}else{

    		swap(s1[s1_last], s2[0]);

    		s = s1 + s2;

    		reverse(s.begin(), s.end());
    	}

    	f ^= 1;

    	pre.push_back(s);

    }

    cout << pre[(k - 1) % 4] << endl;

    //cout << s << endl;

    
    return 0 ;

    runtime();

}
