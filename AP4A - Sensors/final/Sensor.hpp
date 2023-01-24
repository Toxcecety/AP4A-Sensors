/**
 * @author Céliane ALLAIRE
 * @file Sensor.hpp
 * @date 28/09/2022
 * @brief Classe qui gère les différents sensors
 * */

//
//Define guards
#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <unistd.h>

/**
 * @class Sensor
 * @brief classe sensor. Classe mère des différents sensors (ils sont dérivés de cette classe). On y génère les différentes données sur l'avion
 */
template<class T>
class Sensor
{
protected:
  T m_data; //la donnée aléatoire à fournir
  T m_minData;
  T m_maxData;
  std::string m_unite; //Contient unité
  std::string m_file; //Contient le nom du ficher où écrire les données
  int m_freq; //Fréquence à laquelle on récupere les informations du sensor

public:
  // Definition de la forme canonique
  Sensor<T>(); //Constructeur pas défaut
  Sensor<T>(const Sensor<T>& param_s); //Constructeur par recopie
  Sensor<T>& operator=(const Sensor<T>& param_s); //Opérateur d'affectation
  virtual ~Sensor<T>(); //Destructeur

  /**
   * Fonction qui génère une valeur aléatoire pour notre sensor
   */
  virtual void aleaGenVal();

  /**
   * Fonction qui retourne la valeur minimale que notre sensor peut prendre
   * @return la valeur stockée dans l'attribut m_minData
   */
  T getMinData();

  /**
   * Fonction qui retourne la valeur maximale que notre sensor peut prendre
   * @return la valeur stockée dans l'attribut m_maxData
   */
  T getMaxData();

  /**
   * Fonction qui retourne la valeur stockée dans notre sensor
   * @return la valeur stockée dans l'attribut m_data
   */
  T getData();

  /**
   * Fonction qui retourne l'unité du sensor
   * @return la valeur stockée dans l'attribut m_unite
   */
  std::string getUnite();

  /**
   * Fonction qui retourne le nom du fichier où on écrit les données du sensor
   * @return la valeur stockée dans l'attribut m_unite
   */
  std::string getFile();

  /**
   * Fonction qui retourne la fréquence à laquelle on récupère les données de notre sensor
   * @return la valeur stockée dans l'attribut m_freq
   */
  int getFreq();

  /**
   * Fonction qui modifie la valeur minimale et la valeur maximale que peut prendre notre sensor
   * @param min_p valeur minimale que peut prendre notre sensor
   * @param max_p valeur maximale que peut prendre notre sensor
   */
  void setMinMax(T min_p, T max_p);

  /**
   * Fonction qui modifie la valeur minimale que peut prendre notre sensor
   * @param min_p valeur minimale que peut prendre notre sensor
   */
  void setMin(T min_p);

  /**
   * Fonction qui maximale la valeur minimale que peut prendre notre sensor
   * @param max_p valeur maximale que peut prendre notre sensor
   */
  void setMax(T max_p);

  /**
   * Fonction qui modifie la valeur que peut prendre notre sensor
   * @param data_p donnée contenu dans notre sensor
   */
  void setData(T data_p);

  /**
   * Fonction qui modifie l'unité de notre sensor
   * @param unite_p unité de notre sensor
   */
  void setUnite(std::string unite_p);

  /**
   * Fonction qui modifie le nom de fichier de notre sensor
   * @param file_p fichier de notre sensor
   */
  void setFile(std::string file_p);

  /**
   * Fonction qui modifie la fréquence à laquelle on récupère les données de notre sensor
   * @param freq_p fréquence de notre sensor
   */
  void setFreq();

};

template<typename T>
Sensor<T>::Sensor()
{
  this->m_minData = 0;
  this->m_maxData = 0;
  this->m_data = 0;
  this->m_file = "empty";
  this->m_unite = " ";
  this->m_freq = 0;
}

template<typename T>
Sensor<T>::Sensor(const Sensor<T>& param_s)
{
  this->m_maxData = param_s.m_maxData;
  this->m_minData = param_s.m_minData;
  this->m_data = param_s.m_data;
  this->m_unite = param_s.m_unite;
  this->m_file = param_s.m_file;
  this->m_freq = param_s.m_freq;
}

template<typename T>
Sensor<T>& Sensor<T>::operator=(const Sensor<T>& param_s)
{
  this->m_maxData = param_s.m_maxData;
  this->m_minData = param_s.m_minData;
  return *this;
}

template<typename T>
Sensor<T>::~Sensor<T>() = default;

template<typename T>
void Sensor<T>::aleaGenVal()
{
  this->m_data = m_minData + static_cast<float> (rand()) /(static_cast <float> (RAND_MAX/(m_maxData - m_minData)));
}

template<typename T>
T Sensor<T>::getData()
{
  return this->m_data;
}

template<typename T>
T Sensor<T>::getMinData()
{
  return this->m_minData;
}

template<typename T>
T Sensor<T>::getMaxData()
{
  return this->m_maxData;
}

template<typename T>
std::string Sensor<T>::getUnite()
{
  return this->m_unite;
}

template<typename T>
std::string Sensor<T>::getFile()
{
  return this->m_file;
}

template<typename T>
int Sensor<T>::getFreq()
{
  return this->m_freq;
}

template<typename T>
void  Sensor<T>::setMinMax(T min_p, T max_p)
{
  this->m_minData = min_p;
  this->m_maxData = max_p;
}

template<typename T>
void Sensor<T>::setMin(T min_p)
{
  this->m_minData = min_p;
}

template<typename T>
void Sensor<T>::setMax(T max_p)
{
  this->m_maxData = max_p;
}

template<typename T>
void Sensor<T>::setData(T data_p)
{
  this->m_data = data_p;
}

template<typename T>
void Sensor<T>::setUnite(std::string unite_p)
{
  this->m_unite = unite_p;
}

template<typename T>
void Sensor<T>::setFile(std::string file_p)
{
  this->m_file = file_p;
}

template<typename T>
void Sensor<T>::setFreq()
{
  while (this->m_freq <= 0)
  {
    std::cout << "Veuillez entrer à qu'elle fréquence vous souhaitez récuperer les données du sensor ";
    std::cout << this->m_file << std::endl;
    std::cin >> this->m_freq;
    fflush(stdin);
  }
}

#endif  // SENSOR_H