关于类型的选择
1.当明确知晓数值不可能为负时，选用无符号类型。
2.如果选用的数值超过了int的表示范围，选用long long
3.在算术表达式中不要使用char或bool，只有在存放字符或者布尔值时才使用它们。
4.执行浮点数运算选用double

当赋给无符号类型一个超出它表示范围的值时，结果是初始值对无符号类型表示数值总数取模后的余数。

对象：通常情况下，对象是指一块能储存数据并具有某种类型的内存空间。

默认初始化：定义于任何函数体之外的变量被初始化为0。函数体内部则不被初始化。
对于类来说，绝大多数都无需显式初始化，比如std::dstring会定义一个空串。

声明：规定变量的类型和名字；
定义：负责创建与名字关联的实体。

静态类型语言：在编译阶段检查类型。

标识符：
由字母、数字和下画线组成，其中必须以字母或下画线开头，对大小写字母敏感。
不能连续出现两个下画线，也不能以下画线紧连大写字母开头。此外，定义在函数体外的标识符不能以下画线开头。
变量命名规范：
1.标识符要能体现实际含义
2.变量名一般用小写字母
3.用户自定义的类名一般以大写字母开头
4.如果标识符由多个单词组成，则单词间应有明显区分，如student_loan

作用域中一旦声明了某个名字，它所嵌套的所有作用域中都能访问该名字。

引用是为对象起了另外一个名字，在定义引用时，程序把引用和它的初始值绑定在一起。

指针值：
1.指向一个对象
2.指向紧邻对象所占空间的下一位置
3.空指针，意味着指针没有指向任何对象
4.无效指针，也就是上述情况之外的其他值

解引用只适用于有效指针。

只要指针拥有一个合法值，就能将它用在条件表达式中。

如果在多个文件之间共享const对象，必须在变量的定义之前添加extern关键字

建议：
1.程序应该尽量避免依赖于实现环境的行为
2.当第一次使用变量时再定义它


注意：
1.不要混用带符号类型和无符号类型
2.无符号数不会小于零，因此不适用 >= 这种判断条件，但是可以把其本身当作一个判断条件
3.初始化不是赋值，初始化的含义是创建一个变量赋予其一个初始值，而赋值的含义是把对象的当前值擦除，而以一个新值代替
4.变量可以被声明(extern)多次，但是只能被定义一次
5.引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定在一起