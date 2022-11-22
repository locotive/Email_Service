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
		E_control.copy_vec(ID);
		std::cin >> PassWord;
		account_Twin.insert(std::make_pair(ID, PassWord));
		std::cout <<"<"<<ID <<">" << " ���ԵǾ����ϴ�" << std::endl;
	}
	else
		std::cout << "�ߺ��� ID �Դϴ�" << std::endl;
	Sleep(1000);

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
			E_control.start(ID);
		}
		else
		{
			std::cout << "PassWord�� �߸� �Է��ϼ̽��ϴ�." << std::endl;
		}
	}
	else
		std::cout << "ID�� �߸� �Է��ϼ̽��ϴ�." << std::endl;
		Sleep(1000);

}
void AccountController::print_Id()
{
	system("cls");
	std::cout << "ID ���" << std::endl;
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
		std::cout << "���Ͻô� �޴��� �������ּ���" << std::endl;
		std::cout << "�α׾ƿ� 0" << std::endl;
		std::cout << "���� ���� 1" << std::endl;
		std::cout << "���� ������ 2" << std::endl;
		std::cout << "���� ������ 3" << std::endl;
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
			std::cout << email.To << " ���� ������ �߼��մϴ�." << std::endl;
			Sleep(1000);
			return;
		}
		else if (i == ID_list.size()-1)
		{
			std::cout << "�̸����� �������� �ʽ��ϴ�." << std::endl;
			std::cout << "�ٽ� �����÷��� y�� �Է��ϼ���" << std::endl;
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
	std::cout << "���� ������" << std::endl;
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
	std::cout << "���� ������" << std::endl;
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