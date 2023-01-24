/**
 * @author Céliane ALLAIRE
 * @file Temperature.cpp
 * @date 28/09/2022
 * @brief Classe pour le sensor température
 * */

#include "Temperature.hpp"

Temperature::Temperature()
{
  this->m_file = "TEMPERATURE.txt";
  this->m_unite = "K";
  this->m_maxData = 295;
  this->m_minData = 291;
  this->m_freq = 0;
}

Temperature::Temperature(const Temperature &temp_p) : Sensor<float>(temp_p){};

Temperature& Temperature::operator=(const Temperature &temp_p)
{
  this->m_data = temp_p.m_data;
  this->m_minData = temp_p.m_minData;
  this->m_maxData = temp_p.m_maxData;
  this->m_unite = temp_p.m_unite;
  this->m_file = temp_p.m_file;
  this->m_freq = temp_p.m_freq;
  return *this;
}

Temperature::~Temperature() = default;

