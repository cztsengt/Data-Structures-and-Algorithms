#ifndef LAB2_TESTS_HPP
#define LAB2_TESTS_HPP

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include "DynamicStack.hpp"
#include "CircularQueue.hpp"

class DynamicStackTest
{
public:
	bool test1()
	{
		unsigned int size = 24;

		DynamicStack default_size_stack;
		ASSERT_TRUE(default_size_stack.empty() == true)
			ASSERT_TRUE(default_size_stack.size() == 0)

			DynamicStack stack(size);
		ASSERT_TRUE(stack.empty() == true)
			ASSERT_TRUE(stack.size() == 0)
			return true;
	}

	bool test2()
	{
		DynamicStack stack;
		stack.push(10);
		ASSERT_TRUE(stack.empty() == false)
			ASSERT_TRUE(stack.size() == 1)
			ASSERT_TRUE(stack.pop() == 10);
		ASSERT_TRUE(stack.empty() == true)
			ASSERT_TRUE(stack.size() == 0)
			return true;
	}

	bool test3()
	{
		DynamicStack stack(0);
		stack.push(10);
		stack.push(20);
		ASSERT_TRUE(stack.peek() == 20)
			ASSERT_TRUE(stack.pop() == 20)
			ASSERT_TRUE(stack.pop() == 10)
			ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK)
			ASSERT_TRUE(stack.peek() == DynamicStack::EMPTY_STACK)
			return true;
	}

};


class CircularQueueTest
{
public:
	bool test1()
	{
		CircularQueue queue;
		ASSERT_TRUE(queue.empty() == true)
			ASSERT_TRUE(queue.full() == false)
			ASSERT_TRUE(queue.size() == 0)
			ASSERT_TRUE(queue.size_ == 0)
			ASSERT_TRUE(queue.capacity_ == 16)
			return true;
	}

	bool test2()
	{
		CircularQueue queue;
		ASSERT_TRUE(queue.enqueue(10) == true)
			ASSERT_TRUE(queue.empty() == false)
			ASSERT_TRUE(queue.full() == false)
			ASSERT_TRUE(queue.size_ == 1)
			ASSERT_TRUE(queue.head_ == 0)
			ASSERT_TRUE((queue.tail_ == 1) || (queue.tail_ == 2))
			ASSERT_TRUE(queue.dequeue() == 10);
		ASSERT_TRUE(queue.empty() == true)
			ASSERT_TRUE(queue.size_ == 0)
			return true;
	}

	bool test3()
	{
		CircularQueue queue;
		ASSERT_TRUE(queue.enqueue(10) == true)
			ASSERT_TRUE(queue.enqueue(20) == true)
			ASSERT_TRUE(queue.empty() == false)
			ASSERT_TRUE(queue.full() == false)
			ASSERT_TRUE(queue.size_ == 2)
			ASSERT_TRUE(queue.head_ == 0)
			ASSERT_TRUE((queue.tail_ == 2) || ((queue.tail_ == 3)))
			ASSERT_TRUE(queue.peek() == 10);
		ASSERT_TRUE(queue.dequeue() == 10);
		ASSERT_TRUE(queue.peek() == 20);
		ASSERT_TRUE(queue.dequeue() == 20);
		ASSERT_TRUE(queue.peek() == CircularQueue::EMPTY_QUEUE);
		ASSERT_TRUE(queue.dequeue() == CircularQueue::EMPTY_QUEUE);
		ASSERT_TRUE(queue.empty() == true)
			ASSERT_TRUE(queue.size_ == 0)
			ASSERT_TRUE(queue.head_ == 2)
			ASSERT_TRUE((queue.tail_ == 2) || (queue.tail_ == 3))
			return true;
	}

};



#endif
