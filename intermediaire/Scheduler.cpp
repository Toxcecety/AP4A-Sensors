/**
 * @author Céliane ALLAIRE
 * @file Scheduler.cpp
 * @date 28/09/2022
 * @brief Classe qui gère les requêtes de l'utilisateur et assure la communication avec les différentes classes
 * */

#include "Scheduler.hpp"
#include <iostream>
#include <ctime>
#include <windows.h>
#include <unistd.h>
#include <fstream>

using namespace std;

Scheduler::Scheduler() : m_hum(), m_light(), m_press(), m_temp(), m_serv(), m_interval(), m_chrono(){};

Scheduler::Scheduler(const Scheduler& s_p) : m_hum(s_p.m_hum), m_light(s_p.m_light), m_press(s_p.m_press), m_temp(s_p.m_temp), m_serv(s_p.m_serv), m_interval(s_p.m_interval), m_chrono(s_p.m_chrono){};

Scheduler::~Scheduler() = default;

Scheduler& Scheduler::operator=(const Scheduler &param_s)
{
  this->m_serv = param_s.m_serv;
  this->m_interval = param_s.m_interval;
  this->m_chrono = param_s.m_chrono;
  this->m_temp = param_s.m_temp;
  this->m_press = param_s.m_press;
  this->m_light = param_s.m_light;
  this->m_hum = param_s.m_hum;
  return *this;
}

/**
 * Randomizes the values of the different sensors
 */
void Scheduler::aleaSensors()
{
  this->m_hum.aleaGenVal();
  this->m_press.aleaGenVal();
  this->m_light.aleaGenVal();
  this->m_temp.aleaGenVal();
}

/**
 * Sends Data to the Server and writes the data in the log and/or the file depending on the user's request
 */
void Scheduler::sendDataToServer()
{
  if(this->m_serv.getConsolActiv())
  {
    this->m_serv.consolWrite(this->m_hum.getData(), this->m_light.getData(), this->m_press.getData(), this->m_temp.getData());
  }
  if (this->m_serv.getLogActiv()){
    this->m_serv.fileWrite(this->m_hum.getData(), this->m_light.getData(), this->m_press.getData(), this->m_temp.getData());
  }
}

/**
 * Used to start our simulation
 */
void Scheduler::startSimulation()
{
  //Initialisation et création de notre horloge et nos sensors
  this->m_hum.setMinMax(0,100);
  this->m_light.setMinMax(0, 100);
  this->m_press.setMinMax(0, 100);
  this->m_temp.setMinMax(0, 100);
  bool ans;

  cout << "==== BIENVENUE DANS LA SIMULATION CAPTEURS ====" << endl;
  while (this->m_chrono <= 0) //Boucle pour vérifier que notre valeur entrée est positive et non NULL
    {
      cout << "Veuillez entrer la duree souhaitee de la simulation [en secondes] :" << endl;
      cin >> this->m_chrono;
    }
  while (this->m_interval <= 0)
    {
      cout << "Veuillez entrer a qu'elle frequence vous souhaitez recuperer les informations des capteurs [en secondes] :" << endl;
      cin >> this->m_interval;
    }
    cout << "Souhaitez vous afficher les donnees dans la console? [1: oui // 0:non]" << endl;
    cin >> ans;
    this->m_serv.setConsolActiv(ans);
    cout << "Souhaitez vous afficher les donnees dans le log? [1: oui // 0:non]" << endl;
    cin >> ans;
    this->m_serv.setLogActiv(ans);

    cout << "=== Lancement de la simulation ===" << endl;

    //Si l'utilisateur souhaite enregistrer les données dans le log il faut d'abord vider les données de la simulation précédente
    if(this->m_serv.getLogActiv())
    {
      ofstream file("log.txt", ofstream::out | ofstream::trunc);
      file.close();
    }

    //Cette boucle garantie que la simulation dure le temps souhaitée
    while (this->m_chrono - this->m_interval >= 0 ) //On continue uniquement la simulation si il nous reste assez de temps
    {
      aleaSensors(); //On donne des valeurs aléatoires à nos sensors
      sendDataToServer(); //Nous envoyons les données au server
      sleep(this->m_interval); //Nous attendons la periode de temps indiqué par l'utilisateur
      //usleep(this->m_interval); //à utiliser si on est sur Unix et non windows
      this->m_chrono = this->m_chrono - this->m_interval; //mettre à jour le chrono à la fin de la boucle
    }
}


