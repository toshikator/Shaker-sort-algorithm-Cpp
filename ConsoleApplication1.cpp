#include <iostream>
#include <conio.h>
#include <cmath>
#include<ctime>
//#include<locale.h>

using namespace std;

struct MyList
{
	int data; //информационное поле
	MyList* next; //указатель на следующий элемент
	MyList* prev; //указатель на предыдущий элемент
};
MyList* head;
int* my_shaker(MyList* head);
void print_list();
int find_node(const int searched);
void del_node(const int el_for_remove);
void add_list(const int size, const int fill_in_type);
void add_node();
void output_array(int* my_array, const int size);
int* sort_Sheiker(int* my_array, const int size);
int do_input();
void counting(int* my_array, const int size);
int main()
{
	bool stopper = false;
	while (!stopper)
	{

		int size = 0;
		int i = 0;
		setlocale(LC_ALL, "Russsian");
		system("chcp 1251");

		cout << "\nвыберите желаемое действие:\n1.поиск элемента\n2.создать список\n3.добавить элемент\n4.удалить элемент\n5.сортировка списка\n6.вывод списка\n0.для завершения\n";
		int x = 0;
		while (x < 48 || x>54)
		{
			x = _getch();
			if (x < 48 || x>54)
			{
				cout << "\nвведено некорректное значение, введите корректное\n";
			}
		}
		switch (x)
		{
		case 49://поиск элемента
		{
			cout << "\nвведите значение для поиска\n";
			int x = do_input();
			int unique=find_node(x);
			if (unique != 0)
			{
				cout << "\nда, такое значение есть в списке, встречается оно "<<unique<<" раз\n";
			}
			else
			{
				cout << endl << "\nискомое значение в списке не встречается\n";
			}
			break;
		}
		case 50://создать список
		{
			int size = 0;
			do
			{
				cout << "\nвведите желаемый размер списка:\n";
				size=do_input();
				if (size < 1)
				{
					cout << "\nвведено некорректное значение, попробуйте еще раз\n";
				}
			} while (size<1);
			int fill_in_type=0;
			do
			{
				cout << "\nвыберите вариант заполнения списка\n1.заполнение в автоматическом режиме\n2.заполнение с ручным указанием элементов\n";
				fill_in_type = _getch();
				if (fill_in_type < 49 || fill_in_type>50)
				{
					cout << "\nвведено некорректное значение, введите корректное\n";
				}
			} while (fill_in_type < 49 || fill_in_type>50);
			
			

			add_list(size,fill_in_type);
			
			break;

		}
		case 51://добавить элемент
		{
			cout << "\nвведите желаемое значение\n";
			//int temp = do_input();
			add_node();
			break;
		}
		case 52://удалить элемент
		{
			cout << "\nвведите удаляемое значение\n";
			int x = do_input();
			del_node(x);
			break;
		}
		case 53://сортировка списка
		{
			int* temp = new int[2];
			temp[0] = 0;
			temp[1] = 0;
			temp = my_shaker(head);
			cout << "\nколичество сравнений = " << temp[0] << endl;
			cout << "\nколичество перестановок = " << temp[1] << endl;
			break;
		}
		case 54://вывод списка
		{
			print_list();
			break;
		}

		case 48:
		{

			stopper = true;

			break;
		}
		default:
			break;
		}



		
		
	}

	return 0;
}
void add_list(const int size,const int fill_in_type)
{
	if (fill_in_type == 50)
	{
		cout << "вводите элементы по одному\n";
	}
	srand(time(0));
	for (int position = 1; position <= size; position++)
	{
		if (fill_in_type == 50)
		{
			
			add_node();
			
		}
		else if (fill_in_type == 49)
		{
			int value = 1 + rand() % size;
			MyList* Node = new MyList; //создание нового элемента
			Node->data = value; //присвоение элементу значения
			if (head == NULL) //если список пуст
			{
				Node->next = Node; //установка указателя next
				Node->prev = Node; //установка указателя prev
				head = Node; //определяется голова списка
			}
			else
			{
				MyList* p = head;
				p = p->prev;
				p->next->prev = Node;
				Node->next = p->next;
				Node->prev = p;
				p->next = Node;


			}
		}
		else
		{
			cerr << "\nнекорректные входные данные для функции\n";
		}
		
	}
}

