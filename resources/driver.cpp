#include <cstring>
#include <time.h>
#include <sys/time.h>
#include "algos.h"

int main(int argc, char const* argv[]) {

    /*
        * argv[1] = algorithm to be used
        * argv[2] = name of the input file
   */

    clock_t tic = clock();
   // struct timeval start, end;

//    gettimeofday(&start, NULL);

    if (!strcmp(argv[1], "mo")) {
        executeMoAlgorithm(argv[2]);
    }
    else if (!strcmp(argv[1], "sparsetable")) {
        executeSparseTable(argv[2]);
    }
    else if(!strcmp(argv[1], "segmenttrees")) {
        executeSegmentTrees(argv[2]);
    }
    else {
        printf("Invalid input arguments!\n");
        return -1;
    }

    clock_t toc = clock();
    //gettimeofday(&end, NULL);

    printf("%ld\n", toc - tic);

    //long seconds = (end.tv_sec - start.tv_sec);
    //long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

/*
    *We'll obtain the running time in microseconds (10^(-6))
*/
    
    
    //printf("Elapsed time on %s is %ld seconds and %ld microseconds\n", argv[2], seconds, micros);
    //printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);

    return 0;
}