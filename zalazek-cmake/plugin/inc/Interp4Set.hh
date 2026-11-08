#ifndef  COMMAND4SET_HH
#define  COMMAND4SET_HH

#include "AbstractInterp4Command.hh"

class Interp4Set: public AbstractInterp4Command {
  std::string ObjName;
  double xcord, ycord, zcord;
  double OXangl, OYangl, OZangl;
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
  virtual void PrintCmd() const override;
  virtual bool ReadParams(std::istream &rStrm_CmdList) override;
  virtual bool ExecCmd(Scene &Scn) override;
};

#endif