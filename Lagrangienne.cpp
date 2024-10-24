#ifndef _LAGRANGIENNE_CPP_
#define _LAGRANGIENNE_CPP_

#include "Lagrangienne.h"
#include <iostream>

using namespace Eigen;
using namespace std;

// Constructeur par défaut
Lagrangienne::Lagrangienne()
{
}

// Destructeur par défaut
Lagrangienne::~Lagrangienne()
{
}

void Lagrangienne::InitializeFileName(const std::string& file_name)
{
    _file_out.open(file_name);
}

// Récupération de la fonction vectorielle F
const VectorXd& Lagrangienne::GetF() const
{
    return this->_F;
}

// Construction des sous-fonctions
double Lagrangienne::M(const double t, const VectorXd& X)
{
    return 0;
}

double Lagrangienne::R(const double t, const VectorXd& X)
{
    return 0;
}

double Lagrangienne::T(const double t, const VectorXd& X)
{
    return 0;
}

double Lagrangienne::b(const double a)
{
    return 0;
}

double Lagrangienne::tau(const double a)
{
    return 0;
}

void Lagrangienne::BuildF(const double t, const VectorXd& X)
{
    _F.resize(X.size());
    //_F[0] = ...; 
}

#endif // _LAGRANGIENNE_CPP_
