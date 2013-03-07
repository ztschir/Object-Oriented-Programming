// ------------------------
// projects/matLab/Matlab.h
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------

#ifndef MatLab_h
#define MatLab_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <cstdlib> 

using namespace std;

// ------
// concat
// ------

/**
 * Function horzcat
 * Horizontally concatenate two matrices 
 * @param x const T& left side of the new concatenated matrix 
 * @param y const T& right side of the new concatenated matrix 
 * @return T a new matrix with the new concatenated matrices
 * http://www.mathworks.com/help/matlab/ref/horzcat.html
 */
template <typename T>
T horzcat (const T& x, const T& y) {
    if(x.getRC().first != y.getRC().first) throw invalid_argument("Matrix with different number of rows");
    T result(x.getRC().first, x.getRC().second + y.getRC().second);
    for(int i = 0; i< (int)result.size(); ++i){
        for(int j = 0; j< (int)result[0].size(); ++j){
            if(j < x.getRC().second) result[i][j] = x[i][j];
            else result[i][j] = y[i][j-x.getRC().second];
        }    
    }
    return result;}

/**
 * Function vertcat
 * Vertically concatenate two matrices 
 * @param x const T& top side of the new concatenated matrix 
 * @param y const T& bottom side of the new concatenated matrix 
 * @return T a new matrix with the new concatenated matrices
 * http://www.mathworks.com/help/matlab/ref/vertcat.html
 */
template <typename T>
T vertcat (const T& x, const T& y) {
    if(x.getRC().second != y.getRC().second) throw invalid_argument("Matrix with different number of rows");
    T result(x.getRC().first + y.getRC().first, x.getRC().second);
    for(int i = 0; i< (int)result.size(); ++i){
        for(int j = 0; j< (int)result[0].size(); ++j){
            if(i < x.getRC().first) result[i][j] = x[i][j];
            else result[i][j] = y[i-x.getRC().first][j];
        }    
    }
    return result;}

// ----
// diag
// ----

/**
 * Function diag
 * Get the diagonal elements and produces a 1xn matrix with the results
 * @param x const T& a matrix
 * @return T a new matrix with the results
 * http://www.mathworks.com/help/matlab/ref/diag.html
 */
template <typename T>
T diag (const T& x) {
    pair<int, int> rc = x.getRC();
    int len;
    if(rc.first < rc.second) len = rc.first;
    else len = rc.second;
    T result(len, 1);  
    for(int i= 0; i<len; ++i){
        result[i][0] = x[i][i];    
    }
    return result;}
    
// ---------
// transpose
// ---------

/**
 * Function transpose
 * Transpose the elements in the Matrix x
 * @param x const T& a matrix
 * @return T a new matrix with the transpose results
 * http://www.mathworks.com/help/matlab/ref/transpose.html
 */
template <typename T>
T transpose (const T& x) {
    T result(x.getRC().second, x.getRC().first);
    for(int i = 0; i< (int)result.size(); ++i){
        for(int j = 0; j < (int)result[i].size(); ++j){
            result[i][j] = x[j][i];
        }
    }
    return result;
}

// ---
// dot
// ---

/**
 * Function dot
 * Get the dot product of the two matrices
 * @param x const T& a matrix with nxm size
 * @param y const T& a matrix with mxk size
 * @return T a new matrix with the dot product results
 * http://www.mathworks.com/help/matlab/ref/dot.html
 */
template <typename T>
T dot (const T& x, const T& y) {
    T xT = transpose(x);
    return xT * y;}

// ---
// eye
// ---

/**
 * Function eye
 * Produce an Identity matrix of size r-by-c
 * @param r size_t row size
 * @param c size_t column size
 * @return T a new identity matrix
 * http://www.mathworks.com/help/matlab/ref/eye.html
 */
template <typename T>
T eye (std::size_t r, std::size_t c) {
    int len;
    if(r < c) len = r;
    else len = c;
    T x(r, c);
    for(int i=0; i<len; ++i){
        x[i][i] = 1;
    }
    return x;}

// ----------------
// linsolve (bonus)
// ----------------

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/linsolve.html
 */
template <typename T>
T linsolve (const T& x, const T& y) {
    return x;}

// ----
// ones
// ----

/**
 * Function ones
 * Produce matrix of size r-by-c with ones
 * @param r size_t row size
 * @param c size_t column size
 * @return T a new Matrix filled with ones
 * http://www.mathworks.com/help/matlab/ref/ones.html
 */
template <typename T>
T ones (std::size_t r, std::size_t c) {
    T x(r, c, 1);
    return x;}

// ----
// rand
// ----

/**
 * Function rand
 * Produce matrix of size r-by-c with random values between 0 and 1
 * @param r size_t row size
 * @param c size_t column size
 * @return T a new Matrix filled with random values
 * http://www.mathworks.com/help/matlab/ref/rand.html
 */
template <typename T>
T rand (std::size_t r, std::size_t c) {
    T x(r, c);
    typename T::value_type::value_type v;
    srand(time(0));
    for(int i = 0; i< (int)x.size(); ++i){
        for(int j = 0; j< (int)x[i].size(); ++j){
            v = (typename T::value_type::value_type) rand() / (typename T::value_type::value_type)RAND_MAX;
            if(v == 0) v = rand() % 2;
            x[i][j] = v;
        }    
    }
    return x;}


// ----
// tril
// ----

/**
 * Function tril
 * Get the values below the main diagonal 
 * @param x const T& the matrix
 * @return T a new Matrix with the values below the main diagonal
 * http://www.mathworks.com/help/matlab/ref/tril.html
 */
template <typename T>
T tril (const T& x) {
    T result(x.getRC().first, x.getRC().second);
    for(int i = 0; i< (int)x.size(); ++i){
        for(int j = 0; j< (int)x[i].size(); ++j){
            if(i > j) result[i][j] = x[i][j];            
        }
    }
    return result;}

// ----
// triu
// ----

/**
 * Function triu
 * Get the values above the main diagonal 
 * @param x const T& the matrix
 * @return T a new Matrix with the values above the main diagonal
 * http://www.mathworks.com/help/matlab/ref/triu.html
 */
template <typename T>
T triu (const T& x) {
    T result(x.getRC().first, x.getRC().second);
    for(int i = 0; i< (int)x.size(); ++i){
        for(int j = 0; j< (int)x[i].size(); ++j){
            if(i < j) result[i][j] = x[i][j];            
        }
    }
    return result;
}

// -----
// zeros
// -----

/**
 * Function zeros
 * Produce matrix of size r-by-c with zeros
 * @param r size_t row size
 * @param c size_t column size
 * @return T a new Matrix filled with zeros
 * http://www.mathworks.com/help/matlab/ref/zeros.html
 */
template <typename T>
T zeros (std::size_t r, std::size_t c) {
    T x(r, c);
    return x;}

#endif // MatLab_h

