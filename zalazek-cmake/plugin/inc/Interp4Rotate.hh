#ifndef  COMMAND4ROTATE_HH
#define  COMMAND4ROTATE_HH

#include "AbstractInterp4Command.hh"

class Interp4Rotate: public AbstractInterp4Command {
  std::string ObjName;
  std::string AxisName;
  double AngVelocity;
  double RotationAng;
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
  virtual void PrintCmd() const override;
  virtual bool ReadParams(std::istream &rStrm_CmdList) override;
  virtual bool ExecCmd(Scene &Scn) override;
};

#endif