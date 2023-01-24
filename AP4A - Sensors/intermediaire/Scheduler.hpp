/**
 * @author Céliane ALLAIRE
 * @file Scheduler.hpp
 * @date 28/09/2022
 * @brief Classe qui gère les requêtes de l'utilisateur et assure la communication avec les différentes classes
 * */

//
//Define guards
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Sensor.hpp"
#include "Server.hpp"

/**
 * @class Scheduler
 * @brief classe scheduler. Gère l'envoi régulier des données des différents sensors jusqu'au server.
 */
class Scheduler
{
private:
  Humidity m_hum;
  Light m_light;
  Pression m_press;
  Temperature m_temp;
  Server m_serv;
  int m_interval; //Utilisé pour définir l'intervale de temps entre chaque récolte de données
  int m_chrono; //Notre chronomètre
public:
// Definition de la forme canonique
  Scheduler(); //Constructeur pas défaut
  Scheduler(const Scheduler& s_p); //Constructeur par recopie
  Scheduler& operator=(const Scheduler& param_s); //Opérateur d'affectation
  ~Scheduler(); //Destructeur

  /**
   * Randomizes the values of the different sensors
  */
  void aleaSensors();

  /**
   * Sends Data to the Server and writes the data in the log and/or the file depending on the user's request
   */
  void sendDataToServer();

  /**
   * Used to start our simulation
   */
  void startSimulation();
};


#endif  // SCHEDULER_H
