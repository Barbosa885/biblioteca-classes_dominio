/**
 * @file Limite.h
 * @brief Definição da classe Limite.
 *
 * @brief Classe que representa um limite.
 *
 * Autor: Hideki Tomiyama (190014351)
 */

#ifndef LIMITE_H
#define LIMITE_H

#include <string>
#include <stdexcept>

using namespace std;

class Limite 
{
private:
    int limite; /**< Variável que armazena o limite. */
    void isValid(const int &value);
    /**
     * @brief Verifica se um valor é válido como limite.
     * @param value O valor a ser verificado.
     */

public:
    Limite(); /**< Construtor padrão da classe. */
    virtual ~Limite(); /**< Destrutor padrão da classe. */
    /**
     * @brief Obtém o valor do limite.
     * @return O valor do limite.
     */
    void setLimite(const int &value);
    const int &getLimite() const;

};

/**
 * @brief Função inline para obter o valor do limite.
 * @return O valor do limite.
 */
inline const int &Limite::getLimite() const
{
    return limite;
}

#endif // LIMITE_H
