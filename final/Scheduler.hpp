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
  int m_chrono; //Notre chronomètre
public:
// Definition de la forme canonique
  Scheduler(); //Constructeur pas défaut
  Scheduler(const Scheduler& s_p); //Constructeur par recopie
  Scheduler& operator=(const Scheduler& param_s); //Opérateur d'affectation
  ~Scheduler(); //Destructeur

  /**
   * Fonction qui demande à l'utilisateur la durée de la simulation
   */
  void askChrono();

  /**
   * Fonction qui demande à l'utilisateur à qu'elle fréquence il souhaite récuperer les données des sensors
   */
  void askIntervalle();

  /**
   * Fonction qui vide le fichier
   * @param file_p nom du fichier
   */
  void emptyLog(std::string file_p);

  /**
   * Utilisé pour lancer la simulation
   */
  void startSimulation();
};


#endif  // SCHEDULER_H
