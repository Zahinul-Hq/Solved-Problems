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

bool cmp(int x, int y){
	if(x >= y)
		return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	int n;
	cin >> n;
	vector<int>a(n), b(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	vector<pair<int,pair<int,char>>>range;

	range.push_back({0, {n - 1, 'D'}});
	sort(a.rbegin(), a.rend());

	for(int i = 0; i < n ; i++){
		int j = i;

		if(a[j] == b[i])
			continue;

		while(a[j] != b[i]  && j < n){
			j++;

		}

		//debug(a[i], b[i]);
		if(a[i] > b[i]){
			sort(a.begin() + i, a.begin() + j + 1);
			range.push_back({i, {j , 'I'}});
		}else if(a[i] < b[i]){
			sort(a.begin() + i, a.begin() + j + 1, cmp);
			range.push_back({i, {j , 'D'}});
		}
		//debug(i, a, range[i + 1 ], j);
		
	}

	cout << range.size() << endl;

	for(auto i : range){
		cout << i.first + 1 << " " << i.second.first + 1  << " "<< i.second.second << endl;
	}


    return 0 ;
}
