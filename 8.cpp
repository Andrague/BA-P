#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <ctime> 
#include <fstream> 
#include<string> 
using namespace std;

struct subjects {
    int math = 0;
    int physics = 0;
    int inform = 0;
    int chemestry = 02;
};
struct FIO {
    char First_name[20];
    char Last_name[20];
    char Middle_name[20];
};

struct date {
    int day;
    int month;
    int year;
};

int age(date present, int day, int month, int year) {
    int _month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > present.day) {
        present.day = present.day + _month[month - 1];
        present.month = present.month - 1;
    }
    if (month > present.month) {
        present.year = present.year - 1;
        present.month = present.month + 12;
    }
    int final_date = present.day - day;
    int final_month = present.month - month;
    int final_year = present.year - year;
    return final_year;
};

struct student {
    struct FIO F;
    struct date b;
    int group;
    struct subjects sb;
    double grade;
    int final_year;
};
const char* fields[10] = { "Имя","Фамилия","Отчество", "Группа", "Мат", "Физ","Инф","Хим","Ср.балл","Возраст" };
static int pos = 0; // store latest empty position in array 
int N = 1; // array size 

////////////////////////////////// 
date setTodayDate();
student* Add(student* st);
void Edit(student* st);
void Delete(student* st);
void showStudent(student* st, int indx);
void showAllStudent(student* st, int size);
void MainMenu(student* st, int size);
int deleteStudent();
student editStudent();
student addStudent();
student* ReadFile(student* st);
void SaveFile(student* st);
void SaveFileAs(student*, string, int);
bool is_file_exist(string fileName);
void GetTopStudents(student* st);
void Sort(student* st);
///////////////////////////////// 
double average_grade(double math, double physics, double inform, double chemestry)
{
    return (double)((math + physics + inform + chemestry) / 4);
}
int main()
{
    system("chcp 1251");
    student* st;
    date present = setTodayDate();
    cout << "\n Сегодня " << present.day << "." << present.month << "." << present.year << endl;
    st = new student[N];
    MainMenu(st, N);
    return 0;
}




student* Add(student* st) {
    if (pos >= N) {
        student* temp = new student[N + 1];
        for (int i = 0; i < N; i++) {
            temp[i] = st[i];
        }
        N = N + 1;
        st = temp;
    }
    cout << "Введите информацию о студенте: " << endl;
    st[pos] = addStudent();
    pos++;
    return st;
}

student addStudent() {
    student s;
    cout << fields[0] << ": ";
    cin >> s.F.First_name;
    cout << fields[1] << ": ";
    cin >> s.F.Last_name;
    cout << fields[2] << ": ";
    cin >> s.F.Middle_name;
    cout << "Дата рождения: ";
    cin >> s.b.day >> s.b.month >> s.b.year;
    cout << fields[3] << ": ";
    cin >> s.group;
    cout << fields[4] << ": ";
    cin >> s.sb.math;
    cout << fields[5] << ": ";
    cin >> s.sb.physics;
    cout << fields[6] << ": ";
    cin >> s.sb.inform;
    cout << fields[7] << ": ";
    cin >> s.sb.chemestry;
    return s;
}

void Edit(student* st) {
    int key = 0;
    cout << "Укажите номер студента для редактирования: " << endl;
    cin >> key;
    if (key > 0 && key <= N) {
        showStudent(st, key - 1);
        cout << "Введите новую информацию: " << endl;
        st[key - 1] = editStudent();
    }

}
student editStudent() {
    student s;
    cout << fields[0] << ": ";
    cin >> s.F.First_name;
    cout << fields[1] << ": ";
    cin >> s.F.Last_name;
    cout << fields[2] << ": ";
    cin >> s.F.Middle_name;
    cout << "Дата рождения: ";
    cin >> s.b.day >> s.b.month >> s.b.year;
    cout << fields[3] << ": ";
    cin >> s.group;
    cout << fields[4] << ": ";
    cin >> s.sb.math;
    cout << fields[5] << ": ";
    cin >> s.sb.physics;
    cout << fields[6] << ": ";
    cin >> s.sb.inform;
    cout << fields[7] << ": ";
    cin >> s.sb.chemestry;
    return s;
}

