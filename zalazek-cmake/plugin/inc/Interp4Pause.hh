#ifndef  COMMAND4PAUSE_HH
#define  COMMAND4PAUSE_HH

#include "AbstractInterp4Command.hh"

class Interp4Pause: public AbstractInterp4Command {

 public:
  /*!
   * \brief
   */
  Interp4Pause();  
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
  virtual void PrintSyntax() const override;

};

#endif