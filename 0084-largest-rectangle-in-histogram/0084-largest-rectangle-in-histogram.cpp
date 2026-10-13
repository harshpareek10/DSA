class Solution {
public:
    vector<int> nsl(vector<int>& heights) {
    stack<int> st;
    vector<int> left(heights.size());

    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty())
            left[i] = -1;
        else
            left[i] = st.top();

        st.push(i);
    }
    return left;
}

vector<int> nsr(vector<int>& heights) {
    stack<int> st;
    vector<int> right(heights.size());
    for (int i = heights.size() - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty())
            right[i] = heights.size();
        else
            right[i] = st.top();

        st.push(i);
    }

    return right;
} 
   int largestRectangleArea(vector<int>& heights) {

    vector<int> left = nsl(heights);
    vector<int> right = nsr(heights);

    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}
};