#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 1000006
#define M 1000000007
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "STEP123"

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

ll n, f[N];

struct T
{

};

void Init()
{
    cin >> n;
    f[0] = 1;
}

void Solve()
{
    up(i , 1 , n)
    {
        f[i] = 0;
        ll cnt = 1;
        while(cnt <= i)
        {
            f[i] = (f[i] + f[i - cnt]) % M;
            cnt *= 2;
        }
    }
    cout << f[n] % M;
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


