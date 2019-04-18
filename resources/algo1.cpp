#include <stdio.h>
#include <cmath>
#include <algorithm>
#include "Utils.h"

int* preprocessMo(int* arr, int n, int &processedLength) {

    int lastIdx;
    int i;
    int len = (int) sqrt(n);
    int* decomposedMins;

    // Manage the size of array for any case:
    if (n % len == 0) {
        decomposedMins = (int*) malloc(sizeof(int) * (n/len));
        lastIdx = n/len - 1;
    }
    else {
        decomposedMins = (int*) malloc(sizeof(int) * (n/len + 1));
        lastIdx = n/len;
    }

    // Preprocessing:
    for (i = 0; i < n; i += len) {
        decomposedMins[i / len] = *std::min_element(arr + i, arr + i + len);
        processedLength++;
    }

    decomposedMins[lastIdx] = *std::min_element(arr + i - len, arr + n);

    return decomposedMins;

}

void mo(int* arr, Query* queries, int arrLength, int noOfQueries, int* processedMins) {

    int len = (int) sqrt(arrLength);
    std::ofstream fout("output");

    for (int i = 0; i < noOfQueries; i++) {

        int L = queries[i].a;
        int R = queries[i].b;

        int lastStandingMin = __INT_MAX__;

        while (L <= R) { // If our query covers lonely indices (parts of preprocessed intervals):
            if ((L % len != 0) || (R - L < len)) {
                lastStandingMin = MIN(lastStandingMin, arr[L]);
                L++;
            } else { // If our query covers a whole interval of length sqrt(n):
                lastStandingMin = MIN(lastStandingMin, processedMins[L / len]);
                L += len;
            }
        }

        fout << "Minimum of [" << queries[i].a << ", " << queries[i].b << "]: " << lastStandingMin << "\n";
    }
    fout.close();
}

void executeMoAlgorithm(char const* inputFileName) {

    int n, noOfQueries, preprocessedLength = 0;
    int isGoingToModify = 0;
    Query* queries;
    int* arr;

    readInput(arr, n, noOfQueries, queries, inputFileName, isGoingToModify);

    int* preprocessedMins = preprocessMo(arr, n, preprocessedLength);

    mo(arr, queries, n, noOfQueries, preprocessedMins);

    // If the array is being modified:
    if (isGoingToModify) {

        for (int i = 0; i < 7; i++) {
            continueInputRead(arr, isGoingToModify);

            // Our only option is to remake the whole preprocessing
            // part all over again
            int* preprocessedMins = preprocessMo(arr, n, preprocessedLength);

            mo(arr, queries, n, noOfQueries, preprocessedMins);

            fin >> isGoingToModify;
        }
    }
}