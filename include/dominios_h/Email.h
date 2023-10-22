/**
 * @file Email.h
 * @brief Defini��o da classe Email.
 *
 * Esta classe representa um endere�o de e-mail v�lido, seguindo os crit�rios de formato definidos.
 *
 * Autor: Gustavo Barbosa (202037589)
 */

#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <sstream>

using namespace std;

class Email
{
public:
    /**
     * @brief Construtor da classe Email.
     */
    Email();

    /**
     * @brief Define o endere�o de e-mail.
     *
     * @param email O endere�o de e-mail a ser definido.
     * @throw invalid_argument Se o endere�o de e-mail n�o atender aos crit�rios de formato.
     */
    void setEmail(const string& email);

    /**
     * @brief Obt�m o endere�o de e-mail.
     *
     * @return Um objeto stringstream contendo o endere�o de e-mail v�lido.
     */
    const stringstream& getEmail() const;

    /**
     * @brief Destrutor da classe Email.
     */
    virtual ~Email();

private:
    stringstream email; /**< Objeto stringstream contendo o endere�o de e-mail v�lido. */

    /**
     * @brief Valida se o endere�o de e-mail atende aos crit�rios de formato.
     *
     * @param email O endere�o de e-mail a ser validado.
     * @throw invalid_argument Se o endere�o de e-mail n�o atender aos crit�rios de formato.
     */
    void isValid(const string& email);
};

inline const stringstream& Email::getEmail() const
{
    return email;
}

#endif // EMAIL_H
