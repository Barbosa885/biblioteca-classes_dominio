#ifndef PERCENTUAL_H
#define PERCENTUAL_H

#include <iostream>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de um percentual.
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de percentuais,
 * incluindo a validação do percentual e a manipulação de seus componentes.
 */
class Percentual {
  private:
    /**
     * @brief Armazena o percentual.
     */
    float percentual = 0.0;

    /**
     * @brief Constante que representa o limite máximo permitido para o percentual.
     */
    static const int LIMITE = 100;

    /**
     * @brief Valida o percentual fornecido.
     *
     * Este método verifica se o percentual está dentro do limite permitido.
     * - O percentual deve ser um valor entre 0 e 100.
     *
     * @param percentual O percentual a ser validado.
     */
    void validar(float percentual);

  public :
    /**
     * @brief Construtor padrão da classe Percentual.
     */
    Percentual();

    /**
     * @brief Destrutor padrão da classe Percentual.
     */
    virtual ~Percentual();

    /**
     * @brief Define o percentual.
     *
     * Este método define o percentual para o objeto. Antes de definir,
     * o percentual é validado para garantir que esteja dentro do limite permitido.
     *
     * @param percentual O novo percentual.
     */
    void setPercentual(float percentual);

    /**
     * @brief Retorna o percentual.
     *
     * Este método retorna o percentual atual do objeto.
     *
     * @return O percentual atual.
     */
    float getPercentual() const;
};

inline float Percentual::getPercentual() const {
  return percentual;
}

#endif // PERCENTUAL_H
