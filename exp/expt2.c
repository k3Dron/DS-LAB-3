#include <stdio.h>
#include <stdlib.h>

struct Marks {
    int physics;
    int chemistry;
    int mathematics;
};

struct Student {
    char name[50];
    int roll_number;
    struct Marks marks;
};

int main() {
    struct Student student;

    printf("Enter student's name: ");
    fgets(student.name, sizeof(student.name), stdin);

    printf("Enter roll number: ");
    scanf("%d", &student.roll_number);

    printf("Enter marks in Physics: ");
    scanf("%d", &student.marks.physics);

    printf("Enter marks in Chemistry: ");
    scanf("%d", &student.marks.chemistry);

    printf("Enter marks in Mathematics: ");
    scanf("%d", &student.marks.mathematics);

    printf("\nStudent Mark Sheet\n");
    printf("Name: %s", student.name);
    printf("Roll Number: %d\n", student.roll_number);
    printf("Physics: %d\n", student.marks.physics);
    printf("Chemistry: %d\n", student.marks.chemistry);
    printf("Mathematics: %d\n", student.marks.mathematics);

    return 0;
}
