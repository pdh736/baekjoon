#include <stdio.h>

int destroyed(int channel);
int button[10];

int main() {
	int channel;
	int s_chan=100;
	int m;
	
	int temp;
	int cnt;

	int push_cnt1;	
	int push_cnt2;	

	scanf("%d", &channel);
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		button[temp] = 1;
	}
	//--------- +,-�θ� �̵��� ���
	cnt = channel - s_chan;
	if (cnt < 0)cnt *= -1; //���밪

	for (int i = 0; i < 500000; i++) {
		int chan = i;	//Ư��ä��, 0���� ��ä�α��� �ݺ�
		push_cnt1 = destroyed(chan); //Ư��ä�� ��ư���� ��������
		if (push_cnt1 > 0) {
			push_cnt2 = channel - chan;//�̵��� Ư��ä�ΰ� ��ǥä�� +,-�� �̵��ϴ� Ƚ��
			if (push_cnt2 < 0)push_cnt2 *= -1 ; //���밪
			if (cnt > push_cnt2+push_cnt1)cnt = push_cnt2+push_cnt1;
			//ex ��ǥä�� 123  Ư��ä�� 120(i==120) �ϰ�� ��ư�̵� 3(cnt1) +-�̵� 3(cnt2)
			//  push_cnt2+push_cnt1 == 6
		}
	}
	printf("%d\n", cnt);
	return 0;
}

int destroyed(int channel) {//�����ҽ� ��ư ������ Ƚ�� , ��������ư ������ 0 return
	int len = 0;;
	if (channel == 0) return button[0] ? 1 : 0;
	while (channel > 0) {
		if (button[channel % 10])return 0;
		len++;
		channel /= 10;
	}
	return len;
}

