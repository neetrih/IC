#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	// 创建一个优先级队列
	priority_queue<int> pq;
	
	// 插入一些元素
	pq.push(3);
	pq.push(1);
	pq.push(4);
	pq.push(1);
	
	// 访问最高优先级的元素
	cout << "Top element: " << pq.top() << endl;
	
	// 删除最高优先级的元素
	pq.pop();
	
	// 访问新的最高优先级的元素
	cout << "Top element after pop: " << pq.top() << endl;
	
	// 循环访问队列中的所有元素
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	
	return 0;
}
