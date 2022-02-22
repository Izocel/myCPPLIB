#ifndef NODESTACK_H
#define NODESTACK_H
#include "Node.h"

template <class T>
class NodeStack
{
private:
	size_t m_size; // compteur pour le nombre d'�l�ments de la pile
	size_t m_maxSize; // limite quand au nombre maximum d'�l�ment de la pile
	Node<T>* m_top{nullptr}; // pointeur vers l'�l�ment du dessus de la pile
public:
	NodeStack();
	~NodeStack();
	void setMaxSize(size_t size); // d�finie le nombre d'�l�ment maximum que prendra la pile
	bool push(T data); // ajoute une donn�e � la pile
	T pop(); // enl�ve le premier �l�ment sur le dessus de la pile
	size_t getSize() const; // retroune le nombre d'�l�ments dans la pile
	size_t getMaxSize() const; // retroune le nombre maximum de la pile
	T* getTop() const; // retourne la donn�e sur le dessus de la pile, sans modifier la pile
	bool isFull() const;
	bool isEmpty() const; // vrai si la pile est vide
	void toString() const; // fonction utilitaire pour afficher l'�tat de la pile
};

#endif