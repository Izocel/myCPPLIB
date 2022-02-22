#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
	T m_data; // �l�ment contenant les donn�es
	Node* m_next; // lien vers la prochaine donn�e de la s�rie
public:
	Node(T data);
	T* getData();
	void setData(T data);
	Node* getNext();
	void setNext(Node* next);
};

#endif
