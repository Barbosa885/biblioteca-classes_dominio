#ifndef CPF_H
#define CPF_H

#include <iostream>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de um CPF (Cadastro de Pessoa Física).
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de CPFs,
 * incluindo a validação do CPF e a manipulação de seus componentes.
 */
class Cpf {
  private:
    /**
     * @brief Armazena o CPF.
     */
    string cpf;

    /**
     * @brief Constante que representa o tamanho máximo permitido para o CPF.
     */
    static const int TAMANHO_MAX = 11;

    /**
     * @brief Valida o CPF fornecido.
     *
     * Este método verifica se o CPF está no formato correto e
     * se atende aos critérios de validação.
     * - O CPF deve ter 11 caracteres.
     * - O CPF deve estar no formato XXX.XXX.XXX-XX.
     * - O CPF deve ter dígitos válidos.
     *
     * @param cpf O CPF a ser validado.
     */
    void validar(const string& cpf);

    /**
     * @brief Valida os dígitos do CPF.
     *
     * Este método verifica se os dígitos do CPF são válidos.
     *
     * @param digito1 O primeiro dígito do CPF.
     * @param digito2 O segundo dígito do CPF.
     * @param digitos Os dígitos do CPF.
     * @return Verdadeiro se os dígitos forem válidos, falso caso contrário.
     */
    bool validarDigitos(int digito1, int digito2, string digitos);

    /**
     * @brief Valida o formato do CPF.
     *
     * Este método verifica se o CPF está no formato correto.
     *
     * @param cpf O CPF a ser validado.
     * @return Verdadeiro se o CPF estiver no formato correto, falso caso contrário.
     */
    bool validarFormato(const string& cpf);

  public :
    /**
     * @brief Construtor padrão da classe Cpf.
     */
    Cpf();

    /**
     * @brief Destrutor padrão da classe Cpf.
     */
    virtual ~Cpf();

    /**
     * @brief Define o CPF.
     *
     * Este método define o CPF para o objeto. Antes de definir,
     * o CPF é validado para garantir que atenda aos critérios de validação.
     *
     * @param cpf O novo CPF.
     */
    void setCpf(const string& cpf);

    /**
     * @brief Retorna o CPF.
     *
     * Este método retorna o CPF atual do objeto.
     *
     * @return O CPF atual.
     */
    string getCpf() const;
};

inline string Cpf::getCpf() const {
  return cpf;
}

#endif // CPF_H
