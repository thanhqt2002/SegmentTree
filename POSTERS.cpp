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
const int maxn = 1e5 + 5;


int  read() {
	int val = 0, sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	return sign * val;
}
map<int,int> chk;
typedef pair<int,int> Tpair;
int n , Ntest;
set<int> s;
struct TSegment{
private:
    int n , l , h;
    vector<int> a , chk , fina;
    void query(int x , int low , int high , int val){
      	if(low == high){
                fina[low] = max(val,a[x]);
                return;
        }
        int mid = (low + high) / 2;
        query(x * 2, low , mid , max(val,a[x]));
        query(2 * x + 1 , mid + 1 , high , max(val,a[x]));
    }
    void update(int x , int low , int high,int val){
        if(low > h || l > high){
            return;
        }
        if(l <= low && high <= h){
            a[x] = val;
            return;
        }
        int mid = (low + high) / 2;
        update(2 * x , low , mid,val);
        update(2 * x + 1 , mid + 1 , high,val);
    }

public:
    TSegment (const int &_n){
        n = _n;
        chk.assign(n + 5 , 0);
        fina.assign(n + 5 , 0);
        a.assign(4 * n + 5,0);
    }
    void update(int l1 ,int h1,int val){
        l = l1;h = h1;
        update(1,1,n,val);
    }
    int query(){
       	query(1,1,n,0);
        int res = 0;chk[0] = 1;
        for(int i = 1 ; i <= n ; ++i){
            if(chk[fina[i]] == 0)res++ , chk[fina[i]] = 1;
        }
        return res;
    }
};
Tpair a[maxn];
void solve()
{
    n = read();
    for(int i = 1 ; i <= n ; ++i){
        int x , y;
        x = read();y = read();
        a[i] = make_pair(x,y);
    }
    TSegment tree((int)1e7);
    for(int i = 1 ; i <= n ; ++i){
        cout << a[i].first << " " << a[i].second << endl;
        tree.update(a[i].first , a[i].second, i);
    }
    cout << "Case " << Ntest << ": " << tree.query() << '\n';
}
int main()
{
    FAST;
    int t;
    t = read();
    for(Ntest = 1 ; Ntest <= t ; Ntest++)solve();
}
