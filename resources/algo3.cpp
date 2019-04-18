#include "Utils.h"
#include <stdlib.h>
#include <stdio.h>

#define GET_PARENT(i) (i >> 1)
#define GET_LEFT(i) (i << 1)
#define GET_RIGHT(i) ((i << 1) + 1)

int* constructTree(int* arr, int arrLength) {

    int* tree = (int*) malloc(sizeof(int) * 2 * arrLength);

    // Initialize leaves with array values
    for (int i = arrLength; i < 2 * arrLength; i++) {
        tree[i] = arr[i - arrLength];
        tree[i - arrLength] = __INT_MAX__;
    }

    // Strating from the previously initialised leaves, create parents
    for (int i = arrLength - 1; i > 0; i--) {
        tree[i] = MIN(tree[GET_LEFT(i)], tree[GET_RIGHT(i)]);
    }

    return tree;
}

void updateTree(int* tree, int n, int index, int value) {

    index += n;

    tree[index] = value;

    while(index > 1) {

        index = GET_PARENT(index);

        tree[index] = MIN(tree[GET_LEFT(index)], tree[GET_RIGHT(index)]);
    }
}

void segmentTrees(int* tree, Query* queries, int noOfQueries, int arrLength) {
    
    std::ofstream fout("output");
    
    for (int i = 0; i < noOfQueries; i++) {

        int minimum = __INT_MAX__;

        Query treeIdx;
        // Start from the bottom of the tree
        treeIdx.a = arrLength + queries[i].a;
        treeIdx.b = arrLength + queries[i].b + 1;

        while(treeIdx.a < treeIdx.b) {
            
            if (treeIdx.a % 2 != 0) {
                minimum = MIN(minimum, tree[treeIdx.a]);
                treeIdx.a++;
            }
            if (treeIdx.b % 2 != 0) {
                treeIdx.b--;
                minimum = MIN(minimum, tree[treeIdx.b]);
            }

            treeIdx.a = GET_PARENT(treeIdx.a);
            treeIdx.b = GET_PARENT(treeIdx.b);
        }
        fout << "Minimum of [" << queries[i].a << ", " << queries[i].b << "]: " << minimum << "\n";
    }
    fout.close();
}

void executeSegmentTrees(char const* inputFileName) {
    
    int n, noOfQueries;
    int isGoingToModify = 0;
    Query* queries;
    int* arr;

    readInput(arr, n, noOfQueries, queries, inputFileName, isGoingToModify);

    int* tree = constructTree(arr, n);

    segmentTrees(tree, queries, noOfQueries, n);

    // If the array is being modified:
    if (isGoingToModify) {

        for (int i = 0; i < 7; i++) {

            // In contrast to "Sparse Table" and "Mo's Algorithm",
            // segment trees offer us the possibility to modify
            // the previously created data structure, giving us a huge
            // benefit in this case as we don't have to remake the whole
            // preprocessing.
            for (int j = 0; j < isGoingToModify; j++) {
                int index;
                int value;

                fin >> index;
                fin >> value;

                updateTree(tree, n, index, value);
            }
            
            segmentTrees(tree, queries, noOfQueries, n);

            fin >> isGoingToModify;
        }
    }
}