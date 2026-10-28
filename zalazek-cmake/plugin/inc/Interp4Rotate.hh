#ifndef  COMMAND4ROTATE_HH
#define  COMMAND4ROTATE_HH

#include "AbstractInterp4Command.hh"

class Interp4Rotate: public AbstractInterp4Command {
 public:
  /*!
   * \brief
   */
  Interp4Rotate();  
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
  virtual void PrintSyntax() const override;
  virtual const char* GetCmdName() const override;
};

#endif