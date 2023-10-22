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

/**
 * @file LIMITE.h
 * @brief Declaração da classe LIMITE.
 */

#include <string>
#include <stdexcept>

using namespace std;

class LIMITE {
private:
    int limite; /**< Variável que armazena o limite. */

    /**
     * @brief Verifica se um valor é válido como limite.
     * @param value O valor a ser verificado.
     */
    void isValid(int value);

public:

    /**
     * @brief Obtém o valor do limite.
     * @return O valor do limite.
     */
    int GetLimite();
};

/**
 * @brief Função inline para obter o valor do limite.
 * @return O valor do limite.
 */
inline int LIMITE::GetLimite() {
    return limite;
}

#endif // LIMITE_H
