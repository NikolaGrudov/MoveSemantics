#include <iostream>
#include <string>
#include <cstring>
#include <vector>

class Student
{
    public:
    //constructor
    Student(const char* name, unsigned int age, double GPA, std::vector<double>& grades): name_len(strlen(name)), m_age(age), m_GPA(GPA)
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
        other.m_grades ={0};  
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

            other.m_grades = {0};
            other.name_len = 0;
            other.m_name = nullptr;
            other.m_age = 0;
            other.m_GPA = 0;
        }
        return *this; 
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
    void print()
    {
        for(auto i = m_grades.begin();i!= m_grades.end();++i)
        std::cout<<*i<<", ";
        std::cout<<std::endl;
    }
    
    private:
    char* m_name;
    size_t name_len;
    unsigned int m_age;
    double m_GPA;
    std::vector <double> m_grades;
};

int main()
{
    std::vector<double> gr{5,6,5,6,5.5};
    std::vector<double> gr2{1,5,3,3};
    std::vector<double> gr3{2,2,2,2};
    //move constructor
    Student s1("Ivan", 18, 5.5, gr);
    Student s2(std::move(s1));


    if(s1.c_str()== nullptr)
    {
        std::cout<<"nullptr "<<" "<<s1.getAge()<<" "<<s1.getGPA()<<" ";
        s1.print();
    }

    std::cout<<"NAME: "<< s2.c_str()<<" AGE: "<<s2.getAge()<<" GPA: "<<s2.getGPA()<<" GRADES: ";
    s2.print();

    //move assignment operator
    Student s3("Gogo", 14, 3, gr2);
    Student s4("Nikola", 20, 2, gr3);


    std::cout<<"NAME: "<<s3.c_str()<<" AGE: "<<s3.getAge()<<" GPA: "<<s3.getGPA()<<" GRADES: ";
    s3.print();
    
    s3 = std::move(s4);
    std::cout<<"NAME: "<<s3.c_str()<<" AGE: "<<s3.getAge()<<" GPA: "<<s3.getGPA()<<" GRADES: ";
    s3.print();
    if(s4.c_str() == nullptr)
    {
        std::cout<<"nullptr "<<" "<<s4.getAge()<<" "<<s4.getGPA()<<" ";
        s4.print();
    }
    //copy constructor
    Student s5(s2);


    std::cout<<"NAME: "<<s5.c_str()<<" AGE: "<<s5.getAge()<<" GPA: "<<s5.getGPA()<<" GRADES: ";
    s5.print();
    //copy assignment constructor
    Student s6("Pepi", 3, 2, gr);
    

    s6 = s5;
    std::cout<<"NAME: "<<s6.c_str()<<" AGE: "<<s6.getAge()<<" GPA: "<<s6.getGPA()<<" GRADES: ";
    s6.print();
}
