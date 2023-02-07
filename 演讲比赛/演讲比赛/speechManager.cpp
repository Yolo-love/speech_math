#include "speechManager.h"
#include "speaker.h"
#include <algorithm>
#include <time.h>
#include <fstream>

//���캯��
SpeechManager::SpeechManager() {

}

//��������
SpeechManager::~SpeechManager() {

}

//��ʾ�˵�
void SpeechManager::show_Menu() {
	cout << "========================================================" << endl;
	cout << "=================== ��ӭ�μ��ݽ����� ===================" << endl;
	cout << "===================  1.��ʼ�ݽ����� ====================" << endl;
	cout << "===================  2.�鿴������¼ ====================" << endl;
	cout << "===================  3.��ձ�����¼ ====================" << endl;
	cout << "===================  0.�˳��������� ====================" << endl;
	cout << "========================================================" << endl;
	cout << endl;
}

bool compare_score(const Speaker& s1, const Speaker& s2 ) {
	return s1.s_score > s2.s_score;
}

//��ʼ�ݽ�����
void SpeechManager::begin_speech() {
	vector<Speaker> v;
	string str = "ABCDEFGHIJKL";
	string s = "ѡ��";
	int num = 1000000;
	Speaker sp;
	srand(time(NULL));

	for (size_t i = 1; i <= 12; i++)
	{
		sp.s_num = num + i;
		sp.s_name = s + str[i - 1];
		sp.s_score = (rand() % 1000 + 8000) / 100.0;
		v.push_back(sp);
	}

	random_shuffle(v.begin(),v.end());

	vector<Speaker> v1;
	vector<Speaker> v2;

	vector<Speaker> v_last;

	for (size_t i = 0; i < v.size() / 2; i++)
	{
		v1.push_back(v[i]);
		v2.push_back(v[i + 6]);
	}

	for (size_t i = 0; i < 3; i++)
	{
		v1[i].s_score = (rand() % 1000 + 8000) / 100.0;
		v2[i].s_score = (rand() % 1000 + 8000) / 100.0;
		v_last.push_back(v1[i]);
		v_last.push_back(v2[i]);
	}
	sort(v_last.begin(), v_last.end(), compare_score);
	v_last.pop_back();
	v_last.pop_back();
	v_last.pop_back();

	static int count = 1;
	if (count == 1)
	{
		cout << "��<< " << count << " >>���ݽ��������" << endl;
		cout << "---��һ��ɼ�---" << endl;
		sort(v1.begin(), v1.end(), compare_score);
		for (vector<Speaker>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << " ��ţ�" << it->s_num << " ������" << it->s_name << " ������" << it->s_score << endl;
		}
		cout << "---�ڶ���ɼ�---" << endl;
		sort(v2.begin(), v2.end(), compare_score);
		for (vector<Speaker>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << " ��ţ�" << it->s_num << " ������" << it->s_name << " ������" << it->s_score << endl;
		}
		count++;
	}
	else if (count == 2) {
		
		cout << "��<< " << count << " >>���ݽ��������" << endl;
		cout << "---������ѡ����Ϣ---" << endl;
		sort(v_last.begin(), v_last.end(), compare_score);
		for (vector<Speaker>::iterator it = v_last.begin(); it != v_last.end(); it++)
		{
			cout << " ��ţ�" << it->s_num << " ������" << it->s_name << " ������" << it->s_score << endl;
		}
		
		ifstream ifs("speech_winer.txt", ios::in);
		int line_num = 0;
		string s;
		while (getline(ifs, s))
		{
			line_num++;
		}
		ifs.close();

		ofstream ofs("speech_winer.txt", ios::out | ios::app);
		int n = 0;
		n += line_num / 4 + 1;
		ofs << "��" << n << "���ݽ�����" << endl;
		for (vector<Speaker>::iterator it = v_last.begin(); it != v_last.end(); it++)
		{
			ofs << " ��ţ�" << it->s_num << " ������" << it->s_name << " ������" << it->s_score << endl;
		}
		
		ofs.close();
	}
	
	system("pause");
	system("cls");
}

void SpeechManager::scan_message() {
	ifstream ifs("speech_winer.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	char ch;	
	ifs >> ch;	//��ȡһ���ַ�
	if (ifs.eof())  //�����ȡ����
	{
		cout << "�ļ�Ϊ��" << endl;
		return;
	}
	ifs.putback(ch);	//�Żض�ȡ���ַ�

	string buf3;
	while (getline(ifs, buf3)) {
		cout << buf3 << endl;
	}

	ifs.close();
}

//��ձ�����¼
void SpeechManager::clear_message() {
	cout << "�Ƿ�ȷ������ļ�" << endl;
	cout << " 1.ȷ��" << endl;
	cout << " 0.����" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs("speech_winer.txt", ios::trunc);
		ofs.close();
	}
	else if (choice == 0) {
		system("cls");
	}
}

//�˳���������
void SpeechManager::exitSystem() {
	cout << "�����Ƿ�ȷ���˳�����" << endl;
	cout << "  1.ȷ��" << endl;
	cout << "  0.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "��ӭ�´�ʹ��" << endl;
		exit(0);
	}
	else if (select == 0) {
		system("cls");
	}
}
