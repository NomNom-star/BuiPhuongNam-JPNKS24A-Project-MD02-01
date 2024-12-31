#include <stdio.h>
#include<string.h>
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

}

// Ham in menu admin
void adminMenu(){
    printf("========Students Management System Using C========\n"
            "\t\t    ADMIN MENU \n"
            "\t =============================== \n"
            "\t     [1] Students management.\n"
            "\t     [2] Teacher management.\n"
            "\t     [3] Classroom management.\n"
            "\t     [4] User Guideline.\n"
            "\t     [5] About us.\n"
            "\t     [0] Exit the program.\n"
            "\t =============================== \n"); 	
}

// Ham in menu quan ly sinh vien 
void studentMenu(){
    printf("========Students Management System Using C========\n"
            "\t\t  STUDENT MENU \n"
            "\t =============================== \n"
            "\t     [1] Add a new student.\n"
            "\t     [2] Show all students.\n"
            "\t     [3] Search a student.\n"
            "\t     [4] Edit a student.\n"
            "\t     [5] Delete a student.\n"
            "\t     [6] Sort Student list\n\t         by name.\n"
            "\t     [0] Exit the program.\n"
            "\t =============================== \n");        
}   

// ham them 1 sinh vien 
void addStudent(Student student[], int *studentCount) {
    if (*studentCount >= 50) {
        printf("The list is full. Cannot add more students\n");
        return;
    }
	// Dien thong tin sinh vien moi
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
    saveStudentToFile(student, *studentCount);
    printf("Student added successfully!\n");
    // Hien thi thong bao quay lai menu
    printf("\nPress any key to go back: ");
    char choice;
    getchar();
    choice = getchar();
    return;
}

// ham luu thong tin sinh vien vao file
void saveStudentToFile(Student student[], int studentCount){
    FILE *ptr=fopen("studentsData.bin","wb");
    if(ptr==NULL){
        printf("Can not save file !\n");
    }
    fwrite(student,sizeof(Student),studentCount,ptr);
    fclose(ptr);
}

// ham doc thong tin sinh vien tu file
void loadStudentFromFile(Student student[], int *studentCount) {
    FILE *ptr = fopen("studentsData.bin", "rb");
    if (ptr == NULL) {
        printf("Cannot open file\n");
        return;
    }
    *studentCount = fread(student, sizeof(Student), 50, ptr);
    fclose(ptr);

}

// Ham in ra man hinh thong tin sinh vien
void displayStudent(Student student[], int studentCount){
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
    //Hien thi thong bao quay lai menu
    printf("\nPress any key to go back: ");
    char choice;
    getchar();
    choice = getchar();
    return;
}

// Ham sua thong tin sinh vien qua ID
void editStudentByID(Student student[], int studentCount) {
    if (studentCount == 0) {
        printf("No students available to edit.\n");
        return;
    }

    char id[20];
    printf("Enter Student ID to edit: ");
    scanf("%s", id);

    // Tim sinh vien theo ID
    int found = -1;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(student[i].studentId, id) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Student with ID '%s' not found.\n", id);
        return;
    }

    // Hien thi thong tin hien tai 
    printf("\nCurrent Information:\n");
    printf("Classroom ID: %s\nName: %s\nDOB: %02d/%02d/%04d\nGender: %s\nEmail: %s\nPhone: %s\n",
           student[found].classroomID, student[found].name, student[found].dateOfBirth.day,
           student[found].dateOfBirth.month, student[found].dateOfBirth.year,
           student[found].gender ? "Male" : "Female", student[found].email, student[found].phone);

    // Nhap thong tin moi 
    printf("\nEnter new Classroom ID: ");
    scanf("%s", student[found].classroomID);

    printf("Enter new Name: ");
    getchar();
    fgets(student[found].name, sizeof(student[found].name), stdin);
    student[found].name[strcspn(student[found].name, "\n")] = 0;

    printf("Enter new Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &student[found].dateOfBirth.day, &student[found].dateOfBirth.month, &student[found].dateOfBirth.year);

    printf("Enter new Gender (0 for Female, 1 for Male): ");
    scanf("%d", &student[found].gender);

    printf("Enter new Email: ");
    getchar();
    fgets(student[found].email, sizeof(student[found].email), stdin);
    student[found].email[strcspn(student[found].email, "\n")] = 0;

    printf("Enter new Phone: ");
    fgets(student[found].phone, sizeof(student[found].phone), stdin);
    student[found].phone[strcspn(student[found].phone, "\n")] = 0;

    // Luu danh sach sau khi da sua 
    printf("\nStudent information updated successfully!\n");
	saveStudentToFile(student, studentCount);
    // Hien thi thong bao quay lai menu 
    printf("\nPress any key to go back: ");
    char choice;
    getchar();
    choice = getchar();
    return;
}

