template<typename T>
Array<T>::Array() : _size(0), _arr(nullptr) {}

template<typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {
	// std::memset(_arr, 0, size());
	// for (size_t i = 0; i < _size; i++) {
		// _arr[i] = 0;
	// }
}

template<typename T>
Array<T>::Array(const Array& a) {
	_size = a.size();
	_arr = new T[_size];
	for (size_t i = 0; i < _size; i++) {
		_arr[i] = a[i];
	}
}

template<typename T>
Array<T>&	Array<T>::operator=(Array<T>& a) {
	_size = a.size();
	delete [] _arr;
	_arr = new T[_size];
	for (size_t i = 0; i < _size; i++) {
		_arr[i] = a[i];
	}
	return (*this);
}

template<typename T>
T		&Array<T>::operator[](size_t i) const {
	if (i >= size())
		throw std::out_of_range("Invalid index exception");
	return (_arr[i]);
}


template<typename T>
Array<T>::~Array() {
	delete [] _arr;
}

template<typename T>
size_t	Array<T>::size(void) const { return(_size); }
