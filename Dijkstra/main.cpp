#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;



int INF = 100001;

int main() {
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        int n;
        int m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> graf;
        int grafSize[n][n];
        graf.resize(n);
        vector<int> d(n, INF);
        vector<int> p(n, -1);
        bool *used = new bool[n];
        for (int o = 0; o < n; ++o) {
            used[o] = false;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                grafSize[i][j]=-1;
            }
        }
        int k=0;
        vector<pair<int,int>> h;
        for(int i=0;i<m;++i){
        }
        for (int a1 = 0; a1 < m; a1++) {
            int x;
            int y;
            int r;
            cin >> x >> y >> r;
            x--;
            y--;
            if(grafSize[x][y]!=-1){
                int min = grafSize[x][y];
                if (r<min){
                    grafSize[x][y]=grafSize[y][x]=r;
                }
            }
            else{
                h.emplace_back(make_pair(x,y));
                k++;
                grafSize[x][y]=grafSize[y][x]=r;
            }

        }
        for (int a1 = 0; a1 < k; a1++) {
            int x = h[a1].first;
            int y= h[a1].second;
            int r = grafSize[x][y];
            graf[x].emplace_back(make_pair(y, r));
            graf[y].emplace_back(make_pair(x,r));
        }
        int s;
        cin >> s;
        s--;
        d[s] = 0;
        vector<int> pa(n);
        for (int i = 0; i < n; ++i) {
            int v =-1;
            for(int j=0;j<n;++j){
                if((!used[j])&&(v==-1||d[j]<d[v])){
                    v=j;
                }
            }
            if(d[v]==INF){
                continue;
            }
            used[v] = true;
            for (int j = 0; j < graf[v].size(); ++j) {
                int to = graf[v][j].first;
                int w = graf[v][j].second;
                if (d[v] + w < d[to]) {
                    d[to] = d[v] + w;
                    pa[to] = v;
                }
            }

        }

        vector<int> path;
        for (int v=3; v!=s; v=pa[v])
	        path.push_back (v);
        path.push_back (s);
        reverse (path.begin(), path.end());

        for(int i=0;i<n;++i){
            if(i!=s) {
                if(d[i]==INF){
                    cout<<-1<< " ";
                }
                else {
                    cout << d[i] << " ";
                }
            }

        }
        cout<< endl;

      cout<<"Way: ";
        for (vector<int>::iterator it = path.begin() ; it!=path.end() ; ++it)
            cout<<*it<<" ";
    }
    return 0;
}