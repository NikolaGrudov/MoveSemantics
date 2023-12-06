#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Student.h"
int main()
{

    Subject *maths = new Subject("Maths", "Gogev");
    Subject *it = new Subject("IT", "Petrov");
    Subject *sports= new Subject("Sports", "Balabanova");
    std::vector <Subject*> subjects1;

    subjects1.push_back(maths);
    subjects1.push_back(it);
    subjects1.push_back(sports);


    std::vector <Subject*> subjects2;
    subjects2 .push_back(maths);

    std::vector<double> gr{5,6,5,6,5.5};
    std::vector<double> gr2{1,5,3,3};
    std::vector<double> gr3{2,2,4,2};
    std::vector<double> foundgrades;

    //move constructor
    Student s1("Ivan", 18, 5.5, gr, subjects1);
    Student s2(std::move(s1));

    //move assignment operator
    Student s3("Gogo", 14, 3, gr2, subjects2);
    Student s4("Nikola", 20, 2, gr3, subjects2);
    s3 = std::move(s4);

    //copy constructor
    Student s5(s2);

    //copy assignment constructor
    Student s6("Pepi", 3, 2, gr, subjects1);

    s6 = s5;
    
    subjects1.clear();
    subjects2.clear();
    foundgrades.clear();
    
}
