/*
On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: Joowon Park
Section: 02
Student Number: 21600293
*/
//  listnode.cpp
//  Created by idebtor@gmail.com on December 12, 2018.
/*
* Description:	This program implements a simple linked list of nodes
* without a head structure and without sentinel nodes. It simply links
* node to node. The caller is responsible for maintaining the the first
* (head) element of the list. Most functions need the first node to work
* with the list and returns the first node of the list since the first
* may be changed inside of the function.
*/
#include <iomanip>
#include "listnode.h"

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p) {
	if (empty(p)) return nullptr;
	DPRINT(cout << "clear: ";);

	pNode curr = p;
	while (curr != nullptr) {
		pNode prev = curr;
		curr = curr->next;
		delete prev;
	}
	cout << "\n\tAll things are cleared." << endl;
	return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p) {
	if (empty(p)) return 0;
	int count = 0;
	for (pNode c = p; c != nullptr; c = c->next, count++);
	return count;
}

// returns the last node of in the list.
pNode last(pNode p) {
	if (empty(p)) return nullptr;
	while (p->next != nullptr) p = p->next;
	return p;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p) {
	return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by one.
pNode push_front(pNode p, int val) {
	DPRINT(cout << "><push_front val=" << val << endl;);

	return new Node{val, p};
}

// adds a new node with val at the end of the list and returns the
// first node of the list. This effectively increases the list size by one.
pNode push_back(pNode p, int val) {
	DPRINT(cout << "><push_back val=" << val << endl;);

	pNode curr;
	if(empty(p)){
		pNode pushBack = new Node{val, nullptr};
		return pushBack;
	}
	curr = p;
	while(curr->next != nullptr){
		curr = curr-> next;
	}

	pNode pushBack = new Node{val, nullptr};
	curr->next = pushBack;
	return p;
}

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list.
// This effectively increases the container size by one.
pNode push(pNode p, int val, int x) {
	if (empty(p)) return push_front(p, val);
	if (p->item == x) return push_front(p, val);

	pNode curr = p->next;
	pNode prev = p;

	while(curr != nullptr){
		if(curr->item == x){
			pNode insert = new Node{val, curr};
			prev->next = insert;
			return p;
		}
		prev = curr;
		curr = curr->next;
	}

	return p;
}

// adds N number of new nodes at the end of the list, O(n)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
// Since it simply calls push_back() repeatedly, it is O(N^2).
pNode push_backN(pNode p, int N) {
	DPRINT(cout << "<push_backN N=" << size(p) << endl;);

	int range = N + size(p);
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		int val = rand() % range;
		p = push_back(p, val);
		cout << setw(7) << "\r\tinserting in [" << i << "]=" << val;
	}
	cout << "\n";

	DPRINT(cout << "<push_backN size=" << size(p) << endl;);
	return p;
}

// removes the first node in the list and returns the new first node.
// This destroys the removed node, effectively reduces its size by one.
pNode pop_front(pNode p) {
	DPRINT(cout << ">pop_front size=" << size(p) << endl;);

	pNode x;
	if(empty(p)){
		return p;
	}
	x = p;
	p = p->next;
	delete x;

	return p;
}

// removes the last node in the list, effectively reducing the
// container size by one. This destroys the removed node.
pNode pop_back(pNode p) {
	DPRINT(cout << ">pop_back size=" << size(p) << endl;);
	if (empty(p)) return nullptr;
	if(empty(p->next)){
		delete p;
		return nullptr;
	}

	pNode prev, curr;
	prev = nullptr;
	curr = p;
	while(curr->next != nullptr){
		prev = curr;
		curr = curr->next;
	}

	prev->next = nullptr;
	delete curr;

	DPRINT(cout << "<pop_back size=" << size(p) << endl;);
	return p;
}

// deletes N number of nodes, starting from the end.
// It deletes all the nodes if N is zero which is the default or out of
// the range of the list.
// Since it simply calls pop_back() which is O(n) repeatedly, it is O(N^2).
pNode pop_backN(pNode p, int N) {
	DPRINT(cout << ">pop_backN N=" << N << endl;);

	if(empty(p)) return nullptr;

	if(size(p) < N || N == 0){
		pNode curr = p;
		while (curr != nullptr) {
			pNode prev = curr;
			curr = curr->next;
			delete prev;
		}
		return nullptr;
	}

	for (int i = 0; i < N; i++) {
		p = pop_back(p);
		cout << setw(7) << "\r\tdeleting in [" << size(p) << "]         ";
	}
	cout << "\n";

	DPRINT(cout << "<pop_backN size=" << size(p) << endl);
	return p;
}

// removes the first occurrence of the node with val from the list
pNode pop(pNode p, int val) {
	DPRINT(cout << ">pop val=" << val << endl;);
	if (empty(p)) return nullptr;    // nothing to delete

	if (p->item == val) return pop_front(p);

	pNode prev = nullptr;
	pNode curr = p;

	while(curr != nullptr){
		if(curr->item == val){
			prev->next = curr->next;
			delete curr;
			return p;
		}
		prev = curr;
		curr = curr->next;
	}

	DPRINT(cout << "<pop size=" << size(p) << endl;);
	return p;
}

// shows the values of all the nodes in the list if all is true or
// the list size is less than pmax * 2. If there are more than
// (pmax * 2) nodes, then it shows only pmax number of nodes from
// the beginning and the end in the list.
void show(pNode p, bool all) {
	DPRINT(cout << "show(" << size(p) << ")\n";);
	if (empty(p)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}
	int i;
	int pmax = 10;   // a magic number, max number of items per line
	pNode curr;
	const int N = size(p);

	if (all || N < pmax * 2) {
		for (i = 1, curr = p; curr != nullptr; curr = curr->next, i++) {
			cout << " -> " << curr->item;
			if (i % pmax == 0) cout << endl;
		}
		return;
	}

	// print the first pmax items
	for(i=0, curr=p; i<pmax; curr = curr->next, i++ ){
		cout << " -> " << curr->item;
	}

	cout << "\n...left out...\n";
	// print the last pmax items
	// move the pointer to the place where pmax items are left.

	for(i=0; i<size(p)-pmax * 2; i++){
		curr = curr->next;
	}

	for(i=0; i<pmax; curr = curr->next, i++ ){
		cout << " -> " << curr->item;
	}

	cout << "\n";
}
