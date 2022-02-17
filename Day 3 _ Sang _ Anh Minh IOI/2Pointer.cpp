#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 1000006
#define oo 100000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "2Pointer"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;

ll n, a[N], sum[N], cnt = 0, k, res = oo, c[N];

inline void read(long long &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for (;((c<48 || c>57) && c != '-') ;c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline void writeln(long long x)
{
     char buffor[21];
     register int i=0;
     int neg=0; if (x<0) {neg=1; x= -x;}
     do{
           buffor[i++]=(x%10)+'0';
           x/=10;
        } while(x);
       i--;
       if (neg) pc('-');
       while(i>=0) pc(buffor[i--]);
       pc('\n');
}

struct T
{

};
/// sum(i) : Số số khác nhau từ 1 đến i
void Init()
{
    memset(sum , 0 , sizeof(sum));
    read(n);
    read(k);
    int j = 1;

    up(i , 1 , n) {
        cin >> a[i];
        if(sum[a[i]] == 0) cnt++;
        sum[a[i]]++;

        if(cnt >= k) {
            while(cnt >= k) {
                sum[a[j]]--;
                if (sum[a[j]]==0) cnt--;
                j++;
            }
            res = min(res , (ll) i - j + 2);
        }

    }

    if(res == oo) cout << -1;
    else cout << res;
}

void Solve()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Init();
    Solve();
}



