#include <iostream>
#define endl '\n'
using namespace std;
class Student{
private:
    string Name;
    int ID;
    double GPA;
public:
    Student(){
        Name="";
        ID=0;
        GPA=0.0;
    }
    Student(string Name,int ID,double GPA){
        this->Name=Name;
        this->ID=ID;
        this->GPA=GPA;
    }

    const string &getName() const {
        return Name;
    }

    void setName(const string &name) {
        Name = name;
    }

    int getId() const {
        return ID;
    }

    void setId(int id) {
        ID = id;
    }

    double getGpa() const {
        return GPA;
    }

    void setGpa(double gpa) {
        GPA = gpa;
    }
    void display_student_details(){
        cout<<"\tName: "<<Name<<endl;
        cout<<"\tID: "<<ID<<endl;
        cout<<"\tGPA: "<<GPA<<endl;
    }
};
class StudentList{
private:
    struct student{
        Student s;
        student* next;
    };
    student *Head;
    int length;
public:
    StudentList(){
        Head=NULL;
        length=0;
    }
    void Insertion(const Student& insertStudent){
        student *newStudent =new student;
        newStudent->s=insertStudent;
        if(Head==NULL){
            newStudent->next=Head;
            Head=newStudent;
            length++;
            return;
        }
        int idx=0;
        student *temp=Head;
        for (int i = 0; i < length; ++i) {
            if(insertStudent.getId()<=temp->s.getId()){
                idx=i;
                break;
            }
            temp=temp->next;
        }
        student *cur=Head;
        for (int i = 0; i < idx-1; ++i) {
            cur=cur->next;
        }
        newStudent->next=cur->next;
        cur->next=newStudent;
        length++;
    }
    void Delete(int id){
        if(length==0)
            return;
        student *temp=Head,*cur=Head;
        bool flag= true;
        for (int i = 0; i < length; ++i) {
            if(temp->s.getId()==id){
                flag= false;
                break;
            }
            cur=temp;
            temp=temp->next;
        }
        if(flag)
            return;
        cur->next=temp->next;
        delete temp;
        length--;
    }
    void display(){
        student *temp=Head;
        int no_of_student=1;
        while(temp!=NULL){
            cout<<"details of student "<<no_of_student++<<": "<<endl;
            temp->s.display_student_details();
            temp=temp->next;
        }
    }
    void Search(int key){
        if(length==0)
            return;
        student *temp=Head;
        while (temp!=NULL){
            if(temp->s.getId()==key){
                cout<<"details of this student is: "<<endl;
                temp->s.display_student_details();
                break;
            }
        }
    }
    int size(){
        return length;
    }
    ~StudentList(){
        delete Head;
    }

};
class String_Manipulation_using_Doubly_Linked_List{
private:
    struct String_node{
        char character;
        String_node *next;
        String_node *prev;
    };
    String_node*Head;
    String_node*last;
    int length;

public:
    String_Manipulation_using_Doubly_Linked_List(){
        Head=last=NULL;
        length=0;
    }
//    int size(){
//        return length;
//    }
    void insertFirst(char element){
        String_node* new_node=new String_node;
        new_node->character=element;
        if(length==0){//first==NULL
            Head=last=new_node;
            new_node->next=NULL;
            new_node->prev=NULL;
        }
        else{
            new_node->next=Head;
            new_node->prev=NULL;
            Head->prev=new_node;
            Head=new_node;
        }
        length++;
    }
    void insertLast(char element){
        String_node* new_node=new String_node;
        new_node->character=element;
        if(length==0){
            Head=last=new_node;
            new_node->next=new_node->prev=NULL;
        }
        else{
            new_node->next=NULL;
            new_node->prev=last;
            last->next=new_node;
            last=new_node;
        }
        length++;
    }
    void insertAtPos(int pos,char element){
        String_node* new_node=new String_node;
        new_node->character=element;
        if(pos<0 or pos>length){
            return;
        }
        if(pos==0){
            insertFirst(element);
        }
        else if(pos==length){
            insertLast(element);
        }
        else{
            String_node* cur=Head;
            for (int i = 1; i < pos; ++i) {
                cur=cur->next;
            }
            new_node->next=cur->next;
            new_node->prev=cur;
            cur->next->prev=new_node;
            cur->next=new_node;
        }
        length++;
    }
    void Insertion(char c,int idx){
        String_node *new_char=new String_node;
        new_char->character=c;
        if(length==0){
            new_char->prev=NULL;
            new_char->next=NULL;
            Head=last=new_char;
            length++;
            return;
        }
        if(idx<length){
            if(idx==0)
                insertFirst(c);
            else if(idx==length-1)
                insertLast(c);
            else insertAtPos(idx,c);
        }
        else {
            last->next=new_char;
            new_char->prev=last;
            last=new_char;
            new_char->next=NULL;
            length++;
        }

    }
    void removeFirst(){
        if(length==0)
            return;
        else if(length==1){
            delete Head;
            Head=last=NULL;
        }
        else{
            String_node* cur=Head;
            Head= Head->next;
            Head->prev=NULL;
            delete cur;
        }
        length--;
    }
    void removeLast(){
        if(length==0)
            return;
        else if(length==1){
            delete last;
            Head=last=NULL;
        }
        else {
            String_node* cur=last;
            last=last->prev;
            last->next=NULL;
            delete cur;
        }
        length--;
    }
    void Deletion(int pos){
        if(pos<0 or pos>=length)
            return;
        else if(pos==0)
            removeFirst();
        else if(pos==length-1)
            removeLast();
        else{
            String_node *pre,*cur;
            pre=Head;
            cur=Head->next;
            for (int i = 1; i < pos; ++i) {
                pre=cur;
                cur=cur->next;
            }
            pre->next=cur->next;
            delete cur;
            length--;
        }
    }

