#ifndef BIGLIB_DATA_STRUCTRES_VECTOR_H_
#define BIGLIB_DATA_STRUCTRES_VECTOR_H_

#include <cassert>

namespace big {

template<typename T>
class vector {
 public:
  // Constructors, destructor and assignment.
  vector() : vector(0) {}

  vector(unsigned int n, const T& val = T()) :
    data_(new T[n]), end_(n), capacity_(n) {
    for (int i = 0; i < n; ++i) {
      data_[i] = val;
    }
  }
  
  vector(const vector<T>& other) : vector() {
    *this = other;
  }

  vector<T>& operator=(const vector<T>& other) {
    delete data_;
    data_ = new T[other.capacity_];
    end_ = other.end_;
    capacity_ = other.capacity_;
    for (int i = 0; i < end_; ++i) {
      data_[i] = other.data_[i];
    }
    return *this;
  }

  ~vector() {
    delete data_;
  }

  // Capacity.
  int capacity() const { return capacity_; }
  int size() const { return end_; }
  bool empty() const { return end_ == 0; }

  void reserve(unsigned int n) {
    if (capacity_ < n) {
      T* data = new T[n];
      for (int i = 0; i < end_; ++i) {
        data[i] = data_[i];
      }
      delete data_;
      data_ = data;
    }
  }

  void resize(unsigned int n, const T& val = T()) {
    int current_size = end_;
    if (capacity_ < n) {
      reserve(n);
    }
    for (int i = current_size; i < capacity_; ++i) {
      data_[i] = val;
    }
  }

  void shrink_to_fit() {
    resize(end_);
  }

  // Element access.
  T& operator[](unsigned int i) {
    assert(i < end_);
    return data_[i];
  }
  const T& operator[](unsigned int i) const {
    assert(i < end_);
    return data_[i];
  }

  T& at(unsigned int i) {
    assert(i < end_);
    return data_[i];
  }
  const T& at(unsigned int i) const {
    assert(i < end_);
    return data_[i];
  }

  T& front() {
    assert(end_ > 0);
    return data_[0];
  }
  const T& front() const {
    assert(end_ > 0);
    return data_[0];
  }
  
  T& back() {
    assert(end_ > 0);
    return data_[end_ - 1];
  }
  const T& back() const {
    assert(end_ > 0);
    return data_[end_ - 1];
  }

  // Modifiers.
  void assign(unsigned int n, const T& val) {
    T* data = new T[n];
    for (int i = 0; i < n; ++i) {
      data[i] = val;
    }
    delete data_;
    data_ = data;
  }

  void push_back(const T& val) {
    if (end_ == capacity_) {
      reserve(capacity_ * 2);
    }
    data_[end_] = val;
    ++end_;
  }

  void pop_back() {
    assert(end_ > 0);
    --end_;
  }

  void insert(unsigned int pos, const T& val) {
    assert(pos <= end_);
    if (end_ == capacity_) {
      reserve(capacity_ * 2);
    }
    for (int i = end_; i > pos; --i) {
      data_[i] = data_[i - 1];
    }
    data_[pos] = val;
    ++end_;
  }

  void erase(unsigned int pos) {
    assert(pos < end_);
    for (int i = pos; i < end_ - 1; ++i) {
      data_[i] = data_[i + 1];
    }
    --end_;
  }

  void clear() {
    end_ = 0;
    capacity_ = 0;
    delete data_;
    data_ = new T[0];
  }

 private:
  T* data_;
  unsigned int end_;
  unsigned int capacity_;
};

}  // namespace big

#endif  // BIGLIB_DATA_STRUCTRES_VECTOR_H_
