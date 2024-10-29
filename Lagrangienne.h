#ifndef _LAGRANGIENNE_H
#define _LAGRANGIENNE_H

//#include <Eigen/Eigen/Dense>
#include <fstream>
#include <string>
#include <vector>

class Lagrangienne
{
private:
    // Constantes dont on aura besoin
    // Julien, n'oublie pas de bien prendre en compte ces constantes dans le constructeur

protected:
    // La fonction F
    std::vector<double> _F;
    // Écriture du fichier
    std::ofstream _file_out;
    // Entier pour choisir le shéma : 0 pour euler explicite, 1 pour mélange exponentiel et euler explicite
    int _cas;

    double u,g,pi,rhow,T_air,Lv;

public:
    // Constructeur par défaut
    Lagrangienne(); // Ajout des constantes
    // Destructeur par défaut
    virtual ~Lagrangienne();
    // Initialiser le nom du fichier de solution
    void InitializeFileName(const std::string& file_name);
    // Sauvegarder la solution
    virtual void SaveSolution(const double t, const std::vector<double> sol);

    // Récupérer _F
    const std::vector<double>& GetF() const;

    // Construction des sous-fonctions
    double M(const std::vector<double>& X);
    double R(const std::vector<double>& X);
    double T(const std::vector<double>& X);
    double b(const std::vector<double>& X);
    double tauD(const std::vector<double>& X);
    double tauT(const std::vector<double>& X);
    double kae(const std::vector<double>& X);

    // Construire F (doit être implémentée dans les classes dérivées)
    virtual void BuildF(const std::vector<double>& X) = 0;
};

#endif // _LAGRANGIENNE_H
