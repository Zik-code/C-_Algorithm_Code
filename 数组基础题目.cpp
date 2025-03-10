// 
// 题目一
// 创建一维数组逆序输出10个数

//创建数组逆序输出10个数
int main()
{
	int a;
	int arr[10] = { 0 };
	for (a = 0; a < 10; a++)
	{
		cin >> arr[a];
	}
	for (a = 9; a >= 0; a--)
	{
		cout << arr[a]<<" ";
		
	}
	return 0;
}


// 题目二 
// 从键盘上输入一行数字，按照从大到小输出。

// 冒泡排序法：对N个数进行N-1次排序，升序中大数下沉，小数上浮，降序则相反。基本思想是：对于一组有n个记录的数据，从第一个记录开始依次对相邻的两个记录进行比较，当前面的记录大于后面的记录时，交换这两个记录，进行一轮比较和交换后，n个数据中的最大记录将位于第n位；然后对前（n-1）个记录进行第二轮比较；重复该过程直到进行比较的记录只剩下一个为止。

int main()
{
	//首先从键盘输入数组中元素个数
	int n;
	cin >> n;
	//依次存储元素
	int arr[100] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	//冒泡法排序
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1]) //<改为>则变为升序输出
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<<" ";
	}

}



// 题目三
// 矩阵转置

int main() {

	int a[2][3] = { {1,2,3,} ,{4,5,6} };
	int b[3][2] = { };
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++)
			b[j][i] = a[i][j];
	}
	cout << "array b:\n";
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++)
			cout << b[i][j] << ' ';
		cout << "\n"; //每行输出完后换行
return 0;
	}

// 改进
// 不引入另一个数组

int main()
{
      int n,m;
	  cin >> n >> m;
	  int arr[500][500] = { 0 };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
	    //到此储存好二维数组的数据
		cout << endl;
		//转置
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(3) << arr[j][i];//用stew()使得输出对齐
                //注意包含头文件  #include<iomanip>
			}
			cout << endl;
		}
}



// 注意：VS不支持arr中存放变量，只能是常量或者表达式。



// 题目四
// 交换数组

int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 54,23,4,5,7 };
	
	for (int i = 0; i < 5; i++)
	{
		int change = arr1[i];
		arr1 [i] = arr2[i];
		arr2[i] = change;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i]<<" ";
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i]<<" ";
	}
	return 0;
}



//  错误做法



// 题目五

// 有序序列的合并，注意输入时每行数据从小到大输入。



int main()
{
	int n ,m;
	cin >> n >> m;
	int arr1[1000] = { 0 };
	int arr2[1000] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}
	for (int j = 0; j <m; j++)
	{
		cin >> arr2[j];
	}
	//到此处 数组数据全部储存好
	cout << endl;
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (arr1[i] < arr2[j]) //两个数组数据进行比较
		{
			cout << arr1[i]<<" ";
			i++;
		}
		if (arr2[j] < arr1[i])
		{
			cout << arr2[j]<< " ";
			j++;
		}
	}
	//剩下的全部打印
	//i中的数据全部与j比较完成，j中数据还有剩下的
	//说明j中的数据全部比i大，全部输出
	//反之也如此
	while (i < n)
	{
		cout << arr1[i]<<" ";
		i++;
	}
	while (j < m)
	{
		cout << arr2[j]<<" ";
		j++;
	}
	return 0;
}
