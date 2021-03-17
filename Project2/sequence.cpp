#include "sequence.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>//standard c++ library
#include <cassert>
using namespace std;

const sequence::size_type sequence::DEFAULT_CAPACITY;

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
	delete [] data;
}

void sequence::start(){
        current_index = 0;
}

void sequence::advance(){
        current_index+=1;
}

bool sequence::is_item() const{
        if(current_index>=used){
	        return false;
        }else{
                return true;
        }
}
sequence::size_type sequence::size()const{
	return used;
}
sequence::value_type sequence::current()const{ //Library facilities used: assert
	assert(is_item());
	return data[current_index];
}

void sequence::insert(const value_type& entry){
//<====instead of resizing internally, call the resize function
//Library facilities used: assert
//places a new item BEFORE the current item
        if(used>= capacity){
	        resize((capacity + 1)*1.1);
        }
	if(is_item()==false)
        {
                current_index = 0;
        }
	if(used>0){
	        for(int i = used-1; i>=(int)current_index; --i){
                        data[i+1]=data[i];
                 }
        }
        data[current_index] = entry;
        used+=1;
}

void sequence::attach(const value_type& entry){
//adds a new item to the sequence AFTER the current item
        if (used>= capacity){   //use resize(size+1)*1.1
                resize(capacity + 1 *(1.1));//<==does not really work
        }
        if (used>0){
                for(int i = used-1; i>(int)current_index; --i){
                data[i+1]=data[i];
                }
        data[current_index+1] = entry;
        current_index+=1;
        used+=1;
        }else{
            data[current_index] = entry;
            used += 1;
        }
}

void sequence::resize(size_type new_capacity){
        value_type *larger_array;
        if(new_capacity == capacity){
                return;
        }
        if(new_capacity < used){
                new_capacity = used;
        }
        larger_array = new value_type[new_capacity];
        copy(data, data+used, larger_array);
        delete [ ] data;
        data = larger_array;
        capacity = new_capacity;
 }

void sequence::remove_current(){
//Library facilities used: assert
//removes the current item from the sequence
        assert(size()>0);
        for(size_type i = current_index+1; i<used; i++){
                data[i-1]=data[i];
        }
        used-=1;
}

void sequence::operator =(const sequence& source){
        value_type *new_data;
        if(this == &source)
                return;
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
