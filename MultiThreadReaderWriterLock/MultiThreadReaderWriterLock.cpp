#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

const int NUM_READER = 4;
const int NUM_WRITER = 2;

class ReaderWriterLock{
private:
    int readers;
    int writers;
    pthread_mutex_t mutex;
    pthread_cond_t cond;

public:
    ReaderWriterLock(){
        readers = 0;
        writers = 0;
        pthread_mutex_init(&mutex, NULL);
        pthread_cond_init(&cond, NULL);
    }

    ~ReaderWriterLock(){
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }

    void lockRead(){
        pthread_mutex_lock(&mutex);
        while(writers > 0)
            pthread_cond_wait(&cond, &mutex);

        readers++;
        printState();

        pthread_mutex_unlock(&mutex);
    }

    void unlockRead(){
        pthread_mutex_lock(&mutex);

        readers--;
        printState();

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }

    void lockWrite(){
        pthread_mutex_lock(&mutex);
        while(readers > 0 || writers > 0)
            pthread_cond_wait(&cond, &mutex);

        writers++;
        printState();

        pthread_mutex_unlock(&mutex);
    }

    void unlockWrite(){
        pthread_mutex_lock(&mutex);

        writers--;
        printState();

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }

    void printState(){
        cout << "R[" << readers << "] -- W[" << writers << "]" << endl;
    }
};

void* read(void* arg){
    ReaderWriterLock* rwLock = (ReaderWriterLock*) arg;
    while(true){
        sleep(2);
        rwLock->lockRead();
        sleep(2);
        rwLock->unlockRead();
    }
}

void* write(void* arg){
    ReaderWriterLock* rwLock = (ReaderWriterLock*) arg;
    while(true){
        sleep(1);
        rwLock->lockWrite();
        sleep(1);
        rwLock->unlockWrite();
    }
}

int main(){
    ReaderWriterLock* rwLock = new ReaderWriterLock();

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_t readerThreads[NUM_READER];
    for(int i = 0; i < NUM_READER; i++)
        pthread_create(&readerThreads[i], &attr, read, rwLock);

    pthread_t writerThreads[NUM_WRITER];
    for(int i = 0; i < NUM_WRITER; i++)
        pthread_create(&writerThreads[i], &attr, write, rwLock);

    pthread_attr_destroy(&attr);

    pthread_exit(NULL);
}
