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
    cout<<"****************** STL container ******************"<<endl;
    //tag:pair
    //基础 键值对pair
    cout<<"************ pair ************"<<endl;
    //note:创建
    //1) 默认构造函数，即创建空的 pair 对象
    //pair();
    //2) 直接使用 2 个元素初始化成 pair 对象
    //pair (const first_type& a, const second_type& b);
    //3) 拷贝（复制）构造函数，即借助另一个 pair 对象，创建新的 pair 对象
    //template<class U, class V> pair (const pair<U,V>& pr);
    //4) 移动构造函数
    //template<class U, class V> pair (pair<U,V>&& pr);
    //5) 使用右值引用参数，创建 pair 对象
    //template<class U, class V> pair (U&& a, V&& b);

    pair<string,double> pair11;
    pair<string,string> pair22("11","aa");
    pair<string,string> pair33(pair22);
    pair<string,string> pair44(make_pair("22","bb"));
    pair<string,string> pair55(string("12"),string("ab"));

    cout<<"pair11:"<<pair11.first<<" "<<pair11.second<<endl;
    cout<<"pair22:"<<pair22.first<<" "<<pair22.second<<endl;
    cout<<"pair33:"<<pair33.first<<" "<<pair33.second<<endl;    
    cout<<"pair44:"<<pair44.first<<" "<<pair44.second<<endl;
    cout<<"pair55:"<<pair55.first<<" "<<pair55.second<<endl;
    cout<<endl;
    //note: 手动赋值
    pair11.first="00";
    pair11.second=3.1415;
    cout<<"new pair11:"<<pair11.first<<" "<<pair11.second<<endl;

    //note: 比较 
    cout<<(pair22>pair44?pair22.first:pair44.first)<<endl;

    //note: 交换键值对
    pair44.swap(pair55);
    cout<<"New pair44:"<<pair44.first<<" "<<pair44.second<<endl;
    cout<<"New pair55:"<<pair55.first<<" "<<pair55.second<<endl; 
 
    cout<<endl;
    cout<<"************ map ************"<<endl;
    //done:有序容器
    //tag: map
    // note:map示例
	map<string,string> mymap;
	mymap["11"]="aa";
	mymap["22"]="bb";
	mymap["12"]="ab";
	for(map<string,string>::iterator it=mymap.begin();it!=mymap.end();++it)
	{
		cout<<it->first<<"=>"<<it->second<<'\n';
	}
    // note:定义
    // template<class Key,class T,class Compare=less<Key>,class Alloc=allocator<pair<const Key,T>>>class map;
    // note:创建
    map<string,int> myMap1;
    map<string,int> myMap2{{"aa",1},{"bb",2}};
    map<string,int> myMap3{make_pair("cc",3),make_pair("dd",4)};
    map<string,int> myMap4(myMap3);
    map<string,int> newMap(++myMap2.begin(),myMap2.end());
    // 创建时排序
    map<string,int,less<string>> myMap5{{"a",1},{"b",2}};   // 默认升序
    map<string,int,greater<string>> myMap6{{"a",1},{"b",2}};   // 自定义为 降序
    cout<<endl;
    map<string,int,greater<string>> myMap7{{"a",1},{"b",2}};   // 自定义为 降序
    myMap7.emplace("c",3);
    myMap7.emplace("d",4);
    cout<<"myMap7 's size= "<<myMap7.size()<<endl;
    if(!myMap7.empty())
    {
        for(auto it=myMap7.begin();it!=myMap7.end();++it)
        cout<<it->first<<"  "<<it->second<<endl;
    }
    //note:双向迭代器
    //C++ STL 标准库为 map 容器配备的是双向迭代器（bidirectional iterator）。
    //这意味着，map 容器迭代器只能进行 ++p、p++、--p、p--、*p 操作，
    //并且迭代器之间只能使用 == 或者 != 运算符进行比较。

    //note: 查找
    //method1:find()
    //map 类模板中提供了 find() 成员方法，它能帮我们查找指定 key 值的键值对
    //如果成功找到，则返回一个指向该键值对的双向迭代器；反之，其功能和 end() 方法相同。
    auto iter=myMap7.find("c");
    for(;iter!=myMap7.end();iter++)
    {
        cout<<iter->first<<"  "<<iter->second<<endl;
    }
    iter=myMap7.find("e");           //查找一个不存在的键值"e"
    for(;iter!=myMap7.end();iter++)
    {
        cout<<iter->first<<"  "<<iter->second<<endl; //没有输出任何信息
    }
    cout<<"Because of an unresited key,so..."<<endl;
    //lower_bound(key) 返回的是指向第一个键不小于 key 的键值对的迭代器；
    //upper_bound(key) 返回的是指向第一个键大于 key 的键值对的迭代器；

    //fix: 为什么？降序不能用lower_bound???????
    //auto iter2=myMap7.lower_bound("C");
    //cout<<"lower :"<<iter2->first<<"  "<<iter2->second<<endl; //
    std::map<std::string, std::string>myMap8{ {"STL","3"},
                                             {"C","1"},
                                             {"Java","2"} };
    //找到第一个键的值不小于 "Java教程" 的键值对
    auto iter3 = myMap8.lower_bound("Java");
    cout << "lower:" << iter3->first << " " << iter3->second << endl;
   
    //找到第一个键的值大于 "Java教程" 的键值对
    iter3 = myMap8.upper_bound("Java");
    cout <<"upper:" << iter3->first << " " << iter3->second << endl;

    //method2:[]  
    //若map中没有该键值，则创建该键值对，值为默认，string为"",int为0
    string strValue=myMap8["C"];
    cout<<strValue<<endl;
    string strValueNone=myMap8["Py"];
    cout<<strValueNone<<endl;
    //[]也可以赋值，若已存在，则覆盖
    myMap8["C"]="I'm NewString";
    string strNewValue=myMap8["C"];
    cout<<strNewValue<<endl;
    //method3:at()
    //若map中没有该键值，则异常 out_of_range
    cout<<myMap8.at("C")<<endl;
    cout<<myMap8.at("Py")<<endl;  //之前已赋值
    //cout<<myMap8.at("PY")<<endl;   //异常退出
    //method4:遍历  
    for (auto iter5 = myMap8.begin(); iter5 != myMap8.end(); ++iter5) {
        //调用 string 类的 compare() 方法，找到一个键和指定字符串相同的键值对
        if (!iter5->first.compare("C")) {
            cout << iter5->first << " " << iter5->second << endl;
        }
    }
    //note: 插入
    //method1:[],不存在时即添加，存在时覆盖
    //method2:insert()  注意：形式不同，返回值类型不同
    //1) 无需指定插入位置，直接将键值对添加到 map 容器中。insert() 方法的语法格式有以下 2 种：
    //返回pair对象
        map<string,string> newMap2;
        pair<string,string> pair111={"a","1"};
        pair<map<string,string>::iterator,bool> ret;
        //1、引用传递一个键值对
             //pair<iterator,bool> insert (const value_type& val);
        ret=newMap2.insert(pair111);
        cout<<"ret.iter=<{"<<ret.first->first<<","<<ret.first->second<<"},"<<ret.second<<">"<<endl;

        //2、以右值引用的方式传递键值对
            //template <class P>
            //pair<iterator,bool> insert (P&& val);
        ret=newMap2.insert({"b","2"});
        cout<<"ret.iter=<{"<<ret.first->first<<","<<ret.first->second<<"},"<<ret.second<<">"<<endl;
        ret=newMap2.insert({"a","1"});
        cout<<"ret.iter=<{"<<ret.first->first<<","<<ret.first->second<<"},"<<ret.second<<">"<<endl; //bool为0，因为重复
        //ret = newMap.insert(make_pair("C语言教程", "http://c.biancheng.net/c/"));
        //ret = mymap.insert(pair<string,string>{ "C语言教程","http://c.biancheng.net/c/" });
    //2) 除此之外，insert() 方法还支持向 map 容器的指定位置插入新键值对，该方法的语法格式如下：
    //返回迭代器
        // 如果插入成功，insert() 方法会返回一个指向 map 容器中已插入键值对的迭代器；
        // 如果插入失败，insert() 方法同样会返回一个迭代器，该迭代器指向 map 容器中和 val 具有相同键的那个键值对。
        //以普通引用的方式传递 val 参数
        //iterator insert (const_iterator position, const value_type& val);
        pair<string,string> pair222={"c","3"};
        auto iterPos=newMap2.begin();
        auto iterPosRet=newMap2.insert(iterPos,pair222);
        cout<<iterPosRet->first<<" "<<iterPosRet->second<<endl;

        //以右值引用的方式传递 val 键值对参数
        //template <class P>
        //iterator insert (const_iterator position, P&& val);
        auto iterPosRet2=newMap2.insert(iterPos,pair<string,string>("d","4"));
        cout<<iterPosRet2->first<<" "<<iterPosRet2->second<<endl;
        
        auto iterPosRet3=newMap2.insert(iterPos,pair<string,string>("d","4"));  //重复插入，失败，返回结果见上
        cout<<iterPosRet3->first<<" "<<iterPosRet3->second<<endl;
        cout<<endl;
    //3) insert() 方法还支持向当前 map 容器中插入其它 map 容器指定区域内的所有键值对，该方法的语法格式如下：
        //template <class InputIterator>
        //void insert (InputIterator first, InputIterator last); 
        map<string,string>  copymap;         //把newmap2中除了第一个a,都拷贝到 copymap中
        map<string,string>::iterator iterCopyStart=++newMap2.begin();
        auto iterCopyLast=newMap2.end();

        copymap.insert(iterCopyStart,iterCopyLast);
        for(auto iterI=copymap.begin();iterI!=copymap.end();++iterI)
        {
            cout<<iterI->first<<" "<<iterI->second<<endl;
        }
    //4) 除了以上一种格式外，insert() 方法还允许一次向 map 容器中插入多个键值对，其语法格式为：
        //void insert ({val1, val2, ...});
    
        cout<<endl;
        newMap2.insert({ {"e","5"},{"A","11"},{"B","22"}});     //注意AB在前，ab在后
        for(auto iterII=newMap2.begin();iterII!=newMap2.end();++iterII)
        {
            cout<<iterII->first<<" "<<iterII->second<<endl;
        }
    //method3:emplace()  emplace_hint() ,相比以上，此两者效率更高
        //和 insert() 方法相比，emplace() 和 emplace_hint() 方法的使用要简单很多，因为它们各自只有一种语法格式。其中，emplace() 方法的语法格式如下：
        // template <class... Args>
        // pair<iterator,bool> emplace (Args&&... args);

        // 参数 (Args&&... args) 指的是，这里只需要将创建新键值对所需的数据作为参数直接传入即可，此方法可以自行利用这些数据构建出指定的键值对。
        // 另外，该方法的返回值也是一个 pair 对象，其中 pair.first 为一个迭代器，pair.second 为一个 bool 类型变量：
        // 当该方法将键值对成功插入到 map 容器中时，其返回的迭代器指向该新插入的键值对，同时 bool 变量的值为 true；
        // 当插入失败时，则表明 map 容器中存在具有相同键的键值对，此时返回的迭代器指向此具有相同键的键值对，同时 bool 变量的值为 false。
    map<string,string> nnewmap;
    pair<map<string,string>::iterator,bool> nnewret=nnewmap.emplace("a","1");
    cout<<"1.ret.ite<{"<<nnewret.first->first<<","<<nnewret.first->second<<"},"<<nnewret.second<<">"<<endl;
    nnewret=nnewmap.emplace("b","2");
    cout<<"2.ret.ite<{"<<nnewret.first->first<<","<<nnewret.first->second<<"},"<<nnewret.second<<">"<<endl;
    nnewret=nnewmap.emplace("b","2");     //重复插入，bool为0
    cout<<"3.ret.ite<{"<<nnewret.first->first<<","<<nnewret.first->second<<"},"<<nnewret.second<<">"<<endl;
    //    emplace_hint() 方法的功能和 emplace() 类似，其语法格式如下：
        // template <class... Args>
        //   iterator emplace_hint (const_iterator position, Args&&... args);

        // 显然和 emplace() 语法格式相比，有以下 2 点不同：
        // 该方法不仅要传入创建键值对所需要的数据，还需要传入一个迭代器作为第一个参数，指明要插入的位置（新键值对键会插入到该迭代器指向的键值对的前面）；
        // 该方法的返回值是一个迭代器，而不再是 pair 对象。当成功插入新键值对时，返回的迭代器指向新插入的键值对；反之，如果插入失败，则表明 map 容器中存有相同键的键值对，返回的迭代器就指向这个键值对。
    auto iterIII=nnewmap.emplace_hint(nnewmap.begin(),"c","3");
    cout<<iterIII->first<<" "<<iterIII->second<<endl;

    iterIII=nnewmap.emplace_hint(nnewmap.begin(),"d","4");
    cout<<iterIII->first<<" "<<iterIII->second<<endl;

    iterIII=nnewmap.emplace_hint(nnewmap.begin(),"d","3");  //已有键值，不会覆盖，只会输出原有键值对
    cout<<iterIII->first<<" "<<iterIII->second<<endl;

    //tag: multimap
    //区别 可以存在相同的键值，因此不存在at() 但lower_bound()、upper_bound()、equal_range() 以及 count() 成员方法会经常用到。
    //note:创建
    multimap<string,string> myMultimap;
    multimap<string,string> myMultimap1{{"a","1"},{"b","2"},{"c","3"}};
    multimap<string,string> myMultimap2{pair<string,string>{"a","1"},pair<string,string>{"b","2"}};
    multimap<string,string> myMultimap4{make_pair("a","1"),make_pair("b","2")};
    multimap<string,string> myMultimap5(myMultimap4);   //拷贝
    //移动 临时 //fix:?
    // multimap<string, string> dismultimap() {
    
    //     multimap<string,string> tempmultimap{{"a","1"},{"b","2"},{"c","3"}};
    //     return tempmultimap;
    // }
    // multimap<string,string> newmultimap(dismultimap());

    multimap<string,string> myMultimap6(++myMultimap1.begin(),myMultimap1.end());
    //排序
    cout<<endl;
    multimap<char,int,greater<char>> mySortReverseMM{{'a',1},{'b',2}};
    auto iterR=mySortReverseMM.begin();
    cout<<"The first key is:"<<iterR->first<<endl;

    //demo
    multimap<string,int> mm{{"a",1},{"b",2},{"b",2},{"c",3}};
    multimap<string,int> mm2{{"a",1},{"b",2},{"b",22},{"c",3}};
    cout<<mm.size()<<endl;
    cout<<mm.count("b")<<endl;


    cout<<endl;
    cout<<"************ set ************"<<endl;
    //tag:set
    //key=value,故只须赋一个值即可
    // 1.不再以键值对的方式存储数据，因为 set 容器专门用于存储键和值相等的键值对，因此该容器中真正存储的是各个键值对的值（value）；
    // 2.set 容器在存储数据时，会根据各元素值的大小对存储的元素进行排序（默认做升序排序）；
    // 3.存储到 set 容器中的元素，虽然其类型没有明确用 const 修饰，但正常情况下它们的值是无法被修改的；
    // 4.set 容器存储的元素必须互不相等。
    set<string> myset{"aa","bb","dd","cc"};     //默认排序为less即 aa bb cc dd
    set<string> copyset(++myset.begin(),myset.end());  //拷贝了 bb cc dd
    //排序
    set<string,greater<string>> myset2{"aa","bb","dd","cc"};  
    // size(),insert(), 双向迭代器 ，没有at(),[].  略
    //set迭代器为双向迭代器，只支持++p,p++,--p,p--,*p,!=,==
    //begin() end() ......
    //insert，emplace, emplace_hint 用法相同
    //note:删除
    //1.erase() 删除指定
    //删除 set 容器中值为 val 的元素, 其返回值为一个整数，表示成功删除的元素个数；
    // size_type erase (const value_type& val);
    // //删除 position 迭代器指向的元素, 返回值都是迭代器，其指向的是 set 容器中删除元素之后的第一个元素。
    // iterator  erase (const_iterator position);
    // //删除 [first,last) 区间内的所有元素, 返回值都是迭代器，其指向的是 set 容器中删除元素之后的第一个元素。
    // iterator  erase (const_iterator first, const_iterator last);
    //略 见http://c.biancheng.net/view/7198.html
    //2.clear() 删除所有


    //tag: multiset
    //与set唯一区别 ： 元素可以重复
    //移动 临时 //fix:?
    // set<string> retSet() {
    // std::set<std::string> myset{ "http://c.biancheng.net/java/",
    //                         "http://c.biancheng.net/stl/",
    //                         "http://c.biancheng.net/python/" };
    // return myset;
    // }   
    // std::set<std::string> copyset(retSet());

    cout<<endl;
    cout<<"************ unordered_map ************"<<endl;
    //done:无序容器
    // 基于底层实现采用了不同的数据结构，因此和关联式容器相比，无序容器具有以下 2 个特点：
    // 1.无序容器内部存储的键值对是无序的，各键值对的存储位置取决于该键值对中的键，
    // 2.和关联式容器相比，无序容器擅长通过指定键查找对应的值（平均时间复杂度为 O(1)）；
    //   但对于使用迭代器遍历容器中存储的元素，无序容器的执行效率则不如关联式容器。
    //实际场景中如果涉及大量遍历容器的操作，建议首选关联式容器；
    //反之，如果更多的操作是通过键获取对应的值，则应首选无序容器。

    //tag:unordered_map
    //创建 
    //demo
    unordered_map<string,string> my_uMap{{"a","1"},{"b","2"},{"c","3"}};
    string strUmap=my_uMap.at("a");
    cout<<"str="<<strUmap<<endl;
    for(auto iterUmap=my_uMap.begin();iterUmap!=my_uMap.end();++iterUmap)
    {
        cout<<iterUmap->first<<" "<<iterUmap->second<<endl;
    }
    my_uMap.emplace("d","4");
    cout<<"The map size is:"<<" "<<my_uMap.size()<<endl;
    //前向迭代器  *p,++p,p++,!=,==
    //equal_range(key)	
    //返回一个 pair 对象，其包含 2 个迭代器，用于表明当前容器中键为 key 的键值对所在的范围。

    //note:重哈希
    //需要注意的是，在操作 unordered_map 容器过程（尤其是向容器中添加新键值对）中，一旦当前容器的负载因子超过最大负载因子（默认值为 1.0），
    //该容器就会适当增加桶的数量（通常是翻一倍），并自动执行 rehash() 成员方法，重新调整各个键值对的存储位置（此过程又称“重哈希”），此过程很可能导致之前创建的迭代器失效。
    //所谓迭代器失效，针对的是那些用于表示容器内某个范围的迭代器，由于重哈希会重新调整每个键值对的存储位置，所以容器重哈希之后，
    //之前表示特定范围的迭代器很可能无法再正确表示该范围。但是，重哈希并不会影响那些指向单个键值对元素的迭代器。
    
    //note:概念
    // bucket_count()	返回当前容器底层存储键值对时，使用桶（一个线性链表代表一个桶）的数量。
    // max_bucket_count()	返回当前系统中，unordered_map 容器底层最多可以使用多少桶。
    // bucket_size(n)	返回第 n 个桶中存储键值对的数量。
    // bucket(key)	返回以 key 为键的键值对所在桶的编号。
    // load_factor()	返回 unordered_map 容器中当前的负载因子。负载因子，指的是的当前容器中存储键值对的数量（size()）和使用桶数（bucket_count()）的比值，即 load_factor() = size() / bucket_count()。
    // max_load_factor()	返回或者设置当前 unordered_map 容器的负载因子。
    // rehash(n)	将当前容器底层使用桶的数量设置为 n。
    // reserve()	将存储桶的数量（也就是 bucket_count() 方法的返回值）设置为至少容纳count个元（不超过最大负载因子）所需的数量，并重新整理容器。
    // hash_function()	返回当前容器使用的哈希函数对象。 

    //note:访问
    //1.at()  见上
    //2.[]
    string strUmap2=my_uMap["b"];
    cout<<"str2="<<strUmap2<<endl;
    string strUmapN=my_uMap["A"];
    my_uMap["B"]="22";
    for(auto iterUM=my_uMap.begin();iterUM!=my_uMap.end();++iterUM)
    {
        cout<<iterUM->first<<" "<<iterUM->second<<endl;
    }
    //3.find()  返回正向迭代器
    //note:插入
    //method1:insert()
    //与之前用法相同
    // 1) insert() 方法可以将 pair 类型的键值对元素添加到 unordered_map 容器中，其语法格式有 2 种：
        // //以普通方式传递参数
        // pair<iterator,bool> insert ( const value_type& val );
        // //以右值引用的方式传递参数
        // template <class P>
        // pair<iterator,bool> insert ( P&& val );
    // 2) 除此之外，insert() 方法还可以指定新键值对要添加到容器中的位置，其语法格式如下：
        // //以普通方式传递 val 参数
        // iterator insert ( const_iterator hint, const value_type& val );
        // //以右值引用方法传递 val 参数
        // template <class P>
        // iterator insert ( const_iterator hint, P&& val );
    // 3) insert() 方法还支持将某一个 unordered_map 容器中指定区域内的所有键值对，复制到另一个 unordered_map 容器中，其语法格式如下：
        // template <class InputIterator>
        // void insert ( InputIterator first, InputIterator last );
    // 4) 除了以上 3 种方式，insert() 方法还支持一次向 unordered_map 容器添加多个键值对，其语法格式如下：
        // void insert ( initializer_list<value_type> il );
    //method2:emplace()  与右值引用方式 返回值pair相同；   emplace_hint() 返回 迭代器
    //note:删除
    //method1:erase()
    // 1) erase() 方法可以接受一个正向迭代器，并删除该迭代器指向的键值对。该方法的语法格式如下：
        // iterator erase ( const_iterator position );
        // 其中 position 为指向容器中某个键值对的迭代器，该方法会返回一个指向被删除键值对之后位置的迭代器。
    // 2) 我们还可以直接将要删除键值对的键作为参数直接传给 erase() 方法，该方法会自行去 unordered_map 容器中找和给定键相同的键值对，将其删除。erase() 方法的语法格式如下：
        // size_type erase ( const key_type& k );
        // 其中，k 表示目标键值对的键的值；该方法会返回一个整数，其表示成功删除的键值对的数量。
    // 3) 除了支持删除 unordered_map 容器中指定的某个键值对
        // erase() 方法还支持一次删除指定范围内的所有键值对，其语法格式如下：
        // iterator erase ( const_iterator first, const_iterator last );
        // 其中 first 和 last 都是正向迭代器，[first, last) 范围内的所有键值对都会被 erase() 方法删除；
        // 同时，该方法会返回一个指向被删除的最后一个键值对之后一个位置的迭代器。
    //method2:clear()   一次性删除所有键值对
    cout<<"************ unordered_multimap ************"<<endl;
    cout<<endl;
    //tag:unordered_multimap
    //键值可以相同，但无[],at()

    cout<<"************ unordered_set ************"<<endl;
    cout<<endl;
    //tag:unordered_set
    //无[],at()

    cout<<"************ unordered_multiset ************"<<endl;
    cout<<endl;
    //tag:unordered_multiset


    system("pause");             // 暂停用
 
    return 0;
}


