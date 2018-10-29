// words2.cpp - implements class Words
// (dynamic size array version)
// wenhao song 10/25/18

#include <cassert>
#include <string>
#include <iostream>
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
      capacity = source.capacity;
      data = new string[source.capacity];
      used = source.used;
      copy(source.data, source.data+used.data);
    }

    void Words::append(string word) {
      if (used == capacity){
        capacity = used * 2;
        string *newdata = new string[2*used];
        copy(data, used+data, newdata);
        delete [] data;
        data = newdata
      }
        data[used] = word;
        used++;
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
  void Words::operator=(cost Words & source){
    string *newdata;
    if (this == &source){
      return;
    }
    if (capacity != source.capacity){
      newdata = new string[string.capacity];
      capacity = source.capacity;
      delete[] data;
      data = newdata;
    }
    used = source.used;
    copy(source.data, used + source.data, data);
  }
}

