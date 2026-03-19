#include<iostream>
using namespace std;
/*Create two classes: Student and Marks. 
Write a friend function calculateAverage() that:
Accesses data from both classes
Calculates and prints the average marks of the student along with their name*/
class Marks;
class Student{
    string name;
    int roll;
    public:
    void getdata(){
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter roll number: ";
        cin>>roll;
    }
    friend void average(Student s, Marks m);
};
class Marks{
    private:
    int mark1, mark2, mark3;
    public:
    void getdata(){
        cout<<"Enter marks of three subjects: ";
        cin>>mark1>>mark2>>mark3;
    }
    friend void average(Student s, Marks m);
};

void average(Student s, Marks m){
    int avg = (m.mark1 + m.mark2 + m.mark3) / 3;
    cout<<"Name: "<<s.name<<endl;
    cout<<"Average Marks: "<<avg<<endl;
}


/* Two classes Distance1 and Distance2 have distances in m and cm. 
take friend function to compute total dist in cm and m */
class Dist2;
class Dist1{
    float dcm1;
    float dm1;
    public:
    void getdist1(){
        cout<<"Enter distance in centimeters";
        cin>>dcm1;
        dm1=dcm1/100;
    }
    friend void totalDist(Dist1, Dist2);
};
class Dist2{
    float dcm2;
    float dm2;
    public:
    void getdist2(){
        cout<<"Enter distance in centimeters";
        cin>>dcm2;
        dm2=dcm2/100;
    }
    friend void totalDist(Dist1, Dist2);
};
void totalDist (Dist1 d1, Dist2 d2 ){
    float resM,resCM;
    resCM=d1.dcm1+d2.dcm2;
    resM=d1.dm1+d2.dm2;
    int remM=resM/1;
    int remCM=(int)resM%1;
    cout<<"Total Distance in cm="<<resCM<<endl;
    cout<<"Total distance in m="<<resM<<endl;
    cout<<"Resulting distance ="<<remM<<"m "<<remCM<<"cm\n";
}

int main(){
    Student s;
    Marks m;
    s.getdata();
    m.getdata();
    average(s, m);
    Dist1 d1;
    Dist2 d2;
    d1.getdist1();
    d2.getdist2();
    totalDist(d1,d2);
    return 0;
}