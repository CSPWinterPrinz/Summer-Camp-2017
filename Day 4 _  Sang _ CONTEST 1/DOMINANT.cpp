#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 300006
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "DOMINANT"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

/// ***************************** FAST I/O *****************************
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
}
/// ***************************** FAST I/O *****************************

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;

ll n, sum[N];
ll a[N], RESMAX;

struct T
{

};

void Init()
{
    cin >> s;
    sum[0] = 0; ll cnt1 = 0;
    n = s.length();
    up(i , 1 , n) {
        a[i] = s[i - 1] == '1' ? 1 : -1;
        cnt1 += a[i] == 1 ? 1 : 0;
        sum[i] = sum[i - 1] + a[i];
        //cout << a[i] << " " << sum[i] << endl;
    }
    RESMAX = cnt1 * 2 - 1;
}

void Solve()

{
    ll res = 0, cnt = 0;
    up(i , 1 , n) {
        ll start = 1;
        start = max((ll)1 , i - RESMAX);
        up(j , start , n) {
            if(sum[i] > sum[j - 1]) {
                res = max(res, (ll) i - j + 1);
                break;
            }
        }
    }

    up(i , 1 , n) {
        if(i >= res && sum[i] - sum[i - res] > 0)
            cnt++;
    }
    writeln(res); putchar(' '); writeln(cnt);
    //cout << endl << n;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    Init();
    Solve();
}



