#include<stdio.h>
#include<iostream>
#include<mutex>
#include<thread>


using namespace std;

class MutexDemo {
    /*
        Concepts:
        * mutex, semaphore, monitor, condition variable, locks, spin locks
        several RAII wrappers to manage user provide resources:
        * unique_ptr, shared_ptr : to manage dynamically allocated objects
        * lock_guard, unique_lock, shared_lock: to manage mutexes
        * std::condition_variable, std::mutex, these are classes
        Posix interfaces:
        * sem_init, sem_post, sem_wait
        * pthread_mutex_init, pthread_mutex_lock, pthread_mutex_unlock, pthread_mutex_destroy
        * pthread_cond_t, pthread_cond_init, pthread_cond_wait, pthread_cond_signal, pthread_cond_broadcast
        pthread thread apis:
        * pthread_create, pthread_join, pthread_detach 
        
    */
private:
    mutex mt;
public:

    MutexDemo() {}

    void BadMutex() {
        mt.lock();

        cout << "print something" << endl;
        // If function returns in between, mutex won't be released.

        mt.unlock();
    }

    void GoodMutex() {
        lock_guard<mutex> lk(mt);

        cout << "print something" << endl;;
    }

    
};

int main() {
    cout << "hello world" << endl;
    int thread_num = thread::hardware_concurrency();
    cout << "hardware_concurrency: " << thread_num << endl;
}

