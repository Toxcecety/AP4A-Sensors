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
   * Writes the data that we've gathered in our file
   * @param hum_p
   * @param light_p
   * @param press_p
   * @param temp_p
   */
  void fileWrite(const int hum_p, const int light_p, const int press_p, const int temp_p);

  /**
   * Writes the data that we've gathered in our console
   * @param hum_p
   * @param light_p
   * @param press_p
   * @param temp_p
   */
  void consolWrite(const int hum_p, const int light_p, const int press_p, const int temp_p);

  /**
   * Used to find out if the user wishes to write data in the console
   * @return
   */
  bool getConsolActiv();

  /**
   * Used to find out if the user wishes to write data in the log file
   * @return
   */
  bool getLogActiv();

  /**
   * Used to modify m_consolActivation
   */
  void setConsolActiv(bool b_p);

  /**
   * Used to modify m_logActivation
   */
  void setLogActiv(bool b_p);

};


#endif  // SERVER_H