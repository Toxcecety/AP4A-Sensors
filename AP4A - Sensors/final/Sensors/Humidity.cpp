/**
 * @author Céliane ALLAIRE
 * @file Humidity.cpp
 * @date 28/09/2022
 * @brief Classe pour le sensor humidité
 * */

#include "Humidity.hpp"

Humidity::Humidity()
{
  this->m_file = "HUMIDITY.txt";
  this->m_unite = "%";
  this->m_maxData = 60;
  this->m_minData = 40;
  this->m_freq = 0;
  this->m_data = 0;
}

Humidity::Humidity(const Humidity &hum_p) : Sensor<float>(hum_p) {};

Humidity& Humidity::operator=(const Humidity &hum_p)
{
  this->m_data = hum_p.m_data;
  this->m_minData = hum_p.m_minData;
  this->m_maxData = hum_p.m_maxData;
  this->m_unite = hum_p.m_unite;
  this->m_file = hum_p.m_file;
  this->m_freq = hum_p.m_freq;
  return *this;
}

Humidity::~Humidity() = default;


