#ifndef CONTA_H
#define CONTA_H

#include "../dominios_h/Cpf.h"
#include "../dominios_h/Nome.h"
#include "../dominios_h/Senha.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de uma conta.
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de contas,
 * incluindo a validação da conta e a manipulação de seus componentes.
 */
class Conta {
  private:
    /**
     * @brief Armazena o CPF da conta.
     */
    Cpf cpf;

    /**
     * @brief Armazena o nome da conta.
     */
    Nome nome;

    /**
     * @brief Armazena a senha da conta.
     */
    Senha senha;

  public:
    /**
     * @brief Define o CPF da conta.
     *
     * @param cpf O novo CPF para a conta.
     */
    void setCpf(const Cpf& cpf);

    /**
     * @brief Obtém o CPF da conta.
     *
     * @return O CPF atual da conta.
     */
    Cpf getCpf() const;

    /**
     * @brief Define a senha da conta.
     *
     * @param senha A nova senha para a conta.
     */
    void setSenha(const Senha& senha);

    /**
     * @brief Obtém a senha da conta.
     *
     * @return A senha atual da conta.
     */
    Senha getSenha() const;

    /**
     * @brief Define o nome da conta.
     *
     * @param nome O novo nome para a conta.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Obtém o nome da conta.
     *
     * @return O nome atual da conta.
     */
    Nome getNome() const;
};

inline void Conta::setCpf(const Cpf& cpf) {
  this->cpf = cpf;
}

inline Cpf Conta::getCpf() const {
  return cpf;
}

inline void Conta::setSenha(const Senha& senha) {
  this->senha = senha;
}

inline Senha Conta::getSenha() const {
  return senha;
}

inline void Conta::setNome(const Nome& nome) {
  this->nome = nome;
}

inline Nome Conta::getNome() const {
  return nome;
}

#endif // CONTA_H
