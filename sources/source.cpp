// Copyright 2019 alexsun.8 <alexsun24@yahoo.com>

#include <header.hpp>

template <typename T>
stack<T>::stack() {
  _size = 0;
  _capacity = 1;
  //  _data = new T[_capacity];
  _data = std::make_unique<T[]>(_capacity);
  // std::cout<< "stack()"<<std::endl;
}

template <typename T>
stack<T>::stack(stack&& SStack) noexcept
    : _size(SStack._size), _capacity(SStack._capacity) {
  _data = std::move(SStack._data);
  // проверочка на r-value
  //   if(is_lvalue_reference(SStack)) throw std::logic_error("В конструкторе
  //   stack не перемещение");
  //    std::cout<< "stack(stack&& )"<<std::endl;
}

template <typename T>
stack<T>::~stack() {
  //  delete [] _data;
  _capacity = 0;
  _size = 0;
  _data = nullptr;
  //  std::cout<< "~stack()"<<std::endl;
}

template <typename T>
void stack<T>::push(T&& value) {
  if (_size == _capacity) {
    _capacity = (size_t)(1.5 * (_size + 1));
    // T *temp = new T[_capacity];
    std::unique_ptr<T[]> temp = std::make_unique<T[]>(_capacity);
    for (size_t i = 0; i < _size; i++) {
      temp[i] = _data[i];
    }
    temp[_size] = value;
    // delete[] _data;
    _data = std::move(temp);
    _size++;
    temp = nullptr;
  } else {
    _data[_size] = value;
    _size++;
  }
}

template <typename T>
void stack<T>::push(const T& value) {
  if (_size == _capacity) {
    _capacity = (size_t)(1.5 * (_size + 1));
    // T *temp = new T[_capacity];
    std::unique_ptr<T[]> temp = std::make_unique<T[]>(_capacity);
    for (size_t i = 0; i < _size; i++) {
      temp[i] = _data[i];
    }
    temp[_size] = value;
    // delete[] _data;
    _data = std::move(temp);
    _size++;
    temp = nullptr;
  } else {
    _data[_size] = value;
    _size++;
  }
}

template <typename T>
void stack<T>::pop() {
  _size--;
}

template <typename T>
const T& stack<T>::head() const {
  return _data[_size - 1];
}

// проверить весь тип на r - value

template <typename T>
Stack<T>::Stack() {
  _size = 0;
  _capacity = 1;
  //    _data = new T[_capacity];
  _data = std::make_unique<T[]>(_capacity);
  // std::cout<< "stack()"<<std::endl;
}

template <typename T>
Stack<T>::Stack(Stack&& sttack) noexcept
    : _size(sttack._size), _capacity(sttack._capacity) {
  //   if(is_move_assignable(sttack))throw std::logic_error("В конструкторе
  //   Stack");
  _data = std::move(sttack._data);
  // _data = new T[_capacity];
  // for(size_t i = 0; i < _size; i ++) _data[i] = sttack._data[i];
  //    std::cout<< "stack(stack&& )"<<std::endl;
}

template <typename T>
Stack<T>::~Stack() {
  //    if(_data)  delete [] _data;
  _capacity = 0;
  _size = 0;
  _data = nullptr;
  //  std::cout<< "~stack()"<<std::endl;
}

template <typename T>
void Stack<T>::push(T&& value) {
  if (_size == _capacity) {
    _capacity = (size_t)(1.5 * (_size + 1));
    // T *temp = new T[_capacity];
    std::unique_ptr<T[]> temp = std::make_unique<T[]>(_capacity);
    for (size_t i = 0; i < _size; i++) {
      temp[i] = _data[i];
    }
    temp[_size] = value;
    // delete[] _data;
    _data = std::move(temp);
    _size++;
    temp = nullptr;
  } else {
    _data[_size] = value;
    _size++;
  }
}

template <typename T>
T Stack<T>::pop() {
  _size--;
  return std::move(_data[_size]);
}

template <typename T>
const T& Stack<T>::head() const {
  return _data[_size - 1];
}

template <typename T>
template <typename... Args>
void Stack<T>::push_emplace(Args&&... value) {
  //  if(is_lvalue_reference(value ...)) throw std::logic_error("В конструкторе
  //  stack не перемещение");
  // if(is_move_assignable(value ...))throw std::logic_error("В push_emplays
  // Stack");

  if (_size == _capacity) {
    _capacity = (size_t)(1.5 * (_size + 1));
    // T *temp = new T[_capacity];
    std::unique_ptr<T[]> temp = std::make_unique<T[]>(_capacity);
    for (size_t i = 0; i < _size; i++) {
      temp[i] = _data[i];
    }
    // delete[] _data;
    temp[_size] = std::move(T(value...));
    _size++;
    _data = std::move(temp);
  } else {
    _data[_size] = std::move(T(value...));
    _size++;
  }
}
