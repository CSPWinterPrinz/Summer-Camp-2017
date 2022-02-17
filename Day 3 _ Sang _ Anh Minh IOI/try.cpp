#include <bits/stdc++.h>
#define N 400124
#define gc getchar
#define pc putchar
typedef long long ll;

using namespace std;
ll m, n, salary[N];

//************************************************
/// Sum(u) : Sigma salary of tree node u;
/// Salary(i) : salary of member number i;
//************************************************

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

struct Seg_Tree
{
    ll L[N], H[N], sum[N], leaf[N >> 2];

    void Build(int pos, int low, int high)  /// start Build from node pos, semgment low -> high
    {
        L[pos] = low; H[pos] = high; sum[pos] = 0; /// Khoi tao

        if(low == high)   {/// pos == LEAF
            leaf[high] = pos; sum[pos] = salary[high];
        }

        else {
            ll mid = (low + high) >> 1;
            Build(pos << 1, low, mid);          /// Build tree node (2*pos & 2*pos + 1 are two child of pos) divide seg [low, high] to two part.
            Build((pos << 1) + 1, mid + 1, high);
        }

    }

//***********************************************
         /// UPDATE ///

    void Update(int u, int w) ///a[u] = w;
    {
        int diff = w - salary[u];
        /// Update u -> sum of cả cây gốc chứa u thay đổi 1 khoảng W - SALARY[U]
        for(int i = leaf[u]; i > 0; i >>= 1)
            sum[i] += diff;
        salary[u] = w;
    }
//***********************************************
        /// REQUEST ///
/// Lx, Hx : Area of node x;
    ll Request(int pos, int i, int j)
    {
        if(L[pos] > j || H[pos] < i) return 0;          /// pham vi pos nam ngoai khoang L, H pos
        if(i <= L[pos] && H[pos] <= j) return sum[pos]; /// pham vi pos nam giua khoang L, H pos
        return Request(pos << 1, i, j) + Request((pos << 1) + 1, i, j); /// pham vi pos (Lpos, Hpos) && (i, j) giao nhau;
    }

    ll Ask(int i, int j)
    {
        return Request(1, i, j);
    }
//***********************************************
}

STree;

void Init()
{
    read(n); read(m);
    memset(salary, 0, sizeof(salary));
    STree.Build(1 , 1 , n);
}

void Solve()
{
    for(int i = 1; i <= m; i++)
    {
        int x;  cin >> x;
        switch (x)
        {
            ll a, b, val;
            case 2 :
                 read(a); read(b); read(val);
                for(int i = a; i <= b; i++)
                    STree.Update(i , val);
                break;
            case 1 :
                read(a); read(b);
                writeln(STree.Ask(a , b));
                break;
        }
    }
}

int main()
{
  //  freopen("QUERYSUM.INP", "r", stdin);
    //freopen("QUERYSUM.OUT", "w", stdout);

    Init();
    Solve();
}
// http://goo.gl/Td33Pq

