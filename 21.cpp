#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
	if(!l1) return l2;
	if(!l2) return l1;
	ListNode *p1 = l1, *p2 = l2, *pre = NULL;
	while(p1->next && p2){
		if(p2->val < p1->val){
			if(pre){
				ListNode *tmp = p2->next;
				pre->next = p2;
				p2->next = p1;
				p2 = tmp;
				pre = pre->next;
			}else{
				pre = p2;
				p2 = p2->next;
				pre->next = p1;
				l1 = pre;
			}
		}else if(p2->val < p1->next->val){
			ListNode *tmp = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p2 = tmp;
		}else{
			pre = p1;
			p1 = p1->next;
		}
		if(!p1->next){
			p1->next = p2;
			break;
		}
		if(!p2){
			break;
		}
	}
	return l1;
}
int main(){
	ListNode l1(2), l2(1);
	ListNode *head = mergeTwoLists(&l1, &l2);
	ListNode *p=head;
	while(p){
		cout << p->val;
		p = p->next;
	}
	return 0;
}
