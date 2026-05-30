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
    int length = 0;
    while (true) {
        int steps = 0;
        do {
            current = current->prev;
            countOp++;
            steps++;
        } while (!current->light);
        current->light = false;
        for (int i = 0; i < steps; i++) {
            current = current->next;
            countOp++;
        }
        if (!first->light) {
            length = steps;
            break;
        }
    }
    return length;
}
int Train::getOpCount() {
    return countOp;
}
