#include <stdio.h>
int main()
{
	long long int n, x, m, y;
	scanf("%lld%lld%lld%lld", &n, &x, &m, &y);
	long long int count = 0, temp = 0;
	long long int pkgsinglepr = y / m, justsinglepr = x;
	if (pkgsinglepr <= justsinglepr)
	{
		count = n % y;
		if (count == 0 || count < x)
		{
			printf("%lld\n", m * (n / y));
		}
		else
		{
			temp = x / count;
			printf("%lld\n", m * (n / y) + temp);
		}
	}
	else
	{
		long long int total = n / x;
		printf("%d\n", total);
	}
	return 0;
}