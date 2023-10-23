/**
 * @file Cartao.h
 *
 * @brief Definição da classe Cartao.
 *
 * Autor: Gustavo Barbosa (202037589)
 */

#ifndef CARTAO_H_INCLUDED
#define CARTAO_H_INCLUDED

#include "../dominios_h/Codigo.h"
#include "../dominios_h/Texto.h"
#include "../dominios_h/Coluna.h"
#include <string>

using namespace std;

/** 
 * @brief Classe Cartao.
 * 
 * Esta classe é usada para manipular um cartão que contém um código, nome, descrição e coluna.
 */
class Cartao {
    private:
        /** 
         * @brief Variável de código.
         * 
         * Esta variável armazena o código do cartão.
         */
        Codigo codigo;
        
        /** 
         * @brief Variável de nome.
         * 
         * Esta variável armazena o nome do cartão.
         */
        Texto nome;
        
        /** 
         * @brief Variável de descrição.
         * 
         * Esta variável armazena a descrição do cartão.
         */
        Texto descricao;
        
        /** 
         * @brief Variável de coluna.
         * 
         * Esta variável armazena a coluna do cartão.
         */
        Coluna coluna;
    
    public:
        /** 
         * @brief Método setCodigo.
         * 
         * Este método é usado para definir o valor da variável de código.
         * @param Codigo O novo código do cartão.
         */
        void setCodigo(const Codigo&);
        
        /** 
         * @brief Método setNome.
         * 
         * Este método é usado para definir o valor da variável de nome.
         * @param Texto O novo nome do cartão.
         */
        void setNome(const Texto&);
        
        /** 
         * @brief Método setDescricao.
         * 
         * Este método é usado para definir o valor da variável de descrição.
         * @param Texto A nova descrição do cartão.
         */
        void setDescricao(const Texto&);
        
        /** 
         * @brief Método setColuna.
         * 
         * Este método é usado para definir o valor da variável de coluna.
         * @param Coluna A nova coluna do cartão.
         */
        void setColuna(const Coluna&);
        
        /** 
         * @brief Método getCodigo.
         *
         * Este método é usado para obter o valor da variável de código.  
         *
         * @return Retorna o código do cartão.  
         */  
        Codigo getCodigo() const;  
        
        /**   
          *
          *@brief Método getNome.  
          *
          *@return Retorna o nome do cartão.  
          */  
        Texto getNome() const;        
        
        /**   
          *
          *@brief Método getDescricao.  
          *
          *@return Retorna a descrição do cartão.  
          */  
        Texto getDescricao() const;        
        
        /**   
          *
          *@brief Método getColuna.  
          *
          *@return Retorna a coluna do cartão.  
          */  
        Coluna getColuna() const;        
};

/**   
  *
  *@brief Implementação inline dos métodos setters e getters da classe Cartao.  
  *
  */  

inline void Cartao::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}
inline void Cartao::setNome(const Texto &nome){
    this->nome = nome;
}
inline void Cartao::setDescricao(const Texto &descricao){
    this->descricao = descricao;
}
inline void Cartao::setColuna(const Coluna &coluna){
    this->coluna = coluna;
}
inline Codigo Cartao::getCodigo() const{
    return codigo;
}
inline Texto Cartao::getNome() const{
    return nome;
}
inline Texto Cartao::getDescricao() const{
    return descricao;
}
inline Coluna Cartao::getColuna() const{
    return coluna;
}

#endif // CARTAO_H_INCLUDED
