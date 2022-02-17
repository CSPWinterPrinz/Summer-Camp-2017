#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 324
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "MAXRECT"

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
ll n, f[N][N], a[N][N], res = -oo;

struct T
{

};

void Init()
{
    cin >> n;
    up(i , 1 , n)
        up(j , 1 , n)
            cin >> a[i][j];
}

void Solve()
{
    memset(f , 0 , sizeof(f));
    up(i , 1 , n)
        up(j , 1 , n)
            f[i][j] = f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1] + a[i][j];

    up(i , 1 , n)
        up(j , 1 , n)
            up(x , 1 , i)
                up(y , 1 , j)
                    res = max(res , f[i][j] - f[i - x - 1][j] - f[i][j - y - 1] + f[i - x - 1][j - y - 1]);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  //freopen(TITLE".INP", "r", stdin);
  //  freopen(TITLE".OUT", "w", stdout);

    Init();
    Solve();
}



