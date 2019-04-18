#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>

#define MAX_N 100000

typedef struct {
    long a;
    long b;
}Query;

int* generateInputArray(long n) {

    int* arr = (int*) malloc(sizeof(int) * n);

    for (long i = 0; i < n; ++i) {
        arr[i] = rand() % 10000 + 79;
    }

    return arr;
}

Query* stressTestQueries(long n, int* arr) {

    Query* queries = (Query*) malloc(sizeof(Query) * n * (n - 1) / 2);

    unsigned long idx = 0;
    for (int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            queries[idx].a = i;
            queries[idx].b = j;
            idx++;
        }
    }

    printf("%ld\n", idx);

    std::random_shuffle(queries, queries + idx); // shuffle
    
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for(int i = 0; i < idx; i++)
        printf("%ld %ld ", queries[i].a, queries[i].b);
    
    return queries;
}

Query* getLargeQueries(long n, int* arr) {

    Query* queries = (Query*) malloc(sizeof(Query) * n / 11);

    int idx = 0;
    for (int i = 0; i < n / 77; i++) {
        for (int j = n - 1; j >= n - 7; j--) {
            queries[idx].a = i;
            queries[idx].b = j;
            idx++;
        }
    }

    printf("%d\n", idx);

    std::random_shuffle(queries, queries + idx); // shuffle

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for(int i = 0; i < idx; i++)
        printf("%ld %ld ", queries[i].a, queries[i].b);

    return queries;
}

Query* getSmallQueries(long n, long* idx, int* arr) {

    Query* queries = (Query*) malloc(sizeof(Query) * n * n/ 11);

    for (long i = 0; i < n; i += 7) {
        for (long j = i + 1; (j < i + n / 77) && (j < n); j++) {
            queries[*idx].a = i;
            queries[*idx].b = j;
            (*idx)++;
        }
    }

    printf("%ld\n", *idx);

    std::random_shuffle(queries, queries + (*idx)); // shuffle
    
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for(int i = 0; i < *idx; i++)
        printf("%ld %ld ", queries[i].a, queries[i].b);

    return queries;
}

void generateModification(int n) {


    for (int i = 0; i < 7; i++) {

        int noOfModifications = rand() % n/2.5 + 70;

        printf("%d\n", noOfModifications);

        for (int i = 0; i < noOfModifications; i++) {
            int indexToModify = rand() % n;
            int newValue = rand() % 10000 + 79;

            printf("%d %d\n", indexToModify, newValue);
        }
    }
}

int main(int argc, char const *argv[]) {

    long i, j;

    srand(time(0));
    long n = rand() % MAX_N + 10000;

  //  printf("%ld ", n);

    // Generate array:
    int* arr = generateInputArray(n);

    // Generate queries:

    //Query* largeQueries = getLargeQueries(n, arr);

    // long noOfSmallQueries = 0;
    // Query* smallButNumerousQueries = getSmallQueries(n, &noOfSmallQueries, arr);

    //Query* stressQueries = stressTestQueries(n, arr);

    generateModification(atoi(argv[1]));

    return 0;
}
