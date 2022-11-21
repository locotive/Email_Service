#pragma once

#ifndef __header_H__
#define __header_H__

#include<iostream>
#include<string>
#include<vector>
#include <map>
#include <windows.h> 

struct mail {
	std::string To;
	std::string From;
	std::string Title;
	std::string Contents;
};

class Account
{
protected:
	std::string ID;
	std::string PassWord;
	std::vector<std::string> ID_list;
	std::map<std::string, std::string> account_Twin;
	std::vector<mail> email_list;
	mail email;
	int menu;
};
class MainController
{
	int menu;
public:
	void start();
};
class EmailController :public Account
{
public:
	void start(std::string);
	void write();
	void receive();
	void send();
	void copy_vec(const std::string&);
	
};
class AccountController :public Account
{
	EmailController E_control;
public:
	void make_account();
	void login();
	void print_Id();
};

#endif
