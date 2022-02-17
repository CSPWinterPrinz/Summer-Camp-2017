#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// Phép tính <=> Vs mỗi i, tính Max(i) : i đc chọn làm max trong bnh khoảng? , tính Min(i) : i đc chọn làm min trong bnh khoảng.
/// Res = Sigma(i : 1 -> n) (Max(i) - Min(i)) * a[i]
/// Min(i) : Tính thông qua Left(i) : Chỉ số sao cho Phần tử ấy về phía trái từ Left(i) -> i đều >= a[i];
///          Tính thông qua Right(i) : Chỉ số sao cho Phần tử ấy về phía phải từ Right(i) -> i đều > a[i];
/// Max(i) tương tự
//-----------------------------------------------------

#define N 400006
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "WEIGHT"

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
string s;
bool l;

ll n, a[N], Min[N], Max[N];
    ll Right[N], Left[N];

struct T
{

};

void Init()
{
    cin >> n;
    up(i , 1 , n)
        cin >> a[i];
       // cout << 1;
}

void Count_Min()
{
    stack <int> st, st2;
//cout << 1;
    down(i , n , 1)
    {
        while(!st.empty() && a[i] <= a[st.top()])
            st.pop();
        if(st.empty()) Right[i] = n + 1;
        else Right[i] = st.top();
        st.push(i);
    }
//cout << 1;
    up(i , 1 , n)
    {
        while(!st2.empty() && a[i] < a[st2.top()])
            st2.pop();
        if(st2.empty()) Left[i] = 0;
        else Left[i] = st2.top();
        st2.push(i);
    }
//cout << 1;
    up(i , 1 , n)
    {
        Min[i] = (i - Left[i]) * (Right[i] - i);
       // cout << Min[i] << " ";
    }//cout << endl;
//cout << 1;
}

void Count_Max()
{
    stack <int> st, st2;

    down(i , n , 1)
    {
        while(!st.empty() && a[i] >= a[st.top()])
            st.pop();
        if(st.empty()) Right[i] = n + 1;
        else Right[i] = st.top();
        st.push(i);
    }

    up(i , 1 , n)
    {
        while(!st2.empty() && a[i] > a[st2.top()])
            st2.pop();
        if(st2.empty()) Left[i] = 0;
        else Left[i] = st2.top();
        st2.push(i);
    }

    up(i , 1 , n)
    {
        Max[i] = (i - Left[i]) * (Right[i] - i);
        //cout << Max[i] << " ";
    }//cout << endl;

}

void Solve()
{
    ll res = 0;
    up(i , 1 , n)
    {
        res += (ll) a[i] * ((ll)Max[i] - Min[i]);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    Init();
    Count_Min();
    Count_Max();
    Solve();
}



