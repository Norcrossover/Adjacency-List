#include "edge.h"

class AdjacencyList {
	public:
		AdjacencyList();
		AdjacencyList(const char * fileName);
		~AdjacencyList();
		void operator=(const EdgeList *& newList);
		void depthFirstTraversal(int v);
	private:
		EdgeList lists[];
		int size;
};
