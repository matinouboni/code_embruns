#ifndef _SCHEMA_CPP_
#define _SCHEMA_CPP_

#include "Schema.h"
#include <iostream>

using namespace Eigen;
using namespace std;

// Constructeur par défaut 
Schema::Schema() : _sys(0)
{
}

// Destructeur
Schema::~Schema()
{
}

// Initialisation des différentes variables
void Schema::Initialize(double t0, double dt, Eigen::VectorXd& sol0, const std::string& name_file, Lagrangienne* sys)
{
}

// Schéma en temps
// Avancer d'un pas de temps
void Schema::Advance()
{
}

// Enregistre la solution
void Schema::SaveSolution()
{
    _sys->SaveSolution(_t, _sol);
}

// Renvoie _sol 
const VectorXd& Schema::GetIterateSolution() const
{
    return _sol;
}

#endif // _SCHEMA_CPP_
