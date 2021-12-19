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
// 0 -> -1 +1
// 1 ->  0  0
// 2 -> +1 -1
int assigned[N]; // assigned[i] = -1 : not assigned      assigned[i] = j : j assigned to i
int row_plus[N];// row_plus[i] = 2 : sum + a[i][1 ... m] = 2
int row_neg[N];  // row_neg[i] = 4 : sum - a[i][1 ... m] = 4
int cul_plus[N];// cul_plus[i] = 5 : sum + a[1 ... n][i] = 5
int cul_neg[N];  // cul_neg[i] = 5 : sum - a[1 ... n][i] = 5
int mark[N*N]; // just needed at the start to set coordinates for variables
int a[N][N]; // matrix
int state[N][N]; // shows the current state

void place_variable(int var) /// done
{
    int x = v[var].first;
    int y = v[var].second;
    if(assigned[var] == 0){
        state[x][y] = -1;
        if(a[x][y+1] == a[x][y]){
            state[x][y+1] = +1;
        }
        if(a[x+1][y] == a[x][y]){
            state[x+1][y] = +1;
        }
    }
    if(assigned[var] == 2){
        state[x][y] = +1;
        if(a[x][y+1] == a[x][y]){
            state[x][y+1] = -1;
        }
        if(a[x+1][y] == a[x][y]){
            state[x+1][y] = -1;
        }
    }
}
void update_state() /// done
{
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) state[i][j] = 0;

    for(int i = 0; i < v.size(); i++){
        if(assigned[i] != -1){
            place_variable(i);
        }
    }
}

/// done
bool is_consistant() // check if current state is consistent in every aspects
{
    update_state();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(state[i][j] == state[i+1][j] && state[i][j] != 0){
                return false;
            }
            if(state[i][j] == state[i][j+1] && state[i][j] != 0){
                return false;
            }
        }
    }
}
void print() /// done
{
    update_state();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(state[i][j] == 1){
                cout << "+ ";
            }
            if(state[i][j] == -1){
                cout << "- ";
            }
            if(state[i][j] == 0){
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
int get_sum_plus_column(int x) /// done
{
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += state[i][x];
    }
    return sum;
}

int get_sum_neg_column(int x) /// done
{
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum -= state[i][x];
    }
    return sum;
}
int get_sum_plus_row(int x) /// done
{
    int sum = 0;
    for(int i = 1; i <= m; i++){
        sum += state[x][i];
    }
    return sum;
}
int get_sum_neg_row(int x) /// done
{
    int sum = 0;
    for(int i = 1; i <= m; i++){
        sum -= state[x][i];
    }
    return sum;
}
bool is_goal() /// done
{
    for(int i = 1; i <= n; i++){
        if(row_plus[i] != get_sum_plus_row(i)){
            return false;
        }
        if(row_neg[i] != get_sum_neg_row(i)){
            return false;
        }
    }
    for(int i = 1; i <= m; i++){
        if(row_plus[i] != get_sum_plus_column(i)){
            return false;
        }
        if(row_neg[i] != get_sum_neg_column(i)){
            return false;
        }
    }
    if(!is_consistant()){
        return false;
    }
    return true;
}

/// done
void pre_process() // at first no assignment is done and all domain are avalible
{
    memset(assigned, -1, sizeof(assigned));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j++){
            domain[i][j] = 1;
        }
    }
}

void update_domain(int var) /// done
{
    for(int i = 0; i < 4; i++){
        assigned[var] = i;
        if(is_consistant()){
            domain[var][i] = 1;
        }
        else{
            domain[var][i] = 0;
        }
    }
}
void forward_checking() /// done
{
    for(int i = 0; i < v.size(); i++){
        if(assigned[i] == -1){
            update_domain(i);
        }
    }
}

/// done
int MRV() // returns the index of the next element according to MRV heuristic
{
    int id_var = 0;
    int min_domain_size = 5;
    for(int i = 0; i < v.size(); i++){
        int sum = 0;
        for(int j = 0; j < 4; j++){
            sum += domain[i][j];
        }
        if(sum < min_domain_size){
            min_domain_size = sum;
            id_var = i;
        }
    }
    return id_var;
}


int LCV(int var) // returns the value of the chosen variable according to LCV heuristic
{
    // TODO
    for(int i = 0; i < 4; i++){
        if(domain[var][i] == 1){
            return var;
        }
    }
    return -1;
}

/// done
void back_tracking()
{
    if(is_goal()){
        print();
        exit(0);
    }
    forward_checking(); // checks each variable domain
    int id = MRV();
    int value;
    while((value = LCV(id)) != -1){
        assigned[id] = value;
        back_tracking();
        assigned[id] = -1;
        domain[id][value] = 0;
    }

}

/// done
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

/// done
void find_variable_cordinate()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mark[a[i][j]] == 0){
                v.pb(pii(i,j));
                mark[a[i][j]] = 1;
            }
        }
    }
}
int32_t SALI()
{
    pre_process();
    read_input();
    find_variable_cordinate();
    back_tracking();

}
/*
6 6
1 2 3 1 2 1
1 2 1 3 1 2
2 1 2 2 2 1
2 1 2 2 1 2
1 2 2 3 4 4
1 5 5 3 6 6
7 8 8 9 9 10
7 11 12 12 13 10
14 11 15 15 13 16
14 17 17 18 18 16
*/
/**< WRITEN BY ALI ADELKHAH */