// Ham xoa sinh vien 
void deleteStudent(Student student[], int *studentCount){
	 if (studentCount == 0) {
        printf("No students available to delete.\n");
        return;
    }

    char id[20];
    printf("Enter Student ID to delete: ");
    scanf("%s", id);

    // Tim sinh vien theo ID
    int found = -1;
    for (int i = 0; i < *studentCount; i++) {
        if (strcmp(student[i].studentId, id) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Student with ID '%s' not found.\n", id);
        return;
    }

    // Hien thi thong tin sinh vien muon xoa
    printf("\nStudent Found:\n");
    printf("Classroom ID: %s\nName: %s\nDOB: %02d/%02d/%04d\nGender: %s\nEmail: %s\nPhone: %s\n",
           student[found].classroomID, student[found].name, student[found].dateOfBirth.day,
           student[found].dateOfBirth.month, student[found].dateOfBirth.year,
           student[found].gender ? "Male" : "Female", student[found].email, student[found].phone);
    // Xac nhan xoa sinh vien 
    printf("\nPress 'y' to confirm deleting student !\n");
   	char choice;
	getchar();
	choice = getchar();
	if(choice != 'y' && choice != 'Y'){
		printf("Cancelled!\n");
		return;
	}
	// Xoa sinh vien 
	for(int i = found; i < found; i++){
		student[i] = student[i+1];
	}
	(*studentCount)--;
	// Luu thong tin sinh vien sau khi xoa 
	saveStudentToFile(student, *studentCount);
	// Thong bao da xoa thanh cong
	printf("Student with ID: %s has been deleted successfully!\n", id);
    // Hien thi thong bao quay lai menu 
    printf("\nPress any key to go back: ");
    getchar();
    choice = getchar();
    return;
}
    
// Ham sap xep sinh vien theo ten
void sortStudentByName(Student student[], int studentCount){
    if (studentCount < 2) {
        printf("Not enough students to sort.\n");
        return;
    }

    int choice;
    printf("\nChoose sort order:\n");
    printf("[1] Ascending (A-Z)\n");
    printf("[2] Descending (Z-A)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Sap xep
    if (choice == 1) {
        sortAscending(student, studentCount);  
    } else if (choice == 2) {
        sortDescending(student, studentCount); 
    } else {
        printf("Invalid choice!\n");
        return;
    }

    // Hien thi danh sach sau khi sap xep
    printf("\nStudent list after sorting:\n");
    displayStudent(student, studentCount);	
    // Luu danh sach sau khi da sua 
	saveStudentToFile(student, studentCount);
}

// Ham sap xep ten A-Z
void sortAscending(Student student[], int studentCount){
	for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            int cmp = strcmp(student[i].name, student[j].name);
            if (cmp > 0) {
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }	
}

// Ham sap xep ten Z-A
void sortDescending(Student student[], int studentCount){
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            int cmp = strcmp(student[i].name, student[j].name);
            if (cmp < 0) {
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }
}








