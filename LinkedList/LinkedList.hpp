#include <cassert>

template<typename type>
class LinkedList
{
private:
	struct Node
	{
		type data;
		Node *next;
	};
	
	struct Node* _head;
	struct Node* _tail;
	
	size_t _size;
public:
	LinkedList() : _head(nullptr), _tail(nullptr), _size(0) { }
	
	void push_back(type elem);
	void push_front(type elem);
	
	type pop_back();
	type pop_front();
	
	type back();
	type front();
	
	size_t size();
	
	~LinkedList();
};

template<typename type>
void LinkedList<type>::push_back(type elem)
{
	if (_size == 0) {
		assert(_head == nullptr);
		assert(_tail == nullptr);
		
		_head = _tail = new Node{elem, nullptr};
	}
	else {
		assert(_head != nullptr);
		assert(_tail != nullptr);
		
		_tail = _tail->next = new Node{elem, nullptr};
	}
	
	++_size;
}

template<typename type>
void LinkedList<type>::push_front(type elem)
{
	if (_size == 0) {
		assert(_head == nullptr);
		assert(_tail == nullptr);
		
		_head = _tail = new Node{elem, nullptr};
	}
	else {
		assert(_head != nullptr);
		assert(_tail != nullptr);
		
		struct Node* tmp = _head;
		_head = new Node{elem, nullptr};
		_head->next = tmp;
	}
	
	++_size;
}

template<typename type>
type LinkedList<type>::pop_back()
{
	assert(_head != nullptr);
	assert(_tail != nullptr);
	assert(_size > 0);
	
	type retval = _tail->data;
	
	if (_size == 1) {
		delete _tail;
		_head = _tail = nullptr;
	}
	else {
		struct Node* node;
		for (node = _head; node->next != _tail; node = node->next);
		
		delete _tail;
		_tail = node;
	}
	
	--_size;
	
	return retval;
}

template<typename type>
type LinkedList<type>::pop_front()
{
	assert(_head != nullptr);
	assert(_tail != nullptr);
	assert(_size > 0);
	
	type retval = _head->data;
	
	if (_size == 1) {
		delete _head;
		_head = _tail = nullptr;
	}
	else {
		struct Node* tmp = _head->next;
		delete _head;
		_head = tmp;
	}
	
	--_size;
	
	return retval;
}

template<typename type>
type LinkedList<type>::front()
{
	assert(_head != nullptr);
	assert(_tail != nullptr);
	assert(_size > 0);
	
	return _head->data;
}

template<typename type>
type LinkedList<type>::back()
{
	assert(_head != nullptr);
	assert(_tail != nullptr);
	assert(_size > 0);
	
	return _tail->data;
}

template<typename type>
size_t LinkedList<type>::size()
{
	return _size;
}

template<typename type>
LinkedList<type>::~LinkedList<type>()
{
	if (_size > 0) {
		assert(_head != nullptr);
		assert(_tail != nullptr);
		
		struct Node* node 	= _head;
		struct Node* tmp 	= node->next;
		
		while (tmp != nullptr) {
			delete node;
			node 	= tmp;
			tmp 	= node->next;
		}
		
		delete node;
	}
}


