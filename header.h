#pragma once

#ifndef __header_H__
#define __header_H__

struct mail {
	std::string To;
	std::string From;
	std::string Title;
	std::string Contents;
};

#include<iostream>
#include<string>
#include<vector>
#include <map>

class Account
{
protected:
	std::string ID;
	std::string PassWord;
	std::vector<std::string> ID_list;
	std::map<std::string, std::string> account_Twin;
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
	void start();
	void write();
	void receive();
	void send();

};
class AccountController :public Account
{
	EmailController E_control;
public:
	void make_account();
	void login();
};

#endif
