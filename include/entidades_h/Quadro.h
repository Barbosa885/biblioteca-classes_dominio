/**
 * @file Texto.h
 * @brief Definição da classe Texto.
 *
 * @brief Esta classe é usada para manipular e verificar uma string de texto.
 *
 * Autor: Gabriel Kenzo Nomura (211037176)
 */

#ifndef QUADRO_H_INCLUDED
#define QUADRO_H_INCLUDED

#include "../dominios_h/Codigo.h"
#include "../dominios_h/Texto.h"
#include "../dominios_h/Limite.h"
#include <string>

using namespace std;

/**
 * @class Quadro
 * @brief Classe que representa um Quadro.
 */
class Quadro {
    private:
        Codigo codigo; ///< Código do quadro
        Texto nome; ///< Nome do quadro
        Texto descricao; ///< Descrição do quadro
        Limite limite; ///< Limite do quadro
    
    public:
        /**
         * @brief Define o código do quadro.
         * @param codigo O novo código.
         */
        void setCodigo(const Codigo&);

        /**
         * @brief Define o nome do quadro.
         * @param nome O novo nome.
         */
        void setNome(const Texto&);

        /**
         * @brief Define a descrição do quadro.
         * @param descricao A nova descrição.
         */
        void setDescricao(const Texto&);

        /**
         * @brief Define o limite do quadro.
         * @param limite O novo limite.
         */
        void setLimite(const Limite&); 

        /**
         * @brief Obtém o código do quadro.
         * @return O código atual.
         */
        Codigo getCodigo() const;    

        /**
         * @brief Obtém o nome do quadro.
         * @return O nome atual.
         */
        Texto getNome() const;         

        /**
         * @brief Obtém a descrição do quadro.
         * @return A descrição atual.
         */
        Texto getDescricao() const;         

        /**
         * @brief Obtém o limite do quadro.
         * @return O limite atual.
         */
        Limite getLimite() const;        
}; 

inline void Quadro::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}
inline void Quadro::setNome(const Texto &nome){
    this->nome = nome;
}
inline void Quadro::setDescricao(const Texto &descricao){
    this->descricao = descricao;
}
inline void Quadro::setLimite(const Limite &limite){
    this->limite = limite;
}
inline Codigo Quadro::getCodigo() const{
    return codigo;
}
inline Texto Quadro::getNome() const{
    return nome;
}
inline Texto Quadro::getDescricao() const{
    return descricao;
}
inline Coluna Quadro::getLimite() const{
    return limite;
}

#endif // QUADRO_H_INCLUDED
