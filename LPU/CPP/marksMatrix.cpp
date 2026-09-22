#include<iostream>
using namespace std;

class matrix {
    public:
    void matrixPrint(int **student,int *total, int stu,int sub ){
        int highStu = stu+1;
        int highMark = *(total);
        for(int i = 0; i<stu; i++) {       
            for(int j=0; j<sub; j++) {
                cout << *(*(student+i)+j) << "\t";
            }
            cout << endl;
            if(highMark<*total+stu) {
                highStu = stu+1;
                highMark = *(total+i);
            }
        }
        cout << "Student who scored highest is: " << highStu << endl;
        cout << "Highest score is " << highMark << endl;
    }
};

int main() {
    int stu, sub;
    cout << "Enter no. of student and no. of subject. " << endl;
    cin >> stu >> sub;
    int student[stu][sub];
    int total[stu];
    
    for(int i=0; i<stu; i++) {
        total[i] = 0;
        cout << "Enter marks for student " << i+1 << endl;
        for(int j=0; j<sub; j++) {
            cout << "Enter student " << i << " marks of subject " << j+1 << endl;
            cin >> student[i][j];
            total[i] += student[i][j];
        }
    }
    matrix p;
    p.matrixPrint(student, total, stu, sub);
}