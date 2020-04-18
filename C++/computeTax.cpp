#include <iostream>
#include <stdlib.h>
using namespace std;

struct taxRule
{
  int mThreshold; //��˰Ǯ
  int rTax;       //˰��
};

struct taxRule *taxRules;
int ruleNum = 0;

//�����û�����Ĺ����������Ӽ��̵õ����еĹ��򣬴�ŵ�����
void inputRules(int n)
{
  cout << "��������������:";
  cin >> ruleNum;

  taxRules = new struct taxRule[ruleNum];

  for (int i = 0; i < ruleNum; i++)
  {
    cout << "�������" << i + 1 << "������";
    cin >> taxRules[i].mThreshold >> taxRules[i].rTax;
  }
}

//��ʾ����
void displayRules()
{
  cout << "\n��˰�������£�\n";
  cout << "��˰Ǯ\t˰��\n";
  for (int i = 0; i < ruleNum; i++)
  {
    cout << taxRules[i].mThreshold << "\t" << taxRules[i].rTax << "\n";
  }
}

//����income��ʾ��������˰�������������˰
double computeTax(int income)
{
  double sum = 0;
  int i = 0;

  if (taxRules[0].mThreshold > income)
    return 0;

  for (i = 1; i < ruleNum && taxRules[i].mThreshold <= income; i++)
  {
    sum += (taxRules[i].mThreshold - taxRules[i - 1].mThreshold) * taxRules[i - 1].rTax;
  }

  sum += (income - taxRules[i - 1].mThreshold ) * taxRules[i - 1].rTax;
  return sum / 100;
}

int main()
{
  inputRules(ruleNum);

  displayRules();

  int income;

  while (income > -1)
  {
    cout << "\n�������������룺";
    cin >> income;
    if (income == -1)
    {
      cout << "�ټ���" << endl;
      break;
    }
    cout << "���������ǣ�" << income << ", "
         << "Ӧ������˰��" << computeTax(income) << "Ԫ��" << endl;
  }
  system("pause");
  return 0;
}
