#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <sstream>

using namespace std;

class Email
{
  public:
    Email();
    void setEmail(const string& email);
    const stringstream& getEmail() const;
    virtual ~Email();

  private:
    stringstream email;
    bool isValid(const string& email);
};

#endif // EMAIL_H
