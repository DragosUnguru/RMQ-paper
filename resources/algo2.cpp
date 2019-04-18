// #include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include "Utils.h"

int** preprocessTable(int* arr, int arrSize) {

    int** table = (int**) malloc(sizeof(int*) * arrSize);

    for (int i = 0; i < arrSize; i++) {
        table[i] = (int*) malloc(sizeof(int) * myLog(arrSize));
    }

    // Initialize first column. Minimum of [i, i] = arr[i];
    for (int i = 0; i < arrSize; i++)
        table[i][0] = arr[i];

    // Using bitwise operator " << "
    // knowing that: (1 << a) = 2^a

    for (int i = 1; (1 << i) - 1 < arrSize; i++) {
        for (int j = 0; j + (1 << i) - 1 < arrSize; j++) {
            table[j][i] = MIN(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
        }
    }

    return table;
}

void sparseTable(Query* queries, int noOfQueries, int** table) {

    std::ofstream fout("output");

    for (int i = 0; i < noOfQueries; i++) {
        int value = myLog(queries[i].b - queries[i].a + 1);
        int minimum = MIN((table[queries[i].a][value]), (table[queries[i].b - (1 << value) + 1][value]));

        fout << "Minimum of [" << queries[i].a << ", " << queries[i].b << "]: " << minimum << "\n";
    }
    fout.close();
}

void executeSparseTable(char const* inputFileName) {

    int n, noOfQueries;
    int isGoingToModify = 0;
    Query* queries;
    int* arr;

    readInput(arr, n, noOfQueries, queries, inputFileName, isGoingToModify);

    int** table = preprocessTable(arr, n);

    sparseTable(queries, noOfQueries, table);

    // If the array is being modified:
    if (isGoingToModify) {

        for (int i = 0; i < 7; i++) {

            continueInputRead(arr, isGoingToModify);

            // Just like Mo's algorithm, we don't have,
            // any other option but to remake the whole
            // preprocessing part.
            int** table = preprocessTable(arr, n);

            sparseTable(queries, noOfQueries, table);

            fin >> isGoingToModify;
        }
    }
}