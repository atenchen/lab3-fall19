#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
template <class T>
class Queue{
 private:
  T* array;
  unsigned int maxSize;
  unsigned int currentSize;
  unsigned int first;
  unsigned int last;
 public:
  Queue(unsigned int);
  Queue(const Queue &);
  ~Queue();
  bool enqueue(T);
  T& dequeue();
  bool empty(){return currentSize == 0;}
  T peek(){return array[first];}
  void clear();
  void operator+=(T data){enqueue(data);}
};

template <class T>
Queue<T>::Queue(unsigned int size){
  this->array = new T[size];
  this->maxSize = size;
  currentSize = 0;
  first = 0;
  last = 0;
}

template <class T>
Queue<T>::Queue(const Queue & orig){
  this->maxSize = orig.maxSize;
  this->currentSize = orig.currentSize;
  this->first = orig.first;
  this->last = orig.last;
  this->array = new T[maxSize];
  for(unsigned int i = 0; i < maxSize; i++){
    array[i] = orig.array[i];
  }
}

template <class T>
Queue<T>::~Queue(){
  delete[] array;
}

template <class T>
bool Queue<T>::enqueue(T data){
  if(currentSize < maxSize){
    array[last] = data;
    last = (last + 1)%maxSize;
    currentSize++;
    return true;
  }
  else{
    return false;
  }
}

template <class T>
T& Queue<T>::dequeue(){
  /*if(currentSize = 0){
    return NULL;
  }*/
  unsigned int index = first;
  first = (first + 1)%maxSize;
  currentSize --;
  return array[index];
}

template <class T>
void Queue<T>::clear(){
  first = 0;
  last = 0;
  currentSize = 0;
}
#endif
