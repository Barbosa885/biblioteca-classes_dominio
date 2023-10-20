#include <regex>
#include <stdexcept>
#include <string>
#include <sstream>
#include "../../include/dominios_h/Email.h"

using namespace std;

void Email::setEmail(const string& email)
{
  try{
    if(!isValid(email))
    {
      throw invalid_argument("Endereço de email inválido");
    }
    this->email.str(email);
  }
  catch(invalid_argument& e)
  {
    throw e;
  }
}

const stringstream& Email::getEmail() const
{
  return email;
}

bool Email::isValid(const string& email)
{
  const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  istringstream ss(email);

  sregex_token_iterator it(email.begin(), email.end(), pattern, 0);
  sregex_token_iterator end;
  return regex_match(email, pattern);

  while (it != end)
  {
    string part = it->str();
    if(regex_match(part, pattern))
    {
      it++;
    } else {
      return false;
    }
  }

}
