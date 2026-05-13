#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n, k, s, f;
    cin >> n >> k;
    vector<pair<int,int>> activities;
    for (int i = 0; i < n; i++) {
        cin >> s >> f;
        activities.pb({f, s}); // sort by ending time
    }

    sort(activities.begin(), activities.end());

    int cnt = 0;
    multiset<int> ends;
    for (int i = 0; i < k; i++) ends.insert(0);
    for (auto a : activities) {
        auto pos = ends.upper_bound(a.second);

        for(auto it : ends){
        	cout<<it<<" ";
        }

        cout<<endl;
        if (pos != ends.begin()) {
            ends.erase(prev(pos));
            ends.insert(a.first + 1);
            cnt++;
        }
    }

   // cout << cnt;
    return 0 ;
}
