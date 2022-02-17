#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// Next(k ,i , j) (k : 1->4 : 4 hướng, i, j là tọa độ)
/// = số ô để đến đc vị trí có xe Next theo hướng k;

/// N : 1 lên; E : 2 phải; S : 3 dưới; W : 4 trái;
/// duyệt từ trái trên -> phải dưới : tính đc
//-----------------------------------------------------


#define N 2006
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

//#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "CARDRAG"

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

struct II
{
    int x, y;
};

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <II> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;
ll Next[6][N][N], a[N][N], m, n;
bool debug = 0;

void Init()
{
    up(i , 1 , m)
        up(j , 1 , n) {
            char x; cin >> x;
            a[i][j] = x == '.' ? 0 : (x == 'N' ? 1 : (x == 'E' ? 2 : (x == 'S' ? 3 : 4)));
        }
    up(i , 0 , N)
        {a[i][0] = a[0][i] = a[m + 1][i] = a[i][n + 1] = -1; Next[1][0][i] = Next[4][i][0] = Next[2][i][n + 1] = Next[3][m + 1][i] = -1;}

    if(debug)
    up(i , 1 , m) {
        up(j , 1 , n)
        cout << a[i][j]<<" ";
        cout << endl;
    }

}

void Build_Next()
{
    up(i , 1 , m)
        up(j , 1 , n) {
            Next[1][i][j] = a[i - 1][j] != 0 ? (i - 1 != 0 ? i - 1 : -1) : Next[1][i - 1][j];
            Next[4][i][j] = a[i][j - 1] != 0 ? (j - 1 != 0? j - 1 : -1) : Next[4][i][j - 1];
        }

    down(i , m , 1)
        down(j , n , 1) {
            Next[2][i][j] = a[i][j + 1] != 0 ? (j + 1 != n + 1  ? j + 1 : -1) : Next[2][i][j + 1];
            Next[3][i][j] = a[i + 1][j] != 0 ? (i + 1 != m + 1 ? i + 1 : -1) : Next[3][i + 1][j];
        }

    if(debug)
        up(i , 1 , m) {
            up(j , 1 , n)
                cout << Next[1][i][j] << "," << Next[2][i][j] << ","<< Next[3][i][j] << ","<< Next[4][i][j] << "  ";
            cout << endl;
        }
}

void Solve()
{
    up(i , 1 , m)
        up(j , 1 , n) {
            if( Next[ a[i][j] ][i][j] == -1) {II u; u.x = i, u.y = j; Q.push(u);}
        }
    /// khởi tạo Queue, nhét all xe cho ra bãi đc khỏi Q


    ll res = 0;
    while(!Q.empty())
    {
        II u = Q.front(); Q.pop(); res++; //cout << u.x << " " << u.y << endl;
        up(i , 1 , 4) {
            int nextcar = Next[i][u.x][u.y];
            if(nextcar != -1) {
                II v;
                v.x = i & 1 ? nextcar : u.x;
                v.y = i & 1 ? u.y : nextcar;
                int DIREC = i & 1 ? 4 - i : 6 - i;
                Next[ DIREC ][v.x][v.y] = Next[ DIREC ][u.x][u.y];
                if(DIREC == a[v.x][v.y] && Next[ DIREC ][v.x][v.y] == -1) Q.push(v);
            }
        }
    }
    writeln(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
    while(cin >> m) {
        cin >> n;
        if(m == 0 && n == 0) break;
        Init();
        Build_Next();
        Solve();
    }
}



