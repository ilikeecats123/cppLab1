#ifndef CLASSES_H
#define CLASSES_H

#include <map>
#include <queue>

using namespace std;

class SolvedTaskWithName {
    public:
        double a;
        double b;
        double c;
        string studentName;
        vector<double> solution;
        SolvedTaskWithName(double _a, double _b, double _c, string _studentName, vector<double> _solution);
};

class Task {
    public:
        double a;
        double b;
        double c;
        Task(double _a, double _b, double _c);
};



class Student{
    private:
        string name;
        double correctAnswerChance;
    public:
        Student(string _name, double _correctAnswerChance);
        double GetAnswerChance();
        vector<double> Solve(double a, double b, double c);
        string GetName();
};

class GoodStudent : public Student{
    public:
        GoodStudent(string _name);
};

class BadStudent : public Student{
    public:
        BadStudent(string _name);
};


class NormalStudent : public Student{
    public:
        NormalStudent(string _name, double _correctAnswerChance);
};


class Teacher{
    private:
        map<string, int> gradebook;
        queue<SolvedTaskWithName> studentsSolutionsQueue;

        void IncreaseStudentGrades(string studentName, int increaseValue);
    public:
        Teacher();

        int GetStudentGrades(string studentName);

        void RecieveTask(SolvedTaskWithName stwn);

        void CheckRecievedTasks();

        void PrintGradebook(ofstream &file);
};


#endif // CLASSES_H
