// Setor.h
#ifndef SETOR_H
#define SETOR_H

#include <iostream>
#include <vector>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de um setor.
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de setores,
 * incluindo a validação do setor e a manipulação de seus componentes.
 */
class Setor {
  private:
    /**
     * @brief Lista de setores válidos.
     *
     * Esta lista contém os setores que são considerados válidos.
     */
    static const vector<string> SETORES;

    /**
     * @brief Armazena o setor.
     */
    string setor;

    /**
     * @brief Valida o setor fornecido.
     *
     * Este método verifica se o setor está na lista de setores válidos.
     *
     * @param setor O setor a ser validado.
     */
    static void validar(const string& setor);

    /**
     * @brief Verifica se o setor está presente na lista de setores válidos.
     *
     * Este método verifica se o setor fornecido está presente na lista de setores válidos.
     *
     * @param setor O setor a ser verificado.
     * @return Verdadeiro se o setor está presente, falso caso contrário.
     */
    static bool encontrarSetor(const string& setor);

  public:
    /**
     * @brief Construtor padrão da classe Setor.
     */
    Setor();

    /**
     * @brief Construtor com parâmetro da classe Setor.
     * @param setor Setor inicial a ser atribuído ao objeto.
     */
    Setor(const string& setor);

    /**
     * @brief Destrutor padrão da classe Setor.
     */
    virtual ~Setor();

    /**
     * @brief Define o setor.
     *
     * Este método define o setor para o objeto. Antes de definir,
     * o setor é validado para garantir que esteja na lista de setores válidos.
     *
     * @param setor O novo setor.
     */
    void setSetor(const string& setor);

    /**
     * @brief Retorna o setor.
     *
     * Este método retorna o setor atual do objeto.
     *
     * @return O setor atual.
     */
    string getSetor() const;
};

inline string Setor::getSetor() const {
  return setor;
}

#endif // SETOR_H
