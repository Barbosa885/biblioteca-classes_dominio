/**
 * @file Senha.h
 * @brief Definição da classe Senha.
 *
 * @brief Esta classe é usada para manipular e verificar uma string de senha.
 *
 * Autor: Gabriel Kenzo Nomura ()
 */
#ifndef SENHA_H
#define SENHA_H

#include <iostream>
#include <string>

using namespace std;

class Senha {
    private:
        /** 
         * @brief Variável de senha.
         * 
         * Esta variável armazena a string de senha que a classe manipula.
         */
        string senha;
        
        /** 
         * @brief Método de verificação.
         * 
         * Este método privado é usado para verificar a string de senha de acordo com algum critério.
         * @param string A senha a ser verificada.
         */
        void isValid(const string &senha);
    
    public:
        Senha();
        virtual ~Senha();
        /** 
         * @brief Método GetSenha.
         * 
         * Este método é usado para obter o valor da variável de senha.
         * @return Retorna a string de senha.
         */
        const string &getSenha() const;
        
        /** 
         * @brief Método SetSenha.
         * 
         * Este método é usado para definir o valor da variável de senha.
         * @param string A nova string de senha.
         */
        void setSenha(const string &senha);
};

inline const string &Senha::getSenha() const
{
    return senha;
}

#endif // SENHA_H
