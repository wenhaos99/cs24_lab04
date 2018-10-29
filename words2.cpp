// words2.cpp - implements class Words
// (dynamic size array version)
// wenhao song 10/25/18

#include <cassert>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "words2.h"

using namespace std;

using std::string;

namespace lab04_2
{
    Words::Words(unsigned int initial_capacity) {
        used = 0;
        capacity = initial_capacity;
        data = new string [capacity];
    }
    Words::Words(const Words &source){
      /*for (int i =0; i < source.size();i++){
        data[i]=source[i];
        used = source.size();
        capacity = source.get_capacity;*/
     
      data = new std::string[source.get_capacity()];
      capacity = source.get_capacity();
      used = source.size();
      copy(source.data, source.data+used, data);
    }

    void Words::append(std::string word) {
      if (used == capacity){
        capacity = used * 2;
      }
      std::string=data_new;
      data_new = new std::string[capacity];
      for (int i =0; i <used;  i++){
          data_new[i] = data[i];
      }
          /*string *newdata = new string[2*used];
        copy(data, used+data, newdata);
        delete [] data;
        data = newdata
      }
        */
        data_new[used] = word;
        data = data_new
        ++used;
    }

    string& Words::operator[] (unsigned int index) {

        return data[index];
    }

    unsigned int Words::size() const {
        return used;
    }

    unsigned int Words::get_capacity() const {
        return capacity;
    }

    string Words::operator[] (unsigned int index) const {

        return data[index];
    }
    Words::~Words() {
        delete [] data;
    }
  Words& Words::operator=(const Words & source){
    string *newdata;
    if (this == &source){
      return *this;
    }
    if (capacity != source.capacity){
      newdata = new std::string[string.get_capacity()];
      capacity = source.get_capacity();
      delete[] data;
      data = newdata;
    }
    used = source.size();
    copy(source.data, used + source.data, data);
  }
}

