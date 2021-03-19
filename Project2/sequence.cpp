#include "sequence.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>//standard c++ library
#include <cassert>
using namespace std;

//const sequence::size_type sequence::DEFAULT_CAPACITY;

sequence::sequence(size_type initial_capacity){
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
        current_index = 0;
}

sequence::sequence(const sequence& source){
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        copy(source.data, source.data + used, data);
        current_index = source.current_index;
}

sequence::~sequence(){
	delete[] data;
}

void sequence::start(){
        current_index = 0;
}

void sequence::advance(){
        current_index+=1;
}

void sequence::insert(const value_type& entry){
        if( size() == capacity){
                resize(capacity+DEFAULT_CAPACITY);
        }
        if(!is_item()){
                current_index = 0;
        }
        for(size_type i = used; i>current_index; --i){
		data[i] = data[i - 1];
        }
	data[current_index] = entry;
	++used;
	        
}

void sequence::attach(const value_type& entry){
        if(size() == capacity){
                resize(capacity+DEFAULT_CAPACITY);
        }        
        if(!is_item()){
                current_index = used - 1;
        }  
	++current_index;
        for(size_type i = used; i>current_index; --i)
	        data[i] = data[i - 1];
	data[current_index] = entry;
	++used;
	}

void sequence::remove_current(){
    size_type i;
	if(current_index >= used){
		cout<<"No item at current index, setting current index to start of sequence."<<endl;
		current_index = 0;
	}else{
		for (i = current_index; i < used - 1; i++){
        	data[i]= data[i + 1];
    	}
		used--;
	} 
}

void sequence::resize(size_type new_capacity){
        if(new_capacity > used){
		value_type *new_data = new value_type [new_capacity];
		copy(data, data+used, new_data);
		delete [] data;
		data = new_data;
		capacity = new_capacity;
	}
}

void sequence::operator =(const sequence& source){
        value_type *new_data;
        if(this == &source){
                return;
        }
        if(capacity != source.capacity){
                new_data = new value_type[source.capacity];
                delete [] data;
                data = new_data;
                capacity = source.capacity;
        }
        used = source.used;
        current_index = source.current_index;
        copy(source.data, source.data+used, data);
}

sequence::size_type sequence::size()const{
        return used;
}

bool sequence::is_item() const{
        if(current_index>=used){
	        return false;
        }else{
                return true;
        }
}

sequence::value_type sequence::current()const{ 
	assert(is_item());
	return data[current_index];
}




