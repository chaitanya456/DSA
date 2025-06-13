#include<bits/stdc++.h>
using namespace std;

// Function to simulate the rostering process
int calculateRosteringDays(int n, int m, vector<pair<int, int>> &friendships, int k) {
    vector<vector<int>> adjList(n);
    for (const auto &f : friendships) {
        adjList[f.first].push_back(f.second);
        adjList[f.second].push_back(f.first);
    }

   cout<<"Adjacency List:\n";
   for ( auto x: adjList)
   {
        cout<<endl;
        for (auto y: x)
        cout<<y<<" ";
   }
   return 0;
}

int main() {
    int n, m, k;
    cout<<"Enter Number of employees:\t";
    cin >> n;
    cout<<"Enter Number of connections:\t";
    cin>>m;
    vector<pair<int, int>> friendships(m);
    for (int i = 0; i < m; ++i) 
        cin >> friendships[i].first >> friendships[i].second;
    cout<<"Enter Roster:\t";
    cin >> k;

    int result = calculateRosteringDays(n, m, friendships, k);
    cout << result << endl;

    return 0;
}
