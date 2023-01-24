/**
 * @author Céliane ALLAIRE
 * @file main.cpp
 * @date 04/10/2022
 * @brief
 * */

#include <iostream>
#include "Scheduler.hpp"

int main()
{
  Scheduler sched; //On crée notre objet sched pour pouvoir ensuite démarrer la simulation
  sched.startSimulation();
  return 0;
}
