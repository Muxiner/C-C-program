#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int num;
	cout << "����������������ָ���( N > 10 ʱ�����ٶȽ��� ):";
	cin >> num;
	int array[100] = { 0 };
	for (int i = 0; i < num; i++)
		array[i] = rand() % 99 + 1;

	int Max = 0;
	for (int i = 0; i < num; i++)
		if (array[i] > Max)
			Max = array[i];

	int Array[100] = { 0 };
	Array[0] = Max;
	for (int i = 0; i < num; i++)
	{
		while (--Max)
		{
			for (int k = 0; k < num; k++)
				if (Max - array[k] == 0)
				{
					Array[i + 1] = array[k];
					break;
				}

			if (Array[i + 1] != 0)
				break;
		}
	}

	cout << "��������ǰ��\n";
	for (int i = 0; i < num; i++)
		cout << array[i] << " ";
	cout << endl;


	cout << "���������\n";
	for (int i = 0; i < num; i++)
		cout << Array[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}