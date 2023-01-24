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

/**
 * @class Sensor
 * @brief classe sensor. Classe mère des différents sensors (ils sont dérivés de cette classe). On y génère les différentes données sur l'avion
 */
class Sensor
{
private:
  int m_data; //la donnée aléatoire à fournir
  int m_minData;
  int m_maxData;
public:
// Definition de la forme canonique
  Sensor(); //Constructeur pas défaut
  Sensor(const Sensor& param_s); //Constructeur par recopie
  Sensor& operator=(const Sensor& param_s); //Opérateur d'affectation
  ~Sensor(); //Destructeur

  /**
   * Fonction qui génère une valeur aléatoire pour notre sensor
   */
    void aleaGenVal();

  /**
   * Fonction qui récupère la valeur stockée dans notre sensor
   * @return la valeur stockée dans l'attribut m_data
   */
  int getData();

  /**
   * Fonction qui modifie la valeur minimale et la valeur maximale que peut prendre notre sensor
   * @param min_p valeur minimale que peut prendre notre sensor
   * @param max_p valeur maximale que peut prendre notre sensor
   */
  void setMinMax(int min_p, int max_p);
};

#endif  // SENSOR_H