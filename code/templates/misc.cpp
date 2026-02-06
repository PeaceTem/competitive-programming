//---------------------------
// Maximal Square in a Binary Matrix
// Given a 2D binary matrix filled with 0's and 1's,
// find the largest square containing only 1's and return its side length.
//---------------------------

#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(n == 0) return 0;
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxSide = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 1){
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide;
}

int main(){
    vector<vector<int>> mat = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };
    cout << maximalSquare(mat) << "\n"; // Output: 2
}


//---------------------------
// Largest Rectangle in Histogram
// Given an array of integers representing the heights of bars in a histogram,
// find the area of the largest rectangle that can be formed within the bounds of the histogram.
//---------------------------

int largestRectangle(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;
    heights.push_back(0); // sentinel

    for(int i = 0; i <= n; i++) {
        while(!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    return maxArea;
}


//---------------------------
// Maximal Rectangle in Binary Matrix
// Given a 2D binary matrix filled with 0's and 1's,
// find the largest rectangle containing only 1's and return its area.
// ---------------------------

#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;
    heights.push_back(0); // sentinel

    for(int i = 0; i <= n; i++) {
        while(!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    int n = matrix.size(), m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            heights[j] = matrix[i][j] == 0 ? 0 : heights[j] + 1;
        }
        maxArea = max(maxArea, largestRectangle(heights));
    }

    return maxArea;
}

int main() {
    vector<vector<int>> mat = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };

    cout << "Max rectangle area: " << maximalRectangle(mat) << "\n"; // Output: 6
}
