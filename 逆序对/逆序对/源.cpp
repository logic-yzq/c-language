#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <iostream>
#include<cstring>
using namespace std;
int n; int arr[100010]; int tmp[100010]; long long num = 0;
void msort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	msort(left, mid);
	msort(mid + 1, right);
	int i = left, j = mid + 1, p = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			tmp[p] = arr[i];
			p++;
			i++;
		}
		else
		{
			tmp[p] = arr[j];
			num += mid - i + 1;
			p++;
			j++;
		}
	}
	while (i <= mid)
	{
		tmp[p] = arr[i];
		p++;
		i++;
	}
	while (j <= right)
	{
		tmp[p] = arr[j];
		p++;
		j++;
	}
	for (int i = left; i <= right; i++)
		arr[i] = tmp[i];
	return;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	msort(1, n);
	cout << num;
	return 0;
}