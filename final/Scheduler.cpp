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

Scheduler::Scheduler() : m_hum(), m_light(), m_press(), m_temp(), m_serv(), m_chrono(0){};

Scheduler::Scheduler(const Scheduler& s_p) : m_hum(s_p.m_hum), m_light(s_p.m_light), m_press(s_p.m_press), m_temp(s_p.m_temp), m_serv(s_p.m_serv), m_chrono(s_p.m_chrono){};

Scheduler::~Scheduler() = default;

Scheduler& Scheduler::operator=(const Scheduler &param_s)
{
  this->m_serv = param_s.m_serv;
  this->m_chrono = param_s.m_chrono;
  this->m_temp = param_s.m_temp;
  this->m_press = param_s.m_press;
  this->m_light = param_s.m_light;
  this->m_hum = param_s.m_hum;
  return *this;
}

/**
 * Fonction qui demande à l'utilisateur la durée de la simulation
 */
void Scheduler::askChrono()
{
  while (this->m_chrono <= 0) //Boucle pour vérifier que notre valeur entrée est positive et non NULL
  {
    cout << "Veuillez entrer la duree souhaitee de la simulation [en secondes] :" << endl;
    cin >> this->m_chrono;
    fflush(stdin);
  }
}

/**
 * Fonction qui demande à l'utilisateur à qu'elle fréquence il souhaite récuperer les données des sensors
 */
void Scheduler::askIntervalle()
{
  this->m_temp.setFreq();
  this->m_press.setFreq();
  this->m_hum.setFreq();
  this->m_light.setFreq();
}

/**
 * Fonction qui vide le fichier
 * @param file_p nom du fichier
 */
void Scheduler::emptyLog(string file_p)
{
  ofstream file(file_p, ofstream::out | ofstream::trunc);
  file.close();
}

/**
 * Utilisé pour lancer la simulation
 */
void Scheduler::startSimulation()
{
  bool ans;
  float int_hum, int_light, int_press, int_temp;
  clock_t time_start;

  cout << "==== BIENVENUE DANS LA SIMULATION CAPTEURS ====" << endl;
  askChrono();
  cout << "Souhaitez vous afficher les donnees dans la console? [1: oui // 0:non]" << endl;
  cin >> ans;
  this->m_serv.setConsolActiv(ans);
  cout << "Souhaitez vous afficher les donnees dans le log? [1: oui // 0:non]" << endl;
  cin >> ans;
  this->m_serv.setLogActiv(ans);
  cout << "Pour chaque capteur veuillez entrer à qu'elle fréquence vous souhaitez enregistrer leurs valeurs" << endl;
  askIntervalle();
  //Si l'utilisateur souhaite enregistrer les données dans le log il faut d'abord vider les données de la simulation précédente
  if(this->m_serv.getLogActiv())
  {
    emptyLog(m_hum.getFile());
    emptyLog(m_light.getFile());
    emptyLog(m_press.getFile());
    emptyLog(m_temp.getFile());
  }
  cout << "=== Lancement de la simulation ===" << endl;
  //On prends le temps de début de notre simulation pour pouvoir suivre la durée de notre simulation
  time_start = (clock()/CLOCKS_PER_SEC);
  //On commence notre boucle permettant l'envoi des différentes données
  while ((clock()/CLOCKS_PER_SEC - time_start) < this->m_chrono)
  {
    //Pour chaque sensor on effectue le modulo du temps écoulée depuis le début de notre simulation par le temps d'intervalle demandée par l'utilisateur
    if ((clock()/CLOCKS_PER_SEC - time_start) % this->m_temp.getFreq() == 0)
    {
      this->m_temp.aleaGenVal();
      this->m_serv.consolWrite(this->m_temp.getData(), this->m_temp.getFile(), this->m_temp.getUnite());
      this->m_serv.fileWrite(this->m_temp.getData(), this->m_temp.getFile(), this->m_temp.getUnite());
    }
    if ((clock()/CLOCKS_PER_SEC - time_start) % this->m_hum.getFreq() == 0)
    {
      this->m_hum.aleaGenVal();
      this->m_serv.consolWrite(this->m_hum.getData(), this->m_hum.getFile(), this->m_hum.getUnite());
      this->m_serv.fileWrite(this->m_hum.getData(), this->m_hum.getFile(), this->m_hum.getUnite());
    }
    if ((clock()/CLOCKS_PER_SEC - time_start) % this->m_light.getFreq() == 0)
    {
      this->m_light.aleaGenVal();
      this->m_serv.consolWrite(this->m_light.getData(), this->m_light.getFile(), this->m_light.getUnite());
      this->m_serv.fileWrite(this->m_light.getData(), this->m_light.getFile(), this->m_light.getUnite());
    }
    if ((clock()/CLOCKS_PER_SEC - time_start) % this->m_press.getFreq() == 0)
    {
      this->m_press.aleaGenVal();
      this->m_serv.consolWrite(this->m_press.getData(), this->m_press.getFile(), this->m_press.getUnite());
      this->m_serv.fileWrite(this->m_press.getData(), this->m_press.getFile(), this->m_press.getUnite());
    }
    sleep(1);
  }
  cout << "==== Fin Simulation  ====";
}


