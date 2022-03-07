#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Helper
{
public:
	static int stringlength(char *str)
	{
		int len = 0;
		for (int i = 0; str[i] !='\0'; i++)
		{
			len++;
		}
		return len;
	}
	static char * Getstringfrombuffer(char * str)
	{
		int lenght = stringlength(str);
		char *new_str = new char [lenght+1];
		int i =0;
		for (i = 0; i < lenght; i++)
		{
			new_str[i] = str[i];
		}
		new_str[i] = '\0';
		return new_str;
	}
	static char * Getstringfrombuffer_1(string str)
	{
		int lenght = length_of_str(str);
		char *new_str = new char [lenght+1];
		int i =0;
		for (i = 0; i < lenght; i++)
		{
			new_str[i] = str[i];
		}
		new_str[i] = '\0';
		return new_str;
	}
	static char * ConcatenateStrings(char * string , char *string2)
	{
		//Step 2:then it finds the length of each array
		int length = stringlength(string);
		int lengt_2 = stringlength(string2);
		int f_length = length+lengt_2;
		char *arr = new char [f_length+1];
		int  i  =0;
		//Step3:then it deep copies the both array
		for ( i = 0; i < length; i++)
		{
			arr[i] = string[i];
		}
		arr[i] = '\0';
		int k = i;
		for (int j = 0; j < lengt_2; j++)
		{
			arr[k] = string2[j];
			k++;
		}
		arr[k] = '\0';
		return arr;
	}
	static int length_of_str(string str)
	{
		int length = 0;
		for (int i = 0; str[i] !='\0' ; i++)
		{
			length++;
		}
		return length;
	}
};
class Base;
class User;
class Pages;
class Posts;
class Comment;
class Facebook;
class Activity
{
public:
	Activity();
	~Activity();
	int Get_type()
	{
		return Type;
	}
	char * Get_value()
	{
		return Value;
	}
	void Set_type(int a)
	{
		Type = a;
	}
	void Set_value(char * a)
	{
		Value = Helper::Getstringfrombuffer(a);
	}
	void Print()
	{
		if(Type == 1)
		{
			cout << "is feeling" << " " << Value << endl;
		}else if(Type == 2)
		{
			cout << "is thinking about" << " " << Value << endl;
		}else if(Type == 3)
		{
			cout << "is making" << " " << Value << endl;
		}else if(Type == 4)
		{
			cout << "is celebrating" << " " << Value << endl;
		}
	}
private:
	int Type;
	char *Value;
};
Activity::Activity()
{
	Type = 0;
	Value = nullptr;
}
Activity::~Activity()
{
	if(Value != 0)
	{
		delete [] Value;
	}
}
class Date
{
public:
	Date();
	~Date();
	void Print()
	{
		cout << Day  << "/"<< Month << "/" << Year << endl;
	}
	static void Setcurrentdate(int a,int b,int c)
	{
		Current_date.Day = a;
		Current_date.Month = b;
		Current_date.Year = c;
	}
	void Loaddatefromfile(ifstream &);
private:
	static Date Current_date;
	int Day;
	int Month;
	int Year;
};
Date Date::Current_date; 
void Date::Loaddatefromfile(ifstream & fin)
{
	fin >> Day;
	fin >> Month;
	fin >> Year;
}
Date::Date()
{
	Day = 0;
	Month = 0;
	Year = 0;
}
Date::~Date()
{
}
class Base
{
public:
	Base();
	virtual ~Base();
	virtual void Print_1()
	{

	}//likewise make same print in page class
	virtual void Addposttoyourtimeline(Posts *)
	{

	}
	virtual void Print_forcomment()
	{

	}
};
Base::Base()
{
}
Base::~Base()
{
}
class Comment
{
public:
	Comment();
	~Comment();
	void Loadcommentsfromfile(ifstream&);
	void Loadtextfromfile(ifstream&);
	void Print()
	{
		Commmentby->Print_forcomment();
		cout << Text << endl;
	}
	Base *Getpostedby()
	{
		return Commmentby;
	}
	void Setpostedby(Base * bptr)
	{
		Commmentby = bptr;
	}
	void Set_text(char *Text_1)
	{
		Text = Helper::Getstringfrombuffer(Text_1);
	}
private:
	char *ID;
	char *Text;
	Base * Commmentby;
};
void Comment::Loadcommentsfromfile(ifstream & f1)
{
	char temp[10];
	f1 >> temp;
	ID = Helper::Getstringfrombuffer(temp);
}
void Comment::Loadtextfromfile(ifstream & f1)
{
	char temp[100];
	f1.getline(temp,100,'\n');
	Text = Helper::Getstringfrombuffer(temp);

}
Comment::Comment()
{
	ID = nullptr;
	Text = nullptr;
	Commmentby = nullptr;
}
Comment::~Comment()
{
	if(ID != 0)
	{
		delete [] ID;
	}
	if(Text != 0)
	{
		delete [] Text;
	}
	if(Commmentby != 0)
	{
		delete [] Commmentby;
	}
}
class Posts
{
public:
	Posts();
	~Posts();
	void Setlikedby_user(Base * uptr)
	{
		Likedby[arr[current_post]] = uptr;
	}
	void Set_Shared_By(Base *);
	Base * Getsharedby()
	{
		return Sharedby;
	}
	static int arr[12];
	static int current_post;
	void Print_Likedby()
	{
		for (int i = 0; i < arr[current_post]; i++)
		{
			Likedby[i]->Print_1();
			cout << endl;
		}
		cout << endl;
	}
	void Print_Likedby_user()
	{
		for (int i = 0; i < arr[current_post]+1; i++)
		{
			Likedby[i]->Print_1();
			cout << endl;
		}
		cout << endl;
	}
	void Set_sharedby(Base * bptr)
	{
		Sharedby = bptr;
	}
	Base ** Get_Likedby()
	{
		return Likedby;
	}
	char * Getpostbyid()
	{
		return ID;
	}
	void Setlikedby(Base ** bptr)
	{
		Likedby = bptr;
	}
	Comment ** Get_commentlist()
	{
		return Commentlist;
	}
	int count_no_of_comment;
	void Addcommenttopost(Comment * cptr)
	{
		if(Commentlist != nullptr)
		{
			for (int i = count_no_of_comment; i < count_no_of_comment+1; i++)
			{
				if(cptr == nullptr)
				{
					break;
				}
				Commentlist[i] = cptr;
			}
			count_no_of_comment++;
		}else
		{
			count_no_of_comment = 0;
			Commentlist = new Comment*[10];
			count_no_of_comment++;
			for (int i = 0; i < count_no_of_comment; i++)
			{
				Commentlist[i] = cptr;
			}
		}
	}
	virtual void Print();
	Date Shared_date;
	void Loadpostsdata(ifstream &);
	Activity * Get_activity()
	{
		return activity;
	}
private:
	char *ID;
	char *Text;
	Base * Sharedby;
	Base ** Likedby;
	Activity * activity;
	Comment **Commentlist;
};
int Posts::current_post = 0;
int Posts::arr[12] = {0};
void Posts::Loadpostsdata(ifstream & f1)
{
	int check_activity;
	f1 >> check_activity;
	char temp_str[10];
	f1 >> temp_str;
	ID = Helper::Getstringfrombuffer(temp_str);
	Shared_date.Loaddatefromfile(f1);
	f1.ignore();
	char str[150];
	f1.getline(str,100,'\n');
	Text = Helper::Getstringfrombuffer(str);
	if(check_activity == 2)
	{
		activity = new Activity;
		int a;
		f1 >> a;
		activity->Set_type(a);
		f1.ignore();
		char temp_1[100];
		f1.getline(temp_1,100,'\n');
		activity->Set_value(temp_1);
	}else
	{
		activity = nullptr;
	}
}
Posts::Posts()
{
	ID = nullptr;
	Sharedby = nullptr;
	Likedby = nullptr;
	activity = nullptr;
	Text = nullptr;
	Commentlist = nullptr;
}
void Posts::Print()
{
	cout << Text << endl;
	if(Commentlist != 0)
	{
		//count_no_of_comment display's only one because it was the last setted value
		for (int i = 0; i < count_no_of_comment; i++)
		{
			Commentlist[i]->Print();
		}
	}

}
Posts::~Posts()
{
	if(ID != 0)
	{
		delete [] ID;
	}
	if(Likedby != 0)
	{
		delete [] Likedby;
	}
	if(Sharedby != 0)
	{
		delete [] Sharedby;
	}
	if(activity != 0)
	{
		delete [] activity;
	}
	if(Commentlist != 0)
	{
		for (int i = 0; i < count_no_of_comment; i++)
		{
			delete Commentlist[i];
		}
		delete Commentlist;
	}
	if(Text !=0)
	{
		delete [] Text;
	}
}
class Memory : public Posts
{
public:
	Memory();
	~Memory();
	void Setvalues(Posts *& ptr , char *Text_1)
	{
		Text = Helper::Getstringfrombuffer(Text_1);
		original_post = ptr;
	}
	void Print()
	{
		cout << Text << endl;
		original_post->Print();	
	}
	char * Text;
private:
	Posts *original_post;
};

