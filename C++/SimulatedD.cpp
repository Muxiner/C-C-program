#include <iostream>
#include <stdlib.h>
using namespace std;

//��ʾƽ���ϵĵ�Ľṹ��
struct Point
{
	int x;//������
	int y;//������
};

//��ʾ���˵�
void displayMenu()
{
	cout << "************************************" << "\n";
	cout << "1.Circle(Բ)\n2.Rectangle(������)\n3.Exit(�˳�)\n";
	cout << "************************************" << endl;
	cout << "Please select the shape:";
}

//�õ��û������������
void getTwoPoints(struct Point *startP, struct Point *endP)
{
	cout << "Please input the coordinate (X, Y) of the start point:";
	cin >> startP->x >> startP->y;
	cout << "Please input the coordinate (X, Y) of the end point:";
	cin >> endP->x >> endP->y;
}

//�ԣ�X��Y������ʽ��ӡ��
void printPoint(struct Point *p)
{
    //(X,Y)
    cout << "(" << p->x << ", " << p->y << ")";
}

//��Բ�ĺ���
void drawCircle(struct Point *startP, struct Point *endP)
{
	int Width, Length;
    Width = endP->x - startP->x;
    Length = endP->y - startP->y;
    if (Length != Width)
    {
        cout << "No a circle, Select again\n";
    } else
    {
        //ģ�⻭Բ
        cout << "Draw a circle at center ";
        //Բ������
        cout << "(" << (startP->x + endP->x)/2 << ", " << (startP->y + endP->y)/2 << ")";
        cout << " with radius ";
        //�뾶����
        cout << Width / 2 << endl;
    }
}

//�������εĺ���
void drawRectangle(struct Point *startP, struct Point *endP)
{
	int Width, Length;

    if ((endP->x - startP->x) <= 0 || (endP->y - startP->y) <= 0)
    {
        cout << "No a rectangle, Please select again\n";
    }
    else 
    {
    Width = endP->x - startP->x;
    Length = endP->y - startP->y;

    //ģ�⻭������
    cout << "Draw a rectangle at top left ";
    printPoint(startP);
    cout << " whose width is "<< Width << " and height is " << Length << endl;
    }
}

int main()
{
	int choice = 1;//�û�ѡ��

	struct Point startP, endP;//�����յ�

	while (choice != 0)
	{
		displayMenu(); //��ʾ���˵�
		cin >> choice; //�����û�����

		switch (choice)
		{
		case 1://Բ
			getTwoPoints(&startP, &endP);//�õ�������
			drawCircle(&startP, &endP);  //�����û�����
			break;
		case 2://������
			getTwoPoints(&startP, &endP);
			drawRectangle(&startP, &endP);
			break;
		case 0:
			cout << "Good Bye!\n";
			break;
		default:
			cout << "Not supported! Please select again!";
			break;
		}
	}
	system("pause");
	return 0;
}