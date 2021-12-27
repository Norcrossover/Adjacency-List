#include "adj.h"


AdjacencyList:AdjacencyList() : size(0), list(nullptr);


AdjacencyList::AdjacencyList(const char * fileName) {
	ifstream input;
	EdgeList tempLists[1000000000];
	input.open(fileName);
	if (input.good()) {
		while (input.peek() != EOF) {
			int count = 0, val = 0;
			EdgeList * newList = new EdgeList();
			while (input.peek != '\n') {
				input >> val;
				input.get();
				newList->addNode(val);
			}
			tempLists[count] = newList;
			count++;
		}
		this->size = count+1;
		this->lists = new EdgeList[size];
		lists = tempLists;
	}
	else {
		exit();
	}
}



AdjacencyList::~AdjacencyList() {
	for (int i = 0; i < size; i++) {
		delete list[i].head;
	}
	delete [] list;
	size = 0;
}


void AdjacencyList::depthFirstTraversal(int v) {
	return;
}



void AdjacencyList::operator=(const EdgeList *& newList) {
	for (int i = 0; i < size; i++) {
		this->list[i]->head = newList->getHead();
	}
}
