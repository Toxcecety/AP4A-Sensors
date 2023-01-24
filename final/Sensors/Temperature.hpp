/**
 * @author Céliane ALLAIRE
 * @file Temperature.hpp
 * @date 28/09/2022
 * @brief Classe pour le sensor température
 * */

//
//Define guards
#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "../Sensor.hpp"


/**
 * @class Temperature
 * @brief
 */
class Temperature : public Sensor<float>
{
public:
  Temperature();
  Temperature(const Temperature& temp_p);
  Temperature& operator=(const Temperature& temp_p);
  virtual ~Temperature();
};


#endif  // TEMPERATURE_H