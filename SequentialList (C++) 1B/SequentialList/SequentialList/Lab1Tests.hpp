#ifndef LAB1_TESTS_HPP
#define LAB1_TESTS_HPP

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include "DoublyLinkedList.hpp"
#include "SequentialList.hpp"

class SequentialListTest
{
public:
	bool test1()
	{
		unsigned int capacity = 5;
		SequentialList list(capacity);

		ASSERT_TRUE(list.size() == 0)
			ASSERT_TRUE(list.capacity() == capacity)
			ASSERT_TRUE(list.empty() == true)
			ASSERT_TRUE(list.full() == false)
			return true;
	}

	bool test2()
	{
		unsigned int capacity = 5;
		SequentialList list1(capacity);
		SequentialList list2(capacity);
		ASSERT_TRUE(list1.insert_front(100))
			ASSERT_TRUE(list2.insert_back(100))

			ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
			ASSERT_TRUE(list1.data_ != NULL)
			ASSERT_TRUE(list2.data_ != NULL)
			ASSERT_TRUE(list1.data_[0] == list2.data_[0] && list1.data_[0] == 100)
			return true;
	}

	bool test3()
	{
		unsigned int capacity = 5;
		SequentialList list(capacity);

		ASSERT_TRUE(list.insert_front(100))
			ASSERT_TRUE(list.insert_front(101))
			ASSERT_TRUE(list.remove_front())
			ASSERT_TRUE(list.remove_back())
			ASSERT_TRUE(list.search(100) == list.size_)


			for (int i = 0; i < capacity; i++) {
				ASSERT_TRUE(list.insert_back(i * 100))
			}

		unsigned int idx = 3;
		ASSERT_TRUE(list.search(list.select(idx)) == idx)
			ASSERT_TRUE(list.select(capacity + 1) == list.select(capacity))
			ASSERT_TRUE(list.search(1000) == list.size())

			for (int i = 0; i < capacity; i++) {
				ASSERT_TRUE(list.select(i) == i * 100 && list.data_[i] == i * 100)
			}
		return true;
	}

};

class DoublyLinkedListTest
{
public:
	bool test1()
	{
		DoublyLinkedList list;
		ASSERT_TRUE(list.size() == 0)
			ASSERT_TRUE(list.empty() == true)
			ASSERT_TRUE(list.full() == false)
			ASSERT_TRUE(list.head_ == NULL)
			ASSERT_TRUE(list.tail_ == NULL)
			return true;
	}

	bool test2()
	{
		DoublyLinkedList list1, list2;
		list1.insert_front(100);
		list2.insert_back(100);

		ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
			ASSERT_TRUE(list1.head_ != NULL && list1.head_ == list1.tail_)
			ASSERT_TRUE(list2.head_ != NULL && list2.head_ == list2.tail_)
			ASSERT_TRUE(list1.head_->prev == NULL && list1.tail_->next == NULL)
			ASSERT_TRUE(list2.head_->prev == NULL && list2.tail_->next == NULL)
			ASSERT_TRUE(list1.head_->value == list2.head_->value && list1.head_->value == 100)
			return true;
	}

	bool test3()
	{
		DoublyLinkedList list;

		ASSERT_TRUE(list.insert_front(100))
			ASSERT_TRUE(list.insert_front(101))
			ASSERT_TRUE(list.remove_front())
			ASSERT_TRUE(list.remove_back())
			ASSERT_TRUE(list.search(100) == list.size_)
			ASSERT_TRUE(list.head_ == NULL && list.tail_ == NULL)

			// List is [0, 100, ..., 400]
			const int num_elems = 5;
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(list.insert_back(i * 100))
		}

		unsigned int idx = 3;
		ASSERT_TRUE(list.search(list.select(idx)) == idx)
			ASSERT_TRUE(list.search(1000) == list.size_)

			// Check that the list has the right values
			for (int i = 0; i < num_elems; i++) {
				ASSERT_TRUE(list.select(i) == i * 100)
			}

		ASSERT_TRUE(list.head_->prev == NULL && list.tail_->next == NULL)
			return true;
	}

};


#endif
