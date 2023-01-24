/**
 * @author Céliane ALLAIRE
 * @file Light.hpp
 * @date 28/09/2022
 * @brief Classe pour le sensor lumière
 * */

//
//Define guards
#ifndef LIGHT_H
#define LIGHT_H
#include "../Sensor.hpp"


/**
 * @class Light
 * @brief
 */
class Light : public Sensor<bool>
{
public:
  Light();
  Light(const Light& light_p);
  Light& operator=(const Light& light_p);
  virtual ~Light();

  /**
   * Fonction qui génère une valeur aléatoire pour notre sensor
   */
  void aleaGenVal();

  /**
   * Fonction qui récupère la valeur stockée dans le sensor
   * @return la valeur stockée dans m_data
   */
  bool getData();
};


#endif  // LIGHT_H