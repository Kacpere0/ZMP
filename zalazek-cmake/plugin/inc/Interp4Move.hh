#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "AbstractInterp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawiera definicję klasy Interp4Move ...
 */

/*!
 * \brief Modeluje interpreter polecenia Move
 *
 *  Klasa modeluje interpreter polecenie dla modelu obiektu fizycznego,
 *  które wymusza jego ruch.
 */
class Interp4Move: public AbstractInterp4Command {
    std::string ObjName;
    double Speed_mS;
    double Distance_m;

public:
    /*!
    * \brief
    */
    Interp4Move();  
    /*!
    * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
    */
    virtual void PrintSyntax() const override;
    virtual const char* GetCmdName() const override;
    virtual bool ReadParams(std::istream &rStrm_CmdList) override;
    virtual bool ExecCmd(Scene &Scn) override;
};

#endif