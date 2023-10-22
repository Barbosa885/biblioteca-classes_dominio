/**
 * @file Email.h
 * @brief Definição da classe Email.
 *
 * Esta classe representa um endereço de e-mail válido, seguindo os critérios de formato definidos.
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
     * @brief Define o endereço de e-mail.
     *
     * @param email O endereço de e-mail a ser definido.
     * @throw invalid_argument Se o endereço de e-mail não atender aos critérios de formato.
     */
    void setEmail(const string& email);

    /**
     * @brief Obtém o endereço de e-mail.
     *
     * @return Um objeto stringstream contendo o endereço de e-mail válido.
     */
    const stringstream& getEmail() const;

    /**
     * @brief Destrutor da classe Email.
     */
    virtual ~Email();

private:
    stringstream email; /**< Objeto stringstream contendo o endereço de e-mail válido. */

    /**
     * @brief Valida se o endereço de e-mail atende aos critérios de formato.
     *
     * @param email O endereço de e-mail a ser validado.
     * @throw invalid_argument Se o endereço de e-mail não atender aos critérios de formato.
     */
    void isValid(const string& email);
};

inline const stringstream& Email::getEmail() const
{
    return email;
}

#endif // EMAIL_H
