#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
};
ListNode* bremoveNthFromEnd(ListNode *head, int n){
	while(head){
		ListNode *t = head;
		head = head->next;
		delete t;
	}
	return head;
}
ListNode* removeNthFromEnd(ListNode *head, int n){
	if(!head) return NULL;
	ListNode *node = head, *probe = head, *ahead;
	while(1){
		int step=0;
		probe = node;
		while(probe->next && step < 2*n){
			probe = probe->next;
			step++;
			if(step == n) ahead = probe;
		}
		if(step == 2*n){
			node = ahead;
		}
		else if(step < n){		// n == list.size()
			probe = head;
			head = head->next;
			delete probe;
			break;
		}
		else{
			while(step - n){
				node = node->next;
				step--;
			}
			probe = node->next;
			node->next = node->next->next;
			delete probe;
			break;
		}
	}
	return head;
}

int main(){
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	for(int i=1; i<10; i++){
		p->next = new ListNode(i);
		p = p->next;
	}
	head = removeNthFromEnd(head, 10);
	for(p=head; p!=NULL; p=p->next)
		cout << p->val << " ";
	while(p){
		ListNode *tmp = p->next;
		delete p;
		p = tmp;
	}

	return 0;
}
