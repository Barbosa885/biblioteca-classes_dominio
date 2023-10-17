#ifndef CODIGO_H
#define CODIGO_H

#include <string>
#include <stdexcept>

using namespace std;

class Codigo
{
  public:
    Codigo();
    void setCodigo(const string& codigo);
    const string& getCodigo() const;
    virtual ~Codigo();

  private:
    string codigo;
    bool isValid(const string& codigo);
};

#endif // CODIGO_H
