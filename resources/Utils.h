#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include <time.h>

#define MIN(a, b) ((a < b) ? a : b)

typedef struct query{
    long a;
    long b;
}Query;

extern std::ifstream fin;

// Log2 implementation so we can avoid the recursive approach
int myLog(int n);

// Parse input from input file given in command line arguments
void readInput(int*& arr, int &n, int &noOfQueries, Query*& queries, char const *argv, int &val);

// In the case of modifying array elements, continue parsing
void continueInputRead(int* arr, int noOfModifications);
#endif