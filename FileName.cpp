#include <iostream>
using namespace std;

void setpotion(int count, int* PotionHP, int* PotionMP) {
	*PotionHP = count;
	*PotionMP = count;
}
// setpotion이라는 함수는 포션 개수를 설정하는 역할
// int* PotionHP와 int* PotionMp는 각각 HP와 MP 포션의 개수를 저장하는 포인터입니다.
// count는 포션의 개수를 나타내며, 이 값을 두 포인터가 가리키는 변수에 저장합니다.
// *PotionHP와 *PotionMP = count;는 각각의 포인터가 가리키는 변수에 count 값을 할당합니다.
// 이 함수는 포션의 개수를 설정하는 기능을 수행합니다. 또는 동시에 같은 개수로 설정
// 예를 들면 PRG게임에서 초반에 포션을 기본으로 지급 받을 떄 처럼 사용가능.

int main() {
	const int size = 4; // const : 상수, size는 배열의 크기를 나타낸다.
	int stat[size] = { 0 }; // state 배열은 4개의 정수로 초기화되며, 각각의 요소는 0으로 설정된다.
	// state [0] : hp, state [1] : mp, state [2] : potionhp, state [3] : potionmp

	//HP와 MP 입력
	while (true) { // 무한 루프를 사용하여 유효한 HP와 MP 입력을 받을 때까지 반복
		cout << "HP를 입력해주세요: ";
		cin >> stat[0];
		cout << "MP를 입력해주세요: ";
		cin >> stat[1];

		if (stat[0] > 50 && stat[1] > 50) break; // 두 가지 조건을 모두 만족할 때 루프 종료(참이 되면 루프 탈출)
		// &&는 "그리고"를 의미하며, 두 조건이 모두 참일 때만 실행된다.
		// break;는 루프를 종료하는 역할을 한다.
	}

	// 공격력, 방어력 입력
	while (true) {
		cout << "공격력을 입력해주세요: ";
		cin >> stat[2];
		cout << "방어력을 입력해주세요: ";
		cin >> stat[3];
		if (stat[2] > 0 && stat[3] > 0) break;
		cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
	}
	int choice = 0; // 사용자의 선택을 저장할 변수, 메뉴 번호를	선택하는데 사용.
	int HPPotion = 0; // HP 포션 개수
	int MPPotion = 0; // MP 포션 개수
	// 각각 포션의 개수를 0으로 저장한다.

	setpotion(10, &HPPotion, &MPPotion); // setPotion 함수를 호출하여 HP와 MP 포션 개수를 10으로 설정
	// setPotion 함수는 포션의 개수를 설정하는 역할을 한다.
	cout << "포션이 지급되었습니다. (HP, MP 포션 각 10개)" << endl;
	cout << "ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ" << endl;
	cout << "<스탯 관리 시스템>" << endl;

	while (true) {
		cout << "1. HP 포션 사용 \n";
		cout << "2. MP 포션 사용 \n";
		cout << "3. HP 강화 \n";
		cout << "4. MP 강화 \n";
		cout << "5. 공격 스킬 사용 \n";
		cout << "6. 필살기 사용 \n";
		cout << "7. 뒤로가기\n";
		// 무한 루프 : 메뉴를 계속 출력하여 사용자가 선택할 수 있도록 한다.
		cout << "번호를 선택해주세요 : ";
		cin >> choice;

			if (choice == 7)
			{
				cout << "프로그램을 종료합니다." << endl;
				break; // 사용자가 7을 선택하면 프로그램 종료
			}
		switch (choice) 
		{
		case 1: // HP 회복
			if (HPPotion <= 0)
			{
				cout << "포션이 부족합니다." << endl;
				continue; // 포션이 부족하면 다음 반복으로 넘어감, 포션이 없으면 메세지, 있으면 +20, 포션 -1
			}
			stat[0] += stat[0] * 0.2; // 현재 HP에 20% 회복
			HPPotion--; // HP 포션 개수 감소, 후위연산자를 사용하여 감소
			cout << " HP가 20% 회복되었습니다. 포션이 1개 차감됩니다." << endl;
			cout << "현재 HP : " << stat[0] << endl; // 현재 HP 출력
			cout << "남은 포션 수 : " << HPPotion << endl; // 남은 포션의 수를 출력
			break;
		
		case 2: // MP 회복
			if (MPPotion <= 0) 
			{
				cout << "포션이 부족합니다." << endl;
				continue; // 포션이 부족하면 다음 반복으로 넘어감
			}
			stat[1] += stat[1] * 0.2; // MP를 20% 회복
			MPPotion--; // MP 포션 개수 감소
			cout << "MP가 20% 회복되었습니다. 포션이 1개 차감됩니다." << endl;
			cout << "현재 MP: " << stat[1] << endl; // 현재 MP 출력
			cout << "남은 포션 수: " << MPPotion << endl; // 남은 포션의 수를 출력
			break;

		case 3: // HP 강화
			stat[0] *= 2; // HP를 2배로 증가
			cout << "HP가 2배로 증가되었습니다." << endl;
			cout << "현재 HP: " << stat[0] << endl; // 현재 HP 출력
			break;

		case 4: // MP 강화
			stat[1] *= 2; // MP를 2배로 증가
			cout << "MP가 2배로 증가되었습니다." << endl;
			cout << "현재 MP: " << stat[1] << endl; // 현재 MP 출력
			break;

		case 5: // 공격 스킬 사용
			stat[2] -= 10; // 공격력 감소
			if (stat[1] < 50) 
			{
				cout << "스킬 사용이 불가합니다." << endl; // MP가 부족하면 스킬 사용 불가
			}
			else
			{
				stat[1] -= stat[1] * 0.5; // MP 감소
				cout << "스킬을 사용하여 MP가 50% 소모되었습니다." << endl;
				cout << "현재 MP: " << stat[1] << endl; // 현재 MP 출력
			}
				break;
			
		case 6: // 필살기 사용
			stat[1] -= stat[2] / 2; // MP의 50% 감소
			if (stat[1] <= 0)
			{
				cout << "스킬 사용이 불가합니다." << endl; // MP가 부족하면 스킬 사용 불가
			}
			else
			{
				cout << "스킬을 사용하여 MP가 50% 소모되었습니다." << endl;
				cout << "현재 MP: " << stat[1] << endl; // 현재 MP 출력
			}
				break;
			
		default:
			cout << "다시 입력해주세요." << endl;
			break;
			}
		}

			return 0;
	}



