#include "Node.h"


template<typename T>
Node<T>::Node(T data) : m_data { data }, m_next{ nullptr }{}

template<typename T>
T* Node<T>::getData()
{
	return m_data;
}

template<typename T>
void Node<T>::setData(T data)
{
	m_data = data;
}

template<typename T>
Node<T>* Node<T>::getNext()
{
	return m_next;
}

template<typename T>
void Node<T>::setNext(Node* next)
{
	m_next = next;
}