// .hpp files contain class declarations. That is, they declare what methods and
// variables are contained in a class, but they do not implement the methods. This
// is the job of the .cpp file. Below, the class SequentialList contains a bunch of
// methods and 3 member variables. This is how it can be used by other programmers.
//
// SequentialList.hpp
// SequentialList implements list using a sequential block of memory.
// When created, it dynamically allocates an array to store the list data.
// Once allocated, the list cannot be resized.

// NOTES ON CONST KEYWORD
// The const keyword, when used after a class member function, means that
// that function does not change any data members of the object (i.e., the
// object remains the same after the function is called; the function only
// tells you something about the class).

// NOTES ON COPY CONSTRUCTORS, ASSIGNMENT OPERATORS, AND DESTRUCTORS
// Whenever a class dynamically allocates memory, three functions generally 
// have to be implemented: the copy constructor, the assignment operator,
// and the destructor. This is known as the Rule of Three. The destructor,
// as you already know, is responsible for freeing the dynamically allocated
// memory, thereby preventing memory leaks. The copy constructor is responsible
// for making a copy of your class. The assignment (=) operator is also
// responsible for making a copy of your class, but using the = syntax instead
// of a constructor. The reason that you should never implement only a
// destructor is that C++ automatically implements a basic copy constructor
// and assignment operator, and for dynamically allocated memory, the
// automatic copy constructor and assignment operator usually don't work.
// For example, when you have a pointer in your class, the automatic copy
// constructor will simply copy the pointer, and leave it pointing to the
// data of the original object. If the original object is then deleted, its
// destructor will delete all the data, leaving the copied object with a
// pointer to freed memory. This is always bad. What we've done below is
// to make the copy constructor and assignment operator private and then leave them
// un-implemented. This prevents C++ from automatically making an assignment
// operator and copy constructor, and since they are private, they can never
// be called outside the class, so it's okay that we don't implement them.

#ifndef SEQUENTIAL_LIST_HPP
#define SEQUENTIAL_LIST_HPP

class SequentialList
{
	// Befriend so tests have access to variables.
	friend class SequentialListTest;

public:
	// Can be seen outside as SequentialList::DataType
	typedef int DataType;

	// CONSTRUCTORS/DESTRUCTOR
public:
	// Constructor. Create a new SequentialList with the given number of elements. Initialize
	// member variables here.
	SequentialList(unsigned int cap);
	// Destructor. Destroy this SequentialList, freeing all dynamically allocated memory.
	~SequentialList();

	// ACCESSOR METHODS (does not change member variables)
public:
	// Returns the number of elements in the list.
	unsigned int size() const;
	// Returns the maximum number of elements the list can hold.
	unsigned int capacity() const;
	// Returns true if the list is empty, false otherwise.
	bool empty() const;
	// Returns true if the list is at capacity, false otherwise.
	bool full() const;
	// Returns the value at the given index in the list. If index is invalid,
	// return the value of the last element.
	DataType select(unsigned int index) const;
	// Searches for the given value, and returns the index of this value if found.
	// Returns the size of the list otherwise
	unsigned int search(DataType val) const;
	// Prints all elements in the list to the standard output.
	void print() const;

	// MUTATOR METHODS (alters member variables)
public:
	// Inserts a value into the list at a given index.
	bool insert(DataType val, unsigned int index);
	// Inserts a value at the beginning of the list.
	bool insert_front(DataType val);
	// Inserts a value at the end of the list.
	bool insert_back(DataType val);
	// Deletes a value from the list at the given index.
	bool remove(unsigned int index);
	// Deletes a value from the beginning of the list.
	bool remove_front();
	// Deletes a value at the end of the list.
	bool remove_back();
	// Replaces the value at the given index with the given value.
	bool replace(unsigned int index, DataType val);

	// MEMBER VARIABLES: these are what allow instances of classes to keep track of their state.
	// They need to be initialized in the constructor, and any memory allocated with the keyword
	// "new" needs to be returned in the destructor using "delete".
private:
	// A pointer to the block of memory allocated to store the list data.
	DataType *data_;
	// The capacity of the list (i.e., the maximum number of items the list can store).
	unsigned int capacity_;
	// The number of used elements in data_.
	unsigned int size_;

	// COPY CONSTRUCTOR/ASSIGNMENT OPERATOR: You can safely ignore these (but don't change them).
private:
	// Copy constructor. Declared private so we don't use it incorrectly.
	SequentialList(const SequentialList& rhs) {}
	// Assignment operator. Declared private so we don't use it incorrectly.
	SequentialList& operator=(const SequentialList& rhs) {}
};

#endif  //SEQUENTIAL_LIST_HPP
