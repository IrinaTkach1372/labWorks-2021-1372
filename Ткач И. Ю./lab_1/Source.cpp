

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int isExistLetter(string str) //������� �������� ���� �� � ����� �����(������� �� ��� �� ���� ��� ���)
{
	for (auto item : str)
	{
		if (item >= 65 && item <= 90 || item >= 97 && item <= 122) return 1;
	}
	return 0;
}
   
struct Word     //��������� ���� Word , ������ ������ � �����
{
	string word;      //���� �����
	int weight = -1;    //��� ���(����� ���� ����� ����)
	bool isWord = false;       //������ ��� �������� ��������� ����� ��� ����������
};

void Sorting(vector<Word>& sortedWeight)  //������� ����������� ������ �� �����(���������� ������� ��������, �� ����������������)
{
	Word temp;
	for (int i = 0; i < sortedWeight.size() - 1; i++)
	{
		if (!sortedWeight[i].isWord) continue;    //���������� �����, ������� �� ������� �� ����(��� ������ �������� �� ����� �����)
		for (int j = i + 1; j < sortedWeight.size(); j++)
		{
			if (!sortedWeight[j].isWord) continue;         //���������� �����, ������� �� ������� �� ����(��� ������ �������� �� ����� �����)
			if (sortedWeight[i].weight > sortedWeight[j].weight)
			{
				temp = sortedWeight[i];
				sortedWeight[i] = sortedWeight[j];
				sortedWeight[j] = temp;
			}
		}

	}
}

int main()
{
	string str;
	getline(cin, str);
	string temp;     //��������� ���������� ��� �������� �����
	//cout << int(' ');
	vector<Word> sortedWords;      //������(������) ������ ���� Word
	for (auto item : str)
	{
		if (item == '.' || item == ',' || item == '!' || item == '?' || item == ' ')
		{
			if (!isExistLetter(temp)) temp += item;      //���� ����� �� �� ���� �� �������� ��� ������

			else               //����� ��� �� ���� � �����������(� ����� �������� ������ � �.�) ������ ��������� ��� � ������
			{
				int w0 = 0;
				for (auto ch : temp)//������� ��� ���
				{
					w0 += (int)ch;
				}
				sortedWords.push_back(Word{ temp, w0, true });
				temp = item;
			}
		}


		else if (item >= 65 && item <= 90 || item >= 97 && item <= 122)    //����� ���� ��� ����� ��
		{
			//���� ����� �� �� ���� �� ��� ����� ����� �� �������� � �� ��������� ��� � ��� ������(��� = -1, ������� ���� ��� �� ��� �� �����)
			//������ �������������, ������ ��� ��� �� ��������� ����� � ����������)
			if (!isExistLetter(temp) && temp.size() > 0) { sortedWords.push_back(Word{ temp, -1, false }); temp = item; }

			else temp += item;//����� �������� ��������� �����(���������� ��������)
		}
	}
	//����. ����� ���� ��������� ���� ������� ��� ���� , ������ ��� ����� �� ������� �� ����� ������, �� �� ��������� ����� ������� � ��� ����� �������� �� ��������� ����������
	if (temp.size() != 0 && !isExistLetter(temp)) sortedWords.push_back(Word{ temp, -1, false });
	if (temp.size() != 0 && isExistLetter(temp))
	{
		int w0 = 0;
		for (auto ch : temp)
		{
			w0 += (int)ch;
		}
		sortedWords.push_back(Word{ temp, w0, true });
	}

	Sorting(sortedWords);
	//�������� ��� ������(������) � ������� ���������� �� ������ ����������
	for (auto item : sortedWords)
		
	{
		cout << item.word;
	}
	return 0;
}