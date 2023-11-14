#ifndef __Student.h__
#define __Student.h__

#include <vector>
#include <iostream>
#include <cstring>

void print(const std::vector<double>& vect)
    {
        for(auto i : vect)
            std::cout<<i<<" ";
        std::cout<<std::endl;
    }

class Student
{
    public:
    //constructor
    Student(const char* name, unsigned int age, double GPA, const std::vector<double>& grades): m_grades(grades), name_len(strlen(name)), m_age(age), m_GPA(GPA)
    {
        m_name = new char[name_len+1];
        strcpy(m_name, name);
    }
    
    //copy constructor
    Student(const Student& other): m_grades(other.m_grades), name_len(other.name_len), m_age(other.m_age), m_GPA(other.m_GPA)
    {   
        m_name = new char[name_len+1];
        strcpy(m_name, other.m_name);
    }
    //move constructor
    Student (Student&& other) noexcept : name_len(other.name_len), m_name(other.m_name), m_age(other.m_age), m_GPA(other.m_GPA), m_grades(other.m_grades)
    {
        other.m_grades.clear();  
        other.name_len = 0;
        other.m_name = nullptr;
        other.m_age = 0;
        other.m_GPA = 0;
    }
    //destructor
    ~Student()
    {
        delete[] m_name;
    }
    //assignment operator

    Student& operator=(const Student& other)
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
        }
        return *this;   
    }
    //move assignment operator
    Student& operator=(Student&& other) noexcept
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

            other.m_grades.clear();
            other.name_len = 0;
            other.m_name = nullptr;
            other.m_age = 0;
            other.m_GPA = 0;
        }
        return *this; 
    }
    
    bool foundGrades(const std::vector<double>& grades, std::vector<double>& foundgrades)
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

    size_t len()
    {
        return name_len;
    }

    const char* c_str() const
    {
        return m_name;
    }
    const unsigned int getAge() const
    {
        return m_age;
    }
    const double getGPA() const
    {
        return m_GPA;
    }

    const std::vector<double>& getGrades() const
    {
        return m_grades;
    }
    private:
    char* m_name;
    size_t name_len;
    unsigned int m_age;
    double m_GPA;
    std::vector <double> m_grades;
};
#endif