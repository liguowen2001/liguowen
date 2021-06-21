#include<iostream>
#include<string>
#include<fstream>
const int B=10,S=10,T=10,M=10; 
using namespace std;
//��
class Book
{	
	string name;//����
	string id;//���
	string sort;//���
	int number;//ʣ������
	double price;//�۸�
public:
	Book(string n="0",string i="0",string s="0",int nu=0,double p=0){
		name=n;
	id=i;
	sort=s;
	number=nu;
	price=p;
	}
	//����
	void set(string n,string i,string s,int nu,double p);
	//��ȡ��Ϣ
	string get_name(){return name;}
	string get_id(){return id;}
	string get_sort(){return sort;}
	int get_number(){return number;}
	double get_price(){return price;}
	//�����Ϣ
	void print();
	//��ʣ������
	void booknumber(int n);
	//�ļ�д��
	void f_print();
	//����
	friend istream & operator >>(istream &,Book &);
	friend ostream & operator <<(ostream &,Book &); 
};
//������
class Reader{	
	string name;//����
	string id;//ѧ��
	string password;//����
	int book_number;//�ѽ�������Ŀ
	int day;//����ʱ��
public:
	Reader(string na="0",string i="0",string p="0",int b_n=0,int d=0){
		name=na;
		id=i;
		password=p;
		book_number=b_n;
		//book_id1=bn1;
		//book_id2=bn2;
		day=d;
	}
	//д������
	void set(string na,string i,string p,int b_n,int d);
	//��ȡ����
	string get_name(){return name;}
	string get_id(){return id;}
	string get_password(){return password;}
	int get_book_n(){return book_number;}
	//int get_id1(){return book_id1;}
	//int get_id2(){return book_id2;}
	int get_day(){return day;}
	//д���ļ�
	void f_print();
	//�����Ϣ
	void print();
	//������Ŀ�仯
	void range(int n);
};
//ѧ����
class Student:public Reader{
		int book_id1;//�鼮���
	public:
		Student(string na="0",string i="0",string p="0",int b_n=0,int bn1=0,int d=0):
		Reader(na,i,p,b_n,d){
			book_id1=bn1;	
		}
		int get_bookid(){return book_id1;}
		//������Ϣ¼��
		void set_id1(int id);
		//д������
		void set(string na,string i,string p,int b_n,int bn1,int d);
		//���ؽ����鼮��Ϣ 
		int get_id1(){return book_id1;}
};
//��ʦ��
class Teacher :public Reader{
	int book_id1;
	int book_id2;
	public:
		Teacher(string na="0",string i="0",string p="0",int b_n=0,int bn1=0,int bn2=0,int d=0):
		Reader(na,i,p,b_n,d){
		book_id1=bn1;
		book_id2=bn2;			
		}
		//���ؽ����鼮��Ϣ 
		int get_bookid1(){return book_id1;}
		int get_bookid2(){return book_id2;}
		//������Ϣ¼��
		void set_id1(int id);
		void set_id2(int id);  
		//д������
		void set(string na,string i,string p,int b_n,int bn1,int bn2,int d);
}; 
//����Ա
class Manager{
	string name;
	string id;
	string password;
	public:
		Manager(string na="0",string i="0",string p="0"){
			name=na;
			password=p;
			id=i;
		}
		//��ֵ
		void set(string na,string i,string p);
		//������֤
		int fun_pw(string p);
		//������Ϣ
		string get_name(){return name;}
		string get_id(){return id;} 
		string get_password(){return password;}
}; 
//Book��ֵ 
void Book::set(string n,string i,string s,int nu,double p){
	name=n;
	id=i;
	sort=s;
	number=nu;
	price=p;
}
//Book��� 
void Book::print(){
	cout<<"����:"<<name<<" ���:"<<id<<" ���:"<<sort<<" �۸�"<<price<<" ʣ��������"<<number<<endl;
}
//Bookʣ����Ŀͳ�� 
void Book::booknumber(int n){
	if(n==1)
		number++;
	else number--;
}
//Bookд���ļ� 
void Book::f_print(){
	ofstream fout("book.txt",ios::app);
	if(!fout){
		cout<<"�ļ���ʧ��"<<endl;
	}
	fout<<name<<" "<<id<<" "<<sort<<" "<<number<<" "<<price<<" ";
	fout.close();
}
//Book����
istream & operator >>(istream & in,Book & b){
	in>>b.name>>b.id>>b.sort>>b.number>>b.price;
}
ostream & operator <<(ostream & out,Book & b){
	out<<"����:"<<b.name<<" ���:"<<b.id<<" ���:"<<b.sort<<" �۸�"<<b.price<<" ʣ��������"<<b.number<<endl;
} 
//Reader��ֵ 
void Reader::set(string na="0",string i="0",string p="0",int b_n=0,int d=0){
	name=na;
	id=i;
	password=p;
	book_number=b_n;
	//book_id1=bn1;
	//book_id2=bn2;
	day=d;
}
//Readerд���ļ� 
void Reader::f_print(){
	ofstream fout("reader.txt",ios::app);
	if(!fout){
		cout<<"�ļ���ʧ��"<<endl;
	}
	fout<<name<<" "<<id<<" "<<password<<" "<<book_number<<" "<<day<<" ";
	fout.close();
}
//Reader���
void Reader::print(){
	cout<<"������"<<name<<" ѧ�ţ�"<<id<<" �����鼮��Ŀ��"<<book_number<<endl;
} 
//������Ŀ�仯
void Reader::range(int n){
	if(n==1)
	book_number++;
	else book_number--;
}
//Student��ֵ
void Student::set(string na="0",string i="0",string p="0",int b_n=0,int bn1=0,int d=0){
	Reader::set(na,i,p,b_n,d);
	book_id1=bn1;
} 
//Student�鼮��Ϣ¼�� 
void Student::set_id1(int id){
	book_id1=id;
}
//������Ϣ¼��
void Teacher::set_id1(int id){
	book_id1=id;
}
void Teacher::set_id2(int id){
	book_id2=id;
}  
//Teacher��ֵ 
void Teacher::set(string na="0",string i="0",string p="0",int b_n=0,int bn1=0,int bn2=0,int d=0){
	Reader::set(na,i,p,b_n,d);
	book_id1=bn1;
	book_id2=bn2;
} 
//Manager��ֵ
void Manager::set(string na,string i,string p){
	name=na;
	id=i;
	password=p;
}
//Manager������֤
int Manager::fun_pw(string p){
	if(p==password)
	return 1;
	else return 0;
}
//д���ļ����� 
void write(Book book[B],Teacher teacher[T],Student student[S],Manager manager[M]){
	ofstream fout("teacher.txt",ios::out);
	if(!fout)
	cout<<"�洢�ļ�teacher.txt��ʧ��"<<endl;
	for(int i=0;i<T;i++){
		string name=teacher[i].get_name();//����
		string id=teacher[i].get_id();//ѧ��
		string password=teacher[i].get_password();//����
		int book_number=teacher[i].get_book_n();//�ѽ�������Ŀ
		int book_id1=teacher[i].get_bookid1();//�鼮���
		int book_id2=teacher[i].get_bookid2();//�鼮���
		int day=teacher[i].get_day();//����ʱ��
		fout<<name<<" "<<id<<" "<<password<<" "<<book_number<<" "<<book_id1<<" "<<book_id2<<" "<<day<<" ";
	} 
	fout.close();
	
	ofstream fout1("book.txt",ios::out);
	if(!fout1)
	cout<<"�洢�ļ�book.txt��ʧ��"<<endl;
	for(int i=0;i<B;i++){
		string name=book[i].get_name();//����
		string id=book[i].get_id();//���
		string sort=book[i].get_sort();//���
		int number=book[i].get_number();//ʣ������
		double price=book[i].get_price();//�۸�
		fout1<<name<<" "<<id<<" "<<sort<<" "<<number<<" "<<price<<" ";
	}
	fout1.close();
	
	ofstream fout2("student.txt",ios::out);
	if(!fout2)
	cout<<"�洢�ļ�student.txt��ʧ��"<<endl;
	for(int i=0;i<S;i++){
		string name=student[i].get_name();//����
		string id=student[i].get_id();//ѧ��
		string password=student[i].get_password();//����
		int book_number=student[i].get_book_n();//�ѽ�������Ŀ
		int book_id1=student[i].get_bookid();//�鼮���
		int day=student[i].get_day();//����ʱ��
		fout2<<name<<" "<<id<<" "<<password<<" "<<book_number<<" "<<book_id1<<" "<<day<<" ";
	} 
	fout2.close();
	
	ofstream fout3("manager.txt",ios::out);
	if(!fout3)
	cout<<"�洢�ļ�manager.txt��ʧ��"<<endl;
	for(int i=0;i<M;i++){
		string name=manager[i].get_name();//����
		string id=manager[i].get_id();//ѧ��
		string password=manager[i].get_password();//����
		fout3<<name<<" "<<id<<" "<<password<<" ";
	} 
	fout3.close();
} 
//������Ա 
void fun_manager(Book book[B],Teacher teacher[T],Student student[S],Manager manager[M]){
	cout<<"ע�� 1      ��¼ 2"<<endl;
	int choice;
	int m=0,s=0,t=0,b=0; 
	cin>>choice;
	//ע�� 
	if(choice==1){
		for(int i=0;i<M;i++){
			if(manager[i].get_name()!="0")
			m++;
		}
		string name,id,password;
		cout<<"����"<<endl;
		cin>>name;
		cout<<"�˺�"<<endl;
		cin>>id;
		cout<<"����"<<endl;
		cin>>password;
		manager[m].set(name,id,password);
		m++;
		cout<<"ע��ɹ�"<<endl;
	}
	//��¼ 
	if(choice==2){
		cout<<"�������˺�"<<endl;
		string id,password;
		cin>>id;
		int n=M;
		//�������� 
		for(int i=0;i<M;i++){
			if(manager[i].get_id()==id)
			n=i;
		}
		for(int i=0;i<S;i++){
			if(student[i].get_id()!="0")
			s++;
		}
		for(int i=0;i<T;i++){
			if(teacher[i].get_id()!="0")
			t++;
		}
		for(int i=0;i<B;i++){
			if(book[i].get_id()!="0")
			b++;
		}
		if(n==M){
			cout<<"�˻�������"<<endl;
		}
		else{
			cout<<"����������"<<endl;
			cin>>password;
			if(manager[n].fun_pw(password))
			cout<<"�������"<<endl; 
			else {
				//��½�ɹ�
				cout<<"��¼�ɹ�"<<endl;
				cout<<"��ѡ��Ҫ���еĲ���"<<endl;
				cout<<"1(��Ϣ��ѯ) 2���鼮����"<<endl; 
				int choice;
				cin>>choice;
				//��Ϣ��ѯ 
				if(choice==1){
					cout<<"�������ѯ��� ��ʦ 1 ѧ�� 2 �鼮 3"<<endl;
					int choice;
					cin>>choice;
					if(choice==1){
						for(int i=0;i<t;i++)
						teacher[i].print(); 
					}
					if(choice==2){
						for(int i=0;i<s;i++)
						student[i].print();
					}
					if(choice==3){
						for(int i=0;i<b;i++)
						cout<<book[i];
					}
		
				}
				//�鼮����
				if(choice==2){
					cout<<"�����鼮��1 ɾ���鼮��2 �޸��鼮��Ϣ��3"<<endl; 
					cout<<"���������ѡ��"<<endl;
					int choice;
					cin>>choice;
					//�����鼮 
					if(choice==1){
						cout<<"�����鼮��Ϣ"<<endl;
						string name;//����
						string id;//���
						string sort;//���
						int number;//ʣ������
						double price;//�۸�
						cout<<"����:";
						cin>>name; 
						cout<<"���:";
						cin>>id; 
						cout<<"���:";
						cin>>sort; 
						cout<<"����:";
						cin>>number; 
						cout<<"�۸�:";
						cin>>price; 
						Book bo(name,id,sort,number,price);
						book[b]=bo;
						b++;
					} 
					//ɾ���鼮
					if(choice==2){
						cout<<"�������鼮���"<<endl;
						string id;
						cin>>id;
						int n=B;
						for (int i=0;i<b;i++){
							if(book[i].get_id()==id)
							n=i;
						}
						if(n==B)
						cout<<"������idΪ"<<id<<"����"<<endl;
						else{
							for(int i=n;i<b;i++){
								book[n]=book[n+1];
							}
							b--;
						} 
					} 
					//�޸��鼮��Ϣ
					if(choice==3){
						cout<<"�������鼮���"<<endl;
						string id;
						cin>>id;
						int n=B;
						for (int i=0;i<b;i++){
							if(book[i].get_id()==id)
							n=i;
						}
						if(n==10)
						cout<<"������idΪ"<<id<<"����"<<endl;
						else{
							cout<<"�����鼮��Ϣ"<<endl;
							string name;//����
							string id;//���
							string sort;//���
							int number;//ʣ������
							double price;//�۸�
							cout<<"����:";
							cin>>name; 
							cout<<"���:";
							cin>>id; 
							cout<<"���:";
							cin>>sort; 
							cout<<"����:";
							cin>>number; 
							cout<<"�۸�:";
							cin>>price; 
							book[n].set(name,id,sort,number,price);
						}
					} 	
				} 		
			} 
		}	 
	}
	write(book,teacher,student,manager);		 	
} 

