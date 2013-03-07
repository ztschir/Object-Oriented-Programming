// ------------------------
// projects/matlab/Matrix.h
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------

#ifndef Matrix_h
#define Matrix_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // ptrdiff_t, size_t
#include <vector>  // vector
#include <stdexcept>

// ------
// Matrix
// ------
using namespace std;

template <typename T>
class Matrix {
    public:
        // --------
        // typedefs
        // --------

        typedef typename std::vector< std::vector<T> >    container_type;
        typedef typename container_type::value_type       value_type;

        typedef typename container_type::size_type        size_type;
        typedef typename container_type::difference_type  difference_type;

        typedef typename container_type::pointer          pointer;
        typedef typename container_type::const_pointer    const_pointer;

        typedef typename container_type::reference        reference;
        typedef typename container_type::const_reference  const_reference;

        typedef typename container_type::iterator         iterator;
        typedef typename container_type::const_iterator   const_iterator;

    public:
        // -----------
        // operator ==
        // -----------

        /**
         * Operator ==
         * Compares two matrices on an element-by-element basis and returns true for each same element 
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const Matrix& to the right hand side of the operator
         * @return Matrix<bool> of true/false for individual comparisons of each element
         */
        friend Matrix<bool> operator == (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            if(lhs.getRC() != rhs.getRC()) throw invalid_argument("Matrix with different sizes");
            if(lhs.size() != 0){ 
                Matrix<bool> result(lhs.size(), lhs[0].size()); 
                for(int i = 0; i< (int)lhs.size(); ++i){
                    for(int j = 0; j < (int)lhs[i].size(); ++j){
                        result[i][j] = rhs[i][j] == lhs[i][j];
                    }
                }
                return result;
            }
            return false;
        }

        // -----------
        // operator !=
        // -----------

        /**
         * Operator !=
         * Compares two matrices on an element-by-element basis and returns false for each same element 
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const Matrix& to the right hand side of the operator
         * @return Matrix<bool> of true/false for individual comparisons of each element
         */
        friend Matrix<bool> operator != (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            Matrix<bool> result = (rhs == lhs);
            for(int i = 0; i< (int)lhs.size(); ++i){
                for(int j = 0; j < (int)lhs[i].size(); ++j){
                    result[i][j] = !result[i][j];
                }
            }
            return result;}

        // ----------
        // operator <
        // ----------

        /**
         * Operator <
         * Compares two matrices on an element-by-element basis and returns true when the lhs
         *      is smaller than the rhs element
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const Matrix& to the right hand side of the operator
         * @return Matrix<bool> of true/false for individual comparisons of each element
         */
        friend Matrix<bool> operator < (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            if(lhs.getRC() != rhs.getRC()) throw invalid_argument("Matrix with different sizes");
            if(lhs.size() != 0){ 
                Matrix<bool> result(lhs.size(), lhs[0].size()); 
                for(int i = 0; i< (int)lhs.size(); ++i){
                    for(int j = 0; j < (int)lhs[i].size(); ++j){
                        result[i][j] = lhs[i][j] < rhs[i][j];
                    }
                }
                return result;
            }
            return false;
        }

        // -----------
        // operator <=
        // -----------

        /**
         * Operator <=
         * Compares two matrices on an element-by-element basis and returns true when the lhs
         *      is smaller or equal to than the rhs element
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const Matrix& to the right hand side of the operator
         * @return Matrix<bool> of true/false for individual comparisons of each element
         */
        friend Matrix<bool> operator <= (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            if(lhs.getRC() != rhs.getRC()) throw invalid_argument("Matrix with different sizes");
            if(lhs.size() != 0){ 
                Matrix<bool> result(lhs.size(), lhs[0].size()); 
                for(int i = 0; i< (int)lhs.size(); ++i){
                    for(int j = 0; j < (int)lhs[i].size(); ++j){
                        result[i][j] = lhs[i][j] <= rhs[i][j];
                    }
                }
                return result;
            }
            return false;
        }

        // ----------
        // operator >
        // ----------

        /**
         * Operator >
         * Compares two matrices on an element-by-element basis and returns true when the lhs
         *      is bigger than the rhs element
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const Matrix& to the right hand side of the operator
         * @return Matrix<bool> of true/false for individual comparisons of each element
         */
        friend Matrix<bool> operator > (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            Matrix<bool> result = (lhs <= rhs);
            for(int i = 0; i< (int)lhs.size(); ++i){
                for(int j = 0; j < (int)lhs[i].size(); ++j){
                    result[i][j] = !result[i][j];
                }
            }
            return result;}

        // -----------
        // operator >=
        // -----------

        /**
         * Operator >=
         * Compares two matrices on an element-by-element basis and returns true when the lhs
         *      is bigger or equal to than the rhs element
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const Matrix& to the right hand side of the operator
         * @return Matrix<bool> of true/false for individual comparisons of each element
         */
        friend Matrix<bool> operator >= (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            Matrix<bool> result = (lhs < rhs);
            for(int i = 0; i< (int)lhs.size(); ++i){
                for(int j = 0; j < (int)lhs[i].size(); ++j){
                    result[i][j] = !result[i][j];
                }
            }
            return result;}

