#include <iostream>
#include <assert.h>
#include "sequence3.h"



sequence::sequence(){
head_ptr = NULL;
tail_ptr = NULL;
precursor = NULL;
cursor = NULL;
many_nodes = 0;
}

sequence::sequence(const sequence& source){    
    int pos = 1;   
    for(cursor = source.head_ptr; cursor != source.cursor; cursor = cursor -> link()){
        pos++;
}
    list_copy(source.head_ptr,head_ptr,tail_ptr);
    cursor = list_locate(head_ptr, (size_t) pos);   
    if(pos == 1){
        precursor = NULL;
    }else{
        precursor = list_locate(head_ptr, (size_t) pos - 1);
    }
    many_nodes = source.many_nodes;   
}

sequence::~sequence(){
    list_clear(head_ptr);
    many_nodes = 0;
}

void sequence::start(){
        cursor = head_ptr;
}

void sequence::advance(){
        assert(is_item());
        precursor = cursor;
        cursor = cursor -> link();
}

void sequence::insert(const value_type &entry){   
    if(head_ptr == NULL){
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        precursor = cursor;
    }    
    else if(cursor == NULL || cursor == head_ptr){
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        precursor = cursor;
    }
    else{
        list_insert(precursor, entry);
        cursor = precursor -> link();
    }
    many_nodes++;
}

void sequence::attach(const value_type& entry){
    if(is_item()){
        precursor = cursor;
        list_insert(cursor, entry);
        cursor = cursor -> link();
    }
    else{
        if(head_ptr == NULL){
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = NULL;
        }
        else{
            precursor = list_locate(head_ptr, list_length(head_ptr));
            list_insert(precursor, entry);
            cursor = precursor -> link();
        }
    }
    many_nodes++;
}

 void sequence:: operator =(const sequence & source){
     if (this == &source){
         return;
     }
     list_clear(head_ptr);
     int index = 1;
     for(cursor = source.head_ptr; cursor != source.cursor; cursor = cursor->link()){
        index++;
     }
     list_copy(source.head_ptr, head_ptr, tail_ptr);
     cursor = list_locate(head_ptr, (size_t)index);
     if (index == 1){
        precursor = NULL;
     }
     else{
        precursor = list_locate(head_ptr, (size_t)index - 1);
     }
     many_nodes = source.many_nodes;
}

void sequence::remove_current(){
    assert ( is_item() == true);
    if (cursor == head_ptr){
		list_head_remove(head_ptr);							
		cursor = head_ptr;								
		precursor= head_ptr;							
		
	}else{ 
	    cursor = cursor->link();					
		list_remove(precursor);							
		
	}
	--many_nodes;											
		
}
bool sequence::is_item() const{
        if(cursor != NULL){
	        return true;
        }else{
                return false;
        }
}

sequence::value_type sequence::current() const{

    return cursor -> data();
}

 size_t sequence::size( ) const{                       
	return many_nodes;
}