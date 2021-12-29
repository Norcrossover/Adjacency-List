#include "adj.h"



AdjacencyList::AdjacencyList() : lists(nullptr), size(0) {}


AdjacencyList::AdjacencyList(const char * fileName) {
	ifstream input;
	//this->size = getSizeOfGraph(input, fileName);
	this->size = 10;
	if (size == -1) exit(-1);
	//this->lists = new EdgeList[size];
	if (!extractData(input, fileName)) {
		std::cout << "failed to extract" << std::endl;
		exit(-1);
	}
}



int AdjacencyList::getSizeOfGraph(ifstream & input, const char * fileName) {
	int size = 0;
	input.open(fileName);
	if (input.good()) {
		while (input.peek()!=EOF) {
			if (input.peek() == '\n') size++;
		}
		input.close();
		return size;
	}
	return -1;
}



bool AdjacencyList::extractData(ifstream & input, const char * fileName) {
	this->lists = new EdgeList[this->size];
	input.open("test2.txt");
	if (input.good()) {
		while (input.peek() != EOF) {
			int count = 0, val = 0;
			char buffer; 
			while (input.peek() != '\n') {
				input >> val;
				input.get(buffer);
				if (buffer == '\n') break; 
				this->lists[count].addNode(val);
			}
			count++;
		}
		input.close();
		return true;
	}
	return false;
}



AdjacencyList::~AdjacencyList() {
	delete [] lists;
	size = 0;
}


void AdjacencyList::depthFirstTraversal() {
	return;
}


/*
void AdjacencyList::operator=(const EdgeList *& newList) {
	for (int i = 0; i < size; i++) {
		this->list[i]->head = newList->getHead();
	}
}
*/
