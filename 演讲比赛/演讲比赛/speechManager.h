#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SpeechManager{
public:
	//���캯��
	SpeechManager();
	//��������
	~SpeechManager();
	//��ʾ�˵�
	void show_Menu();
	//��ʼ�ݽ�����
	void begin_speech();
	//�鿴���������Ϣ
	void scan_message();
	//��ձ�����¼
	void clear_message();
	//�˳���������
	void exitSystem();

};