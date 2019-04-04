#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if (head_ != NULL)
	{
		Node* curr = head_;
		Node* next = head_->next;
		do
		{
			next = curr->next;
			delete curr;
			curr = next;
		} while (curr != NULL);
	}
}

bool DoublyLinkedList::empty() const
{
	return size_ == 0;
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
	cout << "List: " << endl;
	Node *curr = head_;
	unsigned int count = 0;
	while (count < size_)
	{
		cout << count << " " << curr->value << endl;
		curr = curr->next;
		count++;
	}
}

bool DoublyLinkedList::insert_front(DataType value)
{
	if (size_ >= CAPACITY)
		return 0;
	Node *newNode = new Node(value);
	if (size_ == 0)
	{
		head_ = newNode;
		head_->next = NULL;
		head_->prev = NULL;
		tail_ = head_;
	}
	else
	{
		newNode->next = head_;
		newNode->prev = NULL;
		head_->prev = newNode;
		head_ = newNode;
	}
	++size_;
	return 1;
}

bool DoublyLinkedList::remove_front()
{
	if (head_ == NULL)
		return false;
	if (size_ == 1)
	{
		delete head_;
		head_ = NULL;
		tail_ = NULL;
	}
	else
	{
		Node *temp;
		temp = head_->next;
		delete head_;
		head_ = temp;
		head_->prev = NULL;
		temp = NULL;
	}
	size_--;
	return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{
	if (size_ >= CAPACITY)
		return 0;
	Node *newNode = new Node(value);
	if (size_ == 0)
		insert_front(value);
	else
	{
		newNode->prev = tail_;
		newNode->next = NULL;
		tail_->next = newNode;
		tail_ = newNode;
		++size_;
	}
	return 1;
}

bool DoublyLinkedList::remove_back()
{
	if (head_ == NULL)
		return false;
	if (size_ == 1)
	{
		delete tail_; // or delete head_, should be the same thing tbh.
		head_ = NULL;
		tail_ = NULL;
	}
	else
	{
		Node *temp;
		temp = tail_->prev;
		delete tail_;
		tail_ = temp;
		tail_->next = NULL;
		temp = NULL;
	}
	size_--;
	return true;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if (index > size_ || size_ + 1 > CAPACITY)
		return false;
	if (index == 0)
		insert_front(value);
	else if (index == size_)
		insert_back(value);
	else
	{
		Node * target = getNode(index);
		Node * newNode = new Node(value);
		newNode->next = target;
		newNode->prev = target->prev;
		target->prev->next = newNode;
		target->prev = newNode;
		size_++;
	}
	return true;
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if (index >= size_ || size_ == 0)
		return 0;
	if (index == size_ - 1)
		remove_back();
	else if (index == 0)
		remove_front();
	else
	{
		Node * temp = getNode(index);
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		temp = NULL;
		size_--;
	}
	return 1;

}

unsigned int DoublyLinkedList::search(DataType value) const
{
	unsigned int count = 0;
	Node* curr = head_;
	while (count < size_)
	{
		if (curr->value == value)
			return count;
		curr = curr->next;
		count++;
	}
	return size_;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if (size_ == 0)
		return 0;
	Node *node = getNode(index);
	if (node)
		return node->value;
	else
		return tail_->value;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	Node *node = getNode(index);
	if (node)
	{
		node->value = value;
		return true;
	}
	return false;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	if (index >= size_)
		return NULL;
	int count = 0;
	Node* curr = head_;
	while (count != index)
	{
		curr = curr->next;
		count++;
	}
	return curr;

}
unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
}
bool DoublyLinkedList::full() const
{
	return size_ == CAPACITY;
}