void add_node()
{
	int value = do_input();
	MyList* Node = new MyList; //создание нового элемента
	Node->data = value; //присвоение элементу значения
	if (head == NULL) //если список пуст
	{
		Node->next = Node; //установка указателя next
		Node->prev = Node; //установка указателя prev
		head = Node; //определяется голова списка
	}
	else
	{
		MyList* p = head;
		p = p->prev;
		p->next->prev = Node;
		Node->next = p->next;
		Node->prev = p;
		p->next = Node;


	}

}

void print_list()
{
	int unique = 0;
	if (head == NULL)
	{
		cout << "\nСписок пуст\n\n";
	}
	else
	{
		MyList* temp = head;
		cout << "\nЭлементы списка: ";
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
			
			if (find_node(temp->data) == 1)
			{
				unique++;
			}

		} while (temp != head);
		cout << "\nколичество уникальных элементов в списке = "<<unique<<"\n";
	}
}
int find_node(const int searched)
{
	if (head == NULL)
	{
		cout << "\nСписок пуст\n\n";
		return 0;
	}
	else
	{
		int x = 0;
		MyList* temp = head;		
		do
		{
			if (temp->data == searched)
			{
				x++;
			}
			temp = temp->next;
		} while (temp != head);
		//cout << "\nчисло найдено " << x << " раз\n";
		return x;
	}
}
void del_node(const int el_for_remove)
{

	if (head == NULL)
	{
		cout << "\nСписок пуст\n\n";
	}
	else
	{
		if (head->data == el_for_remove)
		{
			head = head->next;
		}
		int x = 0;
		MyList* temp = head;
		do
		{
			if (temp->data == el_for_remove)
			{
				x++;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			temp = temp->next;
		} while (temp != head);
		if (x != 0)
		{
			cout << "\nда, такое значение есть в списке, удалено оно " << x << " раз\n";
		}
		else
		{
			cout << endl << "искомое значение в списке не встречается";
		}
	}

}

int do_input()
{
	int temp = 0;
	cin >> temp;
	while (!cin.good()) //Контроль корректности вводимых значений
	{
		cin.clear();
		cin.ignore();
		cerr << endl << "Введено некорректное значение, введите корректное" << endl;
		cout << endl << "введите значение ";
		cin >> temp;
	}
	return temp;
}
int* my_shaker(MyList* head)
{
	int* iter = new int[2];
	iter[0] = 0;
	iter[1] = 0;
	bool stop = false;
	if (head == NULL)
	{
		cout << "\nСписок пуст\n\n";
	}
	else if (head == head->next)
	{
		cout << "\nв списке всего 1 элемент\n";
	}
	else
	{
		int amount_elements = 0;		
		MyList* temp = head;
		MyList* leftstop = head;
		MyList* rightstop = head->prev;
		
		do
		{
			temp = temp->next;
			amount_elements++;
		} while (temp != head);
		
		temp = head;
		int iteration = 0;
		do//цикл общей сортировки
		{			
			iteration++;			
			do//цикл вправо, увеличение
			{
				if (temp->next->data > temp->data)
				{
					int buff = temp->next->data;
					temp->next->data = temp->data;
					temp->data = buff;	
					iter[1]++;
				}
				temp = temp->next;
				iter[0]++;
			} while (temp != rightstop);
			rightstop = temp->prev;
			temp = rightstop;
			while (temp != leftstop)//цикл влево,уменьшение
			{
				if (temp->prev->data < temp->data)
				{
					int buff = temp->prev->data;
					temp->prev->data = temp->data;
					temp->data = buff;
					iter[1]++;
				}
				temp = temp->prev;
				iter[0]++;
			}			
			leftstop = temp->next;
			temp = leftstop;
		} while (iteration< amount_elements/2);
	}
	return iter;
}
