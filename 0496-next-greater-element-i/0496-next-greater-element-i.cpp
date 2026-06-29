#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> st;

        // Process nums2 to find the next greater element for every number
        for (int num : nums2) {
            // Maintain a monotonic decreasing stack
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Map the results back to nums1
        vector<int> ans;
        ans.reserve(nums1.size());
        for (int num : nums1) {
            if (next_greater.count(num)) {
                ans.push_back(next_greater[num]);
            } else {
                ans.push_back(-1); // No greater element found
            }
        }

        return ans;
    }
};
