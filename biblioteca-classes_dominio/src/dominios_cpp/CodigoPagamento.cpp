#include "../../include/dominios_h/CodigoPagamento.h"

CodigoPagamento::CodigoPagamento()
{
  //ctor
}

CodigoPagamento::~CodigoPagamento()
{
  //dtor
}


// Método que valida o código de pagamento
void CodigoPagamento::validar(const string& codigo_pagamento){
  // Verifica se o código de pagamento possui 8 caracteres
  if(codigo_pagamento.length() != CODIGO_LEN){
    throw invalid_argument("Codigo de pagamento invalido");
  }

  // Verifica se o código de pagamento possui apenas dígitos
  for(char c : codigo_pagamento){
    if(!isdigit(c)){
      throw invalid_argument("Codigo de pagamento invalido");
    }
  }
  
  // Verifica se o primeiro digito é diferente de 0
  if (codigo_pagamento[0] == '0'){
    throw invalid_argument("Codigo de pagamento invalido");
  }
}

// Método que atribui um código de pagamento
void CodigoPagamento::setCodigo(const string& codigo_pagamento){
  validar(codigo_pagamento);
  this->codigo_pagamento = codigo_pagamento;
}