void Delete(student* st) {
    int key = -1, offset = 0;
    bool quit = false;
    student* temp = new student[N];
    cout << "Укажите номер студента для удаления: ";
    cin >> key;
    if (key > 0 && key <= N) {
        int delRec = key - 1;
        for (int i = 0; i < N; i++) {
            if (i >= delRec)
                offset = 1;
            if (i + offset == N)
                break;
            temp[i] = st[i + offset];
        }
    }
    for (int i = 0; i < N; i++)
        st[i] = temp[i];
    pos--;
    if (N > 1) N--;

}

void showStudent(student* st, int indx) {
    cout << '\t';
    cout << st[indx].F.First_name << "\t";
    cout << st[indx].F.Last_name << "\t";
    cout << st[indx].F.Middle_name << "\t";
    cout << st[indx].group << "\t";
    cout << average_grade(st[indx].sb.math, st[indx].sb.physics, st[indx].sb.inform, st[indx].sb.chemestry) << "\t";
    cout << age(setTodayDate(), st[indx].b.day, st[indx].b.month, st[indx].b.year) << endl;
}


void showAllStudents(student* st, int size) {

    cout << "#";
    for (int i = 0; i < 4; i++)
        cout << '\t' << fields[i];
    cout << '\t' << fields[8];//ср.балл 
    cout << '\t' << fields[9];//возраст 
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". ";
        showStudent(st, i);
    }
}
    void Sort(student * st) {
        
        int key = 0;
        bool quit = false;
        //   system("cls"); 
        while (!quit) {
            cout << "\n Выберите поле сортировки: \n\tГруппа (1),\n\tВозраст(2),\n\tСредний балл(3)\n\tили Выйти (0) :";
            cin >> key;
            switch (key) {
            case 1: {
                student stemp;
                int j = 0;
                for (int i = 0; i < N; i++) {
                    for (j = i + 1; j < N; j++) {
                        if (st[i].group > st[j].group) {
                            stemp = st[i];
                            st[i] = st[j];
                            st[j] = stemp;
                        }
                    }

                }
                break; }
            case 2: {
                student stemp;
                int j = 0;
                for (int i = 0; i < N; i++) {
                    for (j = i + 1; j < N; j++) {
                        if (st[i].final_year > st[j].final_year) {
                            stemp = st[i];
                            st[i] = st[j];
                            st[j] = stemp;
                        }
                    }

                }
                break; }
            case 3: {
                student stemp;
                int j = 0;
                for (int i = 0; i < N; i++) {
                    for (j = i + 1; j < N; j++) {
                        if (st[i].grade > st[j].grade) {
                            stemp = st[i];
                            st[i] = st[j];
                            st[j] = stemp;
                        }
                    }

                }
                break; }
            case 0: quit = true; break;
            }
            if (key != 0)
                showAllStudents(st, pos);
        }
    }

void MainMenu(student* st, int size) {
    int key = 0;
    bool quit = false;
    //   system("cls"); 
    while (!quit) {
        cout << "\n Выберите действие: \n\tДобавить (1),\n\tРедактировать (2), \n\tУдалить (3),\n\tПрочитать из файла (4),\n\tСохранить (5), \n\tСохранить как (6) \n\tЛучшие студенты (7)\n\tСортировка (8)\n\tили Выйти (0) :";
        cin >> key;
        switch (key) {
        case 1: st = Add(st); break;
        case 2: Edit(st); break;
        case 3: Delete(st); break;
        case 4: st = ReadFile(st); break;
        case 5: SaveFile(st); break;
        case 6: SaveFileAs(st, "", N); break;
        case 7: GetTopStudents(st); break;
        case 8:Sort(st); break;
        case 0: quit = true; break;
        }
        if (key != 0)
            showAllStudents(st, pos);
    }
}

date setTodayDate() {
    // current date/time based on current system 
    time_t now = time(0);
    tm* ltm = localtime(&now);
    date today;
    today.year = 1900 + ltm->tm_year;
    today.month = 1 + ltm->tm_mon;
    today.day = ltm->tm_mday;
    return today;
}

