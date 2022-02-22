#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
	T m_data; // élément contenant les données
	Node* m_next; // lien vers la prochaine donnée de la série
public:
	Node(T data);
	T* getData();
	void setData(T data);
	Node* getNext();
	void setNext(Node* next);
};

#endif
