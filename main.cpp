#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


void PrintSolution(ofstream &file, vector<double> solution){
    if (solution.capacity() == 0)
        file << "No real roots" << endl;
    else if (solution.capacity() == 1)
        file << solution[0] << endl;
    else
        file << solution[0] << " " << solution[0] <<  endl;
}

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


vector<double> SolveLinear(double b, double c){
    vector<double> solution;
    if (!(b == 0))
        solution.push_back(-c/b);
    return solution;
}


vector<double> SolveQuadratic(double a, double b, double c){
    vector<double> solution;
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

int main(){
    double a, b, c;
    vector<double> solution;
    ifstream infile("input.txt");
    ofstream ofile("output.txt");

    while (infile >> a >> b >> c){
        solution = SolveQuadratic(a,b,c);
        PrintSolution(ofile, solution);
        solution.clear();
    }


    return 0;
}
