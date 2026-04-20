#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char course[50];
};

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Course: ");
    scanf(" %[^\n]", s.course);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

void displayStudents() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("ID: %d | Name: %s | Age: %d | Course: %s\n", s.id, s.name, s.age, s.course);
    }
    fclose(fp);
}

void searchStudent() {
    int id, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }
    printf("Enter ID to search: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("Record Found: ID: %d | Name: %s | Age: %d | Course: %s\n", s.id, s.name, s.age, s.course);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student not found!\n");
    fclose(fp);
}

void deleteStudent() {
    int id, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!fp || !temp) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("students.dat");
    rename("temp.dat", "students.dat");
    if (found) printf("Student deleted successfully!\n");
    else printf("Student not found!\n");
}

void updateStudent() {
    int id, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb+");
    if (!fp) {
        printf("No records found!\n");
        return;
    }
    printf("Enter ID to update: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new Age: ");
            scanf("%d", &s.age);
            printf("Enter new Course: ");
            scanf(" %[^\n]", s.course);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            found = 1;
            printf("Student updated successfully!\n");
            break;
        }
    }
    if (!found) printf("Student not found!\n");
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
