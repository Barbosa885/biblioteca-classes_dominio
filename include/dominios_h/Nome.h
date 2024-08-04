// Nome.h
#ifndef NOME_H
#define NOME_H

#include <iostream>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de um nome completo.
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de nomes completos,
 * incluindo a validação do nome e sobrenome e a manipulação de seus componentes.
 */
class Nome {
  private:
    /**
     * @brief Constante que representa o comprimento máximo permitido para o nome.
     */
    static const int NOME_LEN_MAX = 10;

    /**
     * @brief Constante que representa o comprimento mínimo permitido para o nome.
     */
    static const int NOME_LEN_MIN = 3;

    /**
     * @brief Armazena o nome (termo 1).
     */
    string nome;

    /**
     * @brief Valida o nome fornecido.
     *
     * Este método verifica se o nome está no comprimento correto e
     * se atende aos critérios de validação.
     * - Composto por um ou dois termos
     * - Cada termo tem 3 a 10 caracteres
     * - Cada caractere é letra (A-Z, a-z)
     * - Termos são separados por um espaço em branco
     * - Primeiro caractere de cada termo é letra maiúscula
     *
     * @param nome O nome a ser validado.
     */
    static void validar(const string& nome);

  public:
    /**
     * @brief Construtor padrão da classe Nome.
     */
    Nome();

    /**
     * @brief Construtor com parâmetro da classe Nome.
     * @param nome Nome inicial a ser atribuído ao objeto.
     */
    Nome(const string& nome);

    /**
     * @brief Destrutor padrão da classe Nome.
     */
    virtual ~Nome();

    /**
     * @brief Define o nome.
     *
     * Este método define o nome para o objeto. Antes de definir,
     * o nome é validado para garantir que esteja no comprimento correto.
     *
     * @param nome O novo nome.
     */
    void setNome(const string& nome);

    /**
     * @brief Retorna o nome.
     *
     * Este método retorna o nome atual do objeto.
     *
     * @return O nome atual.
     */
    string getNome() const;
};

inline string Nome::getNome() const {
  return nome;
}

#endif // NOME_H
