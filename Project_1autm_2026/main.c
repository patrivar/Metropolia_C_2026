#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Used files*/
#define students_filename "students.txt"
#define teachers_filename "teachers.txt"
#define subjects_filename "subject.txt"
#define NAME_LENGHT 20

typedef struct students {
  int student_id;
  char student_name[NAME_LENGHT];
  int points;
} student;

typedef struct teachers {
  int teacher_id;
  char teacher_name[NAME_LENGHT];
  double salary;
} teacher;

typedef struct subjects {
  int subject_id;
  char subject_name[NAME_LENGHT];
  int teacher_id;
  int student_id;
} subject;

int main(void) {
  FILE *students_file;
  students_file = fopen(students_filename, "r");
  FILE *teachers_file;
  teachers_file = fopen(teachers_filename, "r");
  FILE *subjects_file;
  subjects_file = fopen(subjects_filename, "r");

  /*Test if the program can access the files*/
  if (students_file == NULL) {
    printf("Unable to open students.txt");
    return 1;
  }
  if (teachers_file == NULL) {
    printf("Unable to open teachers.txt");
    return 1;
  }
  if (subjects_file == NULL) {
    printf("Unable to open subjects.txt");
    return 1;
  }

  int choice = 0;

  while (choice != 5) {
    printf("\n\nDo you want to know:\n");
    printf("-----------------------------------\n");
    printf("1. Teacher information?\n");
    printf("2. Student information?\n");
    printf("3. Which course are you enrolled?\n");
    printf("4. Who is the course teacher?\n");
    printf("5. Stop the program?\n");
    printf("-----------------------------------\n");
    printf("Enter your choice(1-5): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: {
        teacher t;
        int id;
        int found = 0;

        printf("Enter teacher id: ");
        scanf("%d", &id);

        rewind(teachers_file); /* Reads the file from the start */

        while (fscanf(teachers_file,
                "%d;%19[^;];%lf",
                      &t.teacher_id,
                      t.teacher_name,
                      &t.salary) == 3) {
          if (t.teacher_id == id) {
            printf("\nTeacher information:\n");
            printf("----------------------\n");
            printf("ID   Name           Salary\n");
            printf("%d %s %.2f\n ", t.teacher_id, t.teacher_name, t.salary);
            found = 1;
            break;
          }
        }
        if (!found) {
          printf("Teacher not found.\n\n");
        }
        break;
      }

      case 2: {
        student s;
        int id;
        int found = 0;

        printf("Enter student id: ");
        scanf("%d", &id);

        rewind(students_file); /* Reads the file from the start */

        while (fscanf(students_file,
                      "%d;%19[^;];%d",
                      &s.student_id,
                      s.student_name,
                      &s.points) == 3) {

          if (s.student_id == id) {
            printf("\nStudent information:\n");
            printf("----------------------\n");
            printf("ID: %d\n", s.student_id);
            printf("Name: %s\n", s.student_name);
            printf("Points: %d\n", s.points);

            found = 1;
            break;
          }
        }

        if (!found) {
          printf("Student not found.\n");
        }
        break;
      }

      case 3: {
        subject sub;
        int student_id;
        int found = 0;

        printf("Enter student id: ");
        scanf("%d", &student_id);

        rewind(subjects_file); /* Reads the file from the start */

        while (fscanf(subjects_file,
                      "%d;%19[^;];%d;%d",
                      &sub.subject_id,
                      sub.subject_name,
                      &sub.teacher_id,
                      &sub.student_id) == 4) {

          if (sub.student_id == student_id) {
            printf("Course: %s\n", sub.subject_name);
            found = 1;
            break;
          }
        }

        if (!found) {
          printf("Student not found.\n");
        }

        break;
      }

      case 4: {
        subject sub;
        teacher t;

        char input[20];
        int teacher_id = -1;
        int is_number = 1;

        printf("Enter course name or course name or id: ");
        scanf("%19s", input);

        for (int i = 0; input[i] != '\0'; i++) {
          if (!isdigit(input[i])) {
            is_number = 0;
            break;
          }
        }

        rewind(subjects_file); /* Reads the file from the start */

        while (fscanf(subjects_file,
                      "%d;%19[^;];%d;%d",
                      &sub.subject_id,
                      sub.subject_name,
                      &sub.teacher_id,
                      &sub.student_id) == 4) {

          if (is_number) {
            if (sub.subject_id == atoi(input)) {
              teacher_id = sub.teacher_id;
              break;
            }
          } else {
            if (strcmp(sub.subject_name, input) == 0) {
              teacher_id = sub.teacher_id;
              break;
            }
          }
        }

        if (teacher_id == -1) {
          printf("Course not found.\n");
          break;
        }

        rewind(teachers_file); /* Reads the file from the start */

        while (fscanf(teachers_file,
                      "%d;%19[^;];%lf",
                      &t.teacher_id,
                      t.teacher_name,
                      &t.salary) == 3) {

          if (t.teacher_id == teacher_id) {
            printf("Teacher: %s\n", t.teacher_name);
            break;
          }
        }
        break;
      }
    }
  }
  /* Close files*/
  fclose(students_file);
  fclose(teachers_file);
  fclose(subjects_file);

  return 0;
}

