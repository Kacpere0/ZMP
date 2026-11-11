#ifndef  COMMAND4PAUSE_HH
#define  COMMAND4PAUSE_HH

#include "AbstractInterp4Command.hh"
#include <unistd.h>

class Interp4Pause: public AbstractInterp4Command {
  double Pause_time_ms;
public:
  /*!
  * \brief
  */
  Interp4Pause();  
  /*!
  * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
  */
  virtual void PrintSyntax() const override;
  virtual const char* GetCmdName() const override;
  virtual void PrintCmd() const override;
  virtual bool ReadParams(std::istream &rStrm_CmdList) override;
  virtual bool ExecCmd(Scene &Scn) override;
};

#endif