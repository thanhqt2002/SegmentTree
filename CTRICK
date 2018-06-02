@@ -0,0 +1,101 @@
#include <bits/stdc++.h>

#define Rep(i,n)        for(int i = 0; i < (n); ++i)
#define Repd(i,n)       for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b)      for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b)     for(int i = (a); i >= (b); --i)
#define ALL(a)          (a).begin(), (a).end()
#define pb	push_back
#define NAME            "TEST"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define READ            freopen(NAME".INP","r",stdin);
#define WRITE           freopen(NAME".OUT","w",stdout);
#define gc 		getchar
#define pc		putchar
#define watch(x) 	cout << (#x) << " is " << (x) << '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef float fl;
typedef double db;
const int inf = 1e6;
const int Linf = 1e9;
const ll LLinf = (ll)1e18;
const int maxn = 1e6;


template<typename T = int> inline T read() {
	T val = 0, sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	return sign * val;
}
struct fenwich{
    int n;
    vector<int> sum , res;
    fenwich(const int& _n){
        n = _n;
        sum.assign(n+1,0);
        res.assign(n+1,0);
        build();
    }
    void build(){
        for(int i = 1 ; i <= n ; ++i){
            int x = i;
            int q = x & (x - 1);
            sum[i] = 1;
            for(int ii = i - 1 ; ii > q ; ii &= ii - 1){
                sum[i] += sum[ii];
            }
        }
    }
    void update(int x){
        for( ; x <= n ; x += (x & -x)){
            sum[x]--;
        }
    }
    int query(int x){
        int res = 0;
        for( ; x > 0 ; x &= (x - 1))res += sum[x];
        return res;
    }
    void binsearch(int Kthfreecell , int t){
        int l = 1;
        int h = n;
        while(l <= h){
            int mid = (l + h) / 2;
            if(query(mid) < Kthfreecell)l = mid + 1;
            else h = mid - 1;
        }
        res[l] = t;
        update(l);
    }
    void print(){
        for(int i = 1 ; i <= n ;++i)cout << res[i] << " \n"[i == n];
    }
};
void solve()
{
    int n , Ncard , Kthcell = 1;
    cin >> n;
    Ncard = n;
    fenwich tree(n);
    for(int i = 1 ; i <= n ; ++i){
        Kthcell = (Kthcell + i) % Ncard;
        if(Kthcell == 0)Kthcell = Ncard;
        tree.binsearch(Kthcell,i);
        --Ncard;
    }
    tree.print();
}
int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)solve();
}
