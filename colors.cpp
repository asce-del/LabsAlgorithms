#include "bits//stdc++.h"
using namespace std;

int main() {
    while (true) {
        int n, m;
        int x, y;
        cin >> n;
        if (n == 0) return 0;
        cin >> m;
        vector<vector<int> > a(n + 1);

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }

        queue<int> plan;
        vector<int> color(n + 1, -1);
        vector<int> used(n + 1, 0);

        plan.push(1);
        used[1] = 1;
        color[1] = 0;

        while (!plan.empty()) {
            int v = plan.front();
            plan.pop();

            for (int i = 0; i < a[v].size(); i++) {
                int to = a[v][i];
                if (!used[to]) {
                    plan.push(to);
                    used[to] = 1;
                }

                if (color[to] == -1) {
                    if (color[v] == 0) {
                        color[to] = 1;
                    } else {
                        color[to] = 0;
                    }
                } else {
                    if (color[to] == color[v]) {
                        cout << "NOT BICOLOURABLE." << endl;
                        continue;
                    }
                }
            }
        }

        cout << "BICOLOURABLE." << endl;
    }
}
