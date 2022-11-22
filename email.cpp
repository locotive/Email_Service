#include"header.h"

void MainController::start()
{
	AccountController account;
	while (1)
	{
		system("cls");
		std::cout << "원하시는 메뉴를 선택해주세요" << std::endl;
		std::cout << "종료 0" << std::endl;
		std::cout << "회원 가입 1" << std::endl;
		std::cout << "로그인 2" << std::endl;
		std::cout << "ID 목록 3" << std::endl;
		std::cin >> menu;
		if (menu == 0)
		{
		exit(0);
		}
		else if (menu == 1)
		{
			account.make_account();
		}
		else if (menu == 2)
		{
			account.login();
		}
		else if (menu == 3)
		{
			account.print_Id();
		}
		else
		{
			std::cout << "잘못 입력하셨습니다." << std::endl;
			std::cout << "다시 입력해주세요." << std::endl;
		}
	}

}

void AccountController::make_account()
{
	system("cls");
	std::cout << "ID를 입력하세요: ";
	std::cin >> ID;
	if (find(ID_list.begin(), ID_list.end(), ID) == ID_list.end())
	{
		ID_list.push_back(ID);
		std::cout << "PassWord를 입력하세요: ";
		E_control.copy_vec(ID);
		std::cin >> PassWord;
		account_Twin.insert(std::make_pair(ID, PassWord));
		std::cout <<"<"<<ID <<">" << " 가입되었습니다" << std::endl;
	}
	else
		std::cout << "중복된 ID 입니다" << std::endl;
	Sleep(1000);

}
void AccountController::login()
{
	system("cls");
	std::cout << "ID를 입력하세요: ";
	std::cin >> ID;
	std::cout << "PassWord를 입력하세요: ";
	std::cin >> PassWord;
	if (account_Twin.count(ID) == 1)
	{
		if (account_Twin[ID] == PassWord)
		{
			std::cout << "로그인 되었습니다" << std::endl;
			Sleep(1000);
			E_control.start(ID);
		}
		else
		{
			std::cout << "PassWord를 잘못 입력하셨습니다." << std::endl;
		}
	}
	else
		std::cout << "ID를 잘못 입력하셨습니다." << std::endl;
		Sleep(1000);

}
void AccountController::print_Id()
{
	system("cls");
	std::cout << "ID 목록" << std::endl;
	for (int i = 0; i < ID_list.size(); i++)
		std::cout <<i+1<<") "<< ID_list[i] << std::endl;
	system("PAUSE");
}
void EmailController::copy_vec(const std::string& id) 
{
	ID_list.push_back(id);
}
void EmailController::start(std::string id)
{
	ID = id;
	while (1)
	{
		system("cls");
		std::cout << "원하시는 메뉴를 선택해주세요" << std::endl;
		std::cout << "로그아웃 0" << std::endl;
		std::cout << "메일 쓰기 1" << std::endl;
		std::cout << "받은 메일함 2" << std::endl;
		std::cout << "보낸 메일함 3" << std::endl;
		std::cin >> menu;
		if (menu == 0)
		{
			return;
		}
		else if (menu == 1)
		{
			write();
		}
		else if (menu == 2)
		{
			receive();
		}
		else if (menu == 3)
		{
			send();
		}
	}
}
void EmailController::write()
{
	system("cls");
	email.From= ID ;
	std::cout << "To: ";
	std::cin >> email.To;
	std::cout << "Title: ";
	std::cin >> email.Title;
	std::cout << "Contents: ";
	std::cin >> email.Contents;
	for (int i = 0; i < ID_list.size(); i++)
	{
		if (ID_list[i] == email.To)
		{
			email_list.push_back(email);
			std::cout << email.To << " 에게 메일을 발송합니다." << std::endl;
			Sleep(1000);
			return;
		}
		else if (i == ID_list.size()-1)
		{
			std::cout << "이메일이 존재하지 않습니다." << std::endl;
			std::cout << "다시 보내시려면 y를 입력하세요" << std::endl;
			std::string temp;
			std::cin >> temp;
			if (temp == "y")
			{
				write();
			}
			else
			{
				break;
			}
		}
	}
}
void EmailController::receive()
{
	system("cls");
	std::cout << "보낸 메일함" << std::endl;
	for (int i = 0; i < email_list.size(); i++)
	{
		if (email_list[i].To == ID)
		{
			std::cout << "From: " << email_list[i].From << std::endl;
			std::cout << "Title: " << email_list[i].Title << std::endl;
			std::cout << "Contents: " << email_list[i].Contents << std::endl<<std::endl;
		}
	}
	system("PAUSE");
}
void EmailController::send()
{
	system("cls");
	std::cout << "받은 메일함" << std::endl;
	for (int i = 0; i < email_list.size(); i++)
	{
		if (email_list[i].From == ID)
		{
			std::cout << "To: " << email_list[i].To << std::endl;
			std::cout << "Title: " << email_list[i].Title << std::endl;
			std::cout << "Contents: " << email_list[i].Contents << std::endl << std::endl;
		}
	}
	system("PAUSE");
}