//ѧ��
void fun_student(Book book[B],Teacher teacher[T],Student student[S],Manager manager[M]){
	int b=0,r=0;//�������,�������� 
	int max;
	if(B>S)
	max=B;
	else max=S;
	//�������� 
	for(int i=0;i<max;i++){
		string s=book[i].get_name();
		string s1=student[i].get_name();
		if(s!="0")
		b++;
		if(s1!="0")
		r++;
	} 
	cout<<"ѡ��Ҫ���еĲ���"<<endl;
	int choice;
	cout<<"��¼��1  ע�᣺2"<<endl;
	cin>>choice;
	//ע�� 
	if(choice==2){
		string name;//����
		string id;//ѧ��
		string password;//����
		int book_number;//�ѽ�������Ŀ
		int book_id1;//�鼮���
		int book_id2;//�鼮���
		int day;//����ʱ��
		cout<<"������"<<endl;
		cin>>name;
		cout<<"ѧ�ţ�"<<endl;
		cin>>id;
		cout<<"���룺"<<endl;
		cin>>password;
		student[r].set(name,id,password);
		r++;
		cout<<"ע��ɹ�"<<endl;
	} 
	//��¼ 
	if(choice==1){
		cout<<"������ѧ�ţ�"<<endl;
		int m=S;//student��� 
		string id;
		string password;
		cin>>id;
		cout<<"���������룺"<<endl;
		cin>>password;
		int n=S;
		for(int i=0;i<r;i++){
			if(student[i].get_id()==id)
			n=i;
		} 
		if(n==S)
		cout<<"�û�������"<<endl;
		else{
			if(student[n].get_password()!=password)
			cout<<"�������"<<endl;
			else{
				cout<<"��¼�ɹ�"<<endl; 
				m=n;
			} 
		}
		//��¼�ɹ��� 
		if(m!=S){
			int bn=1,maxday=7;
			cout<<"���飺1  ���飺2"<<endl;
			int choice;
			cin>>choice;
			//����
			if(choice==1){
				//��������鼮��Ϣ
				for(int i=0;i<b;i++)
				book[i].print();
				cout<<"�����鼮��ţ�"<<endl;
				string id;
				int j=B;//�鼮��� 
				cin>>id;
				for(int i=0;i<b;i++){
					if(book[i].get_id()==id)
					j=i;
				}
				if(j==B)
				cout<<"�鼮������"<<endl;
				else{
					if(student[m].get_book_n()>bn)
					cout<<"�Ѵﵽ��������Ŀ" <<endl;
					else{
						int year,month,day;
						cout<<"������������ڣ�"<<endl;
						cin>>year>>month>>day; 
						cout<<"���ĳɹ�"<<endl;
						book[j].booknumber(0);//�鼮��Ŀ�仯 
						student[m].range(1);//�����ѽ����鼮��Ŀ�仯 
						//¼���鼮��Ϣ 
						student[m].set_id1(j);
						//д�������־
						ofstream fout("log.txt",ios::app);
						if(!fout)
						cout<<"��־��ʧ��"<<endl;
						fout<<"���ڣ�"<<year<<"."<<month<<"."<<day<<"    ������"<<student[m].get_name()<<"   �����鼮��"<<
						book[j].get_name()<<endl;
						fout.close(); 
					}
				} 
			}
			//����
			if(choice==2){
				cout<<"�����鼮���"<<endl;
				string id;
				cin>>id;
				int j=B;
				for(int i=0;i<b;i++){
					if(book[i].get_id()==id)
					j=i;
				}
				if(j==B)
				cout<<"�鼮������"<<endl;
				else{
					int d;
					int year,month,day;
					cout<<"�����뻹�����ڣ�"<<endl;
					cin>>year>>month>>day; 
					cout<<"�������ʱ��"<<endl;
					cin>>d;
					if(d>maxday)
					cout<<"����ʱ�䣬�뽻����"<<endl;
					cout<<"����ɹ�"<<endl;
					book[j].booknumber(1);//�鼮��Ŀ�仯 
					student[m].range(0);//�����ѽ����鼮��Ŀ�仯 
					//ɾ���鼮��Ϣ						
					student[m].set_id1(0);
					//д�������־
					ofstream fout("log.txt",ios::app);
					if(!fout)
					cout<<"��־��ʧ��"<<endl;
					fout<<"���ڣ�"<<year<<"."<<month<<"."<<day<<"    ������"<<student[m].get_name()<<"   �黹�鼮��"<<
					book[j].get_name()<<endl;
					fout.close(); 
				} 
			} 
		}
	}
	write(book,teacher,student,manager);
}
//��ʦ 
void fun_teacher(Book book[B],Teacher teacher[T],Student student[S],Manager manager[M]){
	int b=0,r=0;//�������,�������� 
	int max;
	if(B>T)
	max=B;
	else max=T;
	//�������� 
	for(int i=0;i<max;i++){
		string s=book[i].get_name();
		string s1=teacher[i].get_name();
		if(s!="0")
		b++;
		if(s1!="0")
		r++;
	} 
	cout<<"ѡ��Ҫ���еĲ���"<<endl;
	int choice;
	cout<<"��¼��1  ע�᣺2"<<endl;
	cin>>choice;
	//ע�� 
	if(choice==2){
		string name;//����
		string id;//ѧ��
		string password;//����
		int book_number;//�ѽ�������Ŀ
		int book_id1;//�鼮���
		int book_id2;//�鼮���
		int day;//����ʱ��
		cout<<"������"<<endl;
		cin>>name;
		cout<<"�˺ţ�"<<endl;
		cin>>id;
		cout<<"���룺"<<endl;
		cin>>password;
		teacher[r].set(name,id,password);
		r++;
		cout<<"ע��ɹ�"<<endl;
	} 
	//��¼ 
	if(choice==1){
		cout<<"�������˺ţ�"<<endl;
		int m=S;//student��� 
		string id;
		string password;
		cin>>id;
		cout<<"���������룺"<<endl;
		cin>>password;
		int n=T;
		for(int i=0;i<r;i++){
			if(teacher[i].get_id()==id)
			n=i;
		} 
		if(n==T)
		cout<<"�û�������"<<endl;
		else{
			if(teacher[n].get_password()!=password)
			cout<<"�������"<<endl;
			else{
				cout<<"��¼�ɹ�"<<endl; 
				m=n;
			} 
		}
		//��¼�ɹ��� 
		if(m!=T){
			int bn=2,maxday=14;
			cout<<"���飺1  ���飺2"<<endl;
			int choice;
			cin>>choice;
			//����
			if(choice==1){
				//��������鼮��Ϣ
				for(int i=0;i<b;i++)
				book[i].print();
				cout<<"�����鼮��ţ�"<<endl;
				string id;
				int j=B;//�鼮��� 
				cin>>id;
				for(int i=0;i<b;i++){
					if(book[i].get_id()==id)
					j=i;
				}
				if(j==B)
				cout<<"�鼮������"<<endl;
				else{
					if(teacher[m].get_book_n()>bn)
					cout<<"�Ѵﵽ��������Ŀ" <<endl;
					else{
						int year,month,day;
						cout<<"������������ڣ�"<<endl;
						cin>>year>>month>>day; 
						cout<<"���ĳɹ�"<<endl;
						book[j].booknumber(0);//�鼮��Ŀ�仯 
						teacher[m].range(1);//�����ѽ����鼮��Ŀ�仯 
						//¼���鼮��Ϣ 
						teacher[m].set_id1(j);
						//д�������־
						ofstream fout("log.txt",ios::app);
						if(!fout)
						cout<<"��־��ʧ��"<<endl;
						fout<<"���ڣ�"<<year<<"."<<month<<"."<<day<<"    ������"<<teacher[m].get_name()<<"   �����鼮��"<<
						book[j].get_name()<<endl;
						fout.close(); 
					}
				} 
			}
			//����
			if(choice==2){
				cout<<"�����鼮���"<<endl;
				string id;
				cin>>id;
				int j=B;
				for(int i=0;i<b;i++){
					if(book[i].get_id()==id)
					j=i;
				}
				if(j==B)
				cout<<"�鼮������"<<endl;
				else{
					int d;
					int year,month,day;
					cout<<"�����뻹�����ڣ�"<<endl;
					cin>>year>>month>>day; 
					cout<<"�������ʱ��"<<endl;
					cin>>d;
					if(d>maxday)
					cout<<"����ʱ�䣬�뽻����"<<endl;
					cout<<"����ɹ�"<<endl;
					book[j].booknumber(1);//�鼮��Ŀ�仯 
					teacher[m].range(0);//�����ѽ����鼮��Ŀ�仯 
					//ɾ���鼮��Ϣ						
					teacher[m].set_id1(0);
					//д�������־
					ofstream fout("log.txt",ios::app);
					if(!fout)
					cout<<"��־��ʧ��"<<endl;
					fout<<"���ڣ�"<<year<<"."<<month<<"."<<day<<"    ������"<<teacher[m].get_name()<<"   �黹�鼮��"<<
					book[j].get_name()<<endl;
					fout.close(); 
				} 
			} 
		}
	}
	write(book,teacher,student,manager);
}

