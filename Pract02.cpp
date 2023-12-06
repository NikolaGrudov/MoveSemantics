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
    std::vector <Subject*> subjects;

    subjects.push_back(maths);
    subjects.push_back(it);
    subjects.push_back(sports);

    
    std::vector<double> gr{5,6,5,6,5.5};
    std::vector<double> gr2{1,5,3,3};
    std::vector<double> gr3{2,2,4,2};
    std::vector<double> foundgrades;
    //move constructor
    Student s1("Ivan", 18, 5.5, gr);
    Student s2(std::move(s1));


    if(s1.c_str()== nullptr)
    {
        std::cout<<"nullptr "<<" "<<s1.getAge()<<" "<<s1.getGPA()<<" ";
    }

    std::cout<<"NAME: "<< s2.c_str()<<" AGE: "<<s2.getAge()<<" GPA: "<<s2.getGPA()<<" GRADES: ";
    print(s2.getGrades());
    std::cout<<"true or false: "<<s2.foundGrades(s2.getGrades(), foundgrades)<<" other grades: ";
    print(foundgrades);
    foundgrades.clear();

    //move assignment operator
    Student s3("Gogo", 14, 3, gr2);
    Student s4("Nikola", 20, 2, gr3);


    std::cout<<"NAME: "<<s3.c_str()<<" AGE: "<<s3.getAge()<<" GPA: "<<s3.getGPA()<<" GRADES: ";
    print(s3.getGrades());
    std::cout<<"true or false: "<<s3.foundGrades(s3.getGrades(), foundgrades)<<" other grades: ";
    print(foundgrades);
    foundgrades.clear();
    
    s3 = std::move(s4);
    std::cout<<"NAME: "<<s3.c_str()<<" AGE: "<<s3.getAge()<<" GPA: "<<s3.getGPA()<<" GRADES: ";
    print(s3.getGrades());
    std::cout<<"true or false: "<<s3.foundGrades(s3.getGrades(), foundgrades)<<" other grades: ";
    print(foundgrades);
    foundgrades.clear();

    if(s4.c_str() == nullptr)
    {
        std::cout<<"nullptr "<<" "<<s4.getAge()<<" "<<s4.getGPA()<<" ";
    }


    //copy constructor
    Student s5(s2);


    std::cout<<"NAME: "<<s5.c_str()<<" AGE: "<<s5.getAge()<<" GPA: "<<s5.getGPA()<<" GRADES: ";
    print(s5.getGrades());
    std::cout<<"true or false: "<<s5.foundGrades(s5.getGrades(), foundgrades)<<" other grades: ";
    print(foundgrades);
    foundgrades.clear();


    //copy assignment constructor
    Student s6("Pepi", 3, 2, gr);
    

    s6 = s5;
    std::cout<<"NAME: "<<s6.c_str()<<" AGE: "<<s6.getAge()<<" GPA: "<<s6.getGPA()<<" GRADES: ";
    print(s6.getGrades());
    std::cout<<"true or false: "<<s6.foundGrades(s6.getGrades(), foundgrades)<<" other grades: ";
    print(foundgrades);
    foundgrades.clear();
    subjects.clear();
    
}
