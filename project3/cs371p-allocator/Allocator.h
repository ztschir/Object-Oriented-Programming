// ------------------------------
// projects/allocator/Allocator.h
// Copyright (C) 2011
// Glenn P. Downing
// ------------------------------

#ifndef Allocator_h
#define Allocator_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <cstddef>   // size_t
#include <new>       // new
#include <stdexcept> // invalid_argument
#include <string.h>   // memcpy

// ---------
// Allocator
// ---------

template <typename T, std::size_t N>
class Allocator {
    public:
        // --------
        // typedefs
        // --------

        typedef T                 value_type;

        typedef std::size_t       size_type;
        typedef std::ptrdiff_t    difference_type;

        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

    public:
        // -----------
        // operator ==
        // -----------

        friend bool operator == (const Allocator&, const Allocator&) {
            return true;}

        // -----------
        // operator !=
        // -----------

        friend bool operator != (const Allocator& lhs, const Allocator& rhs) {
            return !(lhs == rhs);}

    private:
        // ----
        // data
        // ----

        char a[N];

        // -----
        // valid
        // -----

        /**
         * O(1) in space
         * O(n) in time
         * <your documentation>
         */
        bool valid () const {
            // <your code>
			char* b = const_cast<char *>(a);
			int size = 0;
			int sum = 0;

			while(b != a + N){
				size = *((int*) b);
                                sum += std::abs(size) + 2*sizeof(int);
				b = b + std::abs(size) + 2*sizeof(int);
			}
            return sum == N;
	}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * O(1) in space
         * O(1) in time
         * <your documentation>
         */
        Allocator () {
            // <your code>
            int size = N - 2*sizeof(int);
            
            memcpy(a, &size, sizeof(int));
            memcpy(a + sizeof(a) - sizeof(int), &size, sizeof(int));
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Allocator  (const Allocator<T>&);
        // ~Allocator ();
        // Allocator& operator = (const Allocator&);

        // --------
        // allocate
        // --------

        /**
         * O(1) in space
         * O(n) in time
         * <your documentation>
         * after allocation there must be enough space left for a valid block
         * the smallest allowable block is sizeof(T) + (2 * sizeof(int))
         * choose the first block that fits
         */
        pointer allocate (size_type n) {
            if(n <= 0)
                return 0;
            
            int sizeOfBlock = *((int *) a);
            size_t totalSizeMoved = 0;
            int neededSize = sizeof(T)*n + (2 * sizeof(int));
            
            while(true){
                // Move to next spot
                if(sizeOfBlock < 0 || neededSize > sizeOfBlock){
                    totalSizeMoved += std::abs(sizeOfBlock) + 2*sizeof(int);
                    if(totalSizeMoved > N)
                        return 0;
                    sizeOfBlock = *((int *) (a + std::abs(sizeOfBlock) + 2*sizeof(int)));
                    
                }
                else{
                    int size = sizeof(T)*n;
                    int negSize = -size;
                    int remainingSize = sizeOfBlock - neededSize;
            
                    memcpy(a + totalSizeMoved, &negSize, sizeof(int));
                    memcpy(a + totalSizeMoved + size + sizeof(int), &negSize, sizeof(int));
                    memcpy(a + totalSizeMoved + size + 2*sizeof(int), &remainingSize, sizeof(int));
                    memcpy(a + totalSizeMoved + size + 2*sizeof(int) + remainingSize, &remainingSize, sizeof(int));
                    return (T *)(a + totalSizeMoved + sizeof(int));
                }
                
            }
            
            assert(valid());
            return 0;}                   // replace!

        // ---------
        // construct
        // ---------

        /**
         * O(1) in space
         * O(1) in time
         * <your documentation>
         */
        void construct (pointer p, const_reference v) {
            new (p) T(v);                            // uncomment!
            memcpy(p, &v, sizeof(T));
            assert(valid());
        }

        // ----------
        // deallocate
        // ----------

        /**
         * O(1) in space
         * O(1) in time
         * <your documentation>
         * after deallocation adjacent free blocks must be coalesced
         */
        void deallocate (pointer p, size_type = 0) {
            // <your code>

			char* b = (char*)p - sizeof(int);
			int size = 	abs(*((int *) b));
			char *e = b + size + sizeof(int);
			

			if(a - b != 0){
				int sizeBefore = *((int *)(b - sizeof(int)));
				if(sizeBefore > 0)
					b = b - sizeBefore;
			}
			if(a + N != e + sizeof(int)){
				int sizeAfter = *((int *)(e + sizeof(int)));
				if(sizeAfter > 0)
					e = e + sizeAfter + sizeof(int);
			}
			
			int newSize = e - b;
			
			memcpy((b - sizeof(int)), &newSize, sizeof(int));
			memcpy((e + sizeof(int)), &newSize, sizeof(int));

            assert(valid());}

        // -------
        // destroy
        // -------

        /**
         * O(1) in space
         * O(1) in time
         * <your documentation>
         */
        void destroy (pointer p) {
            p->~T();            // uncomment!
            assert(valid());}};







#endif // Allocator_h
