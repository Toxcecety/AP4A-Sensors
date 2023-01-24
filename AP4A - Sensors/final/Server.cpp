/**
 * @author Céliane ALLAIRE
 * @file Server.cpp
 * @date 28/09/2022
 * @brief Classe qui gère l'écriture des données des sensors dans le log et dans la console
 * */

#include "Server.hpp"
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
 * Utilisé pour savoir si l'utilisateur souhaite écrire les données dans la console
 * @return attribut m_consolActivation
 */
bool Server::getConsolActiv()
{
  return this->m_consolActivation;
}

/**
 * Utilisé pour savoir si l'utilisateur souhaite écrire les données dans un fichier
 * @return attribut m_logActivation
 */
bool Server::getLogActiv()
{
  return this->m_logActivation;
}

/**
 * Utilisé pour modifier la valeur de m_consolActivation
 */
void Server::setConsolActiv(bool b_p)
{
  this->m_consolActivation = b_p;
}

/**
 * Utilisé pour modifier la valeur de m_logActivation
 */
void Server::setLogActiv(bool b_p)
{
  this->m_logActivation = b_p;
}


