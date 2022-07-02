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
	void rev(ListNode* head, ListNode*& point) {
		if (head->next == nullptr) {
			point = head;
			return;
		}

		rev(head->next, point);

		head->next->next = head;
		head->next = nullptr;

		return;
	}

	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)
			return head;

		ListNode* ret = new ListNode();

		rev(head, ret);

		return ret;
	}
};