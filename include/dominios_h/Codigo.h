/**
 * @file Codigo.h
 * @brief Defini��o da classe Codigo.
 *
 * Esta classe representa um c�digo v�lido, seguindo os crit�rios de formato definidos.
 *
 * Autor: Gustavo Barbosa (202037589)
 */

#ifndef CODIGO_H
#define CODIGO_H

#include <string>

using namespace std;

class Codigo
{
public:
    /**
     * @brief Construtor da classe Codigo.
     */
    Codigo();

    /**
     * @brief Define o c�digo.
     *
     * @param codigo O c�digo a ser definido.
     * @throw invalid_argument Se o c�digo n�o atender aos crit�rios de formato.
     */
    void setCodigo(const string& codigo);

    /**
     * @brief Obt�m o c�digo.
     *
     * @return O c�digo v�lido.
     */
    const string& getCodigo() const;

    /**
     * @brief Destrutor da classe Codigo.
     */
    virtual ~Codigo();

private:
    string codigo; /**< O c�digo v�lido seguindo o formato definido. */

    /**
     * @brief Valida se o c�digo atende aos crit�rios de formato.
     *
     * @param codigo O c�digo a ser validado.
     * @throw invalid_argument Se o c�digo n�o atender aos crit�rios de formato.
     */
    void isValid(const string& codigo);
};

inline const string& Codigo::getCodigo() const
{
    return codigo;
}

#endif // CODIGO_H