    char get_this_character(int idx){
        String_node *temp=Head;
        for (int i = 0; i < idx; ++i) {
            temp=temp->next;
        }
        return temp->character;
    }
    void Concatenation(String_Manipulation_using_Doubly_Linked_List obj){
        for (int i = 0; i < obj.length; ++i) {
            Insertion(obj.get_this_character(i),length+i);
        }
    }
    string Substring_Extraction(int idx,int len){
        if(idx>length or len>length)
            return "";
        String_node *temp=Head;
        for (int i = 0; i < idx; ++i) {
            temp=temp->next;
        }
        string s="";
        for (int i = idx; i <idx+len ; ++i) {
            s+=temp->character;
            temp=temp->next;
        }
        return s;
    }
    int Search(string sub){
        String_node *temp=Head;
        string s="";
        for (int i = 0; i < length; ++i) {
            s+=temp->character;
            temp=temp->next;
        }
        for (int i = 0; i < length; ++i) {
            string searched_string="";
            for (int j = i; j < length; ++j) {
                searched_string+=s[j];
                if(searched_string==sub)
                    return i;
            }
        }
        return -1;
    }
    void Replacement(string sub,string another_sub){
        int pos= Search(sub);
        int len=sub.size();
        while(len--){
            Deletion(pos);
        }
        int idx=pos;
        for (int i = 0; i < another_sub.size(); ++i) {
            Insertion(another_sub[i],idx);
            idx++;
        }
    }
    void display() {
        String_node *temp = Head;
        while (temp != NULL) {
            cout << temp->character;
            temp = temp->next;
        }
        cout << endl;
    }

    void Reverse() {
       String_node* ptr1=Head;
       String_node* ptr2=ptr1->next;
       ptr1->next=NULL;
       ptr1->prev=ptr2;
       while(ptr2!=NULL){
           ptr2->prev=ptr2->next;
           ptr2->next=ptr1;
           ptr1=ptr2;
           ptr2=ptr2->prev;
       }
       Head=ptr1;
    }
};
int main() {
    StudentList list;
    Student s1("Ahmed",20190001,3.4);
    Student s2("Menna",20190010,3.5);
    Student s3("Yousef",20190003,1.4);
    list.Insertion(s1);
    list.Insertion(s2);
    list.Insertion(s3);
    list.display();
    Student s4("Ali",20190005,2.5);
    list.Insertion(s4);
    list.Delete(20190003);
    list.display();
    cout<<"################################################"<<endl;
    String_Manipulation_using_Doubly_Linked_List l1,l2;
    cout<<"Enter string to add to list 1:";
    string ss;cin>>ss;
    for (int i = 0; i < ss.size(); ++i) {
        l1.Insertion(ss[i],i);
    }
    cout<<"Enter string to add to list 2:";
    string sss;cin>>sss;
    for (int i = 0; i < sss.size(); ++i) {
        l2.Insertion(sss[i],i);
    }
    l1.Concatenation(l2);
    cout<<"Concatenated Lists:";
    l1.display();
    cout<<"choose a character by index to remove:";
    int idx;cin>>idx;
    l1.Deletion(idx);
    cout<<"List after removal:";
    l1.display();
    cout<<"Enter index and length to get substring:";
    int start,end;cin>>start>>end;
    string s=l1.Substring_Extraction(start,end);
    cout<<"Substring: "<<s<<endl;
    cout<<"Search for a string in the list:";
    cin>>s;
    idx=l1.Search(s);
    cout<<"Found at index: "<<idx<<endl;
    cout<<"Enter 2 substrings to replace one with another:";
    string w,e;
    cin>>w;
    cin>>e;
    l1.Replacement(w,e);
    cout<<"List after replacement: ";
    l1.display();
    l1.Reverse();
    cout<<"Reversed list:";
    l1.display();
}

