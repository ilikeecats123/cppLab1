#include "Solver.h"
#include "Utils.h"
#include "Classes.h"

#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;


int main()
{
    srand(time(NULL));

    ofstream ofile("output.txt");



    vector<Student> students;
    // 2 good students
    students.push_back(GoodStudent("Artem"));
    students.push_back(GoodStudent("Nastya"));
    // 2 random students
    for (int i = 0; i < 10; i++)
        students.push_back(NormalStudent(GenerateRandomName(6), double((rand() % 100 / 100.0))));
    // 2 bad students
    students.push_back(BadStudent("Kirill"));
    students.push_back(BadStudent("Egor"));

    Teacher teacher = Teacher();

    ifstream infile("tasks.txt");
    vector<Task> tasks;

    double a,b,c;
    while (infile >> a >> b >> c){
        tasks.push_back(Task(a,b,c));
    }

    for (Student student : students)
    {
        for (Task task : tasks)
        {
            vector<double> studentSolution = student.Solve(task.a, task.b, task.c);
            SolvedTaskWithName stwn = SolvedTaskWithName(task.a, task.b, task.c, student.GetName(), studentSolution);
            teacher.RecieveTask(stwn);
        }
    }


    teacher.CheckRecievedTasks();
    teacher.PrintGradebook(ofile);

    return 0;
}
