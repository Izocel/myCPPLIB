#ifndef NODE_H
#define NODE_H
template <class T>
class Node
{
private:
	T m_data;
	Node* m_next;
public:
	Node(T data) : m_data{ data }, m_next{ nullptr } {}

	void setData(T data)
	{
		m_data = data;
	}

	T getData()
	{
		return m_data;
	}

	void setNext(Node* next)
	{
		m_next = next;
	}

	Node* getNext()
	{
		return m_next;
	}
};

#endif