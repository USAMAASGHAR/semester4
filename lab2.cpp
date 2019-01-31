#include<iostream>

using namespace std;


class new_student
{
private:
  int roll_no;
  int year;
  int semester;
  float cgpa;
  new_student *next;
public:
new_student()
{

}
  new_student(int rol,int yr,int smstr,float gp)
  {
    roll_no=rol;
    year=yr;
    semester=smstr;
    cgpa=gp;
    next=NULL;
  }
  void get_data()
  {
    cout<<"   Roll number    "<<roll_no;
    cout<<"   year    "<<year;
    cout<<"   semester    "<<semester;
    cout<<"   has cgpa    "<<cgpa<<endl;

  }
  int get_roll()
  {
    return roll_no;
  }
  void set_next(new_student *x)
  {
    next=x;
  }
   new_student* get_next()
  {
  return next;
  }
};
class students
{
private:
  new_student *first;
  int total_student;
public:
  students()
  {

      first=NULL;
      total_student=0;
  }
  void addAtStart(new_student *x)
  {
       total_student++;
       x->set_next(first);
       first=x;
  }
   void addInMiddle(new_student *x)
   {
     total_student++;
     new_student *temp2;
     temp2=first;
     int temp=0;
     while(temp<(total_student/2)-2)
     {
         temp++;
         temp2=temp2->get_next();
     }
     x->set_next(temp2->get_next());
     temp2->set_next(x);
   }
   void addAtEnd(new_student *x)
   {
     total_student++;
     new_student *temp;
     temp=first;
     while(temp->get_next()!=NULL)
     {
      temp=temp->get_next();
     }
      temp->set_next(x);
   }
   void deleteFromStart()
   {
        total_student--;
        first=first->get_next();
   }
    void deleteFromMiddle()
    {
      total_student--;
      new_student *temp2;
      temp2=first;
      int temp=1;
      while(temp!=total_student/2)
      {
        temp2=temp2->get_next();
        temp++;
      }
        temp2->set_next(temp2->get_next()->get_next());
      }
      void deleteFromEnd()
      {
        total_student--;
        new_student *temp;
        temp=first;
        while(temp->get_next()->get_next()!=NULL)
        {
            temp=temp->get_next();
        }
        temp->set_next(NULL);
      }
   void search(int roll)
  {
        new_student *temp;
        temp=first;
        while(temp!=NULL)
        {
           if(temp->get_roll()==roll)
            {
              temp->get_data();
              break;
            }
           else
             {
                temp=temp->get_next();
              }
        }
  }
   void display()
  {
      cout<<"student "<<endl;
      new_student *temp;
      temp=first;
      while(temp!=NULL)
      {
          temp->get_data();
          temp=temp->get_next();
      }
  }

};

int main()
{
  students List;
  List.addAtStart(new new_student(1702007,2,4,3.3));
  List.addAtStart(new new_student(1702008,2,4,3.4));
  List.addAtStart(new new_student(1702009,2,4,3.5));
  List.addAtStart(new new_student(1702010,2,4,3.6));
  List.addAtStart(new new_student(1702011,2,4,3.7));
  List.addInMiddle(new new_student(1702011,2,4,3.8));
  List.addInMiddle(new new_student(1702012,2,4,3.9));
  List.addAtEnd(new new_student(1702013,2,4,4.0));
  List.deleteFromStart();
  List.deleteFromMiddle();
  List.deleteFromEnd();
  List.display();
  cout<<endl;
  List.search(1702012);


  return 0;
}
