#include "../../../include/testes_h/entidades/TUConta.h"

using namespace std;

const string TUConta::CPF_VALIDO = "617.468.050-99";
const string TUConta::NOME_VALIDO = "Gustavo Barbosa";
const string TUConta::SENHA_VALIDA = "842970";

void TUConta::setUp() {
  conta = new Conta();
  estado = SUCESSO;
}

void TUConta::tearDown() {
  delete conta;
}

void TUConta::testarCenarioSucesso() {
  try {
    Nome nome;
    nome.setNome(NOME_VALIDO);
    conta->setNome(nome);
    if (conta->getNome().getNome() != NOME_VALIDO) {
      estado = FALHA;
    }
  } catch (invalid_argument &excecao) {
    estado = FALHA;
  }

  try {
    Cpf cpf;
    cpf.setCpf(CPF_VALIDO);
    conta->setCpf(cpf);
    if (conta->getCpf().getCpf() != CPF_VALIDO) {
      estado = FALHA;
    }
  } catch (invalid_argument &excecao) {
    estado = FALHA;
  }

  try {
    Senha senha;
    senha.setSenha(SENHA_VALIDA);
    conta->setSenha(senha);
    if (conta->getSenha().getSenha() != SENHA_VALIDA) {
      estado = FALHA;
    }
  } catch (invalid_argument &excecao) {
    estado = FALHA;
  }
}

int TUConta::run() {
  setUp();
  testarCenarioSucesso();
  tearDown();

  return estado;
}
