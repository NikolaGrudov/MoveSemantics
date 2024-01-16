#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Subject.h"


Subject::Subject(const char* nameOfSubject, const char* nameOfTeacher): subject_len(strlen(nameOfSubject)), teacher_len(strlen(nameOfTeacher))
{
    m_nameOfSubject = new char[subject_len+1];
    strcpy(m_nameOfSubject, nameOfSubject);
    m_nameOfTeacher = new char[teacher_len+1];
    strcpy(m_nameOfTeacher, nameOfTeacher);
}

size_t Subject::getSubLen()
{
    return subject_len;
}
size_t Subject::getTeaLen()
{
    return teacher_len;
}
const char* Subject::getSubName() const
{
    return m_nameOfSubject;
}
const char* Subject::getTeaName() const
{
    return m_nameOfTeacher;
}

void Subject::printSubject(const Subject& s) const
{

}
