/**
 * @author Céliane ALLAIRE
 * @file Server.cpp
 * @date 28/09/2022
 * @brief Classe qui gère l'écriture des données des sensors dans le log et dans la console
 * */

#include "Server.hpp"
#include "Sensors/Humidity.cpp"
#include "Sensors/Light.cpp"
#include "Sensors/Pression.cpp"
#include "Sensors/Temperature.cpp"
#include <iostream>
#include <fstream>
using namespace std;

Server::Server() : m_consolActivation(), m_logActivation(){};

Server::Server(const Server& param_s):m_consolActivation(param_s.m_consolActivation), m_logActivation(param_s.m_logActivation){};

Server::~Server() = default;

Server& Server::operator=(const Server &param_s)
{
  this->m_consolActivation = param_s.m_consolActivation;
  this->m_logActivation = param_s.m_logActivation;
  return *this;
}

/**
 * Writes the data that we've gathered in our file
 * @param hum_p
 * @param light_p
 * @param press_p
 * @param temp_p
 */
void Server::fileWrite(const int hum_p, const int light_p, const int press_p, const int temp_p)
{
  std::ofstream  file;
  file.open("log.txt", ios::app);
  if (file.is_open())
  {
    file << "==== ENREGISTREMENT ====" << endl;
    file << "Humidity : " << hum_p << " %" << endl;
    file << "Light : " << light_p << " cd" << endl;
    file << "Pression : " << press_p << " Pa" << endl;
    file << "Temperature : " << temp_p << " k" << endl;
    file << "========================" << endl;
    file.close();
  } else {
    cout << "Failed to open file" << endl;
  }
}

/**
 * Writes the data that we've gathered in our console
 * @param hum_p
 * @param light_p
 * @param press_p
 * @param temp_p
 */
void Server::consolWrite(const int hum_p, const int light_p, const int press_p, const int temp_p)
{
  cout << "==== ENREGISTREMENT ====" << endl;
  cout << "Humidity : " << hum_p << " %" << endl;
  cout << "Light : " << light_p << " cd" << endl;
  cout << "Pression : " << press_p << " Pa" << endl;
  cout << "Temperature : " << temp_p << " k" << endl;
  cout << "========================" << endl;
}

/**
 * Used to find out if the user wishes to write data in the console
 * @return
 */
bool Server::getConsolActiv()
{
  return this->m_consolActivation;
}

/**
 * Used to find out if the user wishes to write data in the log file
 * @return
 */
bool Server::getLogActiv()
{
  return this->m_logActivation;
}

/**
 * Used to modify m_consolActivation
 */
void Server::setConsolActiv(bool b_p)
{
  this->m_consolActivation = b_p;
}

/**
 * Used to modify m_logActivation
 */
void Server::setLogActiv(bool b_p)
{
  this->m_logActivation = b_p;
}


