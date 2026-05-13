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
	inout() ;

    int test_cases, cs =1 ;
    cin >> test_cases ;
    vector<string>mont{"X", "January", "February", "March", "April", "May" , "June" ,"July" ,"August", "September", "October", "November", "December" };
    map<string, int> month;
    for(int i = 1; i <= 12; i++){
       	month[mont[i]] = i;
    }
    
    while (test_cases--)
    {
    	string m1, d1, y1;
    	cin >> m1 >> d1 >> y1;
    	string m2, d2, y2;
    	cin >> m2 >> d2 >> y2;
    	d1.pop_back();
    	d2.pop_back();

    	int mnth1 = month[m1];
    	int day1 = stoi(d1);
    	int year1 = stoi(y1);
    	int mnth2 = month[m2];
    	int day2 = stoi(d2);
    	int year2 = stoi(y2);

    	if(mnth1 > 2)
    		year1++;
    	if(mnth2 <= 2){
    		if(mnth2 == 2 && day2 == 29){
    			year2++;
    		}
    		year2--;
    	}
    	year1--;

    	int ans = ((year2 / 4) + (year2 / 400) - (year2 / 100)) - (((year1 / 4) + (year1 / 400) - (year1 / 100)));
    	cout << "Case " << cs++ << ": " << ans << endl;




    	
    }
    return 0 ;
}
