#include <iostream>
#include <vector>
#include <string>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
};

using namespace std;

ListNode *swapPairs(ListNode *head){
	if(!head || !head->next) return head;
	ListNode *nxt = head->next;
	head->next = nxt->next;
	nxt->next = head;
	head = nxt;
	nxt = nxt->next;
	while(nxt && nxt->next && nxt->next->next){
		ListNode *a = nxt->next;
		ListNode *b = nxt->next->next;
		a->next = b->next;
		b->next = a;
		nxt->next = b;
		nxt = a;
	}
	return head;
}

ListNode* anotherSwapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}

int main(){

	ListNode *head = new ListNode(1);
	for(int i=10; i>1; i--){
		ListNode *p = new ListNode(i);
		p->next = head->next;
		head->next = p;
	}
	head = swapPairs(head);
	for(ListNode *p=head; p; p=p->next){
		printf("%d\n", p->val);
	}

	return 0;
}
