#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> st;
        
        // Step 1: Find the next greater element for every number in nums2
        for (int num : nums2) {
            // While stack is not empty and current num is greater than the stack top
            while (!st.empty() && num > st.top()) {
                next_greater[st.top()] = num; // Current num is the next greater element
                st.pop();
            }
            st.push(num); // Push current num to find its next greater element later
        }
        
        // Step 2: Build the result array for nums1 using our map
        std::vector<int> result;
        for (int num : nums1) {
            if (next_greater.count(num)) {
                result.push_back(next_greater[num]);
            } else {
                result.push_back(-1); // No greater element found in nums2
            }
        }
        
        return result;
    }
};
