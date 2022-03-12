#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <type_traits>
#include <memory>

#include "BNode.h"

template<typename T>
class BinaryTree
{
public:
	BinaryTree() = default;
	BinaryTree(const T& data);
	~BinaryTree() = default;

	size_t size();
	const BNode<T>* insert(const T& data);
	const BNode<T>* root();
	const BNode<T>* search(const T& data, const BNode<T>* srcPtr);
	const BNode<T>* search(T&& data, const BNode<T>* srcPtr);

private:
	size_t m_size{0};
	BNode<T>* m_root{ nullptr };
	BNode<T>* m_next{ nullptr };
};

template<typename T>
inline BinaryTree<T>::BinaryTree(const T& data)
	: m_root(new BNode<T>{ data }), m_size{ 1 }
{}


template<typename T>
inline size_t BinaryTree<T>::size()
{
	return m_size;
}

template<typename T>
inline const BNode<T>* BinaryTree<T>::insert(const T& data)
{
	// Create new Node "root"
	if (m_root == nullptr) {
		m_root = new BNode<T>{ data };
		return m_root;
	}

	bool notFound{ true };
	m_next = m_root;
	BNode<T>* newNode{new BNode<T>{ data }};

	/// Unbalanced Tree Algo
	while (notFound)
	{
		if (data == m_next->getData())
			throw std::invalid_argument("\nDuplicate data are not alowwed.");
			

		// Left Move
		if (data < m_next->getData()) {
			if (m_next->getLeft() == nullptr) {
				m_next->setLeft(newNode);
				notFound = false;
			}
			else
				m_next = m_next->getLeft();
		}
		// Right Move
		else {
			if (m_next->getRight() == nullptr) {
				m_next->setRight(newNode);
				notFound = false;
			}
			else
				m_next = m_next->getRight();
		}
	}
	m_size++;
	newNode->setParent(m_next);
	return newNode;
}

template<typename T>
inline const BNode<T>* BinaryTree<T>::root()
{
	return m_root;
}

template<typename T>
inline const BNode<T>* BinaryTree<T>::search(const T& data, const BNode<T>* srcPtr)
{
	if (m_root == nullptr) return nullptr;
	if (srcPtr == nullptr) return nullptr;
	else if (srcPtr->getData() == data) return srcPtr;
	else if (data <= srcPtr->getData()) return search(data, srcPtr->getLeft());
	else return search(data, srcPtr->getRight());
}

template<typename T>
inline const BNode<T>* BinaryTree<T>::search(T&& data, const BNode<T>* srcPtr)
{
	if (m_root == nullptr) return nullptr;
	if (srcPtr == nullptr) return nullptr;
	else if (srcPtr->getData() == data) return srcPtr;
	else if (data <= srcPtr->getData()) return search(data, srcPtr->getLeft());
	else return search(data, srcPtr->getRight());
}


#endif
