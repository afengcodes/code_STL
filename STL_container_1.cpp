//tag:头部
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <iterator>
using namespace std;

//二元谓词函数
bool demoForListClear(double first,double second)
{
	return (int(first)==int(second));         // 后续用
} 

int main()
{
	cout<<"****************** STL container ******************"<<endl;
    //tag:array
    cout<<"************ array ************"<<endl;
    //note:创建
	std::array<int,4> values{};        //<T,n> ,T 为类型，n为大小
	//note:遍历
	//method1：
	for(int i=0;i<values.size();i++)   //size()获取容器大小
	{
		values.at(i)=i;                //at(i),获取第i个引用（i从0起）
	}
	cout<<get<3>(values)<<endl;       //使用 get() 重载函数输出指定位置元素
	if(!values.empty())				  //判断是否为空
	{
		//begin(),end()分别返回第一个元素和最后一个元素的下一个位置的迭代器（和指针类似）
		for(auto val=values.begin();val<values.end();val++)
		{
			cout<<*val<<" ";
		}
	}
	
	cout<<endl;
	array<int,5> values1;
	int h=1;
	auto first1=values1.begin();
	auto last1=values1.end();
	//method2:
	while(first1!=last1)
	{
		*first1=h;
		++first1;
		h++;
	 }
	 
	 first1=values1.begin();
	 while(first1!=last1)
	 {
	 	cout<<*first1<<" ";
	 	++first1;
	 }
	cout<<endl;

	//反向迭代器
	array<int,5> values2;
	h=1;
	//可以定义类型为auto，编译时会根据右值返回值自动设置位对应迭代器类型。
	auto first2=values2.rbegin();   //rbegin(),返回最后一个元素对应迭代器
	auto last2=values2.rend();      //rend(),返回第一个元素之前一个位置的迭代器
	while(first2!=last2)
	{
		*first2=h;                 
		++first2;				//由于rbegin(),rend()返回的是反向迭代器，故++表示向前移动
		h++;
	 }
	 
	 first2=values2.rbegin();
	 while(first2!=last2)
	 {
	 	cout<<*first2<<" ";
	 	++first2;
	 }
	cout<<endl;

	array<string,5> words{"one","two","three","four","five"};
	cout<<get<3>(words)<<endl;

	array<int,5> words2{1,2,3,4,5};
	cout<<*(words2.data()+1);  //data()，返回指向容器首个元素的指针

	cout<<endl;
    //tag:vector
 
    cout<<"************ vector ************"<<endl;
	cout<<endl;
	//note:创建
	vector<int> v{1,2,3,4,5,6,7,8,9,10};
	cout <<"The method 1:"<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	 } 
	 cout<<endl;
	 cout<<"The method 2:"<<endl;
	 vector<int>::iterator i0;
	 for(i0=v.begin();i0!=v.end();i0++)
	 {         
	 	cout<<*i0<<" ";
	 }
	 cout<<endl;

    std::vector<double> values01;
	//重置容器容量
    values01.reserve(20);

    std::vector<int> primes{2,3,5,7,11,13,17,19};

    vector<double> values00(20,1.0);

    int num=2;
    double valueZhi=1.0;
    std::vector<double> valuesNum(num,valueZhi);     //(n,value),两者均可为变量


    std::vector<char> valueEg1(5,'c');
    vector<char> valueEg2(valueEg1);    //复制方式赋值
	int arrayInt[]={1,2,3,4,5};
    vector<int> valueEg3(arrayInt,arrayInt+2);  //从传统数组中以部分复制的方式赋值
    vector<int> valueEg4{1,2,3,4,5};
    vector<int> valueEg41(begin(valueEg4),begin(valueEg4)+2);  //从容器中以部分复制的方式赋值

	vector<char> valueEg5;
	valueEg5.push_back('s');         //向容器中尾部添加元素
	valueEg5.push_back('T');
	valueEg5.push_back('L');
	printf("The number of element:%d\n",valueEg5.size());
	for(auto i=valueEg5.begin();i<valueEg5.end() ;i++){
		cout<<*i<<" ";
	} 
	cout <<endl;
	
	valueEg5.insert(valueEg5.begin(),'C');
	cout<<"The first element is:"<<valueEg5.at(0)<<endl;
	cout <<endl;
	vector<int> valuesNew1{1,2,3};
	cout<<"valuesNew1'first element's address:"<<valuesNew1.data()<<endl;
	auto firstNew1=valuesNew1.begin();
	auto endNew1=valuesNew1.end();
	valuesNew1.reserve(20);
	cout <<endl;
	cout<<"valuesNew1'first element's address:"<<valuesNew1.data()<<endl;
	firstNew1=valuesNew1.begin();
	endNew1=valuesNew1.end();
	while(firstNew1!=endNew1)
	{
		cout<<*firstNew1;
		firstNew1++;
	}

    if(valuesNew1.empty())
    {
        std::cout<<"The container has no elements.\n";
    }
    else
        std::cout<<"The container has "<<valuesNew1.size()<<" elements.\n";
        

    double total=0;
    for(auto&& value:valuesNew1)
        total+=value;
    //访问元素总结
    // data() 首个元素指针
    // front(),back(),首末元素值
    // [i],at(i),直接访问  at()更安全
	//size()实际大小  VS  capacity()容量

	cout <<endl;
	for(auto&& value:valuesNew1)     //基于范围的循环，更多使用请自行搜索相关用法
		cout<<value<<" ";

	cout <<endl;
	// //2.13
	// push_back()  创建并剪切  VS emplace_back()  直接创建
	std::vector<int> demo{1,2};
	demo.insert(demo.begin()+1,3);   //{1,3,2}
	
	demo.insert(demo.end(),2,5);    //{1,3,2,5,5}  尾部添加2个5
	std::array<int,3> test{7,8,9};
	demo.insert(demo.end(),test.begin(),test.end());    //{1,3,2,5,5,7,8,9}
	
	demo.insert(demo.end(),{10,11});   //{1,3,2,5,5,7,8,9,10,11}
	
	for(int i=0;i<demo.size();i++)
	{
		cout<<demo[i]<<" ";
	}
	cout <<endl;


    //tag:deque
    cout<<"************ deque ************"<<endl;
    //note:创建
	deque<int> d;
	d.push_back(2);     //尾部添加
	d.pop_back();       //删除尾部元素
	
	d.push_front(2);    //首位添加
	d.pop_front();		//删除首位添加
	
	d.emplace_back(2);    //直接在尾部添加   {2}
	d.emplace_front(3);   //直接在首位添加   {3,2}
	d.emplace(d.begin()+1,4);   //直接在首位下一位添加  {3，4,2}
	
	for(auto i:d)
	{
		cout<<i<<" ";
	}
	
	d.erase(d.begin());        //删除首个元素 {4，2}
	d.erase(d.begin(),d.end());  //删除首个至最后一个元素  NULL
	cout<<endl;
		for(auto ii:d)
	{
		cout<<ii<<" ";
	}
	cout<<endl;

    //tag:list
    cout<<"************ list ************"<<endl;
    //note:创建

	std::list<double> valuesList;
	valuesList.push_back(3.1);
	valuesList.push_back(2.2);
	valuesList.push_back(2.9);
	cout<<"valuesList size:"<<valuesList.size()<<endl;
	valuesList.sort();
	for(auto it=valuesList.begin();it!=valuesList.end();++it)
	{
		std::cout<<*it<<" ";
	 }

	std::list<int> mylist{1,2,3,4};
	//note：访问
	//list 容器不支持随机访问，未提供下标操作符 [] 和 at() 成员函数，也没有提供 data() 成员函数。
	int &firstML=mylist.front();      //首个元素引用
	int &lastML=mylist.back();        //最后一个元素引用
	cout<<firstML<<" "<<lastML<<endl;
	firstML=10;
	lastML=20;
	cout<<mylist.front()<<" "<<mylist.back()<<endl;
	//note:插入
	//和 insert() 成员方法相比，splice() 成员方法的作用对象是其它 list 容器
	//其功能是将其它 list 容器中的元素添加到当前 list 容器中指定位置处。
	list<int> mylist1{1,2,3,4},mylist2{10,20,30};
	list<int>::iterator itML2= ++mylist1.begin();
	mylist1.splice(itML2,mylist2); //mylist1={1,10,20,30,2,3,4} mylist2={}
	
	mylist2.splice(mylist2.begin(),mylist1,itML2); //it 仍指向2！！！！！！！
	//故此时 mylist1={1,10,20,30,3,4}(2没了) ，mylist2={2}
	
	mylist2.splice(mylist2.begin(),mylist1,mylist1.begin(),mylist1.end());
	cout <<endl;
	cout<<"mylist1 contains " << mylist1.size()<<" elements"<<endl;
	cout<<"mylist2 contains " << mylist2.size()<<" elements"<<endl;
	cout<<"mylist2:";  //mylist2={1,10,20,30,3,4,2}
	for(auto iter=mylist2.begin();iter!=mylist2.end();++iter)
	{
		cout<<*iter<<" ";
	 } 
	cout <<endl;
	cout <<endl;

	//note:删除
	//method1:
	//remove(val)	删除容器中所有等于 val 的元素。
	//method2:
	//pop_front()	删除位于 list 容器头部的一个元素。
	//pop_back()	删除位于 list 容器尾部的一个元素。
	//method3:
	//clear() 删除所有
	//method4:
	//unique();
	list<double> mylistNewNew{1,1.2,1.2,3,4,4.5,4.6};
	mylistNewNew.unique();  //unique() 删除容器中相邻的重复元素，只保留一份。
	
	for(auto it=mylistNewNew.begin();it!=mylistNewNew.end();++it)
	{
		cout<<*it<<' ';
	}
	cout<<endl;
	
	mylistNewNew.unique(demoForListClear);
	for(auto it=mylistNewNew.begin();it!=mylistNewNew.end();++it)
	{
		std::cout<<*it<<' ';
	}
	cout<<endl;
	std::list<int> mylistNewNew2{ 15, 36, 7, 17, 20, 39, 4, 1 };
    //删除 mylist 容器中能够使 lamba 表达式成立的所有元素。
	//method5:
	//remove_if() 删除容器中满足条件的元素
    mylistNewNew2.remove_if([](int value){return (value<10);}); 
        for (auto it = mylistNewNew2.begin(); it != mylistNewNew2.end(); ++it)
        std::cout << ' ' << *it;
	cout<<endl;

    //tag:forward_list
    cout<<"************ forward_list ************"<<endl;
    //note:创建
	std::forward_list<int> my_wordsFL{1,2,3,4};
	//forward_list 容器中是不提供 size() 函数的，但如果想要获取 forward_list 容器中存储元素的个数
	//可以使用头文件 <iterator> 中的 distance() 函数
    int countFL = std::distance(std::begin(my_wordsFL), std::end(my_wordsFL));
    cout << countFL;
	//forward_list 容器迭代器的移动除了使用 ++ 运算符单步移动，还能使用 advance() 函数
 	std::forward_list<int> valuesFL{1,2,3,4};
    auto itFL = valuesFL.begin();
    advance(itFL, 2);
    while (itFL!=valuesFL.end())
    {
        cout << *itFL << " ";
        ++itFL;
    }

    system("pause");             // 暂停用
	return 0;
 } 