#include "Solver.h"
#include <vector>
#include <math.h>



double Discriminant(double a, double b, double c){
    return b * b - 4 * a * c;
}

bool IsDiscriminantNegative(double D){
    if (D < 0)
        return true;
    return false;
}

double FindRoot(double a, double b, double sqrtD){
    return (-b + sqrtD) / (2 * a);
}

bool IsQuadratic(double a){
    return a != 0;
}

std::vector<double> SolveLinear(double b, double c){
    std::vector<double> solution;
    if (!(b == 0))
        solution.push_back(-c/b);
    return solution;
}

std::vector<double> SolveQuadratic(double a, double b, double c){
    std::vector<double> solution;
    if (!IsQuadratic(a)){
        return SolveLinear(b,c);
    }
    double D = Discriminant(a, b, c);
    if (IsDiscriminantNegative(D))
        return solution;
    else {
        D = sqrt(D);
        double root1 = FindRoot(a, b, D);
        solution.push_back(root1);
        if (D != 0){
            double root2 = FindRoot(a, b, -D);
            solution.push_back(root2);
        }
    }
    return solution;
}
