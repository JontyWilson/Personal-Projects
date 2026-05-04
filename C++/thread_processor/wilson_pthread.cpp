//g++ wilson_pthread.cpp -o wilson_pthread -lpthread


//This program generates a random grid and uses multi-threading to discover 
// how many duplicates there are of a given number by the user. 
//Can be done using 4 seperate threads to search the array for an O(n^2) runtime

//Or can be done using 4 seperate threads to sort the array (merge sort) 
// and then find one specified number's duplicates using binary search and 
// iteration - for a runtime closer to O(nlog(n)) 
// -----> not enough time to implement.



#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

std::vector<std::vector<int>> arr;

void *runner(void *param);      /* threads call this function */

int main(int argc, char *argv[]){
    pthread_t thread1;  /*thread identifier*/
    pthread_t thread2;  /*thread identifier*/
    pthread_t thread3;  /*thread identifier*/
    pthread_t thread4;  /*thread identifier*/
    pthread_attr_t attr;   /*set of thread attributes */
    
    int n = 0;
    int rand = 10 + (std::rand() % 90);

    std::cout << "Enter how big would you like your NxN grid to be: N = ";
    std::cin >> n;    
    

    for(int i=0; i<n; i++)
    {
        arr.push_back(std::vector<int>());
        for(int y=0; y<n; y++)
        {
            arr[i].push_back(rand);
            rand = 10 + (std::rand() % 90);
        }
    }

      for(int i=0; i<n; i++)
    {
        for(int y=0; y<n; y++)
        {
            std::cout<< arr[i][y] << " ";
        }
        std::cout<< std::endl;
    }

    int *a = new int, *b = new int, *c = new int, *d = new int;
    int tmp1, tmp2, tmp3, tmp4;
    std::cout<<std::endl << std::endl;
    std::cout<< "Enter 4 numbers (seperated by spaces) to see how many duplicates of each there are: ";
    std::cin >> *a >> *b >> *c >> *d;
    std::cout << std::endl;

    
    pthread_attr_init(&attr);  /* set the default attributes of the thread */
    pthread_create(&thread1, &attr, runner, a);  /* create the thread */
    pthread_create(&thread2, &attr, runner, b); 
    pthread_create(&thread3, &attr, runner, c); 
    pthread_create(&thread4, &attr, runner, d); 

    pthread_join(thread1, NULL); /* wait for thread to exit */
    pthread_join(thread2, NULL); /* wait for thread to exit */
    pthread_join(thread3, NULL); /* wait for thread to exit */
    pthread_join(thread4, NULL); /* wait for thread to exit */

    // printf("thread: %ld\n", thread1);
    // printf("thread: %ld\n", thread2);
    // printf("thread: %ld\n", thread3);
    // printf("thread: %ld\n", thread4);

}
/* this is the function the threads execute */
//if you need to pass more than one argument to the runner, just create a struct and pass the memory location
void *runner(void *param){
    int num = *((int *) param); //cast param to int
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int y = 0; y < arr[i].size(); y++)
        {
            if (arr[i][y] == num)
            {
                count++;
            }
        }
    }

    std::cout << "Number of duplicates for " << num << " = " << count << std::endl;
    pthread_exit(0);
}