/**
 * @author Céliane ALLAIRE
 * @file Pression.cpp
 * @date 28/09/2022
 * @brief Classe pour le sensor pression
 * */

#include "Pression.hpp"

Pression::Pression()
{
  this->m_file = "PRESSION.txt";
  this->m_unite = "kPa";
  this->m_maxData = 76;
  this->m_minData = 82;
  this->m_freq =0;
}

Pression::Pression(const Pression &press_p) : Sensor<int>(press_p){};

Pression& Pression::operator=(const Pression &press_p)
{
  this->m_data = press_p.m_data;
  this->m_minData = press_p.m_minData;
  this->m_maxData = press_p.m_maxData;
  this->m_unite = press_p.m_unite;
  this->m_file = press_p.m_file;
  this->m_freq = press_p.m_freq;
  return *this;
}

Pression::~Pression() = default;

/**
 * Fonction qui génère une valeur aléatoire pour notre sensor
 */
void Pression::aleaGenVal()
{
  this->m_data = (rand()%m_maxData)+m_minData;
}

/**
 * Fonction qui récupère la valeur stockée dans le sensor
 * @return la valeur stockée dans m_data
 */
int Pression::getData() {
  return this->m_data;
}

