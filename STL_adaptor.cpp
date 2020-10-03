//tag:头部
#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <array>
#include <forward_list>
#include <iterator>
using namespace std;

int main()
{
    //done:容器适配器
    cout<<"****************** STL container adapter ******************"<<endl;
    cout<<endl;
    cout<<"****** stack adaptor ******"<<endl;
    //stack,queue 没有迭代器，访问元素只能遍历
    //tag:stack 栈适配器
    //基础容器筛选条件:
        //基础容器需包含以下成员函数：empty(),size(),back(),push_back(),pop_back()
        //满足条件的基础容器有 vector、deque、list。
        //默认为 deque
    //规则：“后进先出（简称LIFO）”
    //note:创建
    //1) 创建一个不包含任何元素的 stack 适配器，并采用默认的 deque 基础容器：
    std::stack<int> values;
    //2) 上面提到，stack<T,Container=deque<T>> 模板类提供了 2 个参数
        //通过指定第二个模板类型参数，我们可以使用出 deque 容器外的其它序列式容器
        //只要该容器支持 empty()、size()、back()、push_back()、pop_back() 这 5 个成员函数即可
    std::stack<std::string, std::list<int>> values1;
    //3) 可以用一个基础容器来初始化 stack 适配器，只要该容器的类型和 stack 底层使用的基础容器类型相同即可。例如：
    std::list<int> values2 {1, 2, 3};
    std::stack<int,std::list<int>> my_stack(values2);
        //注意，初始化后的 my_stack 适配器中，栈顶元素为 3，而不是 1。
        //另外在第 2 行代码中，stack 第 2 个模板参数必须显式指定为 list<int>（必须为 int 类型，和存储类型保持一致)
        //否则 stack 底层将默认使用 deque 容器，也就无法用 lsit 容器的内容来初始化 stack 适配器。
    //4) 还可以用一个 stack 适配器来初始化另一个 stack 适配器，只要它们存储的元素类型以及底层采用的基础容器类型相同即可。例如：
    std::list<int> values3{ 1, 2, 3 };
    std::stack<int, std::list<int>> my_stack1(values3);
    std::stack<int, std::list<int>> my_stack2=my_stack1;
    cout<<endl;
    //note:成员函数
    //empty(),size()
    //top()：返回栈顶元素的引用  
    //push(const T& val): 先复制，后粘贴 ,push(T&& obj)：右值移动
    //pop():弹出栈顶元素
    //swap(stack<T> &other_stack) ：两个适配器中元素互换
    cout<<"size of my_stack1:"<<my_stack1.size()<<endl;
    while(!my_stack1.empty())
    {
        cout<<my_stack1.top()<<endl;
        my_stack1.pop();
    }
    cout<<"size of my_stack1 for now:"<<my_stack1.size()<<endl;

    cout<<endl;
    cout<<"************ queue adaptor ************"<<endl;
    //tag:queue 队列适配器
    //基础容器筛选条件:
        //基础容器需包含以下成员函数：empty(),size(),front(),back(),push_back(),pop_back()
        //满足条件的基础容器有 deque、list。
        //默认为 deque
    //规则：“先进先出（简称 "FIFO" ）”
    //note:创建
    queue<int> queueNone;      //默认deque

    queue<int,list<int>> queueL; //创建以list容器作为基础容器的空queue容器
    
    deque<int> value_q{1,2,3};
    queue<int> my_queue(value_q);
    queue<int> my_queue1(my_queue);  //way1
    queue<int> my_queue2=my_queue;   //way2
    //note:成员函数
    //empty(),size()
    //front()：返回queue的第一个元素的引用    back():返回最后一个元素引用
    //push(const T& val): 先复制，后粘贴 ,push(T&& obj)：右值移动
    //emplace():在queue尾部直接添加一个元素
    //pop():删除queue的第一个元素
    //swap(stack<T> &other_stack) ：两个适配器中元素互换
    cout<<"size of my_queue1:"<<my_queue1.size()<<endl;
    while(!my_queue1.empty())
    {
        cout<<my_queue1.front()<<endl;
        my_queue1.pop();
    }
    cout<<"size of my_queue1 for now:"<<my_queue1.size()<<endl;
    cout<<endl;

    cout<<"************ priority_queue adaptor ************"<<endl;

    //tag:priority_queue 优先权队列适配器
    //基础容器筛选条件:
        //基础容器需包含以下成员函数：empty(),size(),push_back(),pop_back()
        //满足条件的基础容器有 vector、deque
        //默认为 vector
    //规则：“从一端进（称为队尾），从另一端出（称为队头）”，且每次只能访问 priority_queue 中位于队头的元素。
    //note:定义
    // template <typename T,
    //     typename Container=std::vector<T>,
    //     typename Compare=std::less<T> >     //默认从大到小。通常为自定义
    // class priority_queue{
    // //......
    // }
    priority_queue<int> valuesI;  //底层为vector,默认less排序
    //使用普通数组
    int valuesII[]{4,1,3,2};
    priority_queue<int> copy_value(valuesII,valuesII+4);  //fix: {4,2,3,1}???
    cout<<endl;
    //使用序列式容器
    std::array<int,4> arrValues{4,1,3,2};
    priority_queue<int> copy_valueArr(arrValues.begin(),arrValues.end());

    //手动指定 底层容器 与 排序规则
    int valuesIII[]{4,1,2,3};
    priority_queue<int,deque<int>,greater<int>> copy_valueIII(valuesIII,valuesIII+4);  //fix:{1,3,2,4} ???什么规则

    //规则？？？  优先级？？？  可单步执行  http://c.biancheng.net/view/6987.html
    copy_valueArr.push(5);
    copy_valueArr.push(0);

    copy_valueIII.push(5);
    copy_valueIII.push(0);

    while (!copy_valueArr.empty())
    {
        //输出第一个元素并移除。
        std::cout << copy_valueArr.top()<<" ";
        copy_valueArr.pop();//移除队头元素的同时，将剩余元素中优先级最大的移至队头
    }
        while (!copy_valueIII.empty())
    {
        //输出第一个元素并移除。
        std::cout << copy_valueIII.top()<<" ";
        copy_valueIII.pop();//移除队头元素的同时，将剩余元素中优先级最大的移至队头
    }
    
    //done:迭代器适配器
    cout<<"****************** STL iterator adapter ******************"<<endl;
    cout<<endl;
    //#include <iterator>
    //使用迭代器适配器时，其本质是在操作某种基础迭代器。
    //分类
    //反向迭代器适配器（reverse_iterator）、插入型迭代器适配器inserter或者insert_iterator）
    //流迭代器适配器（istream_iterator / ostream_iterator）、流缓冲区迭代器适配器（istreambuf_iterator / ostreambuf_iterator）
    //移动迭代器适配器（move_iterator）
    cout<<"****** reverse_iterator ******"<<endl;
    //tag:reverse_iterator
    //常用来对容器进行反向遍历，即从容器中存储的最后一个元素开始，一直遍历到第一个元素。
    //反向迭代器底层可以选用双向迭代器或者随机访问迭代器作为其基础迭代器。不仅如此，通过对 ++（递增）和 --（递减）运算符进行重载，使得：
        //当反向迭代器执行 ++ 运算时，底层的基础迭代器实则在执行 -- 操作，意味着反向迭代器在反向遍历容器；
        //当反向迭代器执行 -- 运算时，底层的基础迭代器实则在执行 ++ 操作，意味着反向迭代器在正向遍历容器。
    //note:创建
    //method1:
    std::reverse_iterator<std::vector<int>::iterator> my_reIter1;
    //method2:
    vector<int> myvector2{1,2,3,4,5};
    reverse_iterator<std::vector<int>::iterator> my_reIter2(myvector2.end());   //指向5
    //反向迭代器的指向和其底层基础迭代器的指向关系:
        //反向迭代器的指向总是距离基础迭代器偏左 1 个位置 ；反之，基础迭代器的指向总是距离反向迭代器偏右 1 个位置处。
    //method3:
    reverse_iterator<std::vector<int>::iterator> my_reIter3(myvector2.rbegin()); //指向5
    //note:运算符重载
    // operator*	以引用的形式返回当前迭代器指向的元素。
    // operator+	返回一个反向迭代器，其指向距离当前指向的元素之后 n 个位置的元素。此操作要求基础迭代器为随机访问迭代器。
    // operator++	重载前置 ++ 和后置 ++ 运算符。
    // operator+=	当前反向迭代器前进 n 个位置，此操作要求基础迭代器为随机访问迭代器。
    // operator-	返回一个反向迭代器，其指向距离当前指向的元素之前 n 个位置的元素。此操作要求基础迭代器为随机访问迭代器。
    // operator--	重载前置 -- 和后置 -- 运算符。
    // operator-=	当前反向迭代器后退 n 个位置，此操作要求基础迭代器为随机访问迭代器。
    // operator->	返回一个指针，其指向当前迭代器指向的元素。
    // operator[n]	访问和当前反向迭代器相距 n 个位置处的元素。
    cout<<*my_reIter3<<endl;    //5
    cout<<*(my_reIter3+2)<<endl;  //3
    cout<<my_reIter3[1]<<endl;    //4
    //note:base()
    //返回底层基础迭代器
    reverse_iterator<vector<int>::iterator> begin(myvector2.begin());  //指向1之前一个位置
    reverse_iterator<vector<int>::iterator> end(myvector2.end());     //指向5
    for(auto iter=begin.base();iter!=end.base();++iter)
    {
        cout<<*iter<<' ';      //begin.base()即1，end.base()即5之后一个位置
    }                          //输出1 2 3 4 5
    cout<<endl;
    cout<<endl;



    cout<<"****** inserter/insert_iterator ******"<<endl;
    //tag:insert_iterator 
    //功能:向指定容器中插入元素
    //note:类型
    // back_insert_iterator	
        //在指定容器的尾部插入新元素，但前提必须是提供有 push_back() 成员方法的容器（包括 vector、deque 和 list）。
    // front_insert_iterator	
        //在指定容器的头部插入新元素，但前提必须是提供有 push_front() 成员方法的容器（包括 list、deque 和 forward_list）。
    // insert_iterator	
        //在容器的指定位置之前插入新元素，前提是该容器必须提供有 insert() 成员方法。
    //note:使用
    //back_insert_iterator
    vector<int> vtest;
    back_insert_iterator<vector<int>> back_it(vtest);
    back_it=1;
    back_it=2;
    back_it=3;
    //等效于以下 ，即back_it 自动移动指向
    auto pos=vtest.insert(vtest.end(),4);
    ++pos;
    pos=vtest.insert(pos,5);
    for(auto iterVtest=vtest.begin();iterVtest!=vtest.end();++iterVtest)
    {
        cout<<*iterVtest<<" ";
    }
    cout<<endl;
    cout<<endl;
    //或使用 函数back_inserter()
    back_insert_iterator<vector<int>> back_it2=back_inserter(vtest);
    back_it2=6;
    for(auto iterVtest=vtest.begin();iterVtest!=vtest.end();++iterVtest)
    {
        cout<<*iterVtest<<" ";     // {1,2,3,4,5,6}
    }
    cout<<endl;
    cout<<endl;

    // front_insert_iterator
    //不能使用vector了, 换为forward_list
    forward_list<int> flTest;	
    front_insert_iterator<forward_list<int>> front_it=front_inserter(flTest);
    front_it=0;
    front_it=-1;
    front_it=-2;

    for(auto iterflTest=flTest.begin();iterflTest!=flTest.end();++iterflTest)
    {
        cout<<*iterflTest<<" ";     // {-2,-1,0}
    }
    cout<<endl;
    cout<<endl;

    // front_insert_iterator
    // std::insert_iterator<Container> insert_it (container,it);
    //Container 表示目标迭代器的类型，参数 container 表示目标迭代器，而 it 是一个基础迭代器，表示新元素的插入位置。
    auto itTest=++vtest.begin();
    insert_iterator<vector<int>> insert_it=inserter(vtest,itTest);  
    insert_it=7;      // {1,7,2,3,4,5,6}
    insert_it=8;
    insert_it=9;

    for(auto iterVtest=vtest.begin();iterVtest!=vtest.end();++iterVtest)
    {
        cout<<*iterVtest<<" ";     // {1,7,8,9,2,3,4,5,6}
    }
    cout<<endl;
    cout<<endl;

    cout<<"****** istream_iterator / ostream_iterator ******"<<endl;
    //略
    cout<<"****** istreambuf_iterator / ostreambuf_iterator ******"<<endl;
     //略
    cout<<"****** move_iterator ******"<<endl;
    //略

   //done:迭代器适配器函数
    cout<<"****************** STL iterator adapter function******************"<<endl;
    cout<<endl;
    // advance(it, n)	it 表示某个迭代器，n 为整数。该函数的功能是将 it 迭代器前进或后退 n 个位置。
    // distance(first, last)	first 和 last 都是迭代器，该函数的功能是计算 first 和 last 之间的距离。
    // begin(cont)	cont 表示某个容器，该函数可以返回一个指向 cont 容器中第一个元素的迭代器。
    // end(cont)	cont 表示某个容器，该函数可以返回一个指向 cont 容器中最后一个元素之后位置的迭代器。
    // prev(it)	it 为指定的迭代器，该函数默认可以返回一个指向上一个位置处的迭代器。注意，it 至少为双向迭代器。
    // next(it)	it 为指定的迭代器，该函数默认可以返回一个指向下一个位置处的迭代器。注意，it 最少为前向迭代器。
    cout<<"****** advance() ******"<<endl;
    //tag:advance()
    // advance() 函数用于将迭代器前进（或者后退）指定长度的距离，其语法格式如下：
    // template <class InputIterator, class Distance>
    //     void advance (InputIterator& it, Distance n);
    // 其中 it 指的是目标迭代器，n 通常为一个整数。

    // 需要注意的是，如果 it 为输入迭代器或者前向迭代器，则 n 必须为一个正数，即表示将 it 右移（前进） n 个位置；
    // 反之，如果 it 为双向迭代器或者随机访问迭代器，则 n 为正数时表示将 it 右移（前进） n 个位置，n 为负数时表示将 it 左移（后退） n 个位置。

    // 另外，根据 it 类型是否为随机访问迭代器，advance() 函数底层采用了不同的实现机制：
    // 当 it 为随机访问迭代器时，由于该类型迭代器支持 p+n 或者 p-n（其中 p 就是一个随机访问迭代器）运算，advance() 函数底层采用的就是 it+n 操作实现的；
    // 当 it 为其他类型迭代器时，它们仅支持进行 ++ 或者 -- 运算，这种情况下，advance() 函数底层是通过重复执行 n 个 ++ 或者 -- 操作实现的。

    //note:使用
    forward_list<int> myFL{1,2,3,4,5};
    auto iterMyFL=myFL.begin();
    advance(iterMyFL,4);           //5
    cout<<"*iterMyFL="<<*iterMyFL<<endl;

    vector<int> myVec{1,2,3,4,5};
    auto iterMyVec= myVec.begin();
    advance(iterMyVec,1);         //2
    cout<<"*iterMyVec="<<*iterMyVec<<endl;

    auto iterMyVec2= myVec.end();
    advance(iterMyVec2,-1);       //5
    cout<<"*iterMyVec2="<<*iterMyVec2<<endl;

    cout<<endl;
    cout<<"****** distance() ******"<<endl;
    //tag:distance()
    // distance() 函数用于计算两个迭代器表示的范围内包含元素的个数，其语法格式如下：
    // template<class InputIterator>
    //    typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last);
    // 其中，first 和 last 都为迭代器，其类型可以是输入迭代器、前向迭代器、双向迭代器以及随机访问迭代器；
    // 该函数会返回[first, last)范围内包含的元素的个数。

    // 注意，first 和 last 的迭代器类型，直接决定了 distance() 函数底层的实现机制：
    // 1.当 first 和 last 为随机访问迭代器时，distance() 底层直接采用 last - first 
    //  求得 [first, last) 范围内包含元素的个数，其时间复杂度为O(1)常数阶；
    // 2.当 first 和 last 为非随机访问迭代器时，distance() 底层通过不断执行 ++first（或者 first++）
    //   直到 first==last，由此来获取 [first, last) 范围内包含元素的个数，其时间复杂度为O(n)线性阶。
    //note:使用
    //以list为例，其为双向迭代器
    list<int> myList;
    for(int i=0;i<10;i++)
    {
        myList.push_back(i);
    }
    list<int>::iterator first=myList.begin();
    list<int>::iterator last=myList.end();
    cout<<"distance()="<<distance(first,last);    //10


    cout<<endl;
    cout<<"****** begin(),end() ******"<<endl;
    //tag:begin(),end()
    //note:使用
    //1) begin()和end()参数为容器
    //1、非 const 修改的容器作为参数，begin() 函数返回的为非 const 类型的迭代器
    // template <class Container>
    //     auto begin (Container& cont)
    // 2、传入 const 修饰的容器，begin() 函数返回的为 const 类型的迭代器
    // template <class Container>
    //     auto begin (const Container& cont)
    vector<int> myVector{1,2,3}; 
    for(auto it=std::begin(myVector);it!=std::end(myVector);++it)
        cout << *it << " ";
    //2) begin()和end()参数为数组
    int arrTest[] = { 1,2,3,4,5 };  
    vector<int> myVecTest;
    for(int *itT=std::begin(arrTest);itT!=std::end(arrTest);++itT)
        cout<<*itT<<" ";
    cout<<endl;
    cout<<endl;


    cout<<"****** prev(),next() ******"<<endl;
    //tag:prev()
    //note:使用
    // prev() 该函数可用来获取一个距离指定迭代器 n 个元素的迭代器。

    // prev() 函数的语法格式如下：
    // template <class BidirectionalIterator>
    //     BidirectionalIterator prev (BidirectionalIterator it, typename iterator_traits<BidirectionalIterator>::difference_type n = 1);

    // 其中，it 为源迭代器，其类型只能为双向迭代器或者随机访问迭代器；
    // n 为指定新迭代器距离 it 的距离，默认值为 1。该函数会返回一个距离 it 迭代器 n 个元素的新迭代器。
    // 注意，当 n 为正数时，其返回的迭代器将位于 it 左侧；反之，当 n 为负数时，其返回的迭代器位于 it 右侧。
    list<int> myL{1,2,3,4,5};
    auto itMyL=myL.end();
    auto newitMyL=prev(itMyL,4);  //向左移动4个，2
    cout<<"prev(newitMyL)="<<*newitMyL<<endl;

    newitMyL=prev(newitMyL,-2);  //向右移动2个，4
    cout<<"prev(newitMyL)="<<*newitMyL<<endl;

    //tag:next()
    // next() 该函数用来获取一个距离指定迭代器 n 个元素的迭代器。

    // next() 函数的语法格式如下：
    // template <class ForwardIterator>
    //     ForwardIterator next (ForwardIterator it, typename iterator_traits<ForwardIterator>::difference_type n = 1);

    // 其中 it 为源迭代器，其类似可以为前向迭代器、双向迭代器以及随机访问迭代器；
    // n 为指定新迭代器距离 it 的距离，默认值为 1。该函数会返回一个距离 it 迭代器 n 个元素的新迭代器。
    // 需要注意的是，当 it 为前向迭代器时，n 只能为正数，该函数最终得到的新迭代器位于 it 右侧；
    // 当 it 为双向迭代器或者随机访问迭代器时，若 n 为正数，则得到的新迭代器位于 it 右侧，反之位于 it 左侧。

    newitMyL=next(newitMyL,1);     //向右移动1个，5
    cout<<"next(newitMyL)="<<*newitMyL<<endl;
    newitMyL=next(newitMyL,-1);    //向左移动1个，4
    cout<<"next(newitMyL)="<<*newitMyL<<endl;

    system("pause");             // 暂停用
 
    return 0;
}


