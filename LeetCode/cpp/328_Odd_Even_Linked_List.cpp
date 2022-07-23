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
	ListNode* count_node(ListNode* head) {
		ListNode* odd = new ListNode();
		ListNode* even = new ListNode();
		ListNode* odd_head = odd;
		ListNode* even_head = even;
		int cnt = 0;

		while (head != nullptr) {
			cnt++;

			if (cnt % 2 != 0) {
				odd->next = new ListNode(head->val);
				odd = odd->next;
			}
			else {
				even->next = new ListNode(head->val);
				even = even->next;
			}

			head = head->next;
		}

		odd->next = even_head->next;

		return odd_head->next;
	}

	ListNode* oddEvenList(ListNode* head) {
		return count_node(head);
	}
};