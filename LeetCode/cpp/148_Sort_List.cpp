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
	ListNode* sortList(ListNode* head) {
		vector<int> v;
		ListNode* answer = new ListNode();
		ListNode* ret = answer;

		while (head != nullptr) {
			v.push_back(head->val);
			head = head->next;
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			answer->next = new ListNode(v[i]);
			answer = answer->next;
		}

		return ret->next;
	}
};