#include <iostream>
#include <string>
#include <cstring>
#include <vector>

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
    
    bool foundGrades(const std::vector<double>& grades, std::vector<double>& foundgrades)
    {
        bool GoodGrades = false;
        for(auto i = grades.begin(); i!= grades.end(); ++i)
        {
            if(*i == 4 || *i == 5)
            {
                foundgrades.push_back(*i);
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

    const std::vector<double> getGrades() const
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

void print(const std::vector<double>& vect)
    {
        for(auto i = vect.begin();i!= vect.end();++i)
            std::cout<<*i<<" ";
        std::cout<<std::endl;
    }

int main()
{
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
    
}
