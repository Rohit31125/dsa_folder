// Rat in a maze Problem geeks for geeks

// medium level problem


#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isSafe(vector<vector<int>>& m, int n, int x, int y, vector<vector<int>>& visited) {
        return (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1);
    }

    void solve(vector<string>& ans, vector<vector<int>>& visited, int x, int y, vector<vector<int>>& m, int n, string path) {
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Down
        int newx = x + 1, newy = y;
        if (isSafe(m, n, newx, newy, visited)) {
            path.push_back('D');
            solve(ans, visited, newx, newy, m, n, path);
            path.pop_back();
        }

        // Up
        newx = x - 1, newy = y;
        if (isSafe(m, n, newx, newy, visited)) {
            path.push_back('U');
            solve(ans, visited, newx, newy, m, n, path);
            path.pop_back();
        }

        // Right
        newx = x, newy = y + 1;
        if (isSafe(m, n, newx, newy, visited)) {
            path.push_back('R');
            solve(ans, visited, newx, newy, m, n, path);
            path.pop_back();
        }

        // Left
        newx = x, newy = y - 1;
        if (isSafe(m, n, newx, newy, visited)) {
            path.push_back('L');
            solve(ans, visited, newx, newy, m, n, path);
            path.pop_back();
        }

        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        string path;

        if (m[0][0] == 0) {
            return ans;
        }

        int srcx = 0, srcy = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        solve(ans, visited, srcx, srcy, m, n, path);
        sort(ans.begin(), ans.end());

        return ans;
    }
};
