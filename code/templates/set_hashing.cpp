class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // store all buildings in a set for O(1) lookup
        unordered_set<long long> S;
        auto encode = [&](int x, int y) {
            return (long long)x << 32 | y;   // pair hashing
        };

        for (auto &b : buildings)
            S.insert(encode(b[0], b[1]));

        int covered = 0;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            // check all four directions
            bool left  = S.count(encode(x-1, y));
            bool right = S.count(encode(x+1, y));
            bool down  = S.count(encode(x, y-1));
            bool up    = S.count(encode(x, y+1));

            if (left && right && up && down)
                covered++;
        }

        return covered;
    }
};
