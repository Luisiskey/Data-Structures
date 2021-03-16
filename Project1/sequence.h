#ifndef CONTAINER_SEQUENCE_HEADER_FILE
#define CONTAINER_SEQUENCE_HEADER_FILE
#include <iostream>
#include <cstdlib> //size_t
class sequence
{
public: 
    //Typedefs and member constants
    typedef double value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 30;
    //CONSTRUCTOR
    sequence();
    //constant member functions
    size_type size() const;//return number of items in the sequence
    bool is_item() const;
    value_type current();
    
    //modification member functions
    void start();
    void advance();
    void insert(const value_type& entry);
    void attach(const value_type& entry);
    void remove_current();
private:
    value_type data[CAPACITY];
    size_type used;
    size_type current_index;
};
#endif