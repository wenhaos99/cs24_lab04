// words2.cpp - implements class Words
2// (dynamic array version)
3//Peizhen Tong  date: 10/25/2018
4
5#include <cassert>
6#include <string>
7#include "words2.h"
8
9using std::string;
10
11namespace lab04_2
12{
13    Words::Words(unsigned int initialCapacity) {
14        used = 0;
15        capacity = initialCapacity;
16        data = new string[capacity];
17    }
18    
19    Words::Words(const Words &source){
20    	used = source.used;
21        capacity = source.capacity;
22        data = new string[capacity];
23       copy(source.data, source.data + used, data);
26    }
27    
28   
44    
45    Words::~Words() {
46    	delete [] data;
47	}
48
49    void Words::append(string word) {
50        if(used == capacity){
51        	int new_capacity = used*2;
52        	string *ndata;
			ndata = new string[newCapacity];
53        	 copy(data, data + used, data2);
55        	delete [] data;
56        	data = ndata;
57        	capacity = new_capacity;
			data[used] = word;
61        used++;
58        	
59        }else{
60        data[used] = word;
61        used++;
			}
62    }
63    
64    string& Words::operator[] (unsigned int index) {
65        return data[index];
66    }
67    
68    unsigned int Words::size() const {
69        return used;
70    }
71    
72    unsigned int Words::get_capacity() const {
73        return capacity;
74    }
75    
76    string Words::operator[] (unsigned int index) const {
77        return data[index];
78    }
	Words& Words::operator=(const Words & source){
	string *new_data;
	if (this == &source){
		return;
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

79    
80