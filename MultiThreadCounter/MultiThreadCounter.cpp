#include <iostream>
#include <pthread.h>
using namespace std;

const int NUM_THREAD = 5;
const int NUM_INCREMENTS = 200;

class Counter{
private:
    int count;
    pthread_mutex_t mutex;
public:
    Counter(){
        count = 0;
        pthread_mutex_init(&mutex, NULL);
    }

    ~Counter(){
        pthread_mutex_destroy(&mutex);
    }

    void increment(){
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }

    int getCount(){
        int res;
        pthread_mutex_lock(&mutex);
        res = count;
        pthread_mutex_unlock(&mutex);
        return res;
    }
};

void* run(void* arg){
    Counter* counter = (Counter*) arg;
    for(int i = 0; i < NUM_INCREMENTS; i++)
        counter->increment();
    pthread_exit(NULL);
}

int main(){
    // create shared counter
    Counter* counter = new Counter();

    // create attr
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // create threads
    pthread_t threads[NUM_THREAD];
    for(int i = 0; i < NUM_THREAD; i++)
        pthread_create(&threads[i], &attr, run, counter);

    // join all threads.
    for(int i = 0; i < NUM_THREAD; i++)
        pthread_join(threads[i], NULL);

    // destroy the attribute.
    pthread_attr_destroy(&attr);

    // print result
    cout << counter->getCount() << endl;

    pthread_exit(NULL);
}
