#ifndef __Subject_h__
#define __Subject_h__
#include <vector>
#include <iostream>

class Subject
{
public:
    Subject(const char* nameOfSubject, const char* nameOfTeacher);
    size_t getSubLen();
    size_t getTeaLen();
    const char* getSubName() const;
    const char* getTeaName() const;

private:
    char* m_nameOfSubject;
    char* m_nameOfTeacher;
    size_t subject_len;
    size_t teacher_len;
};

#endif
