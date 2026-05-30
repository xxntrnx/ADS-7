// Copyright 2022 NNTU-CS
#include "train.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  srand(time(0));
  for (int n = 2; n <= 50; n += 2) {
    Train train1;
    int count = n;
    while (count--)
      train1.addCar(false);
    train1.getLength();
    Train train2;
    count = n;
    while (count--)
      train2.addCar(true);
    train2.getLength();
    Train train3;
    count = n;
    while (count--)
      train3.addCar(rand() % 2);
    train3.getLength();
    std::cout << n << "\t" << train1.getOpCount() << "\t\t"
              << train2.getOpCount() << "\t\t" << train3.getOpCount() << std::endl;
  }
  return 0;
}
