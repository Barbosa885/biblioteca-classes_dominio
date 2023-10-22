/**
 * @file Codigo.h
 * @brief Definição da classe Codigo.
 *
 * Esta classe representa um código válido, seguindo os critérios de formato definidos.
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
     * @brief Define o código.
     *
     * @param codigo O código a ser definido.
     * @throw invalid_argument Se o código não atender aos critérios de formato.
     */
    void setCodigo(const string& codigo);

    /**
     * @brief Obtém o código.
     *
     * @return O código válido.
     */
    const string& getCodigo() const;

    /**
     * @brief Destrutor da classe Codigo.
     */
    virtual ~Codigo();

private:
    string codigo; /**< O código válido seguindo o formato definido. */

    /**
     * @brief Valida se o código atende aos critérios de formato.
     *
     * @param codigo O código a ser validado.
     * @throw invalid_argument Se o código não atender aos critérios de formato.
     */
    void isValid(const string& codigo);
};

inline const string& Codigo::getCodigo() const
{
    return codigo;
}

#endif // CODIGO_H
