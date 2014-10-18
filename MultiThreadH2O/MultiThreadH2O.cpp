#include <iostream>
#include <pthread.h>
using namespace std;

class H2O{
private:
    int numH;
    int numO;
    int numH2O;
    pthread_mutex_t mutex;
public:
    H2O(){
        numH = 0;
        numO = 0;
        numH2O = 0;
        pthread_mutex_init(&mutex, NULL);
    }
    ~H2O(){
        pthread_mutex_destroy(&mutex);
    }

    void produceH2O(){
        cout << numH << " " << numO << "\n";
        numH--;
        numH--;
        numO--;
        numH2O++;
        cout << "PRODUCE " << numH2O << " H2O" << "\n";
        cout << numH << " " << numO << "\n\n";
    }

    void H(){
        pthread_mutex_lock(&mutex);
        numH++;
        if(numH >= 2 && numO >= 1)
            produceH2O();
        pthread_mutex_unlock(&mutex);
    }

    void O(){
        pthread_mutex_lock(&mutex);
        numO++;
        if(numH >= 2 && numO >= 1)
            produceH2O();
        pthread_mutex_unlock(&mutex);
    }
};

void* produceH(void* arg){
    H2O* h2o = (H2O*) arg;
    while(true){
        h2o->H();
        sleep(1);
    }
}

void* produceO(void* arg){
    H2O* h2o = (H2O*) arg;
    while(true){
        h2o->O();
        sleep(2);
    }
}

int main() {
    // Create shared buffer.
    H2O* h2o = new H2O();

    // Create detached thread attribute.
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    // Create producer and consumer threads.
    pthread_t h, o;
    pthread_create(&h, &attr, produceH, h2o);
    pthread_create(&o, &attr, produceO, h2o);

    // Destroy attribute.
    pthread_attr_destroy(&attr);

    // Terminate main thread.
    pthread_exit(NULL);
}
