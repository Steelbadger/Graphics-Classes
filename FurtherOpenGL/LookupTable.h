#pragma once

typedef unsigned int ObjectID;
 
template<class T, int MaxElements = 1024>
class LookupTable {
public:
    LookupTable() {
        for (int i = 0; i < MaxElements; i++) {
            spacesStack[i] = i;
        }
        stackPointer = 0;
    }
    
    ObjectID Add(T& object){
        ObjectID outID = spacesStack[stackPointer++];
        storage[outID] = Storage(object);
        return outID;
    }
    
    void Remove(ObjectID object) {
        spacesStack[--stackPointer] = object;
        storage[object].used = false;
    }
    
    bool Exists(ObjectID object){
        return storage[object].used;
    }
  
private:
    struct Storage {
        Storage():used(false){}
        Storage(T& data):element(data), used(true){}
        T element;
        bool used;        
    };
 
    Storage storage[MaxElements];
    ObjectID spacesStack[MaxElements]; 
    unsigned int stackpointer;
};