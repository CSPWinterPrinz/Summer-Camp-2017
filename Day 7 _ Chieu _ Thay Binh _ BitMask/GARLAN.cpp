#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// Lập Matrix a(i , j) : (1 - > m + 1) Trọng số đường đi từ i -> j
/// QHĐ : Dp(i , j) : Đường đi ngắn nhất đến đỉnh (y , j) : Giá trị là y, bit trước đó là j;
//-----------------------------------------------------

#define N 20
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define down(i , a , b) for (int i = a; i >= b; --i)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "GARLAN"

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
       pc('\n');
}
/// ***************************** FAST I/O *****************************

vector <int> e[70000];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s[70000];
bool avail[N][N];

int m, n, x, a[70000][N], dp[70000][N];

struct T
{

};

void Init()
{
    memset(avail , 0 , sizeof(avail));
    cin >> n >> m;
    up(i , 1 , m) {
        cin >> s[i];
    }
    s[m+1].resize(n , '0');
    cout << 1;
}

void Build()
{
    up(i , 1 , m - 1) {

        up(j , i + 1 , m) {
            a[i][j] = 0;
            up(z , 0 , n - 1)
                if(s[i][z] != s[j][z]) a[i][j]++;
            a[j][i] = a[i][j];
           cout << a[i][j] << " ";
        }
        cout << endl;
    }

    up(i , 1 , m) {
        up(j , 0 , n - 1)
            if(s[i][j] != '0') a[m + 1][i]++;
        a[i][m + 1] = a[m + 1][i];
    }
}

int Count(int y, int j)
{
    if(y == (1 << j - 1)) return 0;
    if(y == (1 << m)) return oo;
    if(avail[y][j]) return dp[y][j]; /// Đã visit đặt lại đỉnh đã đi;

    int x = y ^ (1 << (j - 1));
    dp[y][j] = oo; avail[y][j] = 1; /// Gán xâu x = y, vs bit j của x = 0;

    up(i , 1 , m)
        if(((x >> (i - 1)) & 1) == 1) { /// Nếu đổi bit j của x = 1;
            int t = Count(x , i);
            dp[y][j] = min(dp[y][j], t + a[i][j]);
    }
    return dp[y][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
   // freopen(TITLE".OUT", "w", stdout);

    Init();
    Build();
    int res = oo; avail[1 << (m - 1)][m + 1] = 1;
    up(i , 1 , m)
    {
        res = min(res, Count((1 << m) - 1, i) + a[m + 1][i]);
        cout << Count(1 << (m + 1) - 1, i) << " ";
    }
    cout << res;
}



