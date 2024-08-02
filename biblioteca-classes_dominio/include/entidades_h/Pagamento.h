#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include "../dominios_h/CodigoPagamento.h"
#include "../dominios_h/Data.h"
#include "../dominios_h/Percentual.h"
#include "../dominios_h/Estado.h"

using namespace std;

class Pagamento {
  private:
    CodigoPagamento codigoPagamento;
    Data data;
    Percentual percentual;
    Estado estado;

  public:
    void setCodigoPagamento(const CodigoPagamento& codigoPagamento);
    void setData(const Data& data);
    void setPercentual(const Percentual& percentual);
    void setEstado(const Estado& estado);

    CodigoPagamento getCodigoPagamento() const;
    Data getData() const;
    Percentual getPercentual() const;
    Estado getEstado() const;
};

inline void Pagamento::setCodigoPagamento(const CodigoPagamento& codigoPagamento) {
  this->codigoPagamento = codigoPagamento;
}

inline void Pagamento::setData(const Data& data) {
  this->data = data;
}

inline void Pagamento::setPercentual(const Percentual& percentual) {
  this->percentual = percentual;
}

inline void Pagamento::setEstado(const Estado& estado) {
  this->estado = estado;
}

inline CodigoPagamento Pagamento::getCodigoPagamento() const {
  return codigoPagamento;
}

inline Data Pagamento::getData() const {
  return data;
}

inline Percentual Pagamento::getPercentual() const {
  return percentual;
}

inline Estado Pagamento::getEstado() const {
  return estado;
}

#endif // PAGAMENTO_H
