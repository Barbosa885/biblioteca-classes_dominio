#include <iostream>
#include "../../include/testes_h/TUSenha.h"
#include "../../include/dominios_h/Senha.h"

TUSenha::TUSenha()
{
    //ctor    
}

TUSenha::~TUSenha()
{
    //dtor
}

using namespace std;

const string TUSenha::SENHAS_VALIDAS[] = {
    "Abc1.",
    "Zy?x2"
};

const string TUSenha::SENHAS_INVALIDAS[] = {
    "abc.1",
    "ABC?2",
    "Abc!e",
    "Abcd3",
    "Abb,4"
};

void TUSenha::setUp(){  /** Configura o ambiente de teste. */
    senha = new SENHA();
    estado = SUCESSO;
}

void TUSenha::tearDown(){ /** Limpa o ambiente de teste, excluindo a instância SENHA. */
    delete senha;
}

void TUSenha::testarCenarioSucesso(){ /** Testa um cenário de sucesso em que a senha é definida como uma senha válida. */
    for (const string &senhaValida : SENHAS_VALIDAS){
        try{
            senha->setSenha(senhaValida);
            if (senha->getSenha() != senhaValida)
                estado = FALHA;
        }
        catch(invalid_argument &excecao){
            estado = FALHA;
        }
    }
}

void TUSenha::testarCenarioFalha(){ /** Testa um cenário de falha em que a senha é definida como uma senha inválida. */
    for (const string &senhaInvalida : SENHAS_INVALIDAS){
        try{
            senha->setSenha(senhaInvalida);
            estado = FALHA;
        }
        catch(invalid_argument &excecao){
            if (senha->getSenha() == senhaInvalida)
                estado = FALHA;
        }
    }
}

void TUSenha::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
}
