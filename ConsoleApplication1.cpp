#include <iostream>
#include <conio.h>
#include <cmath>
#include<ctime>
//#include<locale.h>

using namespace std;

struct MyList
{
	int data; //�������������� ����
	MyList* next; //��������� �� ��������� �������
	MyList* prev; //��������� �� ���������� �������
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

		cout << "\n�������� �������� ��������:\n1.����� ��������\n2.������� ������\n3.�������� �������\n4.������� �������\n5.���������� ������\n6.����� ������\n0.��� ����������\n";
		int x = 0;
		while (x < 48 || x>54)
		{
			x = _getch();
			if (x < 48 || x>54)
			{
				cout << "\n������� ������������ ��������, ������� ����������\n";
			}
		}
		switch (x)
		{
		case 49://����� ��������
		{
			cout << "\n������� �������� ��� ������\n";
			int x = do_input();
			int unique=find_node(x);
			if (unique != 0)
			{
				cout << "\n��, ����� �������� ���� � ������, ����������� ��� "<<unique<<" ���\n";
			}
			else
			{
				cout << endl << "\n������� �������� � ������ �� �����������\n";
			}
			break;
		}
		case 50://������� ������
		{
			int size = 0;
			do
			{
				cout << "\n������� �������� ������ ������:\n";
				size=do_input();
				if (size < 1)
				{
					cout << "\n������� ������������ ��������, ���������� ��� ���\n";
				}
			} while (size<1);
			int fill_in_type=0;
			do
			{
				cout << "\n�������� ������� ���������� ������\n1.���������� � �������������� ������\n2.���������� � ������ ��������� ���������\n";
				fill_in_type = _getch();
				if (fill_in_type < 49 || fill_in_type>50)
				{
					cout << "\n������� ������������ ��������, ������� ����������\n";
				}
			} while (fill_in_type < 49 || fill_in_type>50);
			
			

			add_list(size,fill_in_type);
			
			break;

		}
		case 51://�������� �������
		{
			cout << "\n������� �������� ��������\n";
			//int temp = do_input();
			add_node();
			break;
		}
		case 52://������� �������
		{
			cout << "\n������� ��������� ��������\n";
			int x = do_input();
			del_node(x);
			break;
		}
		case 53://���������� ������
		{
			int* temp = new int[2];
			temp[0] = 0;
			temp[1] = 0;
			temp = my_shaker(head);
			cout << "\n���������� ��������� = " << temp[0] << endl;
			cout << "\n���������� ������������ = " << temp[1] << endl;
			break;
		}
		case 54://����� ������
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
		cout << "������� �������� �� ������\n";
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
			MyList* Node = new MyList; //�������� ������ ��������
			Node->data = value; //���������� �������� ��������
			if (head == NULL) //���� ������ ����
			{
				Node->next = Node; //��������� ��������� next
				Node->prev = Node; //��������� ��������� prev
				head = Node; //������������ ������ ������
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
			cerr << "\n������������ ������� ������ ��� �������\n";
		}
		
	}
}

void add_node()
{
	int value = do_input();
	MyList* Node = new MyList; //�������� ������ ��������
	Node->data = value; //���������� �������� ��������
	if (head == NULL) //���� ������ ����
	{
		Node->next = Node; //��������� ��������� next
		Node->prev = Node; //��������� ��������� prev
		head = Node; //������������ ������ ������
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
		cout << "\n������ ����\n\n";
	}
	else
	{
		MyList* temp = head;
		cout << "\n�������� ������: ";
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
			
			if (find_node(temp->data) == 1)
			{
				unique++;
			}

		} while (temp != head);
		cout << "\n���������� ���������� ��������� � ������ = "<<unique<<"\n";
	}
}
int find_node(const int searched)
{
	if (head == NULL)
	{
		cout << "\n������ ����\n\n";
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
		//cout << "\n����� ������� " << x << " ���\n";
		return x;
	}
}
void del_node(const int el_for_remove)
{

	if (head == NULL)
	{
		cout << "\n������ ����\n\n";
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
			cout << "\n��, ����� �������� ���� � ������, ������� ��� " << x << " ���\n";
		}
		else
		{
			cout << endl << "������� �������� � ������ �� �����������";
		}
	}

}

int do_input()
{
	int temp = 0;
	cin >> temp;
	while (!cin.good()) //�������� ������������ �������� ��������
	{
		cin.clear();
		cin.ignore();
		cerr << endl << "������� ������������ ��������, ������� ����������" << endl;
		cout << endl << "������� �������� ";
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
		cout << "\n������ ����\n\n";
	}
	else if (head == head->next)
	{
		cout << "\n� ������ ����� 1 �������\n";
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
		do//���� ����� ����������
		{			
			iteration++;			
			do//���� ������, ����������
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
			while (temp != leftstop)//���� �����,����������
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
