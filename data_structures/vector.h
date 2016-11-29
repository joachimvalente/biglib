#ifndef BIGLIB_DATA_STRUCTRES_VECTOR_H_
#define BIGLIB_DATA_STRUCTRES_VECTOR_H_

#include <iterator>
#include <memory>

namespace big {

template<class T, class Alloc = allocator<T>>
class vector {
 public:
  typedef T value_type;
  typedef Alloc allocator_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename allocator_traits<allocator_type>::pointer pointer;
  typedef typename allocator_traits<allocator_type>::const_pointer pointer;
  typedef iterator<random_access_iterator_tag, value_type> {} iterator;
  typedef iterator<random_access_iterator_tag, const value_type> {}
      const_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;
  typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;
};

}  // namespace big

#endif  // BIGLIB_DATA_STRUCTRES_VECTOR_H_
