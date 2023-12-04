#ifndef CONTROLADORA_SERVICOS_HPP_INCLUDED
#define CONTROLADORA_SERVICOS_HPP_INCLUDED

#include "interfaces.h"
#include <optional>
#include <string>
#include <vector>

using namespace std;

// Exemplo de classe para serviços de usuário
class Sconta {
  private:
    vector<Conta> contas;  // Armazenamento temporário, substituir por lógica de banco de dados real se necessário

  public:
    Sconta();
    bool createUser(const string& email, const string& nome, const string& senha);
    void editUser(const string& email, const string& novoNome, const string& novaSenha);
    void deleteUser(const string& email);
    optional<Conta> visualizarUsuario(const string& email);
};

// Exemplo de classe para serviços de quadro
class SQuadro {
  private:
    vector<Quadro> quadros;  // Armazenamento temporário, substituir por lógica de banco de dados real

  public:
    SQuadro();
    optional<Quadro> visualizarQuadro(const string& emailUsuario, const string& codigo);
    void editQuadro(const string& emailUsuario, const string& codigo, const optional<string>& novoNome, const optional<string>& novaDescricao, const optional<int>& novoLimite);
    void deleteQuadro(const string& emailUsuario, const string& codigo);
    void criarQuadro(const string& emailConta, const Quadro& quadro);
};

// Exemplo de classe para serviços de cartão
class SCartao {
  private:
    vector<Cartao> cartoes;  // Armazenamento temporário, substituir por lógica de banco de dados real

  public:
    SCartao();
    optional<Cartao> visualizarCartao(const string& codigoCartao, const string& emailUsuario);
    void editCard(const string& codigoCartao, const string& novaColuna, const string& emailUsuario);
    void deleteCard(const string& codigoCartao, const string& emailUsuario);
    void createCard(const Cartao& cartao, const string& codigoQuadro, const string& emailUsuario);
};

#endif  // CONTROLADORA_SERVICOS_HPP_INCLUDED
