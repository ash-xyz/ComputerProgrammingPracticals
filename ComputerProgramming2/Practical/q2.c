#include <stdio.h>
struct majorCode
{

    int id;

    char name[50];
};

struct student
{

    char firstName[20];

    char surName[20];

    int id;

    struct majorCode major;
};
char studentInitial(struct student s)
{
    return s.surName[0];
}
int studentNumber(struct student s)
{
    return s.id;
}
int studentMajor(struct student s)
{
    return s.major.id;
}
int main()
{
    struct majorCode major1 = {888, "Comp Sci"};
    struct student student1 = {"Gavin", "McArdle", 12345, major1};
    printf("%c", studentInitial(student1));
}