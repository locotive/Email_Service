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
		std::cin >> PassWord;
		account_Twin.insert(std::make_pair(ID, PassWord));
		std::cout <<"<"<<ID <<">" << " 가입되었습니다" << std::endl;
		Sleep(1000);
	}
	else
		std::cout << "중복된 ID 입니다" << std::endl;

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
			E_control.start();
		}
		else
		{
			std::cout << "PassWord를 잘못 입력하셨습니다." << std::endl;
		}
	}
	else
		std::cout << "ID를 잘못 입력하셨습니다." << std::endl;

}
void AccountController::print_Id()
{
	system("cls");
	std::cout << "ID 목록" << std::endl;
	for (int i = 0; i < ID_list.size(); i++)
		std::cout <<i+1<<") "<< ID_list[i] << std::endl;
	system("PAUSE");
}
void EmailController::start()
{
	while (1)
	{
		system("cls");
		std::cout << "원하시는 메뉴를 선택해주세요" << std::endl;
		std::cout << "로그아웃 0" << std::endl;
		std::cout << "메일 쓰기 1" << std::endl;
		std::cout << "받은 메일함 2" << std::endl;
		std::cout << "발송 메일함 3" << std::endl;
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
	
}
void EmailController::receive()
{

}
void EmailController::send()
{

}