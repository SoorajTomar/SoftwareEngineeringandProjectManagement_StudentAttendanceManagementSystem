#include <bits/stdc++.h>
using namespace std;
struct Student
{
    long regno,y,attendanceper[5],activehours[5];
    string name,subject[5],facname[5],course;
}s[10];
void inputval()
{
    unsigned seed = time(0);
   srand(seed);
    for(int i=0;i<10;i++)
    {
        s[i].name='A'+i;
        s[i].y=2;
        s[i].course="CSE Spec. Cyber Security";
        for(int j=0;j<5;j++){
        s[i].subject[j]='A'+j;
        s[i].facname[j]='V'+j;
        s[i].attendanceper[j]=(rand() % 100) + 1;
        s[i].activehours[j]=(rand() % 100) + 1;
        }
        s[i].regno=2011030010001+i;
    }
}
long getstudent(long rno)
{
    for(int i=0;i<10;i++)
    if(s[i].regno==rno)
    return i;
    return -1;
}
void displayval(int i)
{
    cout<<"Name:"<<s[i].name<<"\nRegister No:RA"<<s[i].regno<<"\nCourse:"<<s[i].course<<"\nYear:"<<s[i].y<<"\n*******************\nATTENDANCE:";
    for(int i1=0;i1<5;i1++)
    {
        cout<<"\nSubject:"<<s[i].subject[i1]<<"\nFaculty Name:"<<s[i].facname[i1]<<"\nAttendance Percent:"<<s[i].attendanceper[i1]<<"\nActive Hours:"<<s[i].activehours[i1];
        cout<<"\n*******************";
    }
}
void detained(int i)
{
    for(int j=0;j<5;j++)
    {
        if(s[i].attendanceper[j]<75)
        cout<<"Subject:"<<s[i].subject[j]<<"("<<s[i].attendanceper[j]<<")\n";
    }
}
int main()
{
    inputval();
    long val;
    cout<<"Welcome to the student attendance management software!\nKindly enter your register number to continue:RA";
    cin>>val;
    long rno=getstudent(val);
    if(rno!=-1)
    {
        while(val!=0){
            redo1:
        cout<<"\nPress 1 for attendance display, 2 for detained subjects, 3 for details updation and 0 for exit\n";
        cin>>val;
        switch(val){
        case 1:
        displayval(rno);
        break;
        case 2:
        detained(rno);
        break;
        case 3:
        redo:
        cout<<"Press 1 for name update, 2 for Register number update, 0 for exit\n";
        int x;cin>>x;
        switch(x){
        case 1:{
        string a,b;
        cout<<"Enter firstname update:";
        cin>>a;
        cout<<"Enter lastname update:";
        cin>>b;
        s[rno].name=a+" "+b;
        cout<<"Details updated!Update alert sent to Faculty Advisor.";
        break;}
        case 2:
        cout<<"Enter Register number update:RA";
        cin>>s[rno].regno;
        cout<<"Details updated!Update alert sent to Faculty Advisor.";
        break;
        case 0:
        goto exit2;
        break;
        default:
        cout<<"INVALID CHOICE!!!!";
        goto redo;
        break;
        }
        break;
        case 0:
        goto exit1;
        break;
        default:
        cout<<"INVALID CHOICE!!!!";
        goto redo1;
        break;
        }
        exit2:;
      }
    }
    else
    cout<<"NO SUCH REGISTER NUMBER!!!!!!";
    exit1:
    cout<<"\nThank you for visiting!";
    cout<<"\nDeveloped by BiToSh Systems© Pvt. Ltd.\n(v1.3)";
    return 0;
}
