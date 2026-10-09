
class Solution {
public:
    vector<int> NSL(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return nsl;
    }
    vector<int> NSR(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsr(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nsr;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;

        vector<int> nsl = NSL(arr);   // NEXT SMALLER left
        vector<int> nsr = NSR(arr);   // NEXT SMALLER RIGHT

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - nsl[i];
            long long right = nsr[i] - i;

            long long totalways = left * right;
            long long totalSum = arr[i] * totalways;

            sum = (sum + totalSum) % mod;
        }

        return sum;
    }
};