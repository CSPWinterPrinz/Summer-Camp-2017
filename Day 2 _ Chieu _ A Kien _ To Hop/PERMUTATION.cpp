#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 2001
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <char, ll>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "PERMUTATION"

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
ll n, cnt = 1;

struct T
{

};

void Init()
{
    cin >> s;
    sort(s.begin() , s.end());

    //cout << s;
    s = s + '@'; n = s.length() - 1;

    up(i , 1 , n)
        if(s[i] != s[i - 1])
            e.pb(mp(s[i - 1] , cnt)), cnt = 1;
        else cnt++;

    //up(i , 0 , e.size() - 1) cout << e[i].first << " " << e[i].second << endl;
    if(e.size() <= 1) {cout << 1; exit(0);}
}

ll C(ll k, ll n)
{
    ll x = 1;
    up(i , 1 , k)
        x = (x * (n - i + 1));

    up(i , 1 , k)
        x /= i;

    return x;
}

void Solve()
{
    ll res = 1;
    up(i , 0 , e.size() - 2)
    {
        res *= C(e[i].second , n);
        n -= e[i].second;
    }
    cout << res;
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


