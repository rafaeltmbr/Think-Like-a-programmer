#ifndef SCHOOL_RECORD_HPP
#define SCHOOL_RECORD_HPP

#include <string>
#include <vector>

typedef unsigned int student_id_t;
typedef unsigned int student_grade_t;
typedef unsigned int student_count_t;
typedef unsigned int student_status_t;
typedef char student_letter_t;
typedef unsigned int grade_status_t;

struct grade_s {
    student_letter_t letter;
    student_grade_t startRange;
    student_grade_t endRande;
};

class Grade {
public:
    Grade();
    Grade(Grade& grade);
    grade_status_t addGrade(
        student_letter_t letter,
        student_grade_t startRange,
        student_grade_t endRange
    );
    grade_s getGradeByLetter(student_letter_t letter) const;
    grade_s getGradeByValue(student_grade_t value) const;
    static const grade_status_t invalidGrade{ 0x01 };
    static const grade_status_t invalidLetter{ 0x02 };
    static const grade_status_t invalidRange{ 0x04 };

protected:
    std::vector<grade_s> gradeList;
};

class Student {
public:
    Student();
    Student(student_id_t id, std::string name = "", student_grade_t grade = 0);
    student_id_t id(void) const;
    bool setId(student_id_t newId);
    student_grade_t grade(void) const;
    bool setGrade(int newGrade);
    std::string name(void) const;
    bool setName(std::string newName);
    static bool isValidId(student_id_t id);
    static bool isValidGrade(student_grade_t grade);
    static bool isValidName(std::string name);

protected:
    student_id_t _id = ClassRecord::defaultId;
    student_grade_t _grade = 0;
    std::string _name = "";
};

class ClassRecord {
public:
    ClassRecord();
    ClassRecord(ClassRecord& classRecord);
    ~ClassRecord();
    student_count_t studentCount(void) const;
    student_status_t addNewStudent(student_id_t id, std::string name = "", student_grade_t grade = 0);
    student_grade_t getGradeAverage(void);
    Student* getStudentById(student_id_t id) const;
    Student* getStudentByName(std::string name) const;
    static const student_grade_t maxGrade{ 100 };
    static const student_id_t defaultId{ 0 };
    static const student_status_t invalidIdStatus{ 0x01 };
    static const student_status_t invalidGradeStatus{ 0x02 };
    static const student_status_t invalidNameStatus{ 0x04 };

protected:
    student_count_t _studentCount = 0;
    std::vector<Student> students;
    Grade* grade;
};
#endif //SCHOOL_RECORD_HPP