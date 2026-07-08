class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> st;
        
        // Traverse nums2 to find the next greater element for every number
        for (int num : nums2) {
            // If the current number is greater than the stack's top,
            // it is the next greater element for the stack's top element
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        // Build the result vector for nums1 using the map
        vector<int> ans;
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
