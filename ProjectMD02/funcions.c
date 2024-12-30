#include <stdio.h>
#include "funcions.h"
// Khai bao logic ham

// Ham in menu bat dau
void mainMenu(){

    printf("========Students Management System Using C========\n"
            "\t\t CHOOSE YOUR ROLE \n"
            "\t =============================== \n"
            "\t\t[1] Admin.\n"
            "\t\t[2] Student.\n"
            "\t\t[3] Teacher.\n"
            "\t\t[0] Exit the program\n"
            "\t =============================== \n");

// ham in menu quan ly sinh vien
} 
void studentMenu(){
    printf("========Students Management System Using C========\n"
            "\t\t STUDENT MENU \n"
            "\t =============================== \n"
            "\t\t[1] Add a new student.\n"
            "\t\t[2] Show all students.\n"
            "\t\t[3] Search a student.\n"
            "\t\t[4] Edit a student.\n"
            "\t\t[5] Delete a student.\n"
            "\t\t[0] Exit the program.\n"
            "\t =============================== \n");        
}   
// ham them 1 sinh vien 
void addStudent(Student student[], int *studentCount) {
    if (*studentCount >= 50) {
        printf("The list is full. Cannot add more students\n");
        return;
    }

    Student newStudent;

    printf("Enter Student ID: ");
    scanf("%s", newStudent.studentId);
    getchar();

    printf("Enter Classroom ID: ");
    scanf("%s", newStudent.classroomID);
    getchar();

    printf("Enter Name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;

    printf("Enter Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &newStudent.dateOfBirth.day, &newStudent.dateOfBirth.month, &newStudent.dateOfBirth.year);
    getchar();

    printf("Enter Gender (0 for Female, 1 for Male): ");
    scanf("%d", &newStudent.gender);
    getchar();

    printf("Enter Email: ");
    fgets(newStudent.email, sizeof(newStudent.email), stdin);
    newStudent.email[strcspn(newStudent.email, "\n")] = 0;

    printf("Enter Phone: ");
    fgets(newStudent.phone, sizeof(newStudent.phone), stdin);
    newStudent.phone[strcspn(newStudent.phone, "\n")] = 0;

    printf("Enter Password: ");
    fgets(newStudent.password, sizeof(newStudent.password), stdin);
    newStudent.password[strcspn(newStudent.password, "\n")] = 0;

    student[*studentCount] = newStudent;
    (*studentCount)++;
    saveStudentsToFile(student, *studentCount);
    printf("Student added successfully!\n");
    printf("\nPress 'b' to go back to the main menu: ");
    char choice;
    getchar();
    choice = getchar();
    if (choice == 'b' || choice == 'B') return;
}
// ham luu thong tin sinh vien vao file
void saveStudentsToFile(Student student[], int studentCount){
    FILE *ptr=fopen("studentsData.bin","ab");
    if(ptr==NULL){
        printf("Can not save file !\n");
    }
    fwrite(student,sizeof(Student),studentCount,ptr);
    fclose(ptr);
}
// ham doc thong tin sinh vien tu file
void loadStudentsFromFile(Student student[], int *studentCount) {
    FILE *ptr = fopen("studentsData.bin", "rb");
    if (ptr == NULL) {
        printf("Cannot open file\n");
        return;
    }
    *studentCount = fread(student, sizeof(Student), 50, ptr);
    fclose(ptr);

}
// Ham in ra man hinh thong tin sinh vien
void displayStudents(Student student[], int studentCount){
     if (studentCount == 0) {
        printf("No data loaded from file.\n");
        return;
    }

    printf("\n%-10s| %-10s| %-30s| %-10s| %-10s| %-30s| %-15s|\n", 
           "ID", "ClassID", "Name", "DOB", "Gender", "Email", "Phone");
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10s| %-10s| %-30s| %02d/%02d/%04d| %-10s| %-30s| %-15s|\n", 
               student[i].studentId, student[i].classroomID, student[i].name, 
               student[i].dateOfBirth.day, student[i].dateOfBirth.month, student[i].dateOfBirth.year, 
               student[i].gender ? "Male" : "Female", student[i].email, student[i].phone);
    }
    printf("\nPress 'b' to go back to the main menu: ");
    char choice;
    getchar();
    choice = getchar();
    if (choice == 'b' || choice == 'B') return;
}
// Ham sua thong tin sinh vien
void editStudent(Student student[], int *studentCount){
};
    
