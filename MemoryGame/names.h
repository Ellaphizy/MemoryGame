#include<iostream>
#include<string>


using namespace std;


class naming
{

	string name;
	string username;
	string password;
public:
	void setname(string uname);
	string getname();
	void setusername(string used);
	string getusername();
	void setpassword(string pword);
	string getpassword();

};

void naming::setname(string uname)
{
	name = uname;
}
string naming::getname()
{
	return name;
}
void naming::setusername(string used)
{
	username = used;
}
string naming::getusername()
{
	return username;
}
void naming::setpassword(string pword)
{
	password = pword;
}
string naming::getpassword()
{
	return password;
}

