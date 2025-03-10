#include <iostream>
using namespace std;

​
// 求一个正三位数各位的数字和

int main() {
	int i = 0;
	int a, b, c,sum,y;
	cout << "请输入一个三位整数: ";
		cin >> i;
	a = i / 100; //得到百位数
	b = (i % 100) / 10; //得到十位数
	c = i % 10; //得到个位数
	sum = a + b + c;
	y = c * 100 + b * 10 + a;
	cout << "各位数字之和为：" << sum << endl << "逆序后的整数为: " <<y<< endl;
		return 0;
}

//  // 进阶版：任意输入一个整数（不限制位数，包含负数），使用循环语句求其各位数字和

// 得到一个数的各位数，不断地%10/10%10/10······

// 可以记作  模10得到除10拿掉

int main() {
	int a, sum = 0;//sum一定初始化
	cout << "请输入一个整数: ";
		cin >> a;
	int n = abs(a);//求绝对值函数
	while (n != 0) {
		sum += n % 10;  //得到末位数并求和
		n /= 10; //拿掉末位数
	}
	cout << "各位数之和为：" << sum << endl;
	cout << "逆序输出后: ";
	while (a != 0)	{
		cout << a % 10;
		a /= 10;
	}
	return 0;
}

 // 求一个数的位数

 // 求一个数是几位数
 //每次小数点前移一位
  int n,i=0;
  cin >> n;
  while (n != 0) {
      n=n / 10;
      i++;
  }
// 求两个数的最大公约数和最小公倍数

// 三个重要点

// 1、将两个数的值先储存，后续会改变

// 2、求最小公约数用辗转相除法

// 3、求最小公倍数先求最小公约数后带公式

//求两个整数的最大公约数和最小公倍数

int main() {
    int a, b, a0, b0,t;
    int lcm;
    cout << "请输入两个整数: ";
    cin >> a >> b;
    a0 = a; b0 = b; //储存两个数
    while ((t=a%b)!=0) {
        a = b;
        b = t;
    }
    cout << "最大公约数为：" << b<<endl;
    lcm = a0 * b0 / b;
    cout << "最小公倍数为： " << lcm;
    return 0;
}

// 输出1~n的平方和
//使用while循环
int main() {
    int i=1,n=0;
    cout << "请输入一个整数： ";
	cin>> n;
	while (i <= n) {
		cout << i * i<<" ";
		i++;
}
	return 0;
}

//使用for循环
int main() {
	int n;
	cout << "请输入一个整数： ";
	cin >> n;
	for (int i = 1; i <= n; i++)
		cout << i * i<<" ";
	return 0;
  }