student* ReadFile(student* st) {
    int key = 0;
    int res = -1;
    cout << "Открыть файл students.txt (1) или указать иной (2):";
    cin >> key;
    string fileName;
    switch (key) {
    case 1: fileName = "students.txt"; break;
    case 2: cout << "\nУкажите имя файла: "; cin >> fileName; break;
    }


    ifstream myfile;
    if (!myfile.fail()) {
        myfile.open(fileName, ios::in);
        //считаем кол-во записей 
        int numLines = 0;
        ifstream in(fileName);
        std::string unused;
        while (std::getline(in, unused)) {
            if (unused.length() > 0)
                numLines++;
        }
        myfile.close();
        N = numLines;
        pos = N;
        //создаем новый массив 
        st = new student[numLines];
        myfile.open(fileName, ios::in);
        int i = 0;
        if (myfile.is_open()) {
            do {
                myfile >> st[i].F.First_name;
                myfile >> st[i].F.Last_name;
                myfile >> st[i].F.Middle_name;
                myfile >> st[i].b.day;
                myfile >> st[i].b.month;
                myfile >> st[i].b.year;
                myfile >> st[i].group;
                myfile >> st[i].sb.math;
                myfile >> st[i].sb.physics;
                myfile >> st[i].sb.inform;
                myfile >> st[i].sb.chemestry;
                i++;
            } while (!myfile.eof());
        }
        myfile.close();
        res = 0;
        cout << "\nПрочитано " << i << " записей из файла " << fileName << endl;
    }
    else {
        cout << "\nОщибка чтения файла";
    }
    return st;
}

void SaveFile(student* st) {
    SaveFileAs(st, "students.txt", N);
}


void SaveFileAs(student* st, std::string fileName, int st_size) {
    ofstream myfile;
    if (fileName.length() == 0) {
        cout << "Укажите имя файла: ";
        cin >> fileName;
    }
    if (is_file_exist(fileName)) {
        remove(fileName.c_str());
    }

    myfile.open(fileName, ios::out);
    if (myfile.is_open()) {
        for (int i = 0; i < st_size; i++) {
            myfile << st[i].F.First_name;
            myfile << ' ' << st[i].F.Last_name;
            myfile << ' ' << st[i].F.Middle_name;
            myfile << ' ' << st[i].b.day << " " << st[i].b.month << " " << st[i].b.year;
            myfile << ' ' << st[i].group;
            myfile << ' ' << st[i].sb.math;
            myfile << ' ' << st[i].sb.physics;
            myfile << ' ' << st[i].sb.inform;
            myfile << ' ' << st[i].sb.chemestry << endl;
        }

        cout << "\nСохранено " << N << " записей в файл " << fileName << endl;
    }
    else {
        cout << "\nОшибка записи в файл" + fileName;
    }
    myfile.close();
}

bool is_file_exist(string fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
void GetTopStudents(student* st) {
    double av_score = 0;
    int count = 0;
    int groupid = 0;
    cout << "\nВведите номер группы:";
    cin >> groupid;
    //считаем средний балл 
    for (int i = 0; i < N; i++) {
        st[i].grade = average_grade(st[i].sb.math, st[i].sb.physics, st[i].sb.inform, st[i].sb.chemestry);
        if (st[i].group == groupid) {
            count++;
            av_score += st[i].grade;
        }
    }
    av_score = av_score / count;
    cout << "\nСредний балл по группе: " << av_score << endl;
    //считаем сколько студентов  выше среднего 
    count = 0;
    for (int i = 0; i < av_score; i++) {
        if (st[i].grade > av_score)
            count++;
    }
    //сохраняем в файл 
    student* s; //для топ студентов 
    s = new student[count];
    int j = 0;
    for (int i = 0; i < N; i++) {
        if ((st[i].group == groupid) && (st[i].grade > av_score)) {
            s[j] = st[i];
            j++;
        }
    }
    SaveFileAs(s, "", count);
}