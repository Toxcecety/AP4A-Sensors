/**
 * @author Céliane ALLAIRE
 * @file Pression.hpp
 * @date 28/09/2022
 * @brief Classe pour le sensor pression
 * */

//
//Define guards
#ifndef PRESSION_H
#define PRESSION_H
#include "../Sensor.hpp"


/**
 * @class Pression
 * @brief
 */
class Pression : public Sensor<int>
{
public:
  Pression();
  Pression(const Pression& press_p);
  Pression& operator=(const Pression& press_p);
  virtual ~Pression();

  /**
   * Fonction qui génère une valeur aléatoire pour notre sensor
   */
  void aleaGenVal();

  /**
   * Fonction qui récupère la valeur stockée dans le sensor
   * @return la valeur stockée dans m_data
   */
  int getData();
};


#endif  // PRESSION_H