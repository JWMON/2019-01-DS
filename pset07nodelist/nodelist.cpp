//  nodelist.cpp
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
#include "nodelist.h"

// Removes all elements from the list container(which are destroyed),
// and leaving the container with a size of 0.
pNode clear(pNode p) {
	if (empty(p)) return nullptr;
	DPRINT(cout << "clear: ";);

	pNode curr = p;
	while (curr != nullptr) {
		pNode prev = curr;
		curr = curr->next;
		cout << prev->item << " ";
		delete prev;
	}
	cout << " cleared" << endl;
	cout << "\tHappy Coding~~\n";
	return nullptr;
}

// Returns the number of elements in the list container.
int size(pNode p) {
	if (empty(p)) return 0;
	int count = 0;
	for (pNode c = p; c != nullptr; c = c->next, count++);
	return count;
}

// Returns the last element of in the list
pNode last(pNode p) {
	if (empty(p)) return nullptr;
	while (p->next != nullptr) p = p->next;
	return p;
}

// Test whether container is empty
// Returns whether the list container is empty (i.e. whether its size is 0).
// This function does not modify the container in any way. To clear the
// content of a List container, see List::clear.
bool empty(pNode p) {
	return p == nullptr;
}

// Insert element at beginning
// Inserts a new element at the beginning of the list, right before its
// current first element.The content of item is copied(or moved) to the
// inserted element. This effectively increases the list size by one.
pNode push_front(pNode p, int item) {
	DPRINT(cout << "><push_front item=" << item << endl;);
	pNode pushFront;
	if(empty(p)){
		pushFront = new Node{item, nullptr};
		return pushFront;
	}
	pushFront = new Node{item, p};

	return pushFront;
}

// Add element at the end
// Adds a new element at the end of the list, after its current
// last element. The content of val is copied (or moved) to the
// new element. This effectively increases the list size by one.
pNode push_back(pNode p, int item) {
	DPRINT(cout << "><push_back item=" << item << endl;);
	pNode pushBack, head;
	if(empty(p)){
		pushBack = new Node{item, nullptr};
		return pushBack;
	}
	head = p;
	while(p->next != nullptr){
		p = p-> next;
	}

	pushBack = new Node{item, nullptr};
	p->next = pushBack;

	return head;
}

// inserts N nodes at the end, O(n)
pNode push_backN(pNode p, int N) {
	DPRINT(cout << "<push_backN N=" << size(p) << endl;);

	int range = N + size(p);
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		int item = rand() % range;
		p = push_back(p, item);
		cout << setw(7) << "\r\tinserting in [" << i << "]=" << item;
	}
	cout << "\n";

	DPRINT(cout << "<push_backN size=" << size(p) << endl;);
	return p;
}

// Delete first element
// Removes the first element in the list, effectively reducing
// its size by one. This destroys the removed element.
pNode pop_front(pNode p) {
	DPRINT(cout << ">pop_front size=" << size(p) << endl;);
	pNode popFront;
	if(empty(p)){
		return p;
	}
	popFront = p;
	p = p->next;
	delete popFront;

	return p;
}

// Delete last element
// Removes the last element in the list, effectively reducing the
// container size by one. This destroys the removed element.
pNode pop_back(pNode p) {
	DPRINT(cout << ">pop_back size=" << size(p) << endl;);
	if (empty(p)) return nullptr;
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

// delete N nodes from the end, O(N)
// if N is zero which is the default or out of the range of the list,
// delete all the nodes in the list.
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
	}

	DPRINT(cout << "<pop_backN size=" << size(p) << endl);
	return p;
}

// Remove an element with specific value
// Removes from the list the first occurrence of the element
// that compares equal to val.
pNode remove(pNode p, int item) {
	DPRINT(cout << ">remove item=" << item << endl;);
	if(empty(p)) return nullptr;
	if(p->item == item){
		return pop_front(p);
	}

	pNode prev = nullptr;
	pNode curr = p;

	while(curr != nullptr){
		if(curr->item == item){
			prev->next = curr->next;
			delete curr;
			return p;
		}
		prev = curr;
		curr = curr->next;
	}


	DPRINT(cout << "<remove size=" << size(p) << endl;);
	return p;
}

// shows all items in the list container if all is true or
// the list size is less than pmax * 2.
// if there are more than pmax * 2 nodes, then it shows pmax
// number of nodes each from the beginning and the end in the list.
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
