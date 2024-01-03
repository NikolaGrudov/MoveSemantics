#ifndef __Student_h__
#define __Student_h__
#include <vector>
#include <iostream>
#include "Subject.h"



class Student
{
public:
    Student(const char* name, unsigned int age, double GPA, const std::vector<double>& grades, const std::vector<Subject*> &subjects);    
    Student(const Student& other);
    Student(Student&& other) noexcept;
    ~Student();
    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;
    bool foundGrades(const std::vector<double>& grades, std::vector<double>& foundgrades);
    double averageGrades(const std::vector<double>& grades);
    size_t len();
    const char* c_str() const;
    const unsigned int getAge() const;
    const double getGPA() const;
    const std::vector<double>& getGrades() const;
    const std::vector<Subject*> getSubjects() const;
    void printStudent(const Student& student);

    

    private:
    char* m_name;
    size_t name_len;
    unsigned int m_age;
    double m_GPA;
    std::vector <double> m_grades;
    std::vector <Subject*> m_subjects;

};
    template <class T>
    void print(const std::vector<T>& vect);

#endif
