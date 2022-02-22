#ifndef NODESTACK_H
#define NODESTACK_H
#include "Node.h"

template <class T>
class NodeStack
{
private:
	size_t m_size; // compteur pour le nombre d'éléments de la pile
	size_t m_maxSize; // limite quand au nombre maximum d'élément de la pile
	Node<T>* m_top{nullptr}; // pointeur vers l'élément du dessus de la pile
public:
	NodeStack();
	~NodeStack();
	void setMaxSize(size_t size); // définie le nombre d'élément maximum que prendra la pile
	bool push(T data); // ajoute une donnée à la pile
	T pop(); // enlève le premier élément sur le dessus de la pile
	size_t getSize() const; // retroune le nombre d'éléments dans la pile
	size_t getMaxSize() const; // retroune le nombre maximum de la pile
	T* getTop() const; // retourne la donnée sur le dessus de la pile, sans modifier la pile
	bool isFull() const;
	bool isEmpty() const; // vrai si la pile est vide
	void toString() const; // fonction utilitaire pour afficher l'état de la pile
};

#endif