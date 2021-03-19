/*
 * Схема кімнат одного з поверхів будівлі задається прямокутною таблицею, розміром n*m (1≤n,m≤100), у якій цифрою 1 позначені стіни,
 * а всі решта елементів, включаючи краї поверху, цифрою 0.
 * Відомо, що під час будівництва будівельники могли деякі кімнати повністю замурувати.
 * Визначити, чи можна вийти на будь-який край поверху із заданої позиції (х,у), де 1≤х≤n,1≤у≤m.
 * Якщо ні, то вивести «NO», якщо так, то вивести найкоротший шлях від заданої позиції до краю поверху.
 */


#include "bits//stdc++.h"
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    int a[n + 1][m + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int x,y;
    cin >> x >> y;


    queue<vector<int> > plan;
    vector<int> temp = {x, y, 0};
    vector<vector<int> > used(n + 1,vector<int>(m + 1, 0));
    plan.push(temp);
    used[x][y] = 1;

    while (!plan.empty()) {
     vector<int> v = plan.front();
     plan.pop();
     if (v[0] == 1 || v[1] == 1 || v[0] == n || v[1] == m) {
         cout << v[2];
         return 0;
     }

     if (used[v[0] - 1 ][v[1]] != 1 && a[v[0] - 1 ][v[1]] == 0) {
         temp = {v[0] - 1, v[1], v[2]+1};
         plan.push(temp);
         used[v[0] - 1][v[1]] = 1;
     }

     if (used[v[0]][v[1] + 1] != 1 && a[v[0]][v[1] + 1] == 0) {
         temp = {v[0], v[1] + 1, v[2]+1};
         plan.push(temp);
         used[v[0]][v[1] + 1] = 1;
     }

     if (used[v[0] + 1 ][v[1]] != 1 && a[v[0] + 1 ][v[1]] == 0) {
         temp = {v[0] + 1, v[1], v[2]+1};
         plan.push(temp);
         used[v[0] + 1][v[1]] = 1;
     }

     if (used[v[0]][v[1] - 1] != 1 && a[v[0]][v[1] - 1] == 0) {
         temp = {v[0], v[1] - 1, v[2]+1};
         plan.push(temp);
         used[v[0]][v[1] - 1] = 1;
     }

    }

    cout << "No";

    return 0;
}

