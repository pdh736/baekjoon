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
	//--------- +,-로만 이동한 경우
	cnt = channel - s_chan;
	if (cnt < 0)cnt *= -1; //절대값

	for (int i = 0; i < 500000; i++) {
		int chan = i;	//특정채널, 0부터 끝채널까지 반복
		push_cnt1 = destroyed(chan); //특정채널 버튼으로 가능한지
		if (push_cnt1 > 0) {
			push_cnt2 = channel - chan;//이동한 특정채널과 목표채널 +,-로 이동하는 횟수
			if (push_cnt2 < 0)push_cnt2 *= -1 ; //절대값
			if (cnt > push_cnt2+push_cnt1)cnt = push_cnt2+push_cnt1;
			//ex 목표채널 123  특정채널 120(i==120) 일경우 버튼이동 3(cnt1) +-이동 3(cnt2)
			//  push_cnt2+push_cnt1 == 6
		}
	}
	printf("%d\n", cnt);
	return 0;
}

int destroyed(int channel) {//가능할시 버튼 누르는 횟수 , 망가진버튼 있을시 0 return
	int len = 0;;
	if (channel == 0) return button[0] ? 1 : 0;
	while (channel > 0) {
		if (button[channel % 10])return 0;
		len++;
		channel /= 10;
	}
	return len;
}

