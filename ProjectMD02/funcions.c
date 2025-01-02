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

// Ham lua chon thoat chuong trinh
void waitAndClear(){
    char choice;
    while (1) {
        printf("\nPress 'b' to go back to the main menu or '0' to exit the program: ");
        scanf(" %c", &choice); 

        if (choice == '0') {
            printf("\nExiting the program. Goodbye!\n");
            exit(0); 
        } else if (choice == 'b' || choice == 'B') { 
            system("cls"); 
            return;        
        } else {
            printf("\nInvalid input. Please enter 'b' to go back or '0' to exit.\n");
        }
    }	
}

// Ham them 1 sinh vien 
void addStudent(Student student[], int *studentCount) {
    if (*studentCount >= 50) {
        printf("The list is full. Cannot add more students\n");
        waitAndClear();
        return;
    }
	// Dien thong tin sinh vien moi
    Student newStudent;
	
	// Student ID 
	do {
		fflush(stdin); 
	    printf("Enter Student ID( Max 10 characters): ");
	    fgets(newStudent.studentId, sizeof(newStudent.studentId), stdin);
	
	    newStudent.studentId[strcspn(newStudent.studentId, "\n")] = 0;
	
	    if (isNotEmpty(newStudent.studentId) != 1) {
	    	system("cls");
	        printf("Cannot be empty! Please try again.\n");
	    }
	    
	    if(isDuplicateStudentId(student, *studentCount, newStudent.studentId) == 1 ){
	    	system("cls");
	    	printf("Student ID already exists. Enter other ID.\n");
		}
		if(checkStudentIdValid( newStudent.studentId) != 1){
			system("cls");
			printf("Invalid Student ID. Please try again.\n");
		}
	    
	} while (isNotEmpty(newStudent.studentId) != 1 || isDuplicateStudentId(student, *studentCount, newStudent.studentId) == 1 || checkStudentIdValid( newStudent.studentId) != 1);
	// Classroom ID	
	do{
		fflush(stdin);
		printf("Enter Classroom ID( Max 10 characters ): ");
		fgets(newStudent.classroomID, sizeof(newStudent.classroomID), stdin);
		newStudent.classroomID[strcspn(newStudent.classroomID, "\n")] = 0;
		
	    if (isNotEmpty(newStudent.classroomID) != 1) {
	        printf("Cannot be empty! Please try again.\n");
	    }	
		if(checkClassroomIdValid(newStudent.classroomID) != 1){
			printf("Invalid Classroom ID. Please try again.\n");
		}	

	}while (isNotEmpty(newStudent.classroomID) != 1 || checkClassroomIdValid(newStudent.classroomID) != 1);
	// Ten
	do{
		fflush(stdin);
		printf("Enter Name( Max 40 characters): ");
	    fgets(newStudent.name, sizeof(newStudent.name), stdin);
	    newStudent.name[strcspn(newStudent.name, "\n")] = 0;
	    
	    if(isNotEmpty(newStudent.name) != 1){
	    	printf("Cannot be empty! Please try again.\n");
		}
		if(checkNameValid(newStudent.name) != 1 && strlen(newStudent.name) != 0){
			printf("Invalid Name. Please try again.\n");
		}
	} while (isNotEmpty(newStudent.name) != 1 || checkNameValid(newStudent.name) != 1);
	// Ngay sinh
	do{
		printf("Enter Date of Birth (DD MM YYYY): ");
	    scanf("%d %d %d", &newStudent.dateOfBirth.day, &newStudent.dateOfBirth.month, &newStudent.dateOfBirth.year);
   		getchar();
   		
   		if(checkDateValid(newStudent.dateOfBirth.day,newStudent.dateOfBirth.month,newStudent.dateOfBirth.year) != 1){
   			printf(" Invalid date of birth. Please try again.\n");
		   }
	} while (checkDateValid(newStudent.dateOfBirth.day,newStudent.dateOfBirth.month,newStudent.dateOfBirth.year) != 1);
	// Gioi tinh
	do{
		printf("Enter Gender (0 for Female, 1 for Male): ");
	    scanf("%d", &newStudent.gender);
	    getchar();
		if(checkGenderValid(newStudent.gender) != 1){
			printf("Invalid Gender. Please try again.\n");
		}
	}while (checkGenderValid(newStudent.gender) != 1);
	// Email
	do{
		printf("Enter Email(6-50 characters): ");
	    fgets(newStudent.email, sizeof(newStudent.email), stdin);
	    newStudent.email[strcspn(newStudent.email, "\n")] = 0;
	    
		if(isDuplicateEmail(student, *studentCount, newStudent.email) == 1 ){
			printf("Email already exists. Enter other email.\n");
		}
		if(checkEmailValid(newStudent.email) != 1 ){
			printf("Invalid email. Please try again.\n");
		}
	}while( isDuplicateEmail(student, *studentCount, newStudent.email) == 1 || checkEmailValid(newStudent.email) != 1);
	// So dien thoai
	do{
		fflush(stdin);
		printf("Enter Phone( 10-15 digits): ");
	    fgets(newStudent.phone, sizeof(newStudent.phone), stdin);
	    newStudent.phone[strcspn(newStudent.phone, "\n")] = 0;
	    	 
		if(isDuplicatePhone(student, *studentCount, newStudent.phone) == 1){
			printf("Phone already exists. Enter other phone.\n");
		}  
		if(checkPhoneValid(newStudent.phone) != 1){
			printf("Invalid phone. Please try again.\n");
		}
	} while( isDuplicatePhone(student, *studentCount, newStudent.phone) == 1 || checkPhoneValid(newStudent.phone) != 1);
	// Password
	do{
		fflush(stdin);
		printf("Enter Password(6-30 characters): ");
    	fgets(newStudent.password, sizeof(newStudent.password), stdin);
    	newStudent.password[strcspn(newStudent.password, "\n")] = 0;
    	
		if(checkPasswordValid(newStudent.password) != 1){
			printf("Invalid password. Please try again.\n");
		}
    	
	} while (checkPasswordValid(newStudent.password) != 1);


    student[*studentCount] = newStudent;
    (*studentCount)++;
    saveStudentToFile(student, *studentCount);
    printf("Student added successfully!\n");
    // Hien thi thong bao quay lai menu
 	waitAndClear();

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
    }
    *studentCount = fread(student, sizeof(Student), 50, ptr);
    fclose(ptr);
}

