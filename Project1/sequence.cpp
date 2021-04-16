#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "sequence.h"
using namespace std;

sequence::sequence (){
	current_index = 0;
	used = 0;
}

sequence::size_type sequence::size() const{
	return used;
}	

bool sequence::is_item() const{
    return(current_index < used);
}

sequence::value_type sequence::current(){
	assert(is_item());
	return data[current_index];	
}

void sequence::start(){
	current_index = 0;
}

void sequence::advance(){
	if(current_index+1 > used){
		cout<<"At last index in sequence. Cannot advance, please attach or insert."<<endl;
	}else{
		current_index++;
	}	
}

void sequence::insert(const value_type& entry){
    size_type i;
    assert (size()< CAPACITY);
	// insert data at current index, SHIFT DATA to the right if there is data there.
    if (!is_item()){
        data[current_index] = entry;
		used++;
	}else{
		for (i = used; i > current_index; i--){
        	data[i] = data [i-1];
    	}
		data[current_index]= entry;
		used++;	
	}
}
	 
void sequence::attach(const value_type& entry){
    size_type i;
    assert (size()< CAPACITY);
    if (!is_item()){
        data[current_index] = entry;
    }else{
        for( i = used; i > current_index + 1; i--)
            data[i] = data[i - 1];
            data[current_index + 1] = entry;
            current_index++;
    }
    used++;
 }
void sequence::remove_current(){
    size_type i;
	if(current_index >= used){
		cout<<"No item at current index, setting current index to start of sequence."<<endl;
		current_index = 0;
	}else{
		for (i = current_index; i < used-1; i++){
        	data[i]= data[i+1];
    	}
		used--;
	} 
}