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
/// #define TITLE ""

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
bool l = true;

ll g, b, gv, two, one;

struct T
{

};


ll Power (ll s, ll k)
{
     if (k == 0) return 1;
     ll q = Power (s, k / 2);
     if (k % 2 == 0) return (q * q) % M;
     else return ((q * q)* s) % M;
}

void Init()
{
    cin >> g >> b >> gv;
    two = b; // 01 + 10
    one = (g - b); // 0
    if(one <= 0 || two * 2 + one + gv != g + b + gv || one + two != gv - 1) {cout << 0; exit(0);}
}

ll C(ll k, ll n)
{
    ll x = 1;
    up(i , 1 , k)
        x = (x * (n - i + 1) % M) % M;

    up(i , 1 , k)
        x /= i;

    return x;
}

void Solve()
{
    ll cur = C(one , gv - 1);
    ll cur2 = Power(2 , two);
   // cout << cur << " " << cur2 << endl;
    cout << (cur * cur2) % M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Init();
    if(l) Solve();

}


/// 100 50 101
