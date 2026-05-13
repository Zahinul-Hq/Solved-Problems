#include<bits/stdc++.h>
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
int calculateArea(vector < int > & heights, int start, int end) {
  if (start > end) {
    return 0;
  }
  int min_index = start;
  for (int i = start; i <= end; i++) {
    if (heights[min_index] > heights[i]) {
      min_index = i;
    }
  }
  return max({
    heights[min_index] * (end - start + 1),
    calculateArea(heights, start, min_index - 1),
    calculateArea(heights, min_index + 1, end)
  });
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int n ;

    cin >> n;

    vector<int>v(n , 0);

    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }

    cout << calculateArea(v, 0, n - 1) << endl;
    return 0 ;
}
