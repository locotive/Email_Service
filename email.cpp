#include"header.h"

void MainController::start()
{
	AccountController account;
	while (1)
	{
		system("cls");
		std::cout << "���Ͻô� �޴��� �������ּ���" << std::endl;
		std::cout << "���� 0" << std::endl;
		std::cout << "ȸ�� ���� 1" << std::endl;
		std::cout << "�α��� 2" << std::endl;
		std::cout << "ID ��� 3" << std::endl;
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
			std::cout << "�߸� �Է��ϼ̽��ϴ�." << std::endl;
			std::cout << "�ٽ� �Է����ּ���." << std::endl;
		}
	}

}

void AccountController::make_account()
{
	system("cls");
	std::cout << "ID�� �Է��ϼ���: ";
	std::cin >> ID;
	if (find(ID_list.begin(), ID_list.end(), ID) == ID_list.end())
	{
		ID_list.push_back(ID);
		std::cout << "PassWord�� �Է��ϼ���: ";
		std::cin >> PassWord;
		account_Twin.insert(std::make_pair(ID, PassWord));
		std::cout <<"<"<<ID <<">" << " ���ԵǾ����ϴ�" << std::endl;
		Sleep(1000);
	}
	else
		std::cout << "�ߺ��� ID �Դϴ�" << std::endl;

}
void AccountController::login()
{
	system("cls");
	std::cout << "ID�� �Է��ϼ���: ";
	std::cin >> ID;
	std::cout << "PassWord�� �Է��ϼ���: ";
	std::cin >> PassWord;
	if (account_Twin.count(ID) == 1)
	{
		if (account_Twin[ID] == PassWord)
		{
			std::cout << "�α��� �Ǿ����ϴ�" << std::endl;
			Sleep(1000);
			E_control.start();
		}
		else
		{
			std::cout << "PassWord�� �߸� �Է��ϼ̽��ϴ�." << std::endl;
		}
	}
	else
		std::cout << "ID�� �߸� �Է��ϼ̽��ϴ�." << std::endl;

}
void AccountController::print_Id()
{
	system("cls");
	std::cout << "ID ���" << std::endl;
	for (int i = 0; i < ID_list.size(); i++)
		std::cout <<i+1<<") "<< ID_list[i] << std::endl;
	system("PAUSE");
}
void EmailController::start()
{
	while (1)
	{
		system("cls");
		std::cout << "���Ͻô� �޴��� �������ּ���" << std::endl;
		std::cout << "�α׾ƿ� 0" << std::endl;
		std::cout << "���� ���� 1" << std::endl;
		std::cout << "���� ������ 2" << std::endl;
		std::cout << "�߼� ������ 3" << std::endl;
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