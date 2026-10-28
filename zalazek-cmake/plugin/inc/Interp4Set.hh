#ifndef  COMMAND4SET_HH
#define  COMMAND4SET_HH

#include "AbstractInterp4Command.hh"

class Interp4Set: public AbstractInterp4Command {

 public:
  /*!
   * \brief
   */
  Interp4Set();  
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
  virtual void PrintSyntax() const override;
  virtual const char* GetCmdName() const override;
};

#endif