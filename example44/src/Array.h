#ifndef _ARRAY_H_
#define _ARRAY_H_

template<typename T, int N>
class Array {
  int size {N};
  T values[N];

  friend std::ostream& operator<<(std::ostream &os, const Array<T, N> &arr) {
    os << "[";
    for (const auto& val: arr.values) {
      os << val << " ";
    }
    os << "]";
    os << std::endl;
    return os;
  }
public:
  Array() = default;

  Array(T init_val) {
    for (auto& item: values) {
      item = init_val;
    }
  }

  void fill(T val) {
    for (auto& item: values) {
      item = val;
    }
  }

  int get_size() const { return this->size; }

  T& operator[](int index) {
    return this->values[index];
  }
};

#endif // _ARRAY_H_
