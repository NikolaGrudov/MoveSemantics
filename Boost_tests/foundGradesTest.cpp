#define BOOST_TEST_DYN_LINK 
#define BOOST_TEST_MODULE MoveSemantics
#include <boost/test/unit_test.hpp>
#include "vector"
#include <Student.h>
#include <Subject.h>

BOOST_AUTO_TEST_SUITE(foundGrades)
BOOST_AUTO_TEST_CASE(foundGrades)
{
    std::vector<double> gr {5,2,2, 3.3};
    std::vector <Subject*> subjects1;
    
    Subject *maths = new Subject("Maths", "Gogev");
    subjects1.push_back(maths);
    Student s1("Ivan", 18, gr, subjects1);

    
    std::vector<double> fgrades{};
    BOOST_CHECK(s1.foundGrades(gr, fgrades) == true);
    delete maths;
    subjects1.clear();
    gr.clear();
}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(averageGrades)
BOOST_AUTO_TEST_CASE(averageGrades)
{
    std::vector <double> gr {5,5,4,4};
    std::vector <Subject*> subjects1;
    
    Subject *maths = new Subject("Maths", "Gogev");
    subjects1.push_back(maths);
    Student s1("Ivan", 18, gr, subjects1);
    BOOST_CHECK(s1.averageGrades(gr) == 4.5);
    delete maths;
    subjects1.clear();
    gr.clear();
}
BOOST_AUTO_TEST_SUITE_END()
