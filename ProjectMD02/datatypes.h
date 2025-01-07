#include <stdbool.h>  

typedef struct {
    int day;
    int month;
    int year;
} Date;


typedef struct {
    char studentId[20];
    char classroomID[20];
    char name[40];
    Date dateOfBirth;  
    bool gender;       
    char email[50];
    char phone[20];
    char password[30];
} Student;

typedef struct {
    char classroomId[10];
    char teacherId[10];
    char classroomName[30];
    Student students[];
} Classroom;

typedef struct {
    char teacherId[10];
    char classroomId[10];
    char name[40];
    Date dateOfBirth;
    bool gender;
    char email[40];
    char phone[20];
    char password[30];
    Classroom classrooms[];
} Teacher;

