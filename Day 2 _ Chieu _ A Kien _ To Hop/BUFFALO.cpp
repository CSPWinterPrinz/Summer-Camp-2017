#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL : z là số số 1
/// Số phép biến đổi ít nhất là đảo z - số số 1 ở bên kia bit => 00110|0101 => swap k = 2 lần
/// ta sẽ tạo ra all xâu có x bit 0, y bit 1 mà swap k lần ra xâu như đề bài yêu cầu
/// F(x , y , k) : Số lượng dãy bit có x bit 0, y bit 1, swap min k lần
/// => F(x , y , k) = C(k , x) * C(k , y)
//-----------------------------------------------------

#define N 1006
#define M 1000000007
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "BUFFALO"

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

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;

ll C[N+3][N+3];

struct T
{

};

void Build_C()
{
    up(i , 1, N)
        up(j , 1 , N)
            C[i][j] = i == j ? 1 : 0;
    C[0][0] = 1;
    up(i , 1 , N) {
        up(j , 1 , i)
            {C[i][j] = ( C[i - 1][j] + C[i - 1][j - 1] ) % M;}// cout << C[i][j] << " ";}
            //cout << endl;
    }

}

void Solve(ll n, ll k)
{
    ll res = 0;
    up(i , 0 , n)
        up(j , 0 , k)
            res += C[i + 1][j + 1] * C[n - i + 1][j + 1] % M; //f[i][n - i][j] % M;
    cout << res % M << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Build_C();
    ll n, k;
    while(cin >> n) {
        cin >> k;
        Solve(n , k);
    }
}



