#pragma once 
#include <iostream>
#include <stdexcept>

template <typename T>
class MyStack
{
	static constexpr size_t INITIAL_CAPACITY = 8;
	static constexpr size_t GROWTH_FACTOR = 2;

	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void free();
	void copyFrom(const MyStack<T>& other);
	void moveFrom(MyStack<T>&& other);
	void resize();

public:
	MyStack();
	MyStack(const MyStack<T>& other);
	MyStack<T>& operator=(const MyStack<T>& other);
	~MyStack();

	MyStack(MyStack<T>&& other);
	MyStack<T>& operator=(MyStack<T>&& other);

	void push(const T& elem);
	void push(T&& elem);
	void pop();
	const T& top() const;
	bool empty() const;
	size_t getSize() const;
};

template<typename T>
void MyStack<T>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

template <typename T>
void MyStack<T>::copyFrom(const MyStack<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template <typename T>
void MyStack<T>::moveFrom(MyStack<T>&& other)
{
	size = other.size;
	capacity = other.capacity;
	get = other.get;
	put = other.put;
	data = other.data;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template <typename T>
void MyStack<T>::resize()
{
	capacity *= GROWTH_FACTOR;

	T* newData = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = std::move(data[i]);
	}

	delete[] data;

	data = newData;
}

template <typename T>
MyStack<T>::MyStack<T>()
{
	size = 0;
	capacity = INITIAL_CAPACITY;
	data = new T[capacity]{};
}

template<typename T>
MyStack<T>::MyStack(const MyStack<T>& other)
{
	copyFrom(this);
}

template<typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
MyStack<T>::~MyStack()
{
	free();
}

template <typename T>
MyStack<T>::MyStack<T>(MyStack<T>&& other)
{
	moveFrom(std::move(other));
}

template <typename T>
MyStack<T>& MyStack<T>::operator=(MyStack<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
void MyStack<T>::push(const T& elem)
{
	if (size == capacity)
	{
		resize();
	}

	data[size++] = elem;
}

template <typename T>
void MyStack<T>::push(T&& elem)
{
	if (size == capacity)
	{
		resize();
	}

	data[size++] = std::move(elem);
}

template <typename T>
void MyStack<T>::pop()
{
	if (size == 0)
	{
		throw std::logic_error("Empty stack!");
	}

	size--;
}

template <typename T>
const T& MyStack<T>::top() const
{
	if (size == 0)
	{
		throw std::logic_error("Empty stack!");
	}

	return data[size - 1];
}

template <typename T>
bool MyStack<T>::empty() const
{
	return size == 0;
}

template <typename T>
size_t MyStack<T>::getSize() const
{
	return size;
}