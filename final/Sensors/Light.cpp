/**
 * @author Céliane ALLAIRE
 * @file Light.cpp
 * @date 28/09/2022
 * @brief Classe pour le sensor lumière
 * */


#include "Light.hpp"

Light::Light()
{
  this->m_file = "LIGHT.txt";
  this->m_unite = " ";
  this->m_maxData = true;
  this->m_minData = false;
  this->m_freq = 0;
  this->m_data = 0;
}

Light::Light(const Light &light_p) : Sensor<bool>(light_p){};

Light& Light::operator=(const Light &light_p)
{
  this->m_data = light_p.m_data;
  this->m_minData = light_p.m_minData;
  this->m_maxData = light_p.m_maxData;
  this->m_unite = light_p.m_unite;
  this->m_file = light_p.m_file;
  this->m_freq = light_p.m_freq;
  return *this;
}

Light::~Light() = default;

/**
 * Fonction qui génère une valeur aléatoire pour notre sensor
 */
void Light::aleaGenVal()
{
  this->m_data = rand()%2;
}

/**
 * Fonction qui récupère la valeur stockée dans le sensor
 * @return la valeur stockée dans m_data
 */
bool Light::getData() {
  return this->m_data;
}


