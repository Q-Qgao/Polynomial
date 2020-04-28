#pragma once
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
bool flag = 0;
struct Term
{
	double coef;//系数
	int exp;//指数
	Term* link;
	Term(double c, int e, Term* next = NULL)
	{
		coef = c; exp = e; link = next;
	}
	Term*InsertAfter(double c, int e);
	friend ostream& operator <<(ostream&, const Term&);
};
class Polynomial//多项式类定义
{
public:
	Term * first;
	friend ostream&operator<<(ostream&, const Polynomial&);
	friend istream&operator>>(istream&, Polynomial&);
	friend  Polynomial operator+(Polynomial&, Polynomial&);
	friend  Polynomial operator-(Polynomial&, Polynomial&);
	Polynomial() { first = new Term(0, -10000000); }//构造函数，建立空链表
	Polynomial(Polynomial&R);//复制构造函数
	int maxOrder();//计算最大阶数
	Term* find_place(int e);//找到需要插入的位置
	bool inser_order(double c, int e);//插入一个结点，保证建立递增有序单链表
	Term*getHead()const { return first; };//取得单链表的头指针
										  //~Polynomial();
};
Polynomial x, y;
Term* Term::InsertAfter(double c, int e)
{

	link = new Term(c, e, link);
	return link;
}
ostream& operator<<(ostream& out, const Term&x)
{
	if (x.coef == 0.0)return out;
	out << x.coef;
	switch (x.exp)
	{
	case 0:break;
	case 1:out << "X"; break;
	default:out << "X" << x.exp;
		break;
	}
	return out;
}
Polynomial::Polynomial(Polynomial&R)
{
	//复制构造函数
	first = new Term(0, -1);
	Term *destptrr = first, *srcptr = R.getHead()->link;
	while (srcptr != NULL)
	{
		destptrr->InsertAfter(srcptr->coef, srcptr->exp);
		srcptr = srcptr->link;
		destptrr = destptrr->link;
	}
}
int Polynomial::maxOrder()
{
	//升序排序计算最大阶数，即为最后一项
	Term*current = first;
	while (current->link != NULL)
	{
		current = current->link;
	}
	return current->exp;
}
//寻找需要插入的位置，由inser_order(double c, int e)调用
Term* Polynomial::find_place(int e)
{
	Term* current = first;
	while (current->link!=NULL&&current->link->exp<e)
	{
		current = current->link;
	}
	return current;
}
//插入，保持递增单链表
bool Polynomial::inser_order(double c, int e)
{
	Term*current = find_place(e);
	Term*temp=NULL;
//if (current == NULL) { AfxMessageBox(_T("插入出错！")); return false; }
	Term* newnode= new Term(c, e, temp);
	if (newnode == NULL) { AfxMessageBox(_T("插入出错！")); return false; }
	newnode->link = current->link;
	current->link = newnode;
	return true;
}
istream& operator>>(istream&in, Polynomial& x)
{
	//输入，尾插法建立多项式
	Term* rear = x.getHead(); double c; int e;
	while (true)
	{
		cout << "input a term(c,exp)" << endl;
		in >> c >> e;
		if (e < 0)break;
		rear = rear->InsertAfter(c, e);
	}
	return in;
}
ostream& operator<<(ostream &out, Polynomial&x) {
	Term*current = x.getHead()->link;//头指针为空，不输出
	cout << "多项式:" << endl;
	bool h = true;
	while (current != NULL)
	{
		if (h == false && current->coef > 0)out << "+";
		h = false;
		out << *current;
		current = current->link;
	}
	out << endl;
	return out;
}
Polynomial operator+(Polynomial&A, Polynomial&B)
{
	Term*pa, *pb, *pc, *p; double temp;
	Polynomial C; pc = C.first;
	pa = A.getHead()->link; pb = B.getHead()->link;
	while (pa != NULL && pb != NULL)
	{
		if (pa->exp == pb->exp)
		{
			temp = pa->coef + pb->coef;
			if (fabs(temp) > 0.0001)
				pc = pc->InsertAfter(temp, pa->exp);
			pa = pa->link; pb = pb->link;
		}
		else if (pa->exp < pb->exp) {
			pc = pc->InsertAfter(pa->coef, pa->exp);
			pa = pa->link;
		}
		else {
			pc = pc->InsertAfter(pb->coef, pb->exp);
			pb = pb->link;
		}
	}
	if (pa != NULL)p = pa;
	else p = pb;
	while (p != NULL)
	{
		pc = pc->InsertAfter(p->coef, p->exp);
		p = p->link;
	}
	return C;
}
Polynomial operator-(Polynomial&A, Polynomial&B)
{
	Term*pa, *pb, *pc, *p; double temp;
	Polynomial C; pc = C.first;
	pa = A.getHead()->link; pb = B.getHead()->link;
	while (pa != NULL && pb != NULL)
	{
		if (pa->exp == pb->exp)
		{
			temp = pa->coef-pb->coef;
			if (fabs(temp) > 0.0001)
				pc = pc->InsertAfter(temp, pa->exp);
			pa = pa->link; pb = pb->link;
		}
		else if (pa->exp < pb->exp) {
			pc = pc->InsertAfter(pa->coef, pa->exp);
			pa = pa->link;
		}
		else {
			pc = pc->InsertAfter(pb->coef*(-1), pb->exp);
			pb = pb->link;
		}
	}
	bool flag = true;
	if (pa != NULL)p = pa;
	else {
		p = pb; flag = false;
	}
	while (p != NULL)
	{
		if(flag)
		pc = pc->InsertAfter(p->coef, p->exp);
		else 	pc = pc->InsertAfter(p->coef*(-1), p->exp);
		p = p->link;
	}
	return C;
}
