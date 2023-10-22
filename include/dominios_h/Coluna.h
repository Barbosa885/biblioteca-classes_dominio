/**
 * @file Coluna.h
 * @brief Definição da classe Coluna.
 *
 * Autor: Hideki Tomiyama (190014351)
 */

#ifndef COLUNA_H
#define COLUNA_H

#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class COLUNA
 * Uma classe que representa uma coluna de dados.
 */
class COLUNA{
    private:
        string coluna;
        void isValid(string);
        /** 
        * verifica se a coluna atende a critérios específicos.
        * @param a coluna verificada.
        * saída: "argumento inválido" caso a coluna não atenda a um dos críterios estabelecidos.
        */
        
    public:
        /**
        * obtem a coluna;
        * retorna essa coluna.
        */
        string GetColuna();
};

inline string COLUNA::GetColuna(){
    return coluna;
}

#endif // COLUNA_H
