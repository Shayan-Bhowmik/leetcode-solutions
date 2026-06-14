/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;

        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        int left = 0;
        int right = n-1;
        int sum = 0;

        while(left < right) {
            sum  = max(sum, nums[left] + nums[right]);
            left++;
            right--;
        }
        return sum;
    }
};