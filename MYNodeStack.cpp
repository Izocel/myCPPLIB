#pragma once
#include <iostream>
#include "NodeStack.h"

template<class T>
NodeStack<T>::NodeStack() : m_size{ 0 }, m_top{ nullptr }{}

//template<class T>
//NodeStack<T>::~NodeStack<T>()
//{
//	Node<T>* temp{ m_top };
//	while (!(temp == nullptr))
//	{
//		m_top = m_top->getNext();
//		temp->setNext(nullptr);
//		delete temp;
//		temp = m_top;
//	}
//}

//template<class T>
//void NodeStack<T>::setMaxSize(size_t maxSize)
//{
//	if (maxSize >= m_maxSize)
//	{
//		m_maxSize = maxSize;
//	}
//
//	return;
//}
//
//
//template<class T>
//size_t NodeStack<T>::getSize() const
//{
//	return m_size;
//}
//
//template<class T>
//size_t NodeStack<T>::getMaxSize() const
//{
//	return m_maxSize;
//}
//
//template<class T>
//bool NodeStack<T>::isEmpty() const
//{
//	return m_top == nullptr;
//}
//
//template<class T>
//bool NodeStack<T>::isFull()  const
//{
//	return m_size == m_maxSize;
//}
//
//
//template<class T>
//bool NodeStack<T>::push(T data)
//{
//	if (isFull() && m_maxSize) return false;
//
//	Node<T>* temp{ new Node<T>{data} };
//	if (isEmpty())
//		temp->setNext(nullptr);
//	else
//		temp->setNext(m_top);
//
//	m_top = temp;
//	m_size++;
//}
//
//template<class T>
//T NodeStack<T>::pop()
//{
//	if (isEmpty()) return T();
//
//	Node<T> temp{ m_top };
//	Node<T>* tempPtr{ m_top };
//	m_top = m_top->getNext();
//	tempPtr->setNext(nullptr);
//	delete tempPtr;
//	
//	m_size--;
//	return temp;
//}
//
//template<class T>
//T* NodeStack<T>::getTop() const
//{
//	if (isEmpty())
//	{
//		std::cout << "Pile vide\n";
//		return -1;
//	}
//
//	return m_top->getData();
//}
//
//template<class T>
//void NodeStack<T>::toString() const
//{
//	if (isEmpty())
//	{
//		std::cout << "Pile vide\n";
//		return;
//	}
//
//	Node* temp{ m_top };
//	std::cout << "TOP -> ";
//	while (!(temp == nullptr))
//	{
//		std::cout << temp->getData() << " ";
//		temp = temp->getNext();
//	}
//
//	std::cout << "\n";
//}