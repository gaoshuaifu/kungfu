#include <iostream>
#include <pthread.h>
using namespace std;

/*
             out                 in
             |                 |
    -------------------------------
    |    |    |1 |2 |3 |4 |5 |6 |    |    |
    -------------------------------
 */
class BoundedBuffer{
private:
    int capacity;
    int count;
    int in;
    int out;
    int* buffer;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
public:
    BoundedBuffer(int cap){
        capacity = cap;
        count = 0;
        in = 0;
        out = 0;
        buffer = new int[capacity];
        pthread_mutex_init(&mutex, NULL);
        pthread_cond_init(&cond, NULL);
    }
    ~BoundedBuffer(){
        delete[] buffer;
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }
    void put(int val){
        pthread_mutex_lock(&mutex);
        while(count == capacity)
            pthread_cond_wait(&cond, &mutex);

        cout << "PUT";
        for(int i = 0; i < count; i++)
            cout << " " << buffer[(out + i) % capacity] << " ";
        cout << "[" << val << "]" << endl;

        count++;
        buffer[in] = val;
        in = (in + 1) % capacity;

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    int get(){
        pthread_mutex_lock(&mutex);
        while(count == 0)
            pthread_cond_wait(&cond, &mutex);

        count--;
        int val = buffer[out];
        out = (out + 1) % capacity;

        cout << "GET [" << val << "] ";
        for (int i = 0; i < count; i++)
            cout << buffer[(i + out) % capacity] << " ";
        cout << endl;

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        return val;
    }
};

void* producer_run(void* arg){
    BoundedBuffer* buffer = (BoundedBuffer*) arg;
    string s = "0123456789";
    int i = 0;
    while(true){
        buffer->put(s[i] - '0');
        i = (i + 1) % 10;
        sleep(1);
    }
}

void* consumer_run(void *arg) {
    while (true) {
        BoundedBuffer* buffer = (BoundedBuffer*) arg;
        int val = buffer->get();
        sleep(2);
    }
}

int main() {
    // Create shared buffer.
    BoundedBuffer* buffer = new BoundedBuffer(10);

    // Create detached thread attribute.
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    // Create producer and consumer threads.
    pthread_t p, c;
    pthread_create(&p, &attr, producer_run, buffer);
    pthread_create(&c, &attr, consumer_run, buffer);

    // Destroy attribute.
    pthread_attr_destroy(&attr);

    // Terminate main thread.
    pthread_exit(NULL);
}
