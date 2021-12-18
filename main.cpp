/*
___mennat khoday ra azz o va jall ke taatash mojebe ghorbat ast o be shokr andarash mazide nemat.
___har nafasi ke foro miravad momedde hayatast o chon bar miayad mofarrahe zat.
___pas dar har nafasi 2 nemat mojod ast o bar har nematy shokry vajeb.

___az dast o zabane ke barayad ?
___kaz ohdeye shokrash be dar ayad !


___man be to dami gharar natvanam kard
___va ehsane to ra shomar natvanam kard
####################
___gar bar tane man zaban shavad har moyee
___yek shokre to az hezar natvanam kard

*/

#include <bits/stdc++.h>


#define pb push_back
#define SALI main
#define left(x) ((x)*2)
#define right(x) (((x)*2)+1)
#define fuck(x) cout << #x << " : " << x << "  "
#define findLowVec(v,x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define findUpVec(v,x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define findLowArr(a,n,x) (lower_bound(a, a+n, x) - a)
#define findUpArr(a,n,x) (upper_bound(a, a+n, x) - a)
//#define int long long

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,char> pic;
typedef long double ld;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p)
{return out << "(" << p.first << ", " << p.second << ")";}

template<class A> ostream& operator <<(ostream& out, const vector<A> &v)
{out << "[";for(int i = 0; i < v.size(); i++) {if(i) out << ", ";out << v[i];}return out << "]";}

template<class A,class B> ostream& operator <<(ostream& out, const set<A,B> &s)
{out << "[";for(auto i = s.begin(); i != s.end(); i++) {out << ", ";out << *i;}return out << "]";}

template<class A> ostream& operator <<(ostream& out, const set<A> &s)
{out << "[";for(auto i = s.begin(); i != s.end(); i++) {out << ", ";out << *i;}return out << "]";}

const int N = 50;
vector<pii> v; // varaibles
int n,m; // size of matrix
int total_pole; // number of pole should placed
int domain[N][3]; // domain[i][j] = 1 : j can be assigned to variable i
int assigned[N]; // assigned[i] = -1 : not assigned      assigned[i] = j : j assigned to i
int row_plus[N];// row_plus[i] = 2 : sum + a[i][1 ... m] = 2
int row_neg[N];  // row_neg[i] = 4 : sum - a[i][1 ... m] = 4
int cul_plus[N];// cul_plus[i] = 5 : sum + a[1 ... n][i] = 5
int cul_neg[N];  // cul_neg[i] = 5 : sum - a[1 ... n][i] = 5
int mark[N*N]; // just needed at the start to set coordinates for variables
int a[N][N]; // matrix
int state[N][N]; // shows the current state

int get_sum_plus_column(int x)
{

}

int get_sum_neg_column(int x)
{

}
int get_sum_plus_row(int x)
{

}
int get_sum_neg_row(int x)
{

}
bool is_goal()
{

}
void pre_process() // at first no assignment is done and all domain are avalible
{
    memset(assigned, -1, sizeof(assigned));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j++){
            domain[i][j] = 1;
        }
    }
}
bool forward_checking()
{

}

int MRV() // returns the index of the next element according to MRV heuristic
{

}
int LCV() // returns the index of the next element according to LCV heuristic
{

}

void back_tracking()
{

}

void read_input()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> row_plus[i];
        total_pole += row_plus[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> row_neg[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> cul_plus[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> cul_neg[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

}


int32_t SALI()
{
    pre_process();
    read_input();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mark[a[i][j]] == 0){
                v.pb(pii(i,j));
                mark[a[i][j]] = 1;
            }
        }
    }

}

/**< WRITEN BY ALI ADELKHAH */
