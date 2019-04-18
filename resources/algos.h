
#include "Utils.h"

//  ============== Mo's Algorithm ============== 

//  Function to preprocess RMQ for every query of length sqrt(n)
int* preprocessMo(int* arr, int n, int &processedLength);

//  Function that answers to queries
void mo(int* arr, Query* queries, int arrLength, int noOfQueries, int* processedMins);

//  Driver. Calls previous functions
void executeMoAlgorithm(char const* inputFileName);



//  ============== Sparse Table ============== 

//  Function to preprocess the matrix.
int** preprocessTable(int* arr, int arrSize);

// Function that answers to queries
void sparseTable(Query* queries, int noOfQueries, int** table);

// Driver. Calls previous functions
void executeSparseTable(char const* inputFileName);



//  ============== Segment Tree ============== 

//  Preprocess function. Creates the data structure.
int* constructTree(int* arr, int arrLength);

//  Updates the data structure when modifications occured
void updateTree(int* tree, int n, int index, int value);

//  Function that answers to queries
void segmentTrees(int* tree, Query* queries, int noOfQueries, int arrLength);

//  Driver. Calls previous functions
void executeSegmentTrees(char const* inputFileName);