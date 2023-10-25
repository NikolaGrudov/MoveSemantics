#include <iostream>
#include <string>
#include <cstring>


class Student
{
    public:
    //constructor
    Student(const char* name, unsigned int age, double GPA): name_len(strlen(name)), m_age(age), m_GPA(GPA)
    {
        m_name = new char[name_len+1];
        strcpy(m_name, name);
    }
    
    //copy constructor
    Student(const Student& other): name_len(other.name_len), m_age(other.m_age), m_GPA(other.m_GPA)
    {   
        m_name = new char[name_len+1];
        strcpy(m_name, other.m_name);
    }
    //move constructor
    Student (Student&& other) noexcept : name_len(other.name_len), m_name(other.m_name), m_age(other.m_age), m_GPA(other.m_GPA)
    {
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
            
            name_len= other.name_len;
            m_name = new char[name_len+1];
            strcpy(m_name, other.m_name);
            m_age= other.m_age;
            m_GPA= other.m_GPA;

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
    void setAge(unsigned int age)
    {
        m_age = age;
    }
    const unsigned int getAge() const
    {
        return m_age;
    }
    void setAge(double GPA)
    {
        m_GPA = GPA;
    }
    const double getGPA() const
    {
        return m_GPA;
    }

    private:
    char* m_name;
    size_t name_len;
    unsigned int m_age;
    double m_GPA;

};

int main()
{
    //move constructor
    Student s1("Ivan", 18, 6);
    Student s2(std::move(s1));


    if(s1.c_str()== nullptr)
        std::cout<<"nullptr "<<" "<<s1.getAge()<<" "<<s1.getGPA()<<std::endl;

    std::cout<<"NAME: "<< s2.c_str()<<" AGE: "<<s2.getAge()<<" GPA: "<<s2.getGPA()<<std::endl;

    //move assignment operator
    Student s3("Gogo", 14, 3);
    Student s4("Nikola", 20, 2);


    std::cout<<"NAME: "<<s3.c_str()<<" AGE: "<<s3.getAge()<<" GPA: "<<s3.getGPA()<<std::endl;
    s3 = std::move(s4);
    std::cout<<"NAME: "<<s3.c_str()<<" AGE: "<<s3.getAge()<<" GPA: "<<s3.getGPA()<<std::endl;
    if(s4.c_str() == nullptr)
        std::cout<<"nullptr "<<" "<<s4.getAge()<<" "<<s4.getGPA()<<std::endl;

    //copy constructor
    Student s5(s2);


    std::cout<<"NAME: "<<s5.c_str()<<" AGE: "<<s5.getAge()<<" GPA: "<<s5.getGPA()<<std::endl;

    //copy assignment constructor
    Student s6("Pepi", 3, 2);


    s6 = s5;
    std::cout<<"NAME: "<<s6.c_str()<<" AGE: "<<s6.getAge()<<" GPA: "<<s6.getGPA()<<std::endl;
}
