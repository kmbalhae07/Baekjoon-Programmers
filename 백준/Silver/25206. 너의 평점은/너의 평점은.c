#include <stdio.h>
#include <string.h>

int main() {
    float sum = 0;
    float hap = 0;

    for(int i=0; i<20; i++){
        char name[51];
        float credit;
        char grade[3]; 

        scanf("%s %f %s", name, &credit, grade);

        float temp_grade;
        if(strcmp(grade, "A+") == 0) {
            temp_grade = 4.5;
        } else if (strcmp(grade, "A0") == 0) {
            temp_grade = 4.0;
        } else if (strcmp(grade, "B+") == 0) {
            temp_grade = 3.5;
        } else if (strcmp(grade, "B0") == 0) {
            temp_grade = 3.0;
        } else if (strcmp(grade, "C+") == 0) {
            temp_grade = 2.5;
        } else if (strcmp(grade, "C0") == 0) {
            temp_grade = 2.0;
        } else if (strcmp(grade, "D+") == 0) {
            temp_grade = 1.5;
        } else if (strcmp(grade, "D0") == 0) {
            temp_grade = 1.0;
        } else if (strcmp(grade, "F") == 0) {
            temp_grade = 0.0;
        }

        if(strcmp(grade, "P") != 0) {
            sum += credit;
            hap += credit * temp_grade;
        }
    }

    float result = hap / sum;
    printf("%f", result);
    return 0;
}
