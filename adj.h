#include "edge.h"
using namespace std;

class AdjacencyList {
	public:
		AdjacencyList();
		AdjacencyList(const char * fileName);
		int getSizeOfGraph(ifstream & input, const char * fileName);
		bool extractData(ifstream & input, const char * fileName);
		~AdjacencyList();
//		void operator=(const EdgeList *& newList);
		void depthFirstTraversal();
	private:
		EdgeList * lists;
		int size;
};
