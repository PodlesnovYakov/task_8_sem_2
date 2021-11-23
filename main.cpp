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
        cout<<"¬ведите 1, чтобы добавить элемент."<<endl
            <<"¬ведите 2, чтобы удалить элемент."<<endl
            <<"¬ведите 3, чтобы вывести дерево."<<endl
            <<"¬ведите 4, чтобы выполнить индивидуальное задание.Ќаписать программу нахождени€ пути из корн€ в лист через вершины сумма весов которых равна 0. "<<endl
            <<"¬ведите 0, чтобы завершить работу"<<endl;
        cin >> c;
        switch(c)
        {
        case 0:
            k = 0;
            break;
        case 1:
            cout <<"¬ведите элемент, который нужно добавить." << endl;
            cin>>c1;
            add(root,c1);
            break;
        case 2:
            cout <<"¬ведите элемент, который нужно удалить." << endl;
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
