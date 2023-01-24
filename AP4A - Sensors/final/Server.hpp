/**
 * @author Céliane ALLAIRE
 * @file Server.hpp
 * @date 28/09/2022
 * @brief Classe qui gère l'écriture des données des sensors dans le log et dans la console
 * */

//
//Define guards
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>
#include "Sensors/Humidity.hpp"
#include "Sensors/Light.hpp"
#include "Sensors/Pression.hpp"
#include "Sensors/Temperature.hpp"


/**
 * @class Server
 * @brief classe server. Gère la réception et l'enregistrement des données des différents capteurs dans la console et un fichier
 */

class Server
{
private:
  bool m_consolActivation; //Nous indique si l'écriture dans la console est activé
  bool m_logActivation; //Nous indique si l'écriture dans le log est activé

public:
// Definition de la forme canonique
  Server(); //Constructeur pas défaut
  Server(const Server& param_s); //Constructeur par recopie
  Server& operator=(const Server& param_s); //Opérateur d'affectation
  ~Server(); //Destructeur

  /**
   * Note les informations de notre sensor dans un fichier
   * @param data_p la donnée de notre sensor
   * @param file_p le fichier de notre sensor
   * @param unite_p l'unité de notre sensor
   */
  template<typename T>
  void fileWrite(const T data_p, const std::string &file_p, const std::string &unite_p);

  /**
   * Note les informations de notre sensor dans la console
   * @param data_p la donnée de notre sensor
   * @param file_p nom du fichier de notre sensor
   * @param unite_p l'unité de notre sensor
   */
  template<typename T>
  void consolWrite(const T data_p, const std::string &file_p, const std::string &unite_p);

  /**
   * Utilisé pour savoir si l'utilisateur souhaite écrire les données dans la console
   * @return attribut m_consolActivation
   */
  bool getConsolActiv();

  /**
   * Utilisé pour savoir si l'utilisateur souhaite écrire les données dans un fichier
   * @return attribut m_logActivation
   */
  bool getLogActiv();

  /**
   * Utilisé pour modifier la valeur de m_consolActivation
   */
  void setConsolActiv(bool b_p);

  /**
   * Utilisé pour modifier la valeur de m_logActivation
   */
  void setLogActiv(bool b_p);

};


/**
 * Note les informations de notre sensor dans un fichier
 * @param data_p la donnée de notre sensor
 * @param file_p le fichier de notre sensor
 * @param unite_p l'unité de notre sensor
 */
template <typename T>
void Server::fileWrite(const T data_p, const std::string &file_p, const std::string &unite_p)
{
  if(this->m_logActivation)
  {
    std::ofstream  file;
    file.open(file_p, std::ios::app);
    if (file.is_open())
    {
      file << "==== ENREGISTREMENT ====" << std::endl;
      file <<  data_p << " " << unite_p << std::endl;
      file << "========================" << std::endl;
      file.close();
    } else {
      std::cout << "Failed to open file" << std::endl;
    }
  }
}

/**
 * Note les informations de notre sensor dans la console
 * @param data_p la donnée de notre sensor
 * @param file_p nom du fichier de notre sensor
 * @param unite_p l'unité de notre sensor
 */
template <typename T>
void Server::consolWrite(const T data_p, const std::string &file_p, const std::string &unite_p)
{
  if(this->m_consolActivation)
  {
    int i = 0;
    std::string str (".");
    std::cout << "==== ENREGISTREMENT ";
    while (file_p[i] != str[0])
    {
      std::cout << file_p[i];
      i++;
    }
    std::cout << " ===" << std::endl;
    std::cout << data_p << " " << unite_p << std::endl;
    std::cout << "========================" << std::endl;
  }
}


#endif  // SERVER_H