// Ham in ra man hinh thong tin sinh vien
void displayStudent(Student student[], int studentCount){
     if (studentCount == 0) {
        printf("No data loaded from file.\n");
        waitAndClear();
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
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
    }
    // Hien thi thong bao quay lai menu
 	waitAndClear();
}

// Ham sua thong tin sinh vien qua ID
void editStudentByID(Student student[], int studentCount) {
    if (studentCount == 0) {
        printf("No students available to edit.\n");
        waitAndClear();
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
        waitAndClear();
    }

    // Hien thi thong tin hien tai 
    printf("\nCurrent Information:\n");
    printf("Classroom ID: %s\nName: %s\nDOB: %02d/%02d/%04d\nGender: %s\nEmail: %s\nPhone: %s\n",
           student[found].classroomID, student[found].name, student[found].dateOfBirth.day,
           student[found].dateOfBirth.month, student[found].dateOfBirth.year,
           student[found].gender ? "Male" : "Female", student[found].email, student[found].phone);

    // Nhap thong tin moi 
    
    //Classroom ID
	do{
		fflush(stdin);
		printf("\nEnter New Classroom ID( Max 10 characters ): ");
		fgets(student[found].classroomID, sizeof(student[found].classroomID), stdin);
		student[found].classroomID[strcspn(student[found].classroomID, "\n")] = 0;
		
	    if (isNotEmpty(student[found].classroomID) != 1) {
	        printf("Cannot be empty! Please try again.\n");
	    }	
		if(checkClassroomIdValid(student[found].classroomID) != 1){
			printf("Invalid Classroom ID. Please try again.\n");
		}	

	}while (isNotEmpty(student[found].classroomID) != 1 || checkClassroomIdValid(student[found].classroomID) != 1);
	// Ten
	do{
	
		fflush(stdin);
		printf("Enter New Name( Max 40 characters): ");
	    fgets(student[found].name, sizeof(student[found].name), stdin);
	    student[found].name[strcspn(student[found].name, "\n")] = 0;
	    
	    if(isNotEmpty(student[found].name) != 1){
	    	printf("Cannot be empty! Please try again.\n");
		}
		if(checkNameValid(student[found].name) != 1 && strlen(student[found].name) != 0){
			printf("Invalid Name. Please try again.\n");
		}
	} while (isNotEmpty(student[found].name) != 1 || checkNameValid(student[found].name) != 1);
	// Ngay sinh
	do{
		printf("Enter New Date of Birth (DD MM YYYY): ");
	    scanf("%d %d %d", &student[found].dateOfBirth.day, &student[found].dateOfBirth.month, &student[found].dateOfBirth.year);
   		getchar();
   		
   		if(checkDateValid(student[found].dateOfBirth.day,student[found].dateOfBirth.month,student[found].dateOfBirth.year) != 1){
   			printf(" Invalid date of birth. Please try again.\n");
		   }
	} while (checkDateValid(student[found].dateOfBirth.day,student[found].dateOfBirth.month,student[found].dateOfBirth.year) != 1);
	// Gioi tinh
	do{
		printf("Enter New Gender (0 for Female, 1 for Male): ");
	    scanf("%d", &student[found].gender);
	    getchar();
		if(checkGenderValid(student[found].gender) != 1){
			printf("Invalid Gender. Please try again.\n");
		}
	}while (checkGenderValid(student[found].gender) != 1);
	// Email
	do{
		fflush(stdin);
		printf("Enter Email(6-50 characters): ");
	    fgets(student[found].email, sizeof(student[found].email), stdin);
	    student[found].email[strcspn(student[found].email, "\n")] = 0;
	    
		if(isDuplicateEmail(student, studentCount, student[found].email) == 1){
			printf("Email already exists. Enter other email.\n");
		}
		if(checkEmailValid(student[found].email) != 1){
			printf("Invalid email. Please try again.\n");
		}
	}while( isDuplicateEmail(student, studentCount, student[found].email) == 1 || checkEmailValid(student[found].email) != 1);
	// So dien thoai
	do{
		fflush(stdin);
		printf("Enter Phone( 10-15 digits): ");
	    fgets(student[found].phone, sizeof(student[found].phone), stdin);
	   	student[found].phone[strcspn(student[found].phone, "\n")] = 0;
	    	 
		if(isDuplicatePhone(student, studentCount, student[found].phone) == 1){
			printf("Phone already exists. Enter other phone.\n");
		}  
		if(checkPhoneValid(student[found].phone) != 1){
			printf("Invalid phone. Please try again.\n");
		}
	} while(isDuplicatePhone(student, studentCount, student[found].phone) == 1 || checkPhoneValid(student[found].phone) != 1);

    // Luu danh sach sau khi da sua 
    printf("\nStudent information updated successfully!\n");
	saveStudentToFile(student, studentCount);
    // Hien thi thong bao quay lai menu
 	waitAndClear();
}

