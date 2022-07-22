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
	void explore_linked_list(ListNode* head, string& s) {
		if (head == nullptr)
			return;

		s += to_string(head->val);
		explore_linked_list(head->next, s);
	}

	bool find_palindrome(string s) {
		int left = 0;
		int right = s.size() - 1;

		while (left < right) {
			if (s[left++] != s[right--])
				return false;
		}

		return true;
	}

	bool isPalindrome(ListNode* head) {
		string s;
		explore_linked_list(head, s);

		if (find_palindrome(s))
			return true;

		return false;
	}
};