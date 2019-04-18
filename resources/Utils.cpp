#include <fstream>
#include "Utils.h"

std::ifstream fin;

int myLog(int n) {

    int res = -1;

    while(n) {
        res++;
        n >>= 1;
    }
    return res;
}

void readInput(int*& arr, int &n, int &noOfQueries, Query*& queries, char const *argv, int &val) {

    fin.open(argv);

    fin >> n >> noOfQueries;

    arr = (int*) malloc(sizeof(int) * n);
    queries = (Query*) malloc(sizeof(Query) * noOfQueries);

    for (int i = 0; i < n; i++)
        fin >> arr[i];

    for(int i = 0; i < noOfQueries; i++) {
        fin >> queries[i].a;
        fin >> queries[i].b;
    }

    fin >> val;
}

void continueInputRead(int* arr, int noOfModifications) {

    for (int i = 0; i < noOfModifications; i++) {
        int index;
        int value;

        fin >> index;
        fin >> value;

        arr[index] = value;
    }
}