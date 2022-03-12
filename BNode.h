#ifndef BNODE_H
#define BNODE_H
#include <type_traits>

template <class T>
class BNode
{
private:
	T m_data{};
	BNode* m_parent{ nullptr };
	BNode* m_left{ nullptr };
	BNode* m_right{ nullptr };
public:

	BNode<T>() = default;

	// copy constructor with data
	BNode<T>(const T& data);

	// Move constructor with data
	BNode<T>(T && data);

	T getData() const;
	bool isExternal();
	bool isRoot();
	BNode<T>* getParent() const;
	BNode<T>* getLeft() const;
	BNode<T>* getRight() const;
	void setData(T data);
	void setParent(BNode* parentPtr);
	void setLeft(BNode* leftPtr);
	void setRight(BNode* rightPtr);

	void print();

};

template<class T>
inline BNode<T>::BNode(const T& data)
{
	m_data = data;
}

template<class T>
inline BNode<T>::BNode(T&& data) : m_data(std::move(data))
{
	if (std::is_pointer<T>::value)
		data = nullptr;
}

template<class T>
inline T BNode<T>::getData() const
{
	return m_data;
}

template<class T>
inline bool BNode<T>::isExternal()
{

	return this == nullptr || ( m_left != nullptr && m_right != nullptr);
}

template<class T>
inline bool BNode<T>::isRoot()
{
	return m_parent == nullptr;
}

template<class T>
inline BNode<T>* BNode<T>::getParent() const
{
	return m_parent;
}

template<class T>
inline BNode<T>* BNode<T>::getLeft() const
{
	return m_left;
}

template<class T>
inline BNode<T>* BNode<T>::getRight() const
{
	return m_right;
}

template<class T>
inline void BNode<T>::setData(T data)
{
	m_data = data;
}

template<class T>
inline void BNode<T>::setParent(BNode* parentPtr)
{
	m_parent = parentPtr;
}

template<class T>
inline void BNode<T>::setLeft(BNode* leftPtr)
{
	m_left = leftPtr;
}


template<class T>
inline void BNode<T>::setRight(BNode* rightPtr)
{
	m_right = rightPtr;
}

template<class T>
inline void BNode<T>::print()
{
	std::cout
		<< "\n\n|Links: \nL:" 
			<< getLeft() << "\nR"
			<< getRight()
		<< "|  |Data: " << getData()
		<< "|  |Self: " << *this << '|';
}

#endif