// Ham xoa sinh vien 
void deleteStudent(Student student[], int *studentCount){
	 if (studentCount == 0) {
        printf("No students available to delete.\n");
        waitAndClear();
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
        waitAndClear();
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
 	waitAndClear();
}
    
// Ham sap xep sinh vien theo ten
void sortStudentByName(Student student[], int studentCount){
    if (studentCount < 2) {
        printf("Not enough students to sort.\n");
        waitAndClear();
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
	// Hien thi thong bao quay lai menu
 	waitAndClear();
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

// Ham tim kiem sinh vien qua ten 
void searchStudentByName(Student student[], int studentCount) {
    if (studentCount == 0) {
        printf("No students available.\n");
        waitAndClear();
        return;
    }

    char nameToSearch[50];
    printf("Enter the name to search (partial match allowed): ");
    getchar();
    fgets(nameToSearch, sizeof(nameToSearch), stdin);
    nameToSearch[strcspn(nameToSearch, "\n")] = 0;

    int found = 0;

    printf("\n%-10s| %-10s| %-30s| %-10s| %-10s| %-30s| %-15s|\n", 
           "ID", "ClassID", "Name", "DOB", "Gender", "Email", "Phone");
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        if (strstr(student[i].name, nameToSearch) != NULL) {
            printf("%-10s| %-10s| %-30s| %02d/%02d/%04d| %-10s| %-30s| %-15s|\n", 
                   student[i].studentId, student[i].classroomID, student[i].name, 
                   student[i].dateOfBirth.day, student[i].dateOfBirth.month, student[i].dateOfBirth.year, 
                   student[i].gender ? "Male" : "Female", student[i].email, student[i].phone);
            printf("--------------------------------------------------------------------------------------------------------------------------------\n");
            found = 1;
        }
    }
    if (found == 0) {
        printf("No student found with the name '%s'.\n", nameToSearch);
    }

    waitAndClear();
}




// Khai bao logic cac ham kiem tra du lieu

// Ham kiem tra bo trong
int isNotEmpty(const char str[]){
	if(str != NULL && strlen(str) > 0){
		return 1; 
	}else {
		return 0;
	}
}

// Ham kiem tra trung Id sinh vien
int isDuplicateStudentId(Student student[], int studentCount, char id[]){
	for(int i = 0; i < studentCount; i++){
		if(strcmp(student[i].studentId, id) == 0){
			return 1; // trung ID
		}
	}
	return 0; // Khong trung ID
}

// Ham kiem tra trung email
int isDuplicateEmail(Student student[], int studentCount, char email[]){
	for(int i = 0; i < studentCount; i++){
		if(strcmp(student[i].email, email) == 0){
			return 1; // trung email
		}
	}
	return 0; // khong trung email
}

// Ham kiem tra trung so dien thoai
int isDuplicatePhone(Student student[], int studentCount, char phone[]){
	for(int i = 0; i < studentCount; i++){
		if(strcmp(student[i].phone, phone) == 0){
			return 1; // trung so dien thoai
		}
	}	
	return 0; // khong trung so dien thoai
}

// Ham kiem tra tinh hop le cua student ID
int checkStudentIdValid(char studentId[]){
	if(strlen(studentId) >=1 && strlen(studentId) <=10){
		return 1; // Hop le
	}
	return 0; // Khong hop le
}

// Ham kiem tra tinh hop le cua classroomID
int checkClassroomIdValid(char classroomID[]){
	if(strlen(classroomID)<= 10){
		return 1; // Hop le 
	}
	return 0; // Khong hop le
}

// Ham kiem tra tinh hop le cua ten
int checkNameValid(char name[]){
		if(strlen(name) >=2 && strlen(name) <=40){
		return 1; // Hop le
	}
	return 0; // Khong hop le
}

// Ham kiem tra tinh hop le cua gioi tinh
int checkGenderValid(int gender){
	if(gender == 1 || gender == 0){
		return 1; // Hop le
	}
	return 0; // Khong hop le
}

// Ham kiem tra tinh hop le cua email
int checkEmailValid(char email[]){
	if(strlen(email) >= 6 && strlen(email) <= 50 && strchr(email, '@') != NULL && strchr(email, '.') != NULL){
		return 1; // Hop le
	}
	return 0; // Khong hop le
}

// Ham kiem tra tinh hop le cua so dien thoai
int checkPhoneValid(char phone[]){
    int lenght = strlen(phone);

    if (lenght < 10 || lenght > 15) {
    	return 0; // khong hop le
	}
    for (int i = 0; i < lenght; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0; // khong hop le
        }
    }
    return 1; // hop le
}

// Ham kiem tra tinh hop le cua password
int checkPasswordValid(char password[]){
	if(strlen(password) >= 6 && strlen(password) <= 30){
		return 1; // hop le
	}
	return 0; // Khong hop le
}

// Ham kiem tra tinh hop le cua ngay sinh
int checkDateValid(int day, int month, int year){
	if(year < 1900 || year > 2006){
		return 0;
	}
	if(month < 1 || month > 12){
		return 0;
	}
	if(day < 1 || day > 31){
		return 0;
	}
	if( (month == 4 || month == 6 || month == 9 || month == 11) && day > 30 ){
		return 0; 
	}
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) return 0;  
        } else {
            if (day > 28) return 0;  
        }
    }
    return 1;
}












