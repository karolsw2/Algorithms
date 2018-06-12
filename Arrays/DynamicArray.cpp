#include <iostream>

#include <stdexcept>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MIN_CAPACITY 10
#define GROWTH_FACTOR 2

using namespace std;

// This is made for learning purposes
template <class T>
class Array {
	public:
		Array();
		~Array();
		
		void push(T value);
		T pop();
		void set(size_t index, T value);
		T get(size_t index);
		
		size_t size();
		size_t capacity();
		void print();
		void del(size_t value);
		int is_empty();
	private:
		size_t m_size;
		size_t m_capacity;
		T* m_data;
		void resize();
};

template <class T>
Array<T>::Array() {
	m_capacity = MIN_CAPACITY;
	m_size = 0;
	m_data = (T*)malloc(m_capacity * sizeof(*m_data));
	if (!m_data) {
		throw bad_alloc();
	}
}

template <class T>
Array<T>::~Array() {
	free(m_data);
}

template <class T>
void Array<T>::push(T value) {
	if (m_size >= m_capacity) {
		resize();
	}
	*(m_data + m_size++) = value;
}

template <class T>
T Array<T>::pop() {
	return *(m_data + --m_size);
}

template <class T>
void Array<T>::set(size_t index, T value) {
    while (index >= m_size)
        this->push(0);
    *(m_data + index) = value;
}

template <class T>
void Array<T>::del(size_t index) {
	m_size--;
	while (index < m_size) {
		*(m_data + index) = *(m_data + index + 1);
		index++;
	}
}

template <class T>
T Array<T>::get(size_t index) {
	return *(m_data + index);
}

template <class T>
void Array<T>::resize() {
	size_t capacity = m_capacity * GROWTH_FACTOR;
	T *tmp = (T*)realloc(m_data, capacity * sizeof(*m_data));
	if (!tmp) {
		throw bad_alloc();
	}
	m_data = tmp;
	m_capacity = capacity;
}

template <class T>
void Array<T>::print() {
    size_t i = 0;
    while (i < m_size) {
        std::cout << "Array[" << i << "] = " << this->get(i) << "\n";
        i++;
    }
}

template <class T>
int Array<T>::is_empty() {
    return m_size == 0;
}