        // ----------
        // operator +
        // ----------

        /**
         * Operator +
         * Adds a scaler rhs to each element on the matrix lhs
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const T& to the right hand side of the operator
         * @return Matrix<T> of the added matrix result
         */
        friend Matrix<T> operator + (Matrix lhs, const T& rhs) {
            return lhs += rhs;}

        /**
         * Operator +
         * Adds two matrices on an element-by-element basis
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const Matrix& to the left hand side of the operator
         * @return Matrix<T> of the added matrices
         */
        friend Matrix<T> operator + (Matrix lhs, const Matrix& rhs) {
            return lhs += rhs;}

        // ----------
        // operator -
        // ----------

        /**
         * Operator -
         * Subtracts a scaler rhs from each element on the matrix lhs
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const T& to the right hand side of the operator
         * @return Matrix<T> of the subtracted matrix result
         */
        friend Matrix<T> operator - (Matrix lhs, const T& rhs) {
            return lhs -= rhs;}

        /**
         * Operator -
         * Subtracts two matrices on an element-by-element basis
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const Matrix& to the left hand side of the operator
         * @return Matrix<T> of the subtracted matrices
         */
        friend Matrix<T> operator - (Matrix lhs, const Matrix& rhs) {
            return lhs -= rhs;}

        // ----------
        // operator *
        // ----------

        /**
         * Operator *
         * Multiplies a scaler rhs from each element on the matrix lhs
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const T& to the right hand side of the operator
         * @return Matrix<T> of the multiplied matrix result
         */
        friend Matrix<T> operator * (Matrix lhs, const T& rhs) {
            return lhs *= rhs;}

        /**
         * Operator *
         * Multiplies two matrices on an element-by-element basis
         * @param lhs is a const Matrix& to the left hand side of the operator
         * @param rhs is a const Matrix& to the left hand side of the operator
         * @return Matrix<T> of the Multiplied matrices
         */
        friend Matrix<T> operator * (Matrix lhs, const Matrix& rhs) {
            return lhs *= rhs;}
    
        /**
         * Method getRC()
         * Gets the Row and Column sizes of the matrix
         * @return pair<int,int> the Row and Column sizes
         */
    
        pair<int, int> getRC() const {
            pair<int, int> result;
            result.first = _m.size();
            if(_m.size() == 0) result.second = 0;
            else result.second = _m[0].size();
            return result;
        }
    
    private:
        // ----
        // data
        // ----

        std::vector< std::vector<T> > _m;
        

        // -----
        // valid
        // -----

