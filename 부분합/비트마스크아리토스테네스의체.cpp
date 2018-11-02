#include<iostream>

using namespace std;

#define MAX_N 9
int n;
unsigned char sieve[(MAX_N + 7) / 8];

//k�� �Ҽ������� Ȯ���Ѵ�.
inline bool isPrime(int k) {
	return sieve[k >> 3] & (1 << (k & 7));
}

//k�� �Ҽ��� �ƴ϶�� ǥ���Ѵ�.
inline void setComposite(int k) {
	sieve[k >> 3] &= ~(1 << (k & 7));
}
//��Ʈ����ũ�� ����ϴ� �����佺�׳׽��� ü�� ����
//�� �Լ��� �����ϰ� �� ��, isPrime()�� �̿��� �� ���� �Ҽ����� �� �� �ִ�.
void eratosthenes() {
	memset(sieve, 255, sizeof(sieve));//��ü�� memset�Լ��� Ư�� ������ �ִ� ���ӵ� �޸𸮿� ���� �����ϰ� ���� �� ����ϴµ� for������ �� ���� �ӵ��� ���ü��� �ִ�.
	setComposite(0);
	setComposite(1);
	int sqrtn = int(sqrt(n));

	for (int i = 2; i <= sqrtn; i++) {
		//���� ���� �������� �ʾҴٸ�
		if (isPrime(i)) {
			//i�� ��� j�鿡 ���� isPrime[j]=false�� �д�
			//i*i�̸��� ����� �̹� ���������Ƿ� �Ű� ���� �ʴ´�.
			for (int j = i * i; j <= n; j += i) {
				setComposite(j);
			}
		}
	}
	

}
void main() {
	cout<<isPrime(17);

}