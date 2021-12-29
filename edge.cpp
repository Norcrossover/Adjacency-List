#include "edge.h"



EdgeList::EdgeList() : head(nullptr), val(0) {}



EdgeList::~EdgeList() {
	if (head) {
		destroy(head->next);
		delete head;
	}
	head = nullptr;
	val = 0;
}



void EdgeList::destroy(Node * curr) {
	if (!curr) return;
	destroy(curr->next);
	delete curr;
	curr = nullptr;
}



void EdgeList::addNode(int val) {
	Node * newNode = new Node(val);
	if (!head) {
		head = newNode;	
		return;
	}
	addNode(head, head->next, newNode);
}



void EdgeList::addNode(Node * prev, Node * node, Node * newNode) {
	if (!node) {
		prev->next = newNode;
		return;
	}
	if (newNode->val <= node->val) {
		newNode->next = node;
		prev->next = newNode;	
		return;
	}
	addNode(node, node->next, newNode);
}



/*
Node * EdgeList::getHead() {
	return this->head;
}
*/




void EdgeList::displayConnections() {
	if (!head) return;
	std::cout << head->val << " -> ";
	displayConnections(head->next);
}



void EdgeList::displayConnections(Node * node) {
	if (!node) return;
	if (node->next) {
		std::cout << node->val << " -> ";
	}
	else {
		std::cout << node->val;
	}
	displayConnections(node->next);
}
