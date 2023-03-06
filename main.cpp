#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;


void PrintSolution(){
    cout << "No real roots" << endl;
}

void PrintSolution(double root){
    cout << root << endl;
}

void PrintSolution(double root1, double root2){
    cout << root1 << " " << root2 <<  endl;
}

double Discriminant(double a, double b, double c){
    return b * b - 4 * a * c;
}

//double CoefInput(double * ap, double * bp, double * cp){
//    cout << "Enter coefficients" << endl;
//    cin >> *ap >> *bp >> *cp;
//    cout << "Your equation:\nx^2 * " << *ap << " + x * " << *bp << " + " << *cp << " = 0" << endl;
//}

bool IsDiscriminantNegative(double D){
    if (D < 0)
        return true;
    return false;
}


double FindRoot(double a, double b, double sqrtD){
    return (-b + sqrtD) / (2 * a);
}

bool IsQuadratic(double a){
    if (a != 0)
        return true;
    return false;
}


void SolveLinear(double b, double c){
    if (b == 0)
        PrintSolution();
    else
        PrintSolution(-c/b);
}


void SolveQuadratic(double a, double b, double c){
    if (!IsQuadratic(a)){
        SolveLinear(b,c);
        return;
    }
    double D = Discriminant(a, b, c);
    if (IsDiscriminantNegative(D))
        PrintSolution();
    else {
        D = sqrt(D);
        double root1 = FindRoot(a, b, D);
        if (D == 0)
            PrintSolution(root1);
        else {
            double root2 = FindRoot(a, b, -D);
            PrintSolution(root1, root2);
        }
    }
    return;
}

int main(){
    double a, b, c;
    ifstream infile("input.txt");
    ofstream ofile("output.txt");

    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(ofile.rdbuf());

    while (infile >> a >> b >> c){
        SolveQuadratic(a,b,c);
    }
    return 0;
}
