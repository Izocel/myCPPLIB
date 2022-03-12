#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include "Node.h"

template <class T, size_t N>
 
class NodeQueue
{
private:
	Node<T>* m_front{ nullptr };
	Node<T>* m_back{ nullptr };
	size_t m_maxSize{N};
	mutable size_t m_size{ 0 };

	void innitOrAppend(Node<T>*& newNodePtr);
public:
	NodeQueue();

	NodeQueue(T&& data) noexcept;
	NodeQueue(const T& data);

	/// <summary>
	/// Supression par cascade des pointeurs et de la queue...
	/// </summary>
	~NodeQueue();

	/// <summary>
	/// Supression par cascade des pointeurs...
	/// </summary>
	void empty();

	T getFront() const; // Retourne la donn�e � l'avant de la queue
	T getBack() const; // Retourne la donn�e � l'arri�re de la queue

	/// <summary>
	/// Ajoute la donnee à la fin de la queue
	/// </summary>
	/// <param name="data">La donnee</param>
	/// <exception cref="std::length_error">Si la queue est pleine</exception>
	void enqueue(T&& data); // Move at back
	/// <summary>
	/// Ajoute la donnee à la fin de la queue
	/// </summary>
	/// <param name="data">La donnee</param>
	/// <exception cref="std::length_error">Si la queue est pleine</exception>
	void enqueue(const T& data); // Assign at back


	void dequeue(); // Retire la donn�e de la fin de queue
	bool isEmpty() const;
	size_t size() const;
	bool isFull() const;
	void print() const;
};

#endif

template<class T, size_t N>
inline void NodeQueue<T, N>::innitOrAppend(Node<T>*& newNodePtr)
{
	if (m_back == nullptr) {
		m_back = newNodePtr;
		m_front = newNodePtr;
		m_front->setNext(nullptr);
	}
	else {
		newNodePtr->setNext(m_back);
		m_back = newNodePtr;
	}
	m_size++;
}

template<class T, typename size_t N>
inline NodeQueue<T,N>::NodeQueue()
{}

template<class T, size_t N>
inline NodeQueue<T, N>::NodeQueue(T&& data) noexcept
{
	Node<T>* newNodePtr{ new Node<T>{ data } };
	innitOrAppend(newNodePtr);
}

template<class T, size_t N>
inline NodeQueue<T, N>::NodeQueue(const T& data)
{
	Node<T>* newNodePtr{ new Node<T>{ data } };
	innitOrAppend(newNodePtr);
}

template<class T, typename size_t N>
inline NodeQueue<T,N>::~NodeQueue()
{
	std::cout << "\n\nNodeQueue destructor";
	delete m_front;
	delete m_back;
	m_size = 0;
}

template<class T, size_t N>
inline void NodeQueue<T, N>::empty()
{
	if (isEmpty()) return;
	delete m_back.getNext();
	m_back = nullptr;
	m_front = nullptr;
	m_size = 0;
}

template<class T, typename size_t N>
inline T NodeQueue<T,N>::getFront() const
{
	return m_front->getData();
}

template<class T, typename size_t N>
inline T NodeQueue<T,N>::getBack() const
{
	return m_back->getData();
}

template<class T, typename size_t N>
inline void NodeQueue<T, N>::enqueue(const T& data)
{
	if (isFull())
		throw std::length_error("NodeQueue is full max is: " + m_maxSize);

	Node<T>* newNodePtr{ new Node<T>{ data } };
	innitOrAppend(newNodePtr);
}


template<class T, typename size_t N>
inline void NodeQueue<T, N>::enqueue(T&& data)
{
	if (isFull())
		throw std::length_error("NodeQueue is full max is: " + m_maxSize);

	// Move data RValue param into newNode m_data...
	Node<T>* newNodePtr{ new Node<T>{} };
	newNodePtr->setData(std::move(data));

	innitOrAppend(newNodePtr);
}

template<class T, typename size_t N>
inline void NodeQueue<T,N>::dequeue()
{
	if (m_size == 0) throw std::length_error("NodeQueue is empty.");

	if (m_size == 1) {
		m_back = nullptr;
		m_front = nullptr;
	}
	else 
		m_back = m_back.getNext();

	m_size--;
}

template<class T, typename size_t N>
inline bool NodeQueue<T,N>::isEmpty() const
{
	return m_size == 0;
}

template<class T, typename size_t N>
inline size_t NodeQueue<T, N>::size() const
{
	return m_size;
}

template<class T, typename size_t N>
inline bool NodeQueue<T, N>::isFull() const
{
	return m_size == m_maxSize;
}

template<class T, typename size_t N>
inline void NodeQueue<T,N>::print() const
{
	if (isEmpty()) std::cout << "\n\nEMPTY";

	Node<T>* nodeTemp{ m_back };
	for (size_t i = 0; i < m_size; i++)
	{
		nodeTemp->print();
		nodeTemp = nodeTemp->getNext();
	}
	std::cout << "\n\n ---------------------------------";
}