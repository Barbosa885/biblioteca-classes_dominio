// Dinheiro.h
#ifndef DINHEIRO_H
#define DINHEIRO_H

#include <iostream>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de uma quantia em dinheiro.
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de quantias em dinheiro,
 * incluindo a validação do valor e a manipulação de seus componentes.
 */
class Dinheiro {
  private:
    /**
     * @brief Armazena o valor da quantia em dinheiro.
     */
    float valor = 0.0;

    /**
     * @brief Constante que representa o limite máximo permitido para o valor da quantia em dinheiro.
     */
    static constexpr float LIMITE = 1000000.0;

    /**
     * @brief Valida o valor da quantia em dinheiro fornecido.
     *
     * Este método verifica se o valor da quantia em dinheiro está dentro do limite permitido.
     *
     * @param valor O valor da quantia em dinheiro a ser validado.
     */
    void validar(float valor);

  public:
    /**
     * @brief Construtor padrão da classe Dinheiro.
     */
    Dinheiro();

    /**
     * @brief Construtor com parâmetro para inicializar o valor.
     * @param valor Valor inicial da quantia em dinheiro.
     */
    Dinheiro(float valor);

    /**
     * @brief Destrutor padrão da classe Dinheiro.
     */
    virtual ~Dinheiro();

    /**
     * @brief Define o valor da quantia em dinheiro.
     *
     * Este método define o valor da quantia em dinheiro para o objeto. Antes de definir,
     * o valor é validado para garantir que esteja dentro do limite permitido.
     *
     * @param valor O novo valor da quantia em dinheiro.
     */
    void setValor(float valor);

    /**
     * @brief Retorna o valor da quantia em dinheiro.
     *
     * Este método retorna o valor atual da quantia em dinheiro do objeto.
     *
     * @return O valor atual da quantia em dinheiro.
     */
    float getValor() const;
};

inline float Dinheiro::getValor() const {
  return valor;
}

#endif // DINHEIRO_H
