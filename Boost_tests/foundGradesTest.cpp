#define BOOST_TEST_DYN_LINK 
#define BOOST_TEST_MODULE MoveSemantics
#include <boost/test/unit_test.hpp>
#include "vector"
#include <Student.h>

BOOST_AUTO_TEST_SUITE(foundGrades)
BOOST_AUTO_TEST_CASE(foundGrades)
{
    std::vector<double> gr {5,2,2, 3.3};
    Student s1("Ivan", 18, 5.5, gr);

    
    std::vector<double> fgrades{};
    BOOST_CHECK(s1.foundGrades(gr, fgrades) == true);
}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(averageGrades)
BOOST_AUTO_TEST_CASE(averageGrades)
{
    const std::vector<double> gr {5,5,4,4};
    Student s1("Ivan", 18, 5.5, gr);
    BOOST_CHECK(s1.averageGrades(gr) == 4.5);
}
BOOST_AUTO_TEST_SUITE_END()
