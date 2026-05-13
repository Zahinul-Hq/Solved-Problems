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
const int maxb = 60;
bool get_bit(int64_t a,int i)
{
    return a&(1ll<<i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    inout();
    int t;
    cin >> t;
    while(t--)
    {
        int64_t a,b,r;
        cin >> a >> b >> r;
        int64_t x = 0;
        bool first_bit = 1;
        if(a > b)
            swap(a,b);
        for(int i = maxb-1;i >= 0;--i)
        {
            bool bit_a = get_bit(a,i);
            bool bit_b = get_bit(b,i);
            if(bit_a != bit_b)
            {
                if(first_bit)
                {
                    first_bit = 0;
                }
                else
                {
                    if(!bit_a && x+(1ll<<i) <= r)
                    {
                        x += (1ll<<i);
                        a ^= (1ll<<i);
                        b ^= (1ll<<i);
                    }
                }
            }
        }
        cout << b-a << "\n";
    }

}