int main(){
		int n=1;
	do{
		Student student[S];
		Teacher teacher[T];
		Book book[B];
		Manager manager[M];
		//��ȡ��Ϣ
		//�鼮 
		ifstream fin("book.txt",ios::in) ;
		if(!fin)
		cout<<"���ݶ�ȡʧ��"<<endl;
		for(int i=0;i<B;i++){
			string name;//����
			string id;//���
			string sort;//���
			int number;//ʣ������
			double price;//�۸�
			fin>>name>>id>>sort>>number>>price;
			book[i].set(name,id,sort,number,price);
		}
		fin.close();
		//ѧ�� 
		ifstream fin1("student.txt",ios::in) ;
		if(!fin1)
		cout<<"���ݶ�ȡʧ��"<<endl;
		for(int i=0;i<S;i++){
			string name;//����
			string id;//ѧ��
			string password;//����
			int book_number;//�ѽ�������Ŀ
			int book_id1;//�鼮���
			int day;//����ʱ��
			fin1>>name>>id>>password>>book_number>>book_id1>>day;
			student[i].set(name,id,password,book_number,book_id1,day); 
		}
		fin1.close();
		//Teacher 
		ifstream fin2("teacher.txt",ios::in);
		if(!fin2)
		cout<<"���ݶ�ȡʧ��"<<endl;
		for(int i=0;i<S;i++){
			string name;//����
			string id;//ѧ��
			string password;//����
			int book_number;//�ѽ�������Ŀ
			int book_id1;//�鼮���
			int day;//����ʱ��
			fin2>>name>>id>>password>>book_number>>book_id1>>day;
			teacher[i].set(name,id,password,book_number,book_id1,day); 
		}
		fin2.close();
		//������Ա
		ifstream fin3("manager.txt",ios::in) ;
		if(!fin3)
		cout<<"���ݶ�ȡʧ��"<<endl;
		for(int i=0;i<B;i++){
			string name;//���� 
			string id;//�˺� 
			string password;//���� 
			fin3>>name>>id>>password;
			manager[i].set(name,id,password);
		}
		fin3.close(); 
		int choice;
		cout<<"�������"<<endl;
		cout<<"������Ա 1"<<"    ��ʦ   2"<<"    ѧ��  3"<<endl; 
		cin>>choice;
		if(choice==1)
		fun_manager(book,teacher,student,manager);	
		if(choice==2)
		fun_teacher(book,teacher,student,manager);
		if(choice==3)
		fun_student(book,teacher,student,manager);
		write(book,teacher,student,manager);
		cout<<"�Ƿ��������"<<endl;
		cout<<"��  1"<<"��  0"<<endl;
		cin>>n; 
	}
	while(n==1);
	
}


















