#include <iostream>
#include "tree.h"
#include <locale.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int num = 100;
    int *a = new int[num];
    setlocale(LC_ALL, "Rus");
    tree *root = NULL;
    int k = 1;
    int c,c1,c2,t;
    /*for(int i = 0;i < 10;i++){
        t = rand() % 10+1;
        add(root,t);
    }
    */
    while(k)
    {
        cout<<"������� 1, ����� �������� �������."<<endl
            <<"������� 2, ����� ������� �������."<<endl
            <<"������� 3, ����� ������� ������."<<endl
            <<"������� 4, ����� ��������� �������������� �������.�������� ��������� ���������� ���� �� ����� � ���� ����� ������� ����� ����� ������� ����� 0. "<<endl
            <<"������� 0, ����� ��������� ������"<<endl;
        cin >> c;
        switch(c)
        {
        case 0:
            k = 0;
            break;
        case 1:
            cout <<"������� �������, ������� ����� ��������." << endl;
            cin>>c1;
            add(root,c1);
            break;
        case 2:
            cout <<"������� �������, ������� ����� �������." << endl;
            cin>>c2;
            pop(root,c2);
            break;

        case 3:
            show(root,0);
            break;
        case 4:
            indz(root,0,a,0);
            break;
        }
    }
    return 0;
}