        /**
         * Method valid()
         * Tests the matrix to verify that it is a valid matrix
         * @return bool true if a valid matrix
         */
        bool valid () const {
            // <your code>
            if(!_m.empty()){
                int size = _m[0].size();
                for(int i = 0; i < (int)_m.size(); ++i){
                    if((int)_m[i].size() != size) return false;
                }
            }
            
            pair<int, int> rc = (*this).getRC();
            if(rc.first == 0 && rc.second != 0) return false;
            
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Matrix Constructor
         * Gets the Row and Column sizes of the matrix
         * @param r is a size_type for the initial row size of the matrix, defaults to 0
         * @param c is a size_type for the initial column size of the matrix, defaults to 0
         * @param v is a T& for the initial value, defaults to the default constructor of the type
         */
        Matrix (size_type r = 0, size_type c = 0, const T& v = T()) {
            // <your code>
            for(int i = 0 ; i < (int)r; ++i){
                vector<T> col(c, v);
                _m.push_back(col);
            }
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Matrix  (const Matrix<T>&);
        // ~Matrix ();
        // Matrix& operator = (const Matrix&);

        // -----------
        // operator []
        // -----------

        /**
         * Operator []
         * Indexes the Matrix
         * @param i is a size_type to the index to the row that the user wants
         * @return reference to the vector that is at index i
         */
        reference operator [] (size_type i) {
            // <your code>
            return _m[i];}

        /**
         * Operator []
         * Indexes the Matrix
         * @param i is a size_type to the index to the row that the user wants
         * @return const_reference to the vector that is at index i
         */
        const_reference operator [] (size_type i) const {
            return (*const_cast<Matrix*>(this))[i];}

        // -----------
        // operator +=
        // -----------

        /**
         * Operator +=
         * Adds the rhs scaler to this matrix
         * @param rhs const T& scaler value added to the matrix
         * @return Matrix<T>& the result matrix
         */
        Matrix<T>& operator += (const T& rhs) {
            // <your code>
            for(int i = 0; i< (int)_m.size(); ++i){
                for(int j = 0; j < (int)_m[i].size(); ++j){
                    _m[i][j] += rhs;
                }
            }
            return *this;}

        /**
         * Operator +=
         * Adds the rhs matrix to this matrix
         * @param rhs const Matrix& matrix added to this matrix
         * @return Matrix<T>& the result matrix
         */
        Matrix<T>& operator += (const Matrix& rhs) {
            // <your code>
            if((*this).getRC() != rhs.getRC()) throw invalid_argument("Matrix with different sizes");
            for(int i = 0; i< (int)_m.size(); ++i){
                for(int j = 0; j < (int)_m[i].size(); ++j){
                    _m[i][j] += rhs[i][j];
                }
            }
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * Operator -=
         * Subtracts the rhs scaler to this matrix
         * @param rhs const T& scaler value subtracted to the matrix
         * @return Matrix<T>& the result matrix
         */
        Matrix<T>& operator -= (const T& rhs) {
            // <your code>
            for(int i = 0; i< (int)_m.size(); ++i){
                for(int j = 0; j < (int)_m[i].size(); ++j){
                    _m[i][j] -= rhs;
                }
            }
            return *this;}

        /**
         * Operator -=
         * Subtracts the rhs matrix from this matrix
         * @param rhs const Matrix& matrix subtracts from this matrix
         * @return Matrix<T>& the result matrix
         */
        Matrix<T>& operator -= (const Matrix& rhs) {
            // <your code>
            if((*this).getRC() != rhs.getRC()) throw invalid_argument("Matrix with different sizes");
            for(int i = 0; i< (int)_m.size(); ++i){
                for(int j = 0; j < (int)_m[i].size(); ++j){
                    _m[i][j] -= rhs[i][j];
                }
            }
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * Operator *=
         * Multiplies the rhs scaler to this matrix
         * @param rhs const T& scaler value multiplies to the matrix
         * @return Matrix<T>& the result matrix
         */
        Matrix<T>& operator *= (const T& rhs) {
            // <your code>
            for(int i = 0; i< (int)_m.size(); ++i){
                for(int j = 0; j < (int)_m[i].size(); ++j){
                    _m[i][j] *= rhs;
                }
            }
            return *this;}

        /**
         * Operator *=
         * Multiplies the rhs matrix from this matrix
         * @param rhs const Matrix& matrix multiplies from this matrix
         * @return Matrix<T>& the result matrix
         */
        Matrix<T>& operator *= (const Matrix& rhs) {
            // <your code>
            if((*this).getRC().second != rhs.getRC().first) throw invalid_argument("Matrix with different sizes");
            vector<vector<T> > product;  
            for(int i = 0; i< (int)_m.size(); ++i){
                vector<T> row;
                for(int y = 0 ; y < (int)rhs[0].size(); ++y){
                    int j = 0;
                    T sum = 0;
                    for(int x = 0; x < (int)rhs.size(); ++x){
                        sum += (_m[i][j] * rhs[x][y]);
                        ++j;
                    }
                    row.push_back(sum);
                }
                product.push_back(row);
            }
            
            _m = product;
            return *this;}

        // --
        // eq
        // --

        /**
         * Methods eq
         * compares the other matrix to this matrix
         * @param other const Matrix<T>& other matrix to compare to
         * @return bool true if the two matrices are equal in both size and elements
         */
        bool eq (const Matrix<T>& other) const {
            // <your code>
            if(_m.size() != other.size()) return false;
            if(!_m.empty() && other.size() != 0 && _m[0].size() != other[0].size()) return false;
            for(int i = 0; i< (int)_m.size(); ++i){
                for(int j = 0; j < (int)_m[i].size(); ++j){
                    if(_m[i][j] != other[i][j]) return false;
                }
            }
            return true;}

        // -----
        // begin
        // -----

        /**
         * Methods begin
         * Returns an iterator to the first row
         * @return iterator to the first row
         */
        iterator begin () {
            return _m.begin();}

        /**
         * Methods begin
         * Returns an iterator to the first row
         * @return const_iterator to the first row
         */
        const_iterator begin () const {
            return const_cast<Matrix<T>*>(this)->begin();}

        // ---
        // end
        // ---

        /**
         * Methods end
         * Returns an iterator to the last row
         * @return iterator to the last row
         */
        iterator end () {
            return _m.end();}

        /**
         * Methods end
         * Returns an iterator to the last row
         * @return const_iterator to the last row
         */
        const_iterator end () const {
            return const_cast<Matrix<T>*>(this)->end();}

        // ----
        // size
        // ----

        /**
         * Methods size
         * Returns size of the rows
         * @return size_type of the size of rows
         */
        size_type size () const {
            return _m.size();}
        
        void print(char name){
            cout << "   Matrix: " << name << endl;
            for(int i = 0; i< (int)_m.size(); ++i){
                for(int j = 0; j < (int)_m[i].size(); ++j){
                    cout << "   " << _m[i][j] << " ";
                }
                cout << endl;
            }
        }        
};
            
        

#endif // Matrix_h

