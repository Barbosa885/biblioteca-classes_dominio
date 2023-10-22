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
        string coluna; /**< O nome da coluna. */

        /**
         * Verifica se uma string é válida para a coluna.
         * @param str A string a ser verificada.
         */
        void verifica(string str);
        
    public:
        /**
         * Obtém o nome da coluna.
         * @return O nome da coluna.
         */
        string GetColuna();

        /**
         * Define o nome da coluna após a verificação.
         * @param coluna O novo nome da coluna a ser definido.
         */
        void SetColuna(string coluna);
};

/**
 * Define o nome da coluna após a verificação.
 * @param coluna O novo nome da coluna a ser definido.
 */
inline void COLUNA::SetColuna(string coluna){
    verifica(coluna);
    this -> coluna = coluna;
}

/**
 * Obtém o nome da coluna.
 * @return O nome da coluna.
 */
inline string COLUNA::GetColuna(){
    return coluna;
}

#endif
