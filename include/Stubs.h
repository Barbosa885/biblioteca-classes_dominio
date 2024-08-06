#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "./interfaces_h/servico/ISAutenticacao.h"

#include <stdexcept>
#include <iostream>
#include <typeinfo>

using namespace std;

/**
 * @class StubISAutenticacao
 * @brief Classe Stub que implementa a interface ISAutenticacao para fins de testes.
 */
class StubISAutenticacao : public ISAutenticacao {

private:
    /**
     * @brief Definições de valores a serem usados como gatilhos para notificação de erros.
     */
    static const string TRIGGER_FALHA; ///< Gatilho para falha na autenticação.
    static const string TRIGGER_ERRO_SISTEMA; ///< Gatilho para erro de sistema.

public:
    /**
     * @brief Método para autenticar um usuário.
     * @param cpf CPF do usuário.
     * @param senha Senha do usuário.
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    bool autenticar(const Cpf cpf, const Senha senha);
};

#endif // STUBS_H_INCLUDED
