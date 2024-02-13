#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Student.h"
#include "Subject.h"

    //constructor
    Student::Student(const char* name, unsigned int age, double GPA, const std::vector<double>& grades, const std::vector<Subject*>& subjects): m_grades(grades), name_len(strlen(name)), m_age(age), m_GPA(GPA), m_subjects(subjects)
    {
        
        m_name = new char[name_len+1];
        strcpy(m_name, name);
    }
    
    //copy constructor
    Student::Student(const Student& other): m_grades(other.m_grades), name_len(other.name_len), m_age(other.m_age), m_GPA(other.m_GPA), m_subjects(other.m_subjects)
    {   
        m_name = new char[name_len+1];
        strcpy(m_name, other.m_name);
    }
    //move constructor
    Student::Student (Student&& other) noexcept : name_len(other.name_len), m_name(other.m_name), m_age(other.m_age), m_GPA(other.m_GPA), m_grades(other.m_grades), m_subjects(other.m_subjects)
    {
        other.m_grades.clear();  
        other.name_len = 0;
        other.m_name = nullptr;
        other.m_age = 0;
        other.m_GPA = 0;
        other.m_subjects.clear();
    }
    //destructor
    Student::~Student()
    {
        delete[] m_name;
    }
    //assignment operator

    Student& Student::operator=(const Student& other)
    {
        if(this != &other)
        {
            delete [] m_name;
            
            m_grades = other.m_grades;
            name_len= other.name_len;
            m_name = new char[name_len+1];
            strcpy(m_name, other.m_name);
            m_age= other.m_age;
            m_GPA= other.m_GPA;
            m_subjects=other.m_subjects;

        }
        return *this;   
    }
    //move assignment operator
    Student& Student::operator=(Student&& other) noexcept
    {
        if(this != &other)
        {
            delete [] m_name;
            m_grades = other.m_grades;
            name_len= other.name_len;
            m_name = new char[name_len+1];
            strcpy(m_name, other.m_name);
            m_age= other.m_age;
            m_GPA= other.m_GPA;
            m_subjects= other.m_subjects;

            other.m_grades.clear();
            other.m_subjects.clear();
            other.name_len = 0;
            other.m_name = nullptr;
            other.m_age = 0;
            other.m_GPA = 0;
        }
        return *this; 
    }
    
    bool Student::foundGrades(const std::vector<double>& grades, std::vector<double>& foundgrades)
    {
        bool GoodGrades = false;
        for(auto i : grades)
        {
            if(i == 4 || i == 5)
            {
                foundgrades.push_back(i);
                GoodGrades = true;
            }
        }
        return GoodGrades;
        
    }

    double Student::averageGrades(const std::vector<double>& grades)
    {
        double sumOfGrades = 0;
        for(auto i : grades)
            sumOfGrades += i;
        return sumOfGrades/grades.size();
    }

    size_t Student::len()
    {
        return name_len;
    }

    const char* Student::getName() const
    {
        return m_name;
    }
    const unsigned int Student::getAge() const
    {
        return m_age;
    }
    const double Student::getGPA() const
    {
        return m_GPA;
    }

    const std::vector<double>& Student::getGrades() const
    {
        return m_grades;
    }

    const std::vector<Subject*>& Student::getSubjects() const
    {
        return m_subjects;
    }

    template <class T>
    void print(const std::vector<T>& vect)
    {
        for(auto i : vect)
            std::cout<<i<<" ";
    }

    void Student::printStudent() const
    {
        std::cout<<"Name: "<<m_name<<" Age: "<<m_age<<" Grades: ";
        print(m_grades);
        std::cout<<" Subjects: ";
        int a = 0;
        for(auto i : m_subjects)
        {
            std::cout<< m_subjects[a]->getSubName()<<" ";
            a++;
        }
        std::cout<<std::endl;
    }
