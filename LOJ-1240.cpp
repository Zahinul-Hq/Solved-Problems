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
double value(double x , double y, double z){
    return sqrt((x * x) + (y * y) + (z * z));
}
double distance(double x , double y, double z, double x1, double y1, double z1){
    return value((x - x1) , (y - y1) , (z - z1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        double Xa, Xb, Xp, Ya, Yb, Yp, Za, Zb, Zp, eps = 1e-6;


        cin >> Xa >> Ya >> Za >> Xb >> Yb >> Zb >> Xp >> Yp >> Zp ;

        double ABx = Xb - Xa, ABy = Yb - Ya, ABz = Zb - Za, APx = Xp - Xa, APy = Yp - Ya, APz = Zp - Za;
        double BPx = Xp - Xb, BPy = Yp - Yb, BPz = Zp - Zb; 

        double AB = ((ABx * ABx) +  (ABy * ABy) + (ABz * ABz));
        
        double APcos = 0;
        if(AB > eps){

            APcos = ((ABx * APx) + (ABy * APy) + (ABz * APz)) / AB ;
            APcos = max(0.00, min(1.00, APcos));


            
        }
        

        

        double Cx = Xa + (APcos * ABx), Cy = Ya + (APcos * ABy), Cz = Za + (APcos * ABz);


        double ans = distance(Cx, Cy,Cz, Xp, Yp, Zp);

        

        cout << "Case " << cs++ << ": "<< fixed << setprecision(7) << ans << endl;

    }
    return 0 ;
}
