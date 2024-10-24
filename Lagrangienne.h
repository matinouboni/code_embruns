#ifndef _LAGRANGIENNE_H
#define _LAGRANGIENNE_H

#include <Eigen/Eigen/Dense>
#include <fstream>
#include <string>

class Lagrangienne
{
private:
    // Constantes dont on aura besoin
    // Julien, n'oublie pas de bien prendre en compte ces constantes dans le constructeur

protected:
    // La fonction F
    Eigen::VectorXd _F;
    // Écriture du fichier
    std::ofstream _file_out;

public:
    // Constructeur par défaut
    Lagrangienne(); // Ajout des constantes
    // Destructeur par défaut
    virtual ~Lagrangienne();
    // Initialiser le nom du fichier de solution
    void InitializeFileName(const std::string& file_name);
    // Sauvegarder la solution
    virtual void SaveSolution(const double t, const Eigen::VectorXd& sol);

    // Récupérer _F
    const Eigen::VectorXd& GetF() const;

    // Construction des sous-fonctions
    double M(const double t, const Eigen::VectorXd& X);
    double R(const double t, const Eigen::VectorXd& X);
    double T(const double t, const Eigen::VectorXd& X);
    double b(const double a);
    double tau(const double a);

    // Construire F (doit être implémentée dans les classes dérivées)
    virtual void BuildF(const double t, const Eigen::VectorXd& X) = 0;
};

#endif // _LAGRANGIENNE_H
