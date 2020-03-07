#include<iostream>
using namespace std;
template<typename T>class List;
template<typename T>class Node{
	T info;                                     //数据域
	Node<T> *link;                             //指针域
public:
	Node();                                   //生成头结点的构造函数
	Node(const T & data);//生成一般结点的构造函数
	friend class List<T>;
};
template <typename T> Node<T>::Node(){link=NULL;}
template <typename T> Node<T>::Node(const T & data){
	info=data;
	link=NULL;
}
//定义链表类
template<typename T>class List{
	Node<T> *head;      //链表头指针和尾指针
public:
	List();                  //构造函数，生成头结点(空链表)
	~List();                 //析构函数
	void MakeEmpty();        //清空一个链表，只余表头结点
	Node<T>* Find(T data);   //搜索数据域与data相同的结点，返回该结点的地址
	void PrintList();              //打印链表的数据域
	void InsertOrder(Node<T> *p);  //按升序生成链表
	Node<T>* CreatNode(T data);     //创建一个结点(孤立结点)
	Node<T>* DeleteNode(Node<T>* p); //删除指定结点
};
template<typename T>List<T>::List(){
	head=new Node<T>(-9999);//头结点，最小的数据从小到大插入
}
template<typename T>List<T>::~List(){
	MakeEmpty();
	delete head;
}
template<typename T>void List<T>::MakeEmpty(){
	Node<T> *tempP;
	while(head->link!=NULL){
		tempP=head->link;
		head->link=tempP->link;  //把头结点后的第一个节点从链中脱离
		delete tempP;            //删除(释放)脱离下来的结点
	}
}
template<typename T> Node<T>* List<T>::Find(T data){
	Node<T> *tempP=head->link;
	while(tempP!=NULL && tempP->info!=data) tempP=tempP->link;
	return tempP;        //搜索成功返回该结点地址，不成功返回NULL
}
template<typename T>void List<T>::PrintList(){
	Node<T>* tempP=head->link;
	while(tempP!=NULL){
		cout<<tempP->info<<'\t';
		tempP=tempP->link;
	}
	cout<<endl;
}
template<typename T>void List<T>::InsertOrder(Node<T> *p){
	Node<T> *tempP=head,*tempQ=head; //tempQ指向tempP前面的一个节点
	while(tempP!=NULL){
		if(p->info<tempP->info)break; //找第一个比插入结点大的结点，由tempP指向
		tempQ=tempP;
		tempP=tempP->link;
	}
	p->link=tempP;
	tempQ->link=p;
}
template<typename T>Node<T>* List<T>::CreatNode(T data){//建立新节点
	Node<T>*tempP=new Node<T>(data);
	return tempP;
}
template<typename T>Node<T>* List<T>::DeleteNode(Node<T>* p){
	Node<T>* tempP=head->link,*tempQ=head,*tempC;
	while(tempP!=NULL && tempP!=p){
		tempQ=tempP;
		tempP=tempP->link;
	}
	tempC=tempP;
	tempQ->link=tempP->link;
	return tempC;
}
int main(){
	Node<int> * P1;
	List<int> list1;
	int a[10]={20,12,0,-5,9,-18,6,11,5,3},i,j;
	for(i=0;i<10;i++){
		P1=list1.CreatNode(a[i]);
		list1.InsertOrder(P1);
	}
	list1.PrintList();
	cout<<"请输入一个要求删除的整数"<<endl;
	cin>>j;
	P1=list1.Find(j);
	if(P1!=NULL){
		P1=list1.DeleteNode(P1);
		delete P1;
		list1.PrintList();
	}
	else cout<<"未找到"<<endl;
	cout<<"请输入一个要求插入的整数"<<endl;
	cin>>j;
	P1=list1.CreatNode(j);
	list1.InsertOrder(P1);
	list1.PrintList();
	list1.MakeEmpty();//清空list1
	list1.PrintList();
	return 0;
}
