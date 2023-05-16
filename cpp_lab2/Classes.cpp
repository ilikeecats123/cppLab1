#include "Utils.h"
#include "Solver.h"
#include "Classes.h"

#include <fstream>

using namespace std;

SolvedTaskWithName::SolvedTaskWithName(double _a, double _b, double _c, string _studentName, vector<double> _solution)
{
    a = _a; b = _b; c = _c;
    studentName = _studentName;
    solution = _solution;
}


Task::Task(double _a, double _b, double _c)
{
    a = _a; b = _b; c = _c;
}




Student::Student(string _name, double _correctAnswerChance)
{
    name = _name;
    correctAnswerChance = _correctAnswerChance;
}

GoodStudent::GoodStudent(string _name) : Student::Student(_name, 1.0) {};
BadStudent::BadStudent(string _name) : Student::Student(_name, 0.0) {};
NormalStudent::NormalStudent(string _name, double _correctAnswerChance) : Student::Student(_name, _correctAnswerChance) {};

double Student::GetAnswerChance()
{
    return correctAnswerChance;
}


vector<double> Student::Solve(double a, double b, double c)
{
    vector<double> solution;
    double rnd = double((rand() % 100 / 100.0));

    if (correctAnswerChance >= rnd)
        solution = SolveQuadratic(a, b, c);
    else
        solution.push_back(0.0);

    return solution;
}

string Student::GetName()
{
    return name;
}

Teacher::Teacher(){};

void Teacher::IncreaseStudentGrades(string studentName, int increaseValue)
{
    if (gradebook.find(studentName) != gradebook.end())
       gradebook[studentName] = gradebook[studentName] + increaseValue;
    else
        gradebook.insert(pair<string, int>(studentName, increaseValue));
}


int Teacher::GetStudentGrades(string studentName)
{
    if (gradebook.find(studentName) != gradebook.end())
        return gradebook[studentName];
    else
        return 0;
}

void Teacher::RecieveTask(SolvedTaskWithName stwn)
{
    studentsSolutionsQueue.push(stwn);
}

void Teacher::CheckRecievedTasks()
{
    while (!studentsSolutionsQueue.empty())
    {
        SolvedTaskWithName stwn = studentsSolutionsQueue.front();
        if (stwn.solution == SolveQuadratic(stwn.a, stwn.b, stwn.c))
            IncreaseStudentGrades(stwn.studentName, 1);
        else
            IncreaseStudentGrades(stwn.studentName, 0);

        studentsSolutionsQueue.pop();
    }
}


void Teacher::PrintGradebook(ofstream &file)
{
    for (pair<string, int> nameGradePair : gradebook)
    {
        file << nameGradePair.first << ": " << nameGradePair.second << endl;
    }
}

