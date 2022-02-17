/**
 * \file: hetero_store.hpp
 *
 */

#ifndef HETEROSTORE_HPP
#define HETEROSTORE_HPP

#include <iostream>
#include <stdexcept>

template <class T, size_t s = 100, class exc = std::out_of_range>
class HeteroStore{
private:
    T** tmb[s];
    HeteroStore(const HeteroStore&);
    HeteroStore& operator=(const HeteroStore&);
public:
    HeteroStore(){
   tmb = new T*[s];
    }

  size_t size(){
      for (size_t i = 0; i < s; ++i /*??*/) {
          if(tmb[i] == NULL) {
              return i;
          }
          else if(i==s-1){
              return s;
          }
      }
  }

   size_t capacity(){
      return s;
  }

  void add(T* p){
    if(capacity() == size()){
        throw exc{"m"};
    }
    else
        tmb[size()] = p;
  }

    template<class F>
  void traverse(F func){
        for (size_t i = 0; i < size(); ++i) {
            func(tmb[i]);
        }
  }
    void clear(){
        for (int i = 0; i < size(); ++i) {
            delete tmb[i];
        }
  }

};



#endif // HETEROSTORE_HPP
