/** @file libfibonacci.cpp
 * @brief Implementation of algorithmes for Assignment
 *   Analysis of Algorithms
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Fall 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Recursion
 * @date   October 1, 2021
 *
 * Implement algorithms with varying time complexities and compare
 * their performance.
 *
 * This file contains the actual implementation of the functions
 * and code you are required to complete for Assignment Recursion.
 * Make sure you modify the file header information to be correct
 * for the code you are creating.
 */
#include <cmath>
#include <iostream>

using namespace std;


/// phi is the golden ratio, not defined in <cmath> for c++ 11 so define it
/// here by hand for use in this assignment
double PHI = (sqrt(5.0) + 1.0) / 2.0;

/// global variable used to count number of operations in algorithms so we
/// can estimate computational complexity.
int operationCount;

/// global fibonacci table for memoization solution
/// We initialize F_0 and F_1 to 1.  All other values
/// initially 0 indicate not calculated yet NOT_CALCULATED
const int NOT_CALCULATED = -1;
const int MAX_FIBONACCI_NUMBER = 47;
int fibonacciTable[MAX_FIBONACCI_NUMBER + 1] = { NOT_CALCULATED };

/** @brief initialize fibonacci table
 *
 * Function that will (re)intiailzie the fibonacci table, which
 * is used in the task to implement the fibonacci calculation using
 * the memoization technique.  We need to be able to reinitialize
 * this table so that we can accuratly calculate performance and
 * complexity of the implementation.
 */
void initializeFibonacciTable()
{
  // set x_0 to 0 and x_1 to 1
  fibonacciTable[0] = 0;
  fibonacciTable[1] = 1;

  // initialze rest of table to not calculated yet
  for (int n = 2; n <= MAX_FIBONACCI_NUMBER; n++)
  {
    fibonacciTable[n] = NOT_CALCULATED; 
  }
}
/** @brief calculate the fibonacci number linearly
 *
 * Given input n, calculate the nth fibonacci number in the fibonacci
 * sequence. The implementation calculates the nth fibonacci number 
 * using an O(n) linear algorithm.
 * 
 * @param n Which number in the fibonacci sequence we should
 * calculate and return.
 * 
 * @returns int calculations and returns the nth fibonacci number of
 * the fibonacci sequence.
 */
int fibonacciLinear(int n)
{
  if (n <= 1)
  {
    return n;
  }

  int n1 = 0, n2 = 1, n3;         
  for(int i = 2;i <= n;i++, operationCount++)     
  { 
    operationCount++;   
    n3 = n1 + n2;
    operationCount++;      
    n1 = n2;
    operationCount++;    
    n2 = n3;
    operationCount++;
    operationCount++;
  }  
  return n3;
}

/** @brief calculate the fibonacci number recursively
 *
 * Given input n, calculate the nth fibonacci number in the fibonacci
 * sequence. The implementation calculates the nth fibonacci number 
 * using an O(n) recursive algorithm.
 * 
 * @param n Which number in the fibonacci sequence we should
 * calculate and return.
 * 
 * @returns int calculations and returns the nth fibonacci number of
 * the fibonacci sequence.
 */
int fibonacciRecursive(int n)
{
  if (n <= 1)
  {
    return n;
  }
  operationCount++;
  operationCount++;    
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

/** @brief create a constant time implementat of the Fibonacci computation
 *
 * Given input n, calculate the nth fibonacci number in the fibonacci
 * sequence. The implementation calculates the nth fibonacci number 
 * using Binet's formula.
 * 
 * @param n Which number in the fibonacci sequence we should
 * calculate and return.
 * 
 * @returns int calculations and returns the nth fibonacci number of
 * the fibonacci sequence.
 */
int fibonacciConstant(int n)
{
  double top, bottom;
  int fin=0;
  operationCount++;
  top = pow(PHI,n);
  operationCount++;
  bottom = sqrt(5);
  operationCount++;
  fin = round(top/bottom);
  operationCount++;
  return fin;
}
/** @brief Implement Fibonacci calculation using memoization
 *
 * Given input n, calculate the nth fibonacci number in the fibonacci
 * sequence.In this task it will be required to use memoization combined 
 * with recursion, but the memoization table will effectively reduce the 
 * computational time to linear or better if we take into account repeated 
 * use of the calculated table.
 * 
 * @param n Which number in the fibonacci sequence we should
 * calculate and return.
 * 
 * @returns int calculations and returns the nth fibonacci number of
 * the fibonacci sequence.
 */
int fibonacciMemoization(int n)
{
  if (n <= 1)
  {
    return n;
  } 
  int sum;
  if (fibonacciTable[n] == NOT_CALCULATED)
  {  
    operationCount++;
    sum = fibonacciMemoization(n - 1) + fibonacciMemoization(n - 2);
    operationCount++; 
    fibonacciTable[n] = sum;
    operationCount++;
    operationCount++;
  }
  return fibonacciTable[n];
}