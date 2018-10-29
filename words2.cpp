// words2.cpp - implements class Words
// (dynamic array version)
//Peizhen Tong  date: 10/25/2018

#include <cassert>
#include <string>
#include "words2.h"

using std::string;

namespace lab04_2
{
    Words::Words(unsigned int initialCapacity) {
        used = 0;
        capacity = initialCapacity;
        data = new string[capacity];
    }
    
    Words::Words(const Words &source){
    	used = source.used;
        capacity = source.capacity;
        data = new string[capacity];
       copy(source.data, source.data + used, data);
    }
    
   
    
    Words::~Words() {
    	delete [] data;
	}

    void Words::append(string word) {
        if(used == capacity){
        	int new_capacity = used*2;
        	string *ndata;
			ndata = new string[new_capacity];
        	copy(data, data + used, data);
        	delete [] data;
        	data = ndata;
        	capacity = new_capacity;
			data[used] = word;
        used++;
        	
        }else{
        data[used] = word;
        used++;
			}
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
    Words& Words::operator=(const Words & source){
	string *new_data;
	if (this == &source){
		return *this;
    }
	if (capacity != source.capacity){
	new_data = new string[source.capacity];
	delete [ ] data;
	data = new_data;
	capacity = source.capacity;
    }
	used = source.used;
	copy(source.data, source.data + used, data);
    }	

}    
