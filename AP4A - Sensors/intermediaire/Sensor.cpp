/**
 * @author Céliane ALLAIRE
 * @file Sensor.cpp
 * @date 28/09/2022
 * @brief Classe qui gère les différents sensors
 * */

#include "Sensor.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Sensor::Sensor() : m_data(), m_minData(), m_maxData(){} //Constructeur pas défaut

Sensor::Sensor(const Sensor& param_s) : m_data(param_s.m_data), m_minData(param_s.m_minData), m_maxData(param_s.m_maxData){}

Sensor::~Sensor() = default;

Sensor& Sensor::operator=(const Sensor &param_s)
{
  this->m_data = param_s.m_data;
  this->m_maxData = param_s.m_maxData;
  this->m_minData = param_s.m_minData;
  return *this;
}

/**
 * Fonction qui génère une valeur aléatoire pour notre sensor
 */
void Sensor::aleaGenVal()
{
  this->m_data = (rand()%m_maxData)+m_minData;
}

/**
 * Fonction qui récupère la valeur stockée dans notre sensor
 * @return la valeur stockée dans l'attribut m_data
 */
int Sensor::getData()
{
  return this->m_data;
}

/**
 * Fonction qui modifie la valeur minimale et la valeur maximale que peut prendre notre sensor
 * @param min_p valeur minimale que peut prendre notre sensor
 * @param max_p valeur maximale que peut prendre notre sensor
 */
void Sensor::setMinMax(int min_p, int max_p)
{
  this->m_minData = min_p;
  this->m_maxData = max_p;
}
