/**
 * @file Coluna.h
 * @brief Definição da classe Coluna.
 *
 * @brief Uma classe que representa uma coluna de dados.
 *
 * Autor: Hideki Tomiyama (190014351)
 */

#ifndef COLUNA_H
#define COLUNA_H

#include <string>
#include <stdexcept>

using namespace std;

class Coluna
{
private:
    string coluna;
    void isValid(const string &coluna);
    /**
     * verifica se a coluna atende a critérios específicos.
     * @param a coluna verificada.
     * saída: "argumento inválido" caso a coluna não atenda a um dos críterios estabelecidos.
     */

public:
    Coluna();          /**< Construtor */
    virtual ~Coluna(); /**< Destrutor */
    /**
     * obtem a coluna;
     * retorna essa coluna.
     */
    const string &getColuna() const;
    void setColuna(const string &coluna);
};

inline const string &Coluna::getColuna() const
{
    return coluna;
}

#endif // COLUNA_H
