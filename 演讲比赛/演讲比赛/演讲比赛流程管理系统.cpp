#include "speechManager.h"
#include <iostream>
using namespace std;

int main() {
	
	SpeechManager man;
	int choice = 0;
	
	while (true)
	{
		man.show_Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			//��ʼ����
			man.begin_speech();
			break;
		case 2:
			//�鿴������¼
			man.scan_message();
			break;
		case 3:
			//��ձ�����¼
			man.clear_message();
			break;
		case 0:
			//�˳�����
			man.exitSystem();
			break;
		default:
			cout << "===ѡ������������ѡ��===" << endl;
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}