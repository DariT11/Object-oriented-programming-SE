#include <iostream>
#include <utility>

template <typename T>

class MyVector
{
	constexpr size_t INITIAL_CAPACITY = 8;

	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void free();
	void copyFrom(const MyVector& other);
	void moveFrom(MyVector&& other);
	void resize();

public:
	MyVector();
	MyVector(const MyVector<T>& other);
	MyVector<T>& operator=(const MyVector<T>& other);
	~MyVector();

	MyVector(MyVector<T>&& other);
	MyVector<T>& operator=(MyVector<T>&& other);

	MyVector(size_t n);
	MyVector(size_t n, const T& elem);
	void push_back(const T& elem);
	void push_back(T&& elem);
	void pop_back();
	void insert(size_t idx, const T& elem);
	void insert(size_t idx, T&& elem);
	void erase(size_t idx);
	const T& operator[](size_t idx) const;
	T& operator[](size_t idx);
	void shrinkToFit();
	void clear();
	const T& front() const;
	T& front();
	const T& back() const;
	T& back();
	bool empty() const;
	size_t getSize() const;
	size_t getCapacity() const;
};

template<typename T>
inline void MyVector<T>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other)
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
void MyVector<T>::moveFrom(MyVector<T>&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template <typename T>
void MyVector<T>::resize()
{
	T* newData = new T[capacity * 2];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;

	data = newData;
	capacity = capacity * 2;
}

template<typename T>
inline MyVector<T>::MyVector()
{
	size = 0;
	capacity = INITIAL_CAPACITY;
	data = new T[capacity]{};
}

template<typename T>
inline MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
MyVector<T>::~MyVector()
{
	free();
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& other)
{
	moveFrom(std::move(other));
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline MyVector<T>::MyVector(size_t n)
{
	size = n;
	capacity = n;
	data = new T[capacity];
}

template<typename T>
inline MyVector<T>::MyVector(size_t n, const T& elem)
{
	size = n;
	capacity = n;
	data = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = elem;
	}
}

template<typename T>
inline void MyVector<T>::push_back(const T& elem)
{
	if (size == capacity)
	{
		resize();
	}

	data[size++] = elem;
}

template<typename T>
inline void MyVector<T>::push_back(T&& elem)
{
	if (size == capacity)
	{
		resize();
	}

	data[size++] = std::move(elem);
}

template<typename T>
inline void MyVector<T>::pop_back()
{
	data[size--] = 0;
}

template<typename T>
inline void MyVector<T>::insert(size_t idx, const T& elem)
{
	if (idx > size)
	{
		return;
	}

	if (size == capacity)
	{
		resize();
	}

	for (size_t i = size; i > idx; i--)
	{
		data[i] = std::move(data[i-1]);
	}
	data[idx] = elem;
	size++;
}

template<typename T>
inline void MyVector<T>::insert(size_t idx, T&& elem)
{
	if (idx > size)
	{
		return;
	}

	if (size == capacity)
	{
		resize();
	}

	for (size_t i = size; i > idx; i--)
	{
		data[i] = std::move(data[i - 1]);
	}

	data[idx] = std::move(elem);
	size--;
}

template<typename T>
inline void MyVector<T>::erase(size_t idx)
{
	if (idx > size)
	{
		return;
	}

	for (size_t i = idx; i < size - 1; i++)
	{
		data[i] = std::move(data[i + 1]);
	}
	size--;
}

template<typename T>
inline const T& MyVector<T>::operator[](size_t idx) const
{
	return data[idx];
}

template<typename T>
inline T& MyVector<T>::operator[](size_t idx)
{
	return data[idx];
}

template<typename T>
inline void MyVector<T>::shrinkToFit()
{
	resize();
}

template<typename T>
inline void MyVector<T>::clear()
{
	size = 0;
}

template<typename T>
inline const T& MyVector<T>::front() const
{
	return data[0];
}

template<typename T>
inline T& MyVector<T>::front()
{
	return data[0];
}

template<typename T>
inline const T& MyVector<T>::back() const
{
	return data[size-1];
}

template<typename T>
inline T& MyVector<T>::back()
{
	return data[size - 1];
}

template<typename T>
bool MyVector<T>::empty() const
{
	return size == 0;
}

template<typename T>
inline size_t MyVector<T>::getSize() const
{
	return size;
}

template<typename T>
inline size_t MyVector<T>::getCapacity() const
{
	return capacity;
}