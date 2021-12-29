#include <iostream>
#include <fstream>

class EdgeList {
	public:
		EdgeList();
		~EdgeList();
		void displayConnections();
		void addNode(int val);
//		Node * getHead();
	private:	
		struct Node {
			Node(int newVal) {
				val = newVal;
				next = nullptr;
			}	
			~Node() {
				val = 0;
			}
			int val;
			Node * next;
		};
		Node * head;
		int val;
		void addNode(Node * prev, Node * node, Node * newNode);
		void displayConnections(Node * node);
		void destroy(Node * curr);
};
