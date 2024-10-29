#ifndef _LAGRANGIENNE_CPP_
#define _LAGRANGIENNE_CPP_

#include "Lagrangienne.h"
#include <iostream>

//using namespace Eigen;
//using namespace std;

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
const std::vector<double>& Lagrangienne::GetF() const
{
    return this->_F;
}

// Construction des sous-fonctions
double Lagrangienne::M(const std::vector<double>& X)
{
    return 0;
}

double Lagrangienne::R(const std::vector<double>& X)
{
    return 0;
}

double Lagrangienne::T(const std::vector<double>& X)
{
    return 0;
}

double Lagrangienne::b(const std::vector<double>& X)
{
    return 0;
}

double Lagrangienne::tauD(const std::vector<double>& X)
{
    return 0;
}

double Lagrangienne::tauT(const std::vector<double>& X)
{
    return 0;
}

double Lagrangienne::kae(const std::vector<double>& X)
{
    return 0;
}

void Lagrangienne::BuildF(const std::vector<double>& X)
{
    _F.resize(X.size());
    switch(_cas)
    {
        case 0 :
            _F[0] = X[1];
            _F[1] = (g + tauD(X)*(u-X[1]));
            _F[2] = M(X);
            _F[3] = _F[2]/(4*pi*(X[3]*X[3])*rhow);
            _F[4] = ((4*pi*X[3]*kae(X)*(T_air-X[4])) + Lv*_F[2]);
        case 1 :
            _F[0] = X[1];
            _F[1] = u + g*tauD(X);
            _F[2] = M(X);
            _F[3] = _F[2]/(4*pi*(X[3]*X[3])*rhow);
            _F[4] = b(X);
    }
    
}

#endif // _LAGRANGIENNE_CPP_
