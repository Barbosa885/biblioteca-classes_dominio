#include "../include/controladoras.h"
#include "../include/cntrlservices.h"
#include "../include/entidades.h"
#include "../include/dominios.h"
#include <iostream>

//--------------------------------------------------------------------------------------------
//Implementações de métodos de classes controladoras.
//
// Falta implementar códigos.


#include "../include/controladoras.h"
#include <iostream>

// Implementação de métodos da AuthenticationController

// Implementação de métodos da RegistrationController

bool RegistrationController::registerUser(const string& email, const string& name, const string& password) {
    // Lógica de registro
    // Chame o serviço Sconta para registrar o usuário
    if (servicosConta.createUser(email, name, password)) {
        std::cout << "Usuário registrado com sucesso!" << std::endl;
        return true;
    } else {
        std::cout << "Falha no registro. Verifique os dados fornecidos." << std::endl;
        return false;
    }
}

// Implementação de métodos da BoardController

BoardController::BoardController() {
    // Inicialize os serviços ou faça qualquer inicialização necessária
}

bool BoardController::createBoard(const string& userEmail, const string& code, const string& name, const string& description, int limit) {
    // Lógica para criar um quadro
    // Crie um objeto Quadro com os dados fornecidos
    Quadro novoQuadro;

    novoQuadro.setCodigo(code);
    novoQuadro.setNome(name);
    novoQuadro.setDescricao(description);
    novoQuadro.setLimite(limit);

    // Chame o serviço SQuadro para criar o quadro
    servicosQuadro.criarQuadro(userEmail, novoQuadro);

    std::cout << "Quadro criado com sucesso!" << std::endl;
    return true;
}

// Implemente outros métodos da BoardController conforme necessário
// ...

// Implementação de métodos da CardController

CardController::CardController() {
    // Inicialize os serviços ou faça qualquer inicialização necessária
}

bool CardController::createCard(const string& boardCode, const string& cardCode, const string& name, const string& description, const string& column) {
    // Lógica para criar um cartão
    // Crie um objeto Cartao com os dados fornecidos
    Cartao novoCartao;
    novoCartao.setCodigo(cardCode);
    novoCartao.setNome(name);
    novoCartao.setDescricao(description);
    novoCartao.setColuna(column);

    // Chame o serviço SCartao para criar o cartão
    servicosCartao.createCard(novoCartao, boardCode, "");

    std::cout << "Cartão criado com sucesso!" << std::endl;
    return true;
}

// Implemente outros métodos da CardController conforme necessário
// ...
