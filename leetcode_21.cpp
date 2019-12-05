#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	ListNode* root;
	if (l1 == NULL && l2 == NULL) return NULL;
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	if (l1->val > l2->val) {
		root = new ListNode(l2->val);
		l2 = l2->next;
	}
	else {
		root = new ListNode(l1->val);
		l1 = l1->next;
	}

	ListNode* ptr = root;
	while (l1 != NULL && l2 != NULL) {
		if (l1->val > l2->val) {
			ptr->next = new ListNode(l2->val);
			l2 = l2->next;
		}
		else {
			ptr->next = new ListNode(l1->val);
			l1 = l1->next;
		}
		ptr = ptr->next;
	}

	if (l1 != NULL) {
		ptr->next = l1;
		return root;
	}
	ptr->next = l2;

	return root;
}
//int main() {
//
//
//	
//
//	return 0;
//}