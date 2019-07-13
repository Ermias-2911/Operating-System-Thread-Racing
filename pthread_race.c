#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

// Author Ermias Haile
// Csc415
// October 30, 2018

/**
 * THESE DEFINE VALUES CANNOT BE CHANGED.
 * DOING SO WILL CAUSE POINTS TO BE DEDUCTED
 * FROM YOUR GRADE (15 points)
 */
/** BEGIN VALUES THAT CANNOT BE CHANGED */
#define MAX_THREADS 16
#define MAX_ITERATIONS 40
/** END VALUES THAT CANNOT BE CHANGED */


/**
 * use this struct as a parameter for the function
 * nanosleep.
 * For exmaple : nanosleep(&ts, NULL);
 */
struct timespec ts = {0, 123456};

// Variable decleration
int globalvariable = 0;
pthread_t  thr_array[MAX_THREADS];


// Adder thread function
void* adding_thread (void *tid)
{

    int i, thr_id;
    thr_id = *((int*)tid);

    for(int j = 0; j < MAX_ITERATIONS; j++) {
        nanosleep(&ts, NULL);
        int temp = globalvariable;
        temp += 1;
        globalvariable = temp;
        printf("Current Value written to Global Variables by thread : %d is %d\n",thr_id, globalvariable);
    }

}


// Subtractor thread function 
void* subtracting_thread (void *tid) {

    int i, thr_id;
    thr_id = *((int*)tid);

    for(int j = 0; j < MAX_ITERATIONS; j++) {
        nanosleep(&ts,NULL);
        int temp = globalvariable;
        temp -= 1;
        globalvariable = temp;
        printf("Current Value written to Global Variables by thread : %d is %d\n",thr_id, globalvariable);
    }
    return NULL;
}


int main(int argc, char** argv)


{
    int i;
    int trd;


    // Creating threads
    for(i = 1; i <= MAX_THREADS; i++) {


        if(i%2 == 0)
        {
            // Even threads
            trd = pthread_create(&thr_array[i], NULL, adding_thread, (void*)&i);
            if(trd != 0)
            {
                printf(", Warning! can't create Thread %d\n",trd);
                exit(-2);
            }
        }

        else {

            // Odd threads
            trd = pthread_create(&thr_array[i], NULL, subtracting_thread, (void*)&i);
            if(trd  != 0)
            {
                printf(" Warning can't create Thread %d\n",trd);
                exit(-2);
            }
        }
    }

    // Joining the thread
    for(i = 1; i <= MAX_THREADS; i++) {
        pthread_join(thr_array[i], NULL);
    }

    // printing globalvariables
    printf("Final Value of Shared Variable : %d\n",globalvariable);

    return 0;
}
