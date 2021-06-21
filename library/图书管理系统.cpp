#include<iostream>
#include<string>
#include<fstream>
const int B=10,S=10,T=10,M=10; 
using namespace std;
//书
class Book
{	
	string name;//书名
	string id;//编号
	string sort;//类别
	int number;//剩余数量
	double price;//价格
public:
	Book(string n="0",string i="0",string s="0",int nu=0,double p=0){
		name=n;
	id=i;
	sort=s;
	number=nu;
	price=p;
	}
	//输入
	void set(string n,string i,string s,int nu,double p);
	//获取信息
	string get_name(){return name;}
	string get_id(){return id;}
	string get_sort(){return sort;}
	int get_number(){return number;}
	double get_price(){return price;}
	//输出信息
	void print();
	//书剩余数量
	void booknumber(int n);
	//文件写入
	void f_print();
	//重载
	friend istream & operator >>(istream &,Book &);
	friend ostream & operator <<(ostream &,Book &); 
};
//读者类
class Reader{	
	string name;//姓名
	string id;//学号
	string password;//密码
	int book_number;//已借阅书数目
	int day;//借阅时间
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
	//写入数据
	void set(string na,string i,string p,int b_n,int d);
	//获取数据
	string get_name(){return name;}
	string get_id(){return id;}
	string get_password(){return password;}
	int get_book_n(){return book_number;}
	//int get_id1(){return book_id1;}
	//int get_id2(){return book_id2;}
	int get_day(){return day;}
	//写入文件
	void f_print();
	//输出信息
	void print();
	//借阅数目变化
	void range(int n);
};
//学生类
class Student:public Reader{
		int book_id1;//书籍编号
	public:
		Student(string na="0",string i="0",string p="0",int b_n=0,int bn1=0,int d=0):
		Reader(na,i,p,b_n,d){
			book_id1=bn1;	
		}
		int get_bookid(){return book_id1;}
		//借阅信息录入
		void set_id1(int id);
		//写入数据
		void set(string na,string i,string p,int b_n,int bn1,int d);
		//返回借阅书籍信息 
		int get_id1(){return book_id1;}
};
//教师类
class Teacher :public Reader{
	int book_id1;
	int book_id2;
	public:
		Teacher(string na="0",string i="0",string p="0",int b_n=0,int bn1=0,int bn2=0,int d=0):
		Reader(na,i,p,b_n,d){
		book_id1=bn1;
		book_id2=bn2;			
		}
		//返回借阅书籍信息 
		int get_bookid1(){return book_id1;}
		int get_bookid2(){return book_id2;}
		//借阅信息录入
		void set_id1(int id);
		void set_id2(int id);  
		//写入数据
		void set(string na,string i,string p,int b_n,int bn1,int bn2,int d);
}; 
//管理员
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
		//赋值
		void set(string na,string i,string p);
		//密码验证
		int fun_pw(string p);
		//返回信息
		string get_name(){return name;}
		string get_id(){return id;} 
		string get_password(){return password;}
}; 
//Book赋值 
void Book::set(string n,string i,string s,int nu,double p){
	name=n;
	id=i;
	sort=s;
	number=nu;
	price=p;
}
//Book输出 
void Book::print(){
	cout<<"书名:"<<name<<" 编号:"<<id<<" 类别:"<<sort<<" 价格："<<price<<" 剩余数量："<<number<<endl;
}
//Book剩余数目统计 
void Book::booknumber(int n){
	if(n==1)
		number++;
	else number--;
}
//Book写入文件 
void Book::f_print(){
	ofstream fout("book.txt",ios::app);
	if(!fout){
		cout<<"文件打开失败"<<endl;
	}
	fout<<name<<" "<<id<<" "<<sort<<" "<<number<<" "<<price<<" ";
	fout.close();
}
//Book重载
istream & operator >>(istream & in,Book & b){
	in>>b.name>>b.id>>b.sort>>b.number>>b.price;
}
ostream & operator <<(ostream & out,Book & b){
	out<<"书名:"<<b.name<<" 编号:"<<b.id<<" 类别:"<<b.sort<<" 价格："<<b.price<<" 剩余数量："<<b.number<<endl;
} 
//Reader赋值 
void Reader::set(string na="0",string i="0",string p="0",int b_n=0,int d=0){
	name=na;
	id=i;
	password=p;
	book_number=b_n;
	//book_id1=bn1;
	//book_id2=bn2;
	day=d;
}
//Reader写入文件 
void Reader::f_print(){
	ofstream fout("reader.txt",ios::app);
	if(!fout){
		cout<<"文件打开失败"<<endl;
	}
	fout<<name<<" "<<id<<" "<<password<<" "<<book_number<<" "<<day<<" ";
	fout.close();
}
//Reader输出
void Reader::print(){
	cout<<"姓名："<<name<<" 学号："<<id<<" 借阅书籍数目："<<book_number<<endl;
} 
//借阅数目变化
void Reader::range(int n){
	if(n==1)
	book_number++;
	else book_number--;
}
//Student赋值
void Student::set(string na="0",string i="0",string p="0",int b_n=0,int bn1=0,int d=0){
	Reader::set(na,i,p,b_n,d);
	book_id1=bn1;
} 
//Student书籍信息录入 
void Student::set_id1(int id){
	book_id1=id;
}
//借阅信息录入
void Teacher::set_id1(int id){
	book_id1=id;
}
void Teacher::set_id2(int id){
	book_id2=id;
}  
//Teacher赋值 
void Teacher::set(string na="0",string i="0",string p="0",int b_n=0,int bn1=0,int bn2=0,int d=0){
	Reader::set(na,i,p,b_n,d);
	book_id1=bn1;
	book_id2=bn2;
} 
//Manager赋值
void Manager::set(string na,string i,string p){
	name=na;
	id=i;
	password=p;
}
//Manager密码验证
int Manager::fun_pw(string p){
	if(p==password)
	return 1;
	else return 0;
}
//写入文件函数 
void write(Book book[B],Teacher teacher[T],Student student[S],Manager manager[M]){
	ofstream fout("teacher.txt",ios::out);
	if(!fout)
	cout<<"存储文件teacher.txt打开失败"<<endl;
	for(int i=0;i<T;i++){
		string name=teacher[i].get_name();//姓名
		string id=teacher[i].get_id();//学号
		string password=teacher[i].get_password();//密码
		int book_number=teacher[i].get_book_n();//已借阅书数目
		int book_id1=teacher[i].get_bookid1();//书籍编号
		int book_id2=teacher[i].get_bookid2();//书籍编号
		int day=teacher[i].get_day();//借阅时间
		fout<<name<<" "<<id<<" "<<password<<" "<<book_number<<" "<<book_id1<<" "<<book_id2<<" "<<day<<" ";
	} 
	fout.close();
	
	ofstream fout1("book.txt",ios::out);
	if(!fout1)
	cout<<"存储文件book.txt打开失败"<<endl;
	for(int i=0;i<B;i++){
		string name=book[i].get_name();//书名
		string id=book[i].get_id();//编号
		string sort=book[i].get_sort();//类别
		int number=book[i].get_number();//剩余数量
		double price=book[i].get_price();//价格
		fout1<<name<<" "<<id<<" "<<sort<<" "<<number<<" "<<price<<" ";
	}
	fout1.close();
	
	ofstream fout2("student.txt",ios::out);
	if(!fout2)
	cout<<"存储文件student.txt打开失败"<<endl;
	for(int i=0;i<S;i++){
		string name=student[i].get_name();//姓名
		string id=student[i].get_id();//学号
		string password=student[i].get_password();//密码
		int book_number=student[i].get_book_n();//已借阅书数目
		int book_id1=student[i].get_bookid();//书籍编号
		int day=student[i].get_day();//借阅时间
		fout2<<name<<" "<<id<<" "<<password<<" "<<book_number<<" "<<book_id1<<" "<<day<<" ";
	} 
	fout2.close();
	
	ofstream fout3("manager.txt",ios::out);
	if(!fout3)
	cout<<"存储文件manager.txt打开失败"<<endl;
	for(int i=0;i<M;i++){
		string name=manager[i].get_name();//姓名
		string id=manager[i].get_id();//学号
		string password=manager[i].get_password();//密码
		fout3<<name<<" "<<id<<" "<<password<<" ";
	} 
	fout3.close();
} 
//管理人员 
void fun_manager(Book book[B],Teacher teacher[T],Student student[S],Manager manager[M]){
	cout<<"注册 1      登录 2"<<endl;
	int choice;
	int m=0,s=0,t=0,b=0; 
	cin>>choice;
	//注册 
	if(choice==1){
		for(int i=0;i<M;i++){
			if(manager[i].get_name()!="0")
			m++;
		}
		string name,id,password;
		cout<<"姓名"<<endl;
		cin>>name;
		cout<<"账号"<<endl;
		cin>>id;
		cout<<"密码"<<endl;
		cin>>password;
		manager[m].set(name,id,password);
		m++;
		cout<<"注册成功"<<endl;
	}
	//登录 
	if(choice==2){
		cout<<"请输入账号"<<endl;
		string id,password;
		cin>>id;
		int n=M;
		//计算数量 
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
			cout<<"账户不存在"<<endl;
		}
		else{
			cout<<"请输入密码"<<endl;
			cin>>password;
			if(manager[n].fun_pw(password))
			cout<<"密码错误"<<endl; 
			else {
				//登陆成功
				cout<<"登录成功"<<endl;
				cout<<"请选择要进行的操作"<<endl;
				cout<<"1(信息查询) 2（书籍管理）"<<endl; 
				int choice;
				cin>>choice;
				//信息查询 
				if(choice==1){
					cout<<"请输入查询类别 教师 1 学生 2 书籍 3"<<endl;
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
				//书籍管理
				if(choice==2){
					cout<<"增加书籍：1 删除书籍：2 修改书籍信息：3"<<endl; 
					cout<<"请输入你的选择"<<endl;
					int choice;
					cin>>choice;
					//增加书籍 
					if(choice==1){
						cout<<"输入书籍信息"<<endl;
						string name;//书名
						string id;//编号
						string sort;//类别
						int number;//剩余数量
						double price;//价格
						cout<<"书名:";
						cin>>name; 
						cout<<"编号:";
						cin>>id; 
						cout<<"类别:";
						cin>>sort; 
						cout<<"数量:";
						cin>>number; 
						cout<<"价格:";
						cin>>price; 
						Book bo(name,id,sort,number,price);
						book[b]=bo;
						b++;
					} 
					//删除书籍
					if(choice==2){
						cout<<"请输入书籍编号"<<endl;
						string id;
						cin>>id;
						int n=B;
						for (int i=0;i<b;i++){
							if(book[i].get_id()==id)
							n=i;
						}
						if(n==B)
						cout<<"不存在id为"<<id<<"的书"<<endl;
						else{
							for(int i=n;i<b;i++){
								book[n]=book[n+1];
							}
							b--;
						} 
					} 
					//修改书籍信息
					if(choice==3){
						cout<<"请输入书籍编号"<<endl;
						string id;
						cin>>id;
						int n=B;
						for (int i=0;i<b;i++){
							if(book[i].get_id()==id)
							n=i;
						}
						if(n==10)
						cout<<"不存在id为"<<id<<"的书"<<endl;
						else{
							cout<<"输入书籍信息"<<endl;
							string name;//书名
							string id;//编号
							string sort;//类别
							int number;//剩余数量
							double price;//价格
							cout<<"书名:";
							cin>>name; 
							cout<<"编号:";
							cin>>id; 
							cout<<"类别:";
							cin>>sort; 
							cout<<"数量:";
							cin>>number; 
							cout<<"价格:";
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

//学生
void fun_student(Book book[B],Teacher teacher[T],Student student[S],Manager manager[M]){
	int b=0,r=0;//书的种数,读者数量 
	int max;
	if(B>S)
	max=B;
	else max=S;
	//计算数量 
	for(int i=0;i<max;i++){
		string s=book[i].get_name();
		string s1=student[i].get_name();
		if(s!="0")
		b++;
		if(s1!="0")
		r++;
	} 
	cout<<"选择要进行的操作"<<endl;
	int choice;
	cout<<"登录：1  注册：2"<<endl;
	cin>>choice;
	//注册 
	if(choice==2){
		string name;//姓名
		string id;//学号
		string password;//密码
		int book_number;//已借阅书数目
		int book_id1;//书籍编号
		int book_id2;//书籍编号
		int day;//借阅时间
		cout<<"姓名："<<endl;
		cin>>name;
		cout<<"学号："<<endl;
		cin>>id;
		cout<<"密码："<<endl;
		cin>>password;
		student[r].set(name,id,password);
		r++;
		cout<<"注册成功"<<endl;
	} 
	//登录 
	if(choice==1){
		cout<<"请输入学号："<<endl;
		int m=S;//student身份 
		string id;
		string password;
		cin>>id;
		cout<<"请输入密码："<<endl;
		cin>>password;
		int n=S;
		for(int i=0;i<r;i++){
			if(student[i].get_id()==id)
			n=i;
		} 
		if(n==S)
		cout<<"用户不存在"<<endl;
		else{
			if(student[n].get_password()!=password)
			cout<<"密码错误"<<endl;
			else{
				cout<<"登录成功"<<endl; 
				m=n;
			} 
		}
		//登录成功后 
		if(m!=S){
			int bn=1,maxday=7;
			cout<<"借书：1  还书：2"<<endl;
			int choice;
			cin>>choice;
			//借书
			if(choice==1){
				//输出现有书籍信息
				for(int i=0;i<b;i++)
				book[i].print();
				cout<<"输入书籍编号："<<endl;
				string id;
				int j=B;//书籍编号 
				cin>>id;
				for(int i=0;i<b;i++){
					if(book[i].get_id()==id)
					j=i;
				}
				if(j==B)
				cout<<"书籍不存在"<<endl;
				else{
					if(student[m].get_book_n()>bn)
					cout<<"已达到最大借阅数目" <<endl;
					else{
						int year,month,day;
						cout<<"请输入借阅日期："<<endl;
						cin>>year>>month>>day; 
						cout<<"借阅成功"<<endl;
						book[j].booknumber(0);//书籍数目变化 
						student[m].range(1);//读者已借阅书籍数目变化 
						//录入书籍信息 
						student[m].set_id1(j);
						//写入借阅日志
						ofstream fout("log.txt",ios::app);
						if(!fout)
						cout<<"日志打开失败"<<endl;
						fout<<"日期："<<year<<"."<<month<<"."<<day<<"    姓名："<<student[m].get_name()<<"   借阅书籍："<<
						book[j].get_name()<<endl;
						fout.close(); 
					}
				} 
			}
			//还书
			if(choice==2){
				cout<<"输入书籍编号"<<endl;
				string id;
				cin>>id;
				int j=B;
				for(int i=0;i<b;i++){
					if(book[i].get_id()==id)
					j=i;
				}
				if(j==B)
				cout<<"书籍不存在"<<endl;
				else{
					int d;
					int year,month,day;
					cout<<"请输入还书日期："<<endl;
					cin>>year>>month>>day; 
					cout<<"输入借阅时间"<<endl;
					cin>>d;
					if(d>maxday)
					cout<<"超出时间，请交罚款"<<endl;
					cout<<"还书成功"<<endl;
					book[j].booknumber(1);//书籍数目变化 
					student[m].range(0);//读者已借阅书籍数目变化 
					//删除书籍信息						
					student[m].set_id1(0);
					//写入借阅日志
					ofstream fout("log.txt",ios::app);
					if(!fout)
					cout<<"日志打开失败"<<endl;
					fout<<"日期："<<year<<"."<<month<<"."<<day<<"    姓名："<<student[m].get_name()<<"   归还书籍："<<
					book[j].get_name()<<endl;
					fout.close(); 
				} 
			} 
		}
	}
	write(book,teacher,student,manager);
}
//教师 
void fun_teacher(Book book[B],Teacher teacher[T],Student student[S],Manager manager[M]){
	int b=0,r=0;//书的种数,读者数量 
	int max;
	if(B>T)
	max=B;
	else max=T;
	//计算数量 
	for(int i=0;i<max;i++){
		string s=book[i].get_name();
		string s1=teacher[i].get_name();
		if(s!="0")
		b++;
		if(s1!="0")
		r++;
	} 
	cout<<"选择要进行的操作"<<endl;
	int choice;
	cout<<"登录：1  注册：2"<<endl;
	cin>>choice;
	//注册 
	if(choice==2){
		string name;//姓名
		string id;//学号
		string password;//密码
		int book_number;//已借阅书数目
		int book_id1;//书籍编号
		int book_id2;//书籍编号
		int day;//借阅时间
		cout<<"姓名："<<endl;
		cin>>name;
		cout<<"账号："<<endl;
		cin>>id;
		cout<<"密码："<<endl;
		cin>>password;
		teacher[r].set(name,id,password);
		r++;
		cout<<"注册成功"<<endl;
	} 
	//登录 
	if(choice==1){
		cout<<"请输入账号："<<endl;
		int m=S;//student身份 
		string id;
		string password;
		cin>>id;
		cout<<"请输入密码："<<endl;
		cin>>password;
		int n=T;
		for(int i=0;i<r;i++){
			if(teacher[i].get_id()==id)
			n=i;
		} 
		if(n==T)
		cout<<"用户不存在"<<endl;
		else{
			if(teacher[n].get_password()!=password)
			cout<<"密码错误"<<endl;
			else{
				cout<<"登录成功"<<endl; 
				m=n;
			} 
		}
		//登录成功后 
		if(m!=T){
			int bn=2,maxday=14;
			cout<<"借书：1  还书：2"<<endl;
			int choice;
			cin>>choice;
			//借书
			if(choice==1){
				//输出现有书籍信息
				for(int i=0;i<b;i++)
				book[i].print();
				cout<<"输入书籍编号："<<endl;
				string id;
				int j=B;//书籍编号 
				cin>>id;
				for(int i=0;i<b;i++){
					if(book[i].get_id()==id)
					j=i;
				}
				if(j==B)
				cout<<"书籍不存在"<<endl;
				else{
					if(teacher[m].get_book_n()>bn)
					cout<<"已达到最大借阅数目" <<endl;
					else{
						int year,month,day;
						cout<<"请输入借阅日期："<<endl;
						cin>>year>>month>>day; 
						cout<<"借阅成功"<<endl;
						book[j].booknumber(0);//书籍数目变化 
						teacher[m].range(1);//读者已借阅书籍数目变化 
						//录入书籍信息 
						teacher[m].set_id1(j);
						//写入借阅日志
						ofstream fout("log.txt",ios::app);
						if(!fout)
						cout<<"日志打开失败"<<endl;
						fout<<"日期："<<year<<"."<<month<<"."<<day<<"    姓名："<<teacher[m].get_name()<<"   借阅书籍："<<
						book[j].get_name()<<endl;
						fout.close(); 
					}
				} 
			}
			//还书
			if(choice==2){
				cout<<"输入书籍编号"<<endl;
				string id;
				cin>>id;
				int j=B;
				for(int i=0;i<b;i++){
					if(book[i].get_id()==id)
					j=i;
				}
				if(j==B)
				cout<<"书籍不存在"<<endl;
				else{
					int d;
					int year,month,day;
					cout<<"请输入还书日期："<<endl;
					cin>>year>>month>>day; 
					cout<<"输入借阅时间"<<endl;
					cin>>d;
					if(d>maxday)
					cout<<"超出时间，请交罚款"<<endl;
					cout<<"还书成功"<<endl;
					book[j].booknumber(1);//书籍数目变化 
					teacher[m].range(0);//读者已借阅书籍数目变化 
					//删除书籍信息						
					teacher[m].set_id1(0);
					//写入借阅日志
					ofstream fout("log.txt",ios::app);
					if(!fout)
					cout<<"日志打开失败"<<endl;
					fout<<"日期："<<year<<"."<<month<<"."<<day<<"    姓名："<<teacher[m].get_name()<<"   归还书籍："<<
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
		//读取信息
		//书籍 
		ifstream fin("book.txt",ios::in) ;
		if(!fin)
		cout<<"数据读取失败"<<endl;
		for(int i=0;i<B;i++){
			string name;//书名
			string id;//编号
			string sort;//类别
			int number;//剩余数量
			double price;//价格
			fin>>name>>id>>sort>>number>>price;
			book[i].set(name,id,sort,number,price);
		}
		fin.close();
		//学生 
		ifstream fin1("student.txt",ios::in) ;
		if(!fin1)
		cout<<"数据读取失败"<<endl;
		for(int i=0;i<S;i++){
			string name;//姓名
			string id;//学号
			string password;//密码
			int book_number;//已借阅书数目
			int book_id1;//书籍编号
			int day;//借阅时间
			fin1>>name>>id>>password>>book_number>>book_id1>>day;
			student[i].set(name,id,password,book_number,book_id1,day); 
		}
		fin1.close();
		//Teacher 
		ifstream fin2("teacher.txt",ios::in);
		if(!fin2)
		cout<<"数据读取失败"<<endl;
		for(int i=0;i<S;i++){
			string name;//姓名
			string id;//学号
			string password;//密码
			int book_number;//已借阅书数目
			int book_id1;//书籍编号
			int day;//借阅时间
			fin2>>name>>id>>password>>book_number>>book_id1>>day;
			teacher[i].set(name,id,password,book_number,book_id1,day); 
		}
		fin2.close();
		//管理人员
		ifstream fin3("manager.txt",ios::in) ;
		if(!fin3)
		cout<<"数据读取失败"<<endl;
		for(int i=0;i<B;i++){
			string name;//姓名 
			string id;//账号 
			string password;//密码 
			fin3>>name>>id>>password;
			manager[i].set(name,id,password);
		}
		fin3.close(); 
		int choice;
		cout<<"输入身份"<<endl;
		cout<<"管理人员 1"<<"    教师   2"<<"    学生  3"<<endl; 
		cin>>choice;
		if(choice==1)
		fun_manager(book,teacher,student,manager);	
		if(choice==2)
		fun_teacher(book,teacher,student,manager);
		if(choice==3)
		fun_student(book,teacher,student,manager);
		write(book,teacher,student,manager);
		cout<<"是否继续操作"<<endl;
		cout<<"是  1"<<"否  0"<<endl;
		cin>>n; 
	}
	while(n==1);
	
}


















