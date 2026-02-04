
// learning from this question is that whenever u r using bfs caluculate neighbour ans not the present ans
//leetcode heighestpeak

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>> ans(m, vector<int>(n, -1));

        // push all water cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (auto d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;

                if (ans[ni][nj] == -1) {
                    ans[ni][nj] = ans[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return ans;
    }
};
