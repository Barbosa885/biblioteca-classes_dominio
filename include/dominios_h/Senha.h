#ifndef SENHA_H
#define SENHA_H

#include <iostream>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de uma senha.
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de senhas,
 * incluindo a validação da senha e a manipulação de seus componentes.
 */
class Senha {
  private:
    /**
     * @brief Armazena a senha.
     */
    string senha;

    /**
     * @brief Constante que representa o tamanho máximo permitido para a senha.
     */
    static const int TAMANHO_MAX = 6;

    /**
     * @brief Valida a sequência da senha.
     *
     * Este método verifica se a senha segue uma sequência específica.
     *
     * @param senha A senha a ser validada.
     * @return Verdadeiro se a senha segue a sequência, falso caso contrário.
     */
    bool validarSequencia(const string& senha);

    /**
     * @brief Valida os caracteres da senha.
     *
     * Este método verifica se a senha contém apenas caracteres permitidos.
     *
     * @param senha A senha a ser validada.
     * @return Verdadeiro se a senha contém apenas caracteres permitidos, falso caso contrário.
     */
    bool validarCaracteres(const string& senha);

    /**
     * @brief Valida a senha fornecida.
     *
     * Este método verifica se a senha está no tamanho correto e
     * se atende aos critérios de validação.
     * - Formato XXXXXX
     * - X - Dígito (0-9)
     * - Não há dígito duplicado
     * - Primeiro dígito é diferente de zero (1-9)
     * - Sequência de dígitos não pode ser sequência de dígitos em ordem crescente ou decrescente
     *
     * @param senha A senha a ser validada.
     */
    void validar(const string& senha);

  public :
    /**
     * @brief Construtor padrão da classe Senha.
     */
    Senha();

    /**
     * @brief Destrutor padrão da classe Senha.
     */
    virtual ~Senha();

    /**
     * @brief Define a senha.
     *
     * Este método define a senha para o objeto. Antes de definir,
     * a senha é validada para garantir que esteja no tamanho correto e
     * siga as regras de validação.
     *
     * @param senha A nova senha.
     */
    void setSenha(const string& senha);

    /**
     * @brief Retorna a senha.
     *
     * Este método retorna a senha atual do objeto.
     *
     * @return A senha atual.
     */
    string getSenha() const;
};

inline string Senha::getSenha() const {
  return senha;
}

#endif // SENHA_H
