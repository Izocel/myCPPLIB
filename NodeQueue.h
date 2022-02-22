#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include "Node.h"

template <class T>
class NodeQueue
{
private:
	Node* m_front;
	Node* m_back;
	int m_size;
public:
	NodeQueue();
	int getFront();
	int getBack();
	void enqueue(int data);
	void dequeue();
	bool isEmpty();
	void afficherFile();
};

#endif
