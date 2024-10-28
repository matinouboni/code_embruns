#ifndef _SCHEMA_CPP_
#define _SCHEMA_CPP_

#include "Schema.h"
#include <iostream>

// Constructeur par défaut 
Schema::Schema() : _sys(0)
{
}

// Destructeur
Schema::~Schema()
{
}

// Initialisation des différentes variables
void Schema::Initialize(double t0, double dt, std::vector& sol0, const std::string& name_file, Lagrangienne* sys)
{
    this->_dt = dt;
    this->_t = t0 ;
    this->_sol0 = sol0;
    this->_sol = sol0;
    this->_sys = sys;
    if (name_file.size() > 0)
    {
        this->_sys->InitializeFileName(name_file);
    }
}

// Schéma en temps
// Avancer d'un pas de temps
void EulerScheme::Advance()
{
    this->_sys->BuildF(this->_t, this->_sol);
    this->_sol += this->_dt*this->_sys->GetF();
    this->_t += this->_dt;
}


void RungeKuttaScheme4::Advance()
{
    std::vector k1, k2, k3, k4;
    this->_sys->BuildF(this->_t, this->_sol);
    k1 = this->_sys->GetF();
    this->_sys->BuildF(this->_t + (this->_dt)/2., this->_sol + ((this->_dt)/2)*k1);
    k2 = this->_sys->GetF();
    this->_sys->BuildF(this->_t + (this->_dt)/2., this->_sol + ((this->_dt)/2)*k2);
    k3 = this->_sys->GetF();
    this->_sys->BuildF(this->_t + this->_dt, this->_sol + (this->_dt)*k3);
    k4 = this->_sys->GetF();
    this->_sol += ((this->_dt)/6.)*(k1 + 2*k2 + 2*k3 + k4);
    this->_t += this->_dt;
}

void ExponentialScheme::Advance()
{
    double tau(this->_sys->tau(this->_dt));
    this->_sol = _sol*exp(-this->_dt/tau) + (1./tau)*this->_sys->b(this->_t)*(1.-exp(-this->_dt/tau));
    this->_t += this->_dt;
}

// Enregistre la solution
void Schema::SaveSolution()
{
    _sys->SaveSolution(_t, _sol);
}

// Renvoie _sol 
const std::vector& Schema::GetIterateSolution() const
{
    return _sol;
}

#endif // _SCHEMA_CPP_
