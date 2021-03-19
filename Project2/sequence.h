
// FILE: sequence.h
// CLASS PROVIDED: sequence 
//
#ifndef CONTAINER_SEQUENCE_HEADER_FILE
#define CONTAINER_SEQUENCE_HEADER_FILE
#include <cstdlib>  // Provides size_t

    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef size_t size_type; //typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 30; //enum {DEFAULT_CAPACITY = 30}; //
        // CONSTRUCTOR
        sequence(size_type initial_capacity = DEFAULT_CAPACITY);
        sequence(const sequence& source);
        ~sequence( );
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current( );
        void resize(size_type new_capacity);
        void operator=(const sequence& source);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const;
        bool is_item( ) const;
        value_type current( ) const;
    private:
		value_type* data;
        size_type used;
        size_type current_index;
        size_type capacity;
    };
	#endif

