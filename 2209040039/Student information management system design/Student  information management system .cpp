#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int studentId;
    string name;
    string className;
    double mathScore;
    double englishScore;
    double computerScore;
    double averageScore;
};

// ѧ�����ݹ�����
class StudentManager {
private:
    vector<Student> students;

public:
    // ���ѧ����¼
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // ��ѯѧ������ѧ�ţ�
    Student* findStudentById(int studentId) {
        for (auto& student : students) {
            if (student.studentId == studentId) {
                return &student;
            }
        }
        return nullptr;
    }

    // ��ѯѧ������������
    vector<Student*> findStudentsByName(const string& name) {
        vector<Student*> result;
        for (auto& student : students) {
            if (student.name == name) {
                result.push_back(&student);
            }
        }
        return result;
    }

    // ��ѧ���������򣨰�ƽ���ɼ�����
    void sortByAverageScore() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.averageScore > b.averageScore;
            });
    }

    // ��ѧ���������򣨰�������ɼ�����
    void sortByComputerScore() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.computerScore > b.computerScore;
            });
    }

    // ɾ��ѧ����¼
    void deleteStudent(int studentId) {
        students.erase(remove_if(students.begin(), students.end(), [studentId](const Student& student) {
            return student.studentId == studentId;
            }), students.end());
    }

    // �޸�ѧ����¼
    void updateStudent(const Student& updatedStudent) {
        for (auto& student : students) {
            if (student.studentId == updatedStudent.studentId) {
                student = updatedStudent;
                break;
            }
        }
    }

    // �༶�ɼ�����
    void analyzeClassScores() {
        double mathSum = 0.0;
        double englishSum = 0.0;
        double computerSum = 0.0;
        double highestScore = 0.0;
        double lowestScore = 100.0;
        int passCount = 0;

        for (auto& student : students) {
            mathSum += student.mathScore;
            englishSum += student.englishScore;
            computerSum += student.computerScore;

            if (student.computerScore > highestScore) {
                highestScore = student.computerScore;
            }

            if (student.computerScore < lowestScore) {
                lowestScore = student.computerScore;
            }

            if (student.computerScore >= 60.0) {
                passCount++;
            }
        }

        double mathAverage = mathSum / students.size();
        double englishAverage = englishSum / students.size();
        double computerAverage = computerSum / students.size();
        double passRate = (static_cast<double>(passCount) / students.size()) * 100.0;

        cout << "�༶�ɼ�������" << endl;
        cout << "��ѧƽ���֣�" << mathAverage << endl;
        cout << "Ӣ��ƽ���֣�" << englishAverage << endl;
        cout << "�����ƽ���֣�" << computerAverage << endl;
        cout << "��߷֣�" << highestScore << endl;
        cout << "��ͷ֣�" << lowestScore << endl;
        cout << "�����ʣ�" << passRate << "%" << endl;
    }

    // ���ѧ����Ϣ��
    void printStudentInfoTable() {
        cout << "ѧ��\t����\t�༶\t��ѧ\tӢ��\t�����\tƽ���ɼ�" << endl;
        for (auto& student : students) {
            cout << student.studentId << "\t" << student.name << "\t" << student.className << "\t"
                << student.mathScore << "\t" << student.englishScore << "\t" << student.computerScore << "\t"
                << student.averageScore << endl;
        }
    }
};

int main() {
    StudentManager studentManager;

    // ���ѧ����¼
    Student student1 = { 1, "Alice", "Class A", 80.0, 85.0, 90.0, 0.0 };
    student1.averageScore = (student1.mathScore + student1.englishScore + student1.computerScore) / 3;
    studentManager.addStudent(student1);

    Student student2 = { 2, "Bob", "Class A", 75.0, 70.0, 80.0, 0.0 };
    student2.averageScore = (student2.mathScore + student2.englishScore + student2.computerScore) / 3;
    studentManager.addStudent(student2);

    Student student3 = { 3, "Charlie", "Class B", 90.0, 95.0, 85.0, 0.0 };
    student3.averageScore = (student3.mathScore + student3.englishScore + student3.computerScore) / 3;
    studentManager.addStudent(student3);

    // ��ѯѧ������ѧ�ţ�
    Student* foundStudent = studentManager.findStudentById(2);
    if (foundStudent != nullptr) {
        cout << "ѧ��Ϊ2��ѧ��������" << foundStudent->name << endl;
    }
    else {
        cout << "δ�ҵ�ѧ��Ϊ2��ѧ��" << endl;
    }

    // ��ѯѧ������������
    vector<Student*> foundStudents = studentManager.findStudentsByName("Alice");
    if (!foundStudents.empty()) {
        cout << "����ΪAlice��ѧ��������" << foundStudents.size() << endl;
    }
    else {
        cout << "δ�ҵ�����ΪAlice��ѧ��" << endl;
    }

    // ��ѧ���������򣨰�ƽ���ɼ�����
    studentManager.sortByAverageScore();

    // ��ѧ���������򣨰�������ɼ�����
    studentManager.sortByComputerScore();

    // ɾ��ѧ����¼
    studentManager.deleteStudent(3);

    // �޸�ѧ����¼
    Student updatedStudent = { 2, "Bob Smith", "Class B", 85.0, 80.0, 90.0, 0.0 };
    updatedStudent.averageScore = (updatedStudent.mathScore + updatedStudent.englishScore + updatedStudent.computerScore) / 3;
    studentManager.updateStudent(updatedStudent);

    // �༶�ɼ�����
    studentManager.analyzeClassScores();

    // ���ѧ����Ϣ��
    studentManager.printStudentInfoTable();

    return 0;
}