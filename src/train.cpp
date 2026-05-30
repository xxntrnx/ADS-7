// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;
    
    if (first == nullptr) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (first == nullptr) return 0;
    
    countOp = 0;
    Car* current = first;
    
    current->light = true;
    int length = 1;
    
    while (true) {
        for (int i = 0; i < length; i++) {
            current = current->next;
            countOp++;
        }
        
        if (!current->light) {
            current->light = true;
            length++;
            for (int i = 0; i < length; i++) {
                current = current->prev;
                countOp++;
            }
        } 
        else {
            bool allLit = true;
            Car* check = first;
            for (int i = 0; i < length; i++) {
                if (!check->light) {
                    allLit = false;
                    break;
                }
                check = check->next;
            }
            if (allLit) {
                break;
            }
        }
    }
    
    return length;
}

int Train::getOpCount() {
    return countOp;
}
