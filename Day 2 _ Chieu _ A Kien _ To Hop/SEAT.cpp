#include <bits/stdc++.h>

//-----------------------------------------------------
/// De bai
///
///
//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 2001
#define oo 1000000007

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <char, ll>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "TEAM"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ull;
typedef unsigned long long ll;
typedef long double ld;

using namespace std;

vector <II> e;
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;

char a[N];
ull Mid, A, B, X, Y;

struct T
{

};

void Init()
{
    cin >> A >> B >> X >> Y;
}

ull C(ull k, ull n)
{
    if(k > n) return 0;
    ull x = 1;
    up(i , 1 , k)
        x = (x * (n - i + 1)) % oo;

    up(i , 1 , k)
        x /= i;

    return x % oo;
}

void Solve()
{
    memset(c , 0 , sizeof(c));
    ll m = n, one = 0, two = 0;
    up(i , 1 , n)
    {
        res *= C;
    }
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


