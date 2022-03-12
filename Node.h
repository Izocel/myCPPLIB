#ifndef NODE_H
#define NODE_H
#include <type_traits>

template <class T>
class Node
{
private:
	T m_data{ NULL };
	Node* m_next{ nullptr };
public:

	Node<T>() = default;

	// copy constructor with data
	Node<T>(const T & data);

	// Move constructor with data
	Node<T>(T && data);

	T getData() const;
	void setData(T data);
	Node<T>* getNext() const;
	void setNext(Node* next);

	void print();
};

template<class T>
inline Node<T>::Node(const T& data)
{
	m_data = data;
}

template<class T>
inline Node<T>::Node(T&& data) : m_data(std::move(data))
{
	if (std::is_pointer<T>::value)
		data = nullptr;
}

template<class T>
inline T Node<T>::getData() const
{
	return m_data;
}

template<class T>
inline void Node<T>::setData(T data)
{
	m_data = data;
}

template<class T>
inline Node<T>* Node<T>::getNext() const
{
	return m_next;
}

template<class T>
inline void Node<T>::setNext(Node* next)
{
	m_next = next;
}

template<class T>
inline void Node<T>::print()
{
	std::cout 
		<< "\n\n|Link: " << getNext()
		<< "|  |Data: " << getData()
		<< "|  |Self: " << this << '|';
}

#endif 
