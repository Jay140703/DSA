#include <iostream>
using namespace std;
int main() {
int n;
cout << "Enter the number of vertices: ";
cin >> n;
int cost[n][n];
int visited[n];
for (int i = 0; i < n; i++) {
visited[i] = 0;
for (int j = 0; j < n; j++) {
cost[i][j] = -1;
}
}
for (int i = 0; i < n; i++) {
for (int j = i + 1; j < n; j++) {
char edge;
cout << "Do you want an edge between " << i << " and " << j << "? (y/n): ";
cin >> edge;
if (edge == 'y' || edge == 'Y') {
int w;
cout << "Enter the weight: ";
cin >> w;
cost[i][j] = w;
cost[j][i] = w;
}
}
}
visited[0] = 1;
int minCost = 0;
cout << "\nEdges in the Minimum Spanning Tree:\n";
for (int e = 0; e < n - 1; e++) {
int minWeight = 999;
int row = -1, col = -1;
for (int i = 0; i < n; i++) {
if (visited[i] == 1) {
for (int j = 0; j < n; j++) {
if (visited[j] == 0 && cost[i][j] != -1 && cost[i][j] < minWeight) {
minWeight = cost[i][j];
row = i;
col = j;
}
}
}
}
if (row != -1 && col != -1) {
visited[col] = 1;
minCost += minWeight;
cout << row << " - " << col << " with weight " << minWeight << endl;
}
}
cout << "\nMinimum Cost of the Spanning Tree: " << minCost << endl;
return 0;
}