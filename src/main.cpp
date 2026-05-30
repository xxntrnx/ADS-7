// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  std::srand(std::time(nullptr));
  for (int len = 2; len <= 50; len += 2) {
    Train offTrain;
    for (int i = 0; i < len; ++i)
      offTrain.addCar(false);
    offTrain.getLength();
    Train onTrain;
    for (int i = 0; i < len; ++i)
      onTrain.addCar(true);
    onTrain.getLength();
    Train randTrain;
    for (int i = 0; i < len; ++i)
      randTrain.addCar(std::rand() % 2);
    randTrain.getLength();
    std::cout << len << "\t"
              << offTrain.getOpCount() << "\t"
              << onTrain.getOpCount() << "\t"
              << randTrain.getOpCount() << std::endl;
  }
  return 0;
}
