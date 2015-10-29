#pragma once
#include <pthread.h>
#include <queue>
#include <iostream>
using std::cerr;
using std::endl;
template <typename T>
class BlockingQueue
{

public:
    BlockingQueue(size_t max_len=256):is_full(false),is_empty(true),max_len_(max_len)
    {
        pthread_mutex_init(&mutex_,NULL);
        pthread_cond_init(&not_full_,NULL);
        pthread_cond_init(&not_empty_,NULL);
    }

    T pop()
    {
        T rt;
        pthread_mutex_lock(&mutex_);
        while(is_empty)
        {
//          cerr << pthread_self() << " : empty, waiting not empty signal... " << endl;
            pthread_cond_wait(&not_empty_,&mutex_);
//	    cerr << pthread_self() << " : got not empty signal." << endl;
        }
        rt = q.front();
        q.pop();
	is_full = false;
        if(q.empty())
        {
            is_empty = true;
        }
//	cerr <<pthread_self()<<" : signaling not full" << endl;
        pthread_mutex_unlock(&mutex_);
        pthread_cond_signal(&not_full_);
        return rt;
    }

    int push(T & e)
    {
        pthread_mutex_lock(&mutex_);
        while(is_full)
        {
//            cerr << pthread_self() << " : full, waiting not full signal... " << endl;
            pthread_cond_wait(&not_full_,&mutex_);
//	    cerr << pthread_self() << " : got not full signal." << endl;
        }
        q.push(e);
	is_empty = false;
        if(q.size() == max_len_)
        {
            is_full = true;
        }
//	cerr <<pthread_self()<<" : signaling not empty" << endl;
        pthread_mutex_unlock(&mutex_);
	pthread_cond_signal(&not_empty_);
    }

private:
    std::queue<T> q;
    pthread_mutex_t mutex_;
    pthread_cond_t not_full_;
    pthread_cond_t not_empty_;
    bool is_full;
    bool is_empty;
    unsigned max_len_;
};

template class BlockingQueue<int>;