Memory::Memory()
{
	 original_post = nullptr;
}

Memory::~Memory()
{
	original_post = 0;
}
class Pages : public Base
{
public:
	Pages();
	~Pages();
	void Loaddata_ofPages(ifstream &);
	void Print()
	{
		cout << Id << " " << Title << endl;
	}
	void Print_1()
	{
		cout << Title << " "; //activity
	}
	void Print_forcomment()
	{
		cout << Title << " wrote ";
	}
	char* Getid()
	{
		return Id;
	}
	
	char* Gettitle()
	{
		return Title;
	}
	int count;
	//static int count_posts[20];
	void Addposttoyourtimeline(Posts * post_ptr)
	{
		if(Timeline != nullptr)
		{ 
			for (int i = count; i < count+1; i++)
			{
				if(post_ptr == nullptr)
				{
					break;
				}
					Timeline[i] = post_ptr;
			}
			count++;
		}else
		{
			count = 0;
			Timeline = new Posts *[10];
			count++;
			for (int i = 0; i < count; i++)
			{
				Timeline[i] = post_ptr;
			}
		}
	}
	Posts ** Get_Timeline()
	{
		return Timeline;
	}
private:
	Posts ** Timeline;
	char *Id;
	char *Title;
};
void Pages::Loaddata_ofPages(ifstream & f1)
{
	//string muneeb;
	char ID_1[8];
	f1 >> ID_1;
	Id = Helper::Getstringfrombuffer_1(ID_1);
	//I have changed it to char [80] to string and f1.getlint to getline
	/*string temp_1;
	getline(f1,temp_1,'\n');
	Title = Helper::Getstringfrombuffer_1(temp_1);*/
	char temp_1[100];
	f1.getline(temp_1,100,'\n');
	Title = Helper::Getstringfrombuffer(temp_1);
}
Pages::Pages()
{
	Id = nullptr;
	Title = nullptr;
	Timeline = nullptr;
}
Pages::~Pages()
{
	if(Id != 0)
	{
		delete [] Id;
	}
	if(Title != 0)
	{
		delete [] Title;
	}
	for (int i = 0; i < count; i++)
	{
		delete Timeline[i];
	}
	delete [] Timeline;
}
class User : public Base
{
public:
	User();
	~User();
	void Loaddata_ofuser(ifstream &);
	void Print()
	{
		cout << Id << " " << F_name << " " << L_name << endl;  
	}
	void Print_1()
	{
		cout << F_name  << " " << L_name << " ";
	}
	void Print_forcomment()
	{
		cout << F_name << " " << L_name << " wrote ";
	}
	char*  GetId()
	{
		return Id;
	}
	char * Get_fname()
	{
		return F_name;
	}
	char * Get_lname()
	{
		return L_name;
	}
	void Viewfriendlist();
	void ViewHomePage();
	void Viewpgaeslist();
	int count;
	void Addposttoyourtimeline(Posts * post_ptr)
	{
		if(Timeline != nullptr)
		{ 
			for (int i = count; i < count+1; i++)
			{
				if(post_ptr == nullptr)
				{
					break;
				}
					Timeline[i] = post_ptr;
			}
			count++;
		}else
		{
			count = 0;
			Timeline = new Posts *[20];
			count++;
			for (int i =0; i < count; i++)
			{
				Timeline[i] = post_ptr;
			}
		}
	}
	User** Get_Friendlist()
	{
		return Friendlist;
	}
	void Setfriendlist(User ** friend_list)
	{
		Friendlist = friend_list;
	}
	Pages ** Get_Pageslist()
	{
		return Pageslist;
	}
	void SetPageslist(Pages ** Pages_list)
	{
		Pageslist = Pages_list;
	}
	static int count_friends [20];
	static int count_pages [20];
	static int current_user;
	void Viewtimeline();
private:
	char *Id;
	char *F_name;
	char *L_name;
	User** Friendlist;
	Pages** Pageslist;
	Posts ** Timeline;
	Comment ** Commentlist;
};
int  User::count_friends[20] = {0};
int User::count_pages[20] = {0};
int User::current_user = 0;
void User::Viewpgaeslist()
{
	if(Pageslist != 0)
	{
		for (int i = 0; i < count_pages[current_user]; i++)
		{
			Pageslist[i]->Print();
		}
	}else
	{
		cout << "User has no liked pages" << endl;
	}
}
void User::Viewtimeline()
{
	for (int i = 0; i < count; i++)
	{
		Timeline[i]->Print();
	}
}
void User::ViewHomePage()
{
	if(Friendlist != 0)
	{
		for (int i = 0; i < count_friends[current_user]; i++)
		{
			if(Friendlist[i]->Timeline[i] != nullptr)
			{	
				//date constraint and do all this in posts class
					Base * sharedby = Friendlist[i]->Timeline[0]->Getsharedby();
					sharedby->Print_1();
					Activity * ac = Friendlist[i]->Timeline[0]->Get_activity();
					if(ac != nullptr)
					{
						ac->Print();
					}else
					{
						cout << endl;
					}
				Friendlist[i]->Timeline[0]->Print();
			}
			//timeline ith not equal to null
			cout << endl;
		}
	}
	if(Pageslist != 0)
	{
		for (int i = 0; i < count_pages[current_user]; i++)
		{
			Posts ** Timeline_1 = Pageslist[i]->Get_Timeline();
			if(Timeline_1 == nullptr)
			{
				break;
			}
			if(Timeline_1[0] != nullptr)
			{
				Base * sharedby = Timeline_1[0]->Getsharedby();
				sharedby->Print_1();
				Activity * ac = Timeline[0]->Get_activity();
				if(ac != nullptr)
					{
						ac->Print();
					}else
					{
						cout << endl;
					}
				Timeline_1[0]->Print();
			}
			cout << endl;
		}
	}
	cout << endl;
}
void User::Viewfriendlist()
{
	//here i should use a generic term
	cout << F_name << " " << L_name << " set as a current user" << endl;
	if(Friendlist != 0)
	{
		for (int i = 0; i < count_friends[current_user] ; i++)
		{
			Friendlist[i]->Print();
		}
	}else
	{
		cout << "This user has no friends" <<endl;
	}
}
User::User()
{
	Id = nullptr;
	F_name = nullptr;
	L_name = nullptr;
	Friendlist = nullptr;
	Pageslist = nullptr;
	Timeline = nullptr;
}
User::~User()
{
	if(Id != 0)
	{
		delete [] Id;
	}
	if(Friendlist != 0)
	{
		/*for (int i = 0; i < count_friends[current_user]; i++)
		{
			delete Friendlist[i];
		}*/
		delete [] Friendlist;
	}
	if(Pageslist != 0)
	{
		/*for (int i = 0; i < count_pages[current_user]; i++)
		{
			delete Pageslist[i];
		}*/
		delete [] Pageslist;
	}
	if(F_name != 0)
	{
		delete [] F_name;
	}
	if(L_name != 0)
	{
		delete [] L_name;
	}
	for (int i = 0; i < count; i++)
	{
		delete Timeline[i];
	}
	delete  Timeline;
	//here the value of count = 10;
}
void User::Loaddata_ofuser(ifstream & f2)
{
	char temp[5];
	f2 >> temp;
	Id = Helper::Getstringfrombuffer(temp);
	char first[20];
	f2>>first;
	F_name = Helper::Getstringfrombuffer(first);
	char Last[30];
	f2 >> Last;
	L_name = Helper::Getstringfrombuffer(Last);
}
class Facebook : public Base
{
public:
	Facebook();
	~Facebook();
	void Addpost(Posts * post_ptr)
	{
		Posts ** ptr = new Posts*[Facebook::no_of_posts+1];
		for (int i = 0; i < Facebook::no_of_posts; i++)
		{
			ptr[i] = Postlist[i];
		}
		ptr[Facebook::no_of_posts+1] = post_ptr;
		Facebook::no_of_posts++;
		delete [] Postlist;
		Postlist = ptr;
	}
	//static Date currentdate;
	void Comment_on_a_post(char * , User * , char *);
	void Like_a_post(char * , User *);
	void Loaddatafromfile(char *,char *,char *,char *);
	void Sharememory(char *ID , User * , char *);
	User* Search_User_By_Id(char *);
	Pages* SearchPages(char *);
	Base * Search_object_by_id(char *);
	Posts * Search_post_by_id(char *);
	void Viewmemory(User *);
	static int no_of_pages;
	static int no_of_users;
	static int no_of_posts;
	static int no_of_comments;
	void Addfriend(int *&,char ***);
	void AddPages(int *,char ***);
	void Print(int);
	Posts** Get_Postlist()
	{
		return Postlist;
	}
private:
	User ** Userlist;
	Pages ** PagesList;
	Posts** Postlist;
	Comment ** Commentlist;
};
int Facebook::no_of_comments = 0;
int Facebook::no_of_posts = 0;
int Facebook::no_of_pages = 0;
int Facebook::no_of_users = 0;
void Facebook::Sharememory(char * ID , User * uptr , char * Text)
{
	Posts *ptr = Search_post_by_id(ID);
	Memory *mptr = new Memory;
	//date object
	mptr->Setvalues(ptr, Text);
	//mptr->Print();
	Addpost(mptr);
	//Postlist[no_of_posts+1] = mptr;
}
void Facebook::Viewmemory(User *uptr)
{
	for (int i = 0; i < no_of_posts; i++)
	{
		Base *bptr = Postlist[i]->Getsharedby();
		/*char *ID = Helper::Getstringfrombuffer(bptr-);
		char *ID_1 = Helper::Getstringfrombuffer(uptr->GetId());
		if(ID == )*/
	}
}
void Facebook::AddPages(int * arr, char *** temp)
{
	for (int i = 0; i < no_of_users; i++)
	{
		Pages ** Pages_list = Userlist[i]->Get_Pageslist();
		Pages_list = new Pages*[arr[i]];
		for (int j = 0; j < arr[i]; j++)
		{
			Pages_list[j] = new Pages;
			Pages_list[j] = SearchPages(temp[i][j]);
		}
		Userlist[i]->SetPageslist(Pages_list);
		if(Pages_list == 0)
		{
			Pages_list = nullptr;
		}
	}
}
void Facebook::Addfriend(int *& arr , char *** temp)
{
	for (int i = 0; i < no_of_users; i++)
	{
		User ** Friendlist = nullptr;
		Friendlist = Userlist[i]->Get_Friendlist();
		Friendlist = new User*[arr[i]];
		for (int j = 0; j < arr[i]; j++)
		{
			Friendlist[j] = new User;
			Friendlist[j] = Search_User_By_Id(temp[i][j]);
		}
		Userlist[i]->Setfriendlist(Friendlist);
		if(Friendlist ==0)
		{
			Friendlist = nullptr;
		}
	}
}
void Facebook::Loaddatafromfile(char * ptr , char * ptr_1 , char * ptr_2 , char *ptr_3)
{
	char *mystr = Helper::Getstringfrombuffer(ptr);
	ifstream f1;
	f1.open(mystr);
	f1 >> no_of_pages;
	PagesList = new Pages* [no_of_pages];
	for (int i = 0; i < no_of_pages; i++)
	{
		PagesList[i] = new Pages;
	}
	for (int i = 0; i < no_of_pages; i++)
	{
		PagesList[i]->Loaddata_ofPages(f1);
	}
	f1.close();
	char *mystr_1 = Helper::Getstringfrombuffer(ptr_1);
	ifstream f2;
	f2.open(mystr_1);
	f2 >> no_of_users;
	char *** temp_User = new char **[no_of_users];
	char *** temp_pages = new char **[no_of_users];
	Userlist = new User* [no_of_users];
	for (int i = 0; i < no_of_users; i++)
	{
		Userlist[i] = new User;
	}
	int * arr = new int [no_of_users];
	int *arr_1 = new int [no_of_users];
	for (int i = 0; i < no_of_users; i++)
	{
		Userlist[i]->Loaddata_ofuser(f2);
		temp_User[i] = new char *[10];
		int count = 0;
		for (int j = 0; j < 10; j++)
		{
			temp_User[i][j] = new char [10];
			f2 >> temp_User[i][j];
			if(temp_User[i][j][0] == '-')
			{
				break;
			}
			count++;
		}
		arr[i] = count;
		User::count_friends[i] = count;
		temp_pages[i] = new char *[10];
		int count_pages = 0;
		for (int j = 0; j < 10; j++)
		{
			temp_pages[i][j] = new char [10];
			f2 >> temp_pages[i][j];
			if(temp_pages[i][j][0] == '-')
			{
				break;
			}
			count_pages++;
		}
		User::count_pages[i] = count_pages;
		arr_1[i] = count_pages++;
	}
	f2.close();
	Addfriend(arr,temp_User);
	AddPages(arr_1,temp_pages);
	for (int i = 0; i < no_of_users; i++)
	{
		for (int j = 0; j < arr_1[i]; j++)
		{
				delete [] temp_pages[i][j];
		}
		delete[] temp_pages[i];
	}
	delete[] temp_pages;
	for (int i = 0; i < no_of_users; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			delete [] temp_User[i][j];
		}
		delete [] temp_User[i];
	}
	delete [] temp_User;
	char *mystr_2 = Helper::Getstringfrombuffer(ptr_2);
	ifstream f3;
	f3.open(mystr_2);
	f3 >> no_of_posts;
	Postlist = new Posts*[no_of_posts];
	for (int i = 0; i < no_of_posts; i++)
	{
		Postlist[i] = new Posts;
		Postlist[i]->Loadpostsdata(f3);
		char temp[10];
		f3 >> temp;
		Base * sharedby = Postlist[i]->Getsharedby();
		sharedby = Search_object_by_id(temp);
		Postlist[i]->Set_sharedby(sharedby);
		sharedby->Addposttoyourtimeline(Postlist[i]);
		char temp_list_liked_by[5][5];
		int count = 0;
		for (int i = 0; i < 5; i++)
		{
			f3 >> temp_list_liked_by[i];
			int len = Helper::stringlength(temp_list_liked_by[i]);
				if(temp_list_liked_by[i][0] == '-')
				{
					break;
				}
			count++;
		}
		Postlist[i]->arr[i] = count;
		Base ** Likedby = Postlist[i]->Get_Likedby();
		Likedby = new Base*[count+1];
		for (int i = 0; i < count; i++)
		{
			Likedby[i] = Search_object_by_id(temp_list_liked_by[i]);
		}
		for (int i = 0; i < count; i++)
		{
			Likedby[i]->Addposttoyourtimeline(Postlist[i]);
		}
		Postlist[i]->Setlikedby(Likedby);
	}
	f3.close();
	char *str = Helper::Getstringfrombuffer(ptr_3);
	ifstream f4;
	f4.open(str);
	f4 >> no_of_comments;
	Commentlist = new Comment*[no_of_comments];
	for (int i = 0; i < no_of_comments; i++)
	{
		Commentlist[i] = new Comment;
		Commentlist[i]->Loadcommentsfromfile(f4);
		char temp[10];
		f4 >> temp;
		Posts * Ptr = Search_post_by_id(temp);
		Ptr->Addcommenttopost(Commentlist[i]);
		char temp_posted_by[20];
		f4 >> temp_posted_by;
		Base * postedby = Commentlist[i]->Getpostedby();
		postedby = Search_object_by_id(temp_posted_by);
		Commentlist[i]->Setpostedby(postedby);
		Commentlist[i]->Loadtextfromfile(f4);
	}
	f4.close();
}
void Facebook::Comment_on_a_post(char *ID , User * uptr , char * Text)
{
	Commentlist[no_of_comments+1] = new Comment;
	Commentlist[no_of_comments+1]->Set_text(Text);
	Posts *ptr = Search_post_by_id(ID);
	ptr->Addcommenttopost(Commentlist[no_of_comments+1]);
	Commentlist[no_of_comments+1]->Setpostedby(uptr);
}
void Facebook::Like_a_post(char *ID, User *uptr)
{
	Posts *ptr = Search_post_by_id(ID);
	char *ID_1 = uptr->GetId();
	Base *bptr = Search_User_By_Id(ID_1);
	ptr->Setlikedby_user(bptr);
	ptr->Print_Likedby_user();
}
Posts *  Facebook::Search_post_by_id(char * ID)
{
	int len = Helper::stringlength(ID);
	for (int i = 0; i < no_of_posts; i++)
	{
		char *ID_compareto_be = Helper::Getstringfrombuffer(Postlist[i]->Getpostbyid());
		int count = 0;
		for (int j = 0; j < len; j++)
		{
			if(ID[j] == ID_compareto_be[j])
			{
				count++;
			}
		}
		if(count == len)
		{
			Posts::current_post = i;
			return Postlist[i];
		}
	}
}
Base * Facebook::Search_object_by_id(char * str)
{
	int len = Helper::stringlength(str);
	if(str[0]== 'u')
	{
		Base *bptr = Search_User_By_Id(str);
		return bptr;
	}else
	{
		Base * bptr = SearchPages(str);
		return bptr;
	}
}
Pages * Facebook::SearchPages(char *str)
{
	int len = Helper::stringlength(str);
	for (int i = 0; i < no_of_pages; i++)
	{
		char* Id = Helper::Getstringfrombuffer(PagesList[i]->Getid());
		int count = 0;
		for (int j = 0; j < len; j++)
		{
			if(Id[j]==str[j])
			{
				count++;
			}
		}
		if(count==len)
		{
			return PagesList[i];
		}
	}
}
User * Facebook::Search_User_By_Id(char * arr)
{
	int len = Helper::stringlength(arr);
	for (int i = 0; i < no_of_users; i++)
	{
		char *ID = Helper::Getstringfrombuffer(Userlist[i]->GetId());
		int count = 0;
		for (int j = 0; j <len; j++)
		{
			if(ID[j] == arr[j])
			{
				count++;
			}
		}
		if(count == len)
		{
			User::current_user = i;
			return Userlist[i];
		}
		delete [] ID;
	}
}
Facebook::Facebook()
{
	Userlist = nullptr;
	PagesList = nullptr;
	Postlist = nullptr;
	Commentlist = nullptr;
}
Facebook::~Facebook()
{
	for (int i = 0; i < no_of_users; i++)
	{
		delete  Userlist[i];
	}
	delete [] Userlist;
	for (int i = 0; i < no_of_pages; i++)
	{
		delete  PagesList [i];
	}
	delete [] PagesList;
	if(Commentlist !=0)
	{
		delete [] Commentlist;
	}
	if(Postlist != 0)
	{
		delete [] Postlist;

	}
}
//set liked by
int main()
{
	Facebook fb;
	Date::Setcurrentdate(15,11,2017);
	fb.Loaddatafromfile("Pages.txt","Users.txt","Posts.txt","Comments.txt");
	User *userptr = nullptr;
	userptr = fb.Search_User_By_Id("u7");
	cout << "--------------Friendlist---------------" << endl;
	userptr->Viewfriendlist();
	cout << "--------------Pageslist---------------" << endl;
	userptr->Viewpgaeslist();
	cout << "--------------Homepage---------------" << endl;
	userptr->ViewHomePage();
	cout << "--------------Timeline---------------" << endl;
	userptr->Viewtimeline();
	Posts *ptr = fb.Search_post_by_id("post5");
	cout << "--------------ViewPostbyid---------------" << endl;
	ptr->Print();
	cout << "--------------Liked by of Post---------------" << endl;
	ptr->Print_Likedby();
	fb.Comment_on_a_post("post4" , userptr , "Good Luck for your result");
	Posts *ptr_1 = fb.Search_post_by_id("post4");
	cout << "--------------Addcomment on a post---------------" << endl;
	ptr_1->Print();
	cout << "--------------Like a post---------------" << endl;
	fb.Like_a_post("post5" , userptr);
	cout << "--------------Share a memory---------------" << endl;
	fb.Sharememory("post10" , userptr,"Never thought I will be specialist in this field");
	//view memory(current user)
	//facebook view memory(current user)
	//i<totalposts(count) 
	//timeline->print()
	//postsprint is virtual
	system("pause");
	return 0;